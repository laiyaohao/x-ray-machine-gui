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
#include <QToolBar>
#include <QHBoxLayout>
#include <QPushButton>
#include <QStandardPaths>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //, ui(new Ui::MainWindow)
{
    QWidget *cw = new QWidget();

    QTabWidget *tabs = new QTabWidget(this);

    QWidget *filetab = new QWidget();
    QVBoxLayout *buttonLayout = new QVBoxLayout();
    openButton = new QPushButton(tr("Open Images"));
    cancelButton = new QPushButton(tr("Cancel"));
    buttonLayout->addWidget(openButton);
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addStretch();
    filetab->setLayout(buttonLayout);
    tabs->addTab(filetab,tr("Files"));

    frame = new QVBoxLayout();
    pictures = new QHBoxLayout();
    haventModifiedPics = new QVBoxLayout();
    modifiedPics = new QVBoxLayout();

    pictures->addLayout(haventModifiedPics);
    pictures->addLayout(modifiedPics);
    pictures->addStretch();

    frame->addWidget(tabs);
    frame->addLayout(pictures);
    frame->addSpacing(100);
    cw->setLayout(frame);
    setCentralWidget(cw);

    QMenu *fileMenu = menuBar()->addMenu(tr("File"));

    QToolBar *fileToolBar = addToolBar(tr("File"));



//    addDockWidget(Qt::TopDockWidgetArea,fileDock);
    const QIcon openIcon = QIcon::fromTheme("document-open", QIcon(":resources/images/open.png"));
    QAction *openingAct = new QAction(openIcon,tr("Open..."),this);
    fileMenu->addAction(openingAct);
    //tr("Open..."),this,&MainWindow::open);
    connect(openingAct,&QAction::triggered,this,&MainWindow::open);
    openingAct->setShortcut((QKeySequence::Open));
    fileToolBar->addAction(openingAct);

    const QIcon saveIcon = QIcon::fromTheme("document-save",QIcon(":resources/images/save.png"));
    saveAsAct = fileMenu->addAction(tr("Save As..."),this, &MainWindow::saveAs);
    saveAsAct->setEnabled(false);

    fileMenu->addSeparator();

    QAction *exitAct = fileMenu->addAction(tr("Exit"), this, &QWidget::close);
    exitAct->setShortcut(tr("Ctrl+W"));


    resize(QGuiApplication::primaryScreen()->availableSize());
}




void MainWindow::settingImage(const QImage &imageToSet)
{
//    image = imageToSet;
//    if (image.colorSpace().isValid())
//        image.convertToColorSpace(QColorSpace::SRgb);
//    xRayImageLabel->setPixmap(QPixmap::fromImage(image));

//    xRayScrollArea->setVisible(true);


}



void MainWindow::open()
{

    const int imageLength = 800;
    const int imageHeight = 400;
    QString file = QFileDialog::getOpenFileName(this, tr("Select Images"),
                            QStandardPaths::writableLocation(QStandardPaths::PicturesLocation),
                            "*.jpg *.png");
    bool selected = false;
    if (!file.isEmpty()) {
        selected = true;
    }
    if (selected)
    {
    QLabel *imageLabel = new QLabel;
    imageLabel->setFixedSize(imageLength,imageHeight);
    QImage image(file);
    QImage scaled = image.scaled(QSize(imageLength, imageHeight), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    imageLabel->setPixmap(QPixmap::fromImage(scaled));
    haventModifiedPics->addWidget(imageLabel);
    labels.append(imageLabel);
    //limit 2
    if (labels.length() > 2) {
        haventModifiedPics->removeWidget(labels.front());
        labels.pop_front();
    }
    }
}

bool MainWindow::savingImage(const QString &fileName)
{
//    QImageWriter writer(fileName);
//    if (writer.write(image)) {
//        QMessageBox::information(this,QGuiApplication::applicationDisplayName(),
//                                 tr("Cannot write %1: %2")
//                                 .arg(QDir::toNativeSeparators(fileName),writer.errorString()));
//        return false;
//    }
//    const QString msg = tr("Saved.");
//    statusBar()->showMessage(msg);
//    return true;
    return true;
}

void MainWindow::saveAs()
{
//    QFileDialog dialog(this,tr("Save File As"));
//    initializeImageFileDialog(dialog, QFileDialog::AcceptSave);

//    while (dialog.exec() == QDialog::Accepted && !savingImage(dialog.selectedFiles().first())) {}
}


