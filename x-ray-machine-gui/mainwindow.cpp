#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QScrollArea>
#include <QScreen>
#include <QFileDialog>
#include <QMenuBar>
#include <QStatusBar>
#include <QImageReader>
#include <QImageWriter>
#include <QColorSpace>
#include <QMessageBox>
#include <QScrollBar>


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
    resize(QGuiApplication::primaryScreen()->availableSize());
}

static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
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
//    copyAct->setEnabled(!image.isNull());
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
        QMessageBox::information(this,QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName),reader.errorString()));
        return false;
    }
    settingImage(imageToRead);
    setWindowFilePath(fileName);
    const QString msg = tr("Opened \"%1\", %2x%3, Depth: %4")
        .arg(QDir::toNativeSeparators(fileName)).arg(image.width()).arg(image.height()).arg(image.depth());
    statusBar()->showMessage(msg);
    return true;
}

void MainWindow::open()
{
    QFileDialog dialog(this,tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);
    while (dialog.exec() == QDialog::Accepted && !loadingImage(dialog.selectedFiles().first())) {}
}

bool MainWindow::savingImage(const QString &fileName)
{
    QImageWriter writer(fileName);
    if (writer.write(image)) {
        QMessageBox::information(this,QGuiApplication::applicationDisplayName(),
                                 tr("Cannot write %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName),writer.errorString()));
        return false;
    }
    const QString msg = tr("Saved.");
    statusBar()->showMessage(msg);
    return true;
}

void MainWindow::saveAs()
{
    QFileDialog dialog(this,tr("Save File As"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptSave);

    while (dialog.exec() == QDialog::Accepted && !savingImage(dialog.selectedFiles().first())) {}
}

void MainWindow::normalSize()
//! [11] //! [12]
{
    xRayImageLabel->adjustSize();
    scaleFactor = 1.0;
}

void MainWindow::fittingToWindow()
//! [13] //! [14]
{
    bool fitToWindow = fittingToWindowAct->isChecked();
    xRayScrollArea->setWidgetResizable(fitToWindow);
    if (!fitToWindow)
        normalSize();
    updateActions();
}

void MainWindow::adjustXRayScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}

void MainWindow::scaleImage(double factor)
//! [23] //! [24]
{
    scaleFactor *= factor;
    xRayImageLabel->resize(scaleFactor * xRayImageLabel->pixmap(Qt::ReturnByValue).size());

    adjustXRayScrollBar(xRayScrollArea->horizontalScrollBar(), factor);
    adjustXRayScrollBar(xRayScrollArea->verticalScrollBar(), factor);

    zoomInAct->setEnabled(scaleFactor < 3.0);
    zoomOutAct->setEnabled(scaleFactor > 0.333);
}

void MainWindow::zoomIn()
{
    scaleImage(1.25);
}

void MainWindow::zoomOut()
{
    scaleImage(0.8);
}

void MainWindow::create()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("File"));

    QAction *openingAct = fileMenu->addAction(tr("Open..."),this,&MainWindow::open);
    openingAct->setShortcut((QKeySequence::Open));


    saveAsAct = fileMenu->addAction(tr("Save As..."),this, &MainWindow::saveAs);
    saveAsAct->setEnabled(false);

    fileMenu->addSeparator();

    QAction *exitAct = fileMenu->addAction(tr("Exit"), this, &QWidget::close);
    exitAct->setShortcut(tr("Ctrl+Q"));

    QMenu *viewMenu = menuBar()->addMenu(tr("View"));

    zoomInAct = viewMenu->addAction(tr("Zoom in (25%)"),this,&MainWindow::zoomIn);
    zoomInAct->setEnabled(false);

    zoomOutAct = viewMenu->addAction(tr("Zoom out (25%)"),this,&MainWindow::zoomOut);
    zoomOutAct->setEnabled(false);

    normalSizeAct = viewMenu->addAction(tr("Normal Size"), this, &MainWindow::normalSize);
    normalSizeAct->setEnabled(false);

    fittingToWindowAct = viewMenu->addAction(tr("Fit to Window"), this, &MainWindow::fittingToWindow);
    fittingToWindowAct->setEnabled(false);
    fittingToWindowAct->setCheckable(true);
    fittingToWindowAct->setShortcut(tr("Ctrl+F"));
}
