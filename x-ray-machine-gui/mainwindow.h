#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
class QAction;
class QLabel;
class QScrollArea;
class QMenu;
class QAction;
class QScrollBar;
class QFrame;
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
    void saveAs();



private:

    void settingImage(const QImage &newImage);

    bool savingImage(const QString &fileName);

    QList<QLabel *> labels;

    QVBoxLayout *frame;
    QHBoxLayout *pictures;
    QVBoxLayout *haventModifiedPics;
    QVBoxLayout *modifiedPics;
    QAction *saveAsAct;
    QPushButton *openButton;
    QPushButton *cancelButton;
};
#endif // MAINWINDOW_H
