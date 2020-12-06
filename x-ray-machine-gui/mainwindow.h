#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
class QAction;
class QLabel;
class QMenu;
class QHBoxLayout;
class QPushButton;
class QVBoxLayout;

QT_END_NAMESPACE

class MainWindow : public QMainWindow
        //single colon represents inheritance
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);


private slots:
    void open();
    void toFPGA();
    void process();


private:


    QWidget *cw;



    QVBoxLayout *frame;
    QHBoxLayout *pictures;
    QVBoxLayout *haventModifiedPics;
    QVBoxLayout *modifiedPics;

    QMenu *fileMenu;
    QToolBar *fileToolBar;

    QAction *openingAct;
    QAction *exitAct;
    QList<QLabel *> labels;

    QMenu *processMenu;
    QAction *processAct;

    QMenu *FPGAMenu;
    QAction *toFPGAAct;
};
#endif // MAINWINDOW_H
