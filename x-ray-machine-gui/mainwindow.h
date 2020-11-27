#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QLabel;
class QScrollArea;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
        //single colon represents inheritance
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool loadingImage(const QString &);

private slots:
    void open();
private:
    void create();
    void settingImage(const QImage &newImage);
    void updateActions();

    QImage image;
    QLabel *xRayImageLabel;
    QScrollArea *xRayScrollArea;
    double scaleFactor = 1;

    QAction *saveAsAct;
    QAction *fittingToWindowAct;
    QAction *printingAct;
    QAction *copyAct;
    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *normalSizeAct;
};
#endif // MAINWINDOW_H
