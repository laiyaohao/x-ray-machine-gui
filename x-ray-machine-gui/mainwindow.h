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
    void saveAs();
    void normalSize();
    void fittingToWindow();
    void zoomIn();
    void zoomOut();

private:
    void create();
    void settingImage(const QImage &newImage);
    void updateActions();
    bool savingImage(const QString &fileName);
    void scaleImage(double factor);
    void adjustXRayScrollBar(QScrollBar *scrollBar, double factor);

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
