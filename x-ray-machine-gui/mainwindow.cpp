#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QScreen>
#include <QFileDialog>
#include <QMenuBar>
#include <QStatusBar>
#include <QDebug>
#include <QToolBar>
#include <QHBoxLayout>
#include <QStandardPaths>
#include <QMimeDatabase>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
{

    cw = new QWidget();

    frame = new QVBoxLayout();
    pictures = new QHBoxLayout();
    haventModifiedPics = new QVBoxLayout();

    modifiedPics = new QVBoxLayout();

    pictures->addLayout(haventModifiedPics);
    pictures->addLayout(modifiedPics);
    pictures->addStretch();


    frame->addLayout(pictures);
    frame->addStretch();
    cw->setLayout(frame);
    setCentralWidget(cw);

    fileMenu = menuBar()->addMenu(tr("File"));

    fileToolBar = addToolBar(tr("File"));

    const QIcon openIcon = QIcon::fromTheme("document-open", QIcon(":resources/images/open.png"));
    openingAct = new QAction(openIcon,tr("Open..."),this);
    connect(openingAct,&QAction::triggered,this,&MainWindow::open);
    openingAct->setShortcut((QKeySequence::Open));
    fileMenu->addAction(openingAct);
    fileToolBar->addAction(openingAct);

//    const QIcon saveIcon = QIcon::fromTheme("document-save",QIcon(":resources/images/save.png"));
//    saveAsAct = fileMenu->addAction(tr("Save As..."),this, &MainWindow::saveAs);
//    saveAsAct->setEnabled(false);

    fileMenu->addSeparator();

    const QIcon exitIcon = QIcon::fromTheme("application-exit");
    exitAct = fileMenu->addAction(exitIcon, tr("Exit"), this, &QWidget::close);
    exitAct->setShortcut(tr("Ctrl+W"));
    fileToolBar->addAction(exitAct);

    processMenu = menuBar()->addMenu(tr("Process..."));
    processAct = new QAction(tr("Process"),this);
    connect(processAct,&QAction::triggered,this,&MainWindow::process);
    processMenu->addAction(processAct);

    FPGAMenu = menuBar()->addMenu(tr("FPGA..."));
    toFPGAAct = new QAction(tr("To FPGA"),this);
    connect(toFPGAAct,&QAction::triggered,this,&MainWindow::toFPGA);
    resize(QGuiApplication::primaryScreen()->availableSize());
    FPGAMenu->addAction(toFPGAAct);
}




void MainWindow::process()
{
//    image = imageToSet;
//    if (image.colorSpace().isValid())
//        image.convertToColorSpace(QColorSpace::SRgb);
//    xRayImageLabel->setPixmap(QPixmap::fromImage(image));

//    xRayScrollArea->setVisible(true);
    QString folderOfImages = QFileDialog::getExistingDirectory(this, tr("Select Folder of images"),
                            QStandardPaths::writableLocation(QStandardPaths::PicturesLocation));
    QString save = QFileDialog::getExistingDirectory(this, tr("Select location to save folder of images"),
                            QStandardPaths::writableLocation(QStandardPaths::PicturesLocation));
    QDir imagesDir(folderOfImages);
    QDir savedDir(save);
//    qDebug() << save;
//    qDebug() << folderOfImages;
    QList <QFileInfo> fileInfo = imagesDir.entryInfoList();
    for (auto info: fileInfo) {
        // check if its base folder, like /home or /
        // base folder's baseName is empty
        // so if not empty, it should be the "real" files/folders
        if (!info.baseName().isEmpty()) {
            QMimeDatabase db;
            QMimeType mime = db.mimeTypeForFile(info,QMimeDatabase::MatchContent);
            // check if preferredsuffix is the file type we want
            // can also use suffixes, but will return QStringList
            // a list of QString
            if (mime.preferredSuffix() != "mp3")
            {
                qDebug() << info.absoluteFilePath();

            }
        }
        // we can now exclude the files with file format that we dont want
        // what if have folders inside also

    }
}



void MainWindow::open()
{

    const int imageLength = 900;
    const int imageHeight = 400;
    QString file = QFileDialog::getOpenFileName(this, tr("Select Images"),
                            QStandardPaths::writableLocation(QStandardPaths::PicturesLocation),
                            "*.jpg *.png");
    bool selected = false;
    if (!file.isEmpty()) {
        selected = true;
    }
    if (selected) {
        QLabel *imageLabel = new QLabel;
        imageLabel->setFixedSize(imageLength,imageHeight);
        imageLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QImage image(file);
        QImage scaled = image.scaled(QSize(imageLength, imageHeight), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        imageLabel->setPixmap(QPixmap::fromImage(scaled));
        haventModifiedPics->addWidget(imageLabel);
        labels.append(imageLabel);
        //limit 2
        if (labels.length() > 2) {
            haventModifiedPics->removeWidget(labels.front());
            labels.front()->setParent(NULL);
            labels.pop_front();
        }

    }
    haventModifiedPics->addStretch(100);
}


void MainWindow::toFPGA()
{
//    QFileDialog dialog(this,tr("Save File As"));
//    initializeImageFileDialog(dialog, QFileDialog::AcceptSave);

//    while (dialog.exec() == QDialog::Accepted && !savingImage(dialog.selectedFiles().first())) {}
}


