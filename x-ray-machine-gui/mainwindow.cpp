#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QtWidgets>
#include <QFileDialog>
#include <QMenuBar>
MainWindow::MainWindow(QWidget *parent) //MainWindow(QWidget *parent)
    : QMainWindow(parent), xRayImageLabel(new QLabel)
    , xRayScrollArea(new QScrollArea)
    //, ui(new Ui::MainWindow)
{
    xRayImageLabel->setBackgroundRole(QPalette::Base);
    xRayImageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    xRayImageLabel->setScaledContents(true);

    xRayScrollArea->setBackgroundRole(QPalette::Dark);
    xRayScrollArea->setWidget(xRayImageLabel);
    xRayScrollArea->setVisible(false);
    setCentralWidget(xRayScrollArea);

    create();
}

void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;

    if (firstDialog) {
        firstDialog = false;
        //const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        dialog.setDirectory(QDir::currentPath());
    }
    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
        ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();
    for (const QByteArray &mimeTypeName : supportedMimeTypes)
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");
    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix("jpg");
}

void MainWindow::updateActions()
{
    saveAsAct->setEnabled(!image.isNull());
    copyAct->setEnabled(!image.isNull());
    zoomInAct->setEnabled(!fittingToWindowAct->isChecked());
    zoomOutAct->setEnabled(!fittingToWindowAct->isChecked());
    normalSizeAct->setEnabled(!fittingToWindowAct->isChecked());
}

void MainWindow::settingImage(const QImage &imageToSet)
{
    image = imageToSet;
    if (image.colorSpace().isValid())
        image.convertToColorSpace(QColorSpace::SRgb);
    xRayImageLabel->setPixmap(QPixmap::fromImage(image));
    scaleFactor = 1.0;
    xRayScrollArea->setVisible(true);
    printingAct->setEnabled(true);
    fittingToWindowAct->setEnabled(true);
    updateActions();

    if (!fittingToWindowAct->isChecked()) {
        xRayImageLabel->adjustSize();
    }
}

bool MainWindow::loadingImage(const QString &fileName)
{
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage imageToRead = reader.read();
    if (imageToRead.isNull()) {
        QMessageBox::information(this,QGuiApplication::applicationDisplayName(),tr("Cannot load %1: %2").arg(QDir::toNativeSeparators(fileName),reader.errorString()));
        return false;
    }
    settingImage(imageToRead);
    setWindowFilePath(fileName);
    const QString msg = tr("Opened");
    statusBar()->showMessage(msg);
    return true;
}

void MainWindow::open()
{
    QFileDialog dialog(this,tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);
    while (dialog.exec() == QDialog::Accepted && !loadingImage(dialog.selectedFiles().first())) {}
}

void MainWindow::create()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("File"));
    QAction *openingAct = fileMenu->addAction(tr("Open..."),this,&MainWindow::open);
    openingAct->setShortcut((QKeySequence::Open));
}
