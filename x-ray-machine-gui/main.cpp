#include "mainwindow.h"
#include <QCommandLineParser>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCommandLineParser commandLineParser;
    commandLineParser.addHelpOption();
    commandLineParser.addPositionalArgument(MainWindow::tr("[file]"), MainWindow::tr("Image file to open."));
    commandLineParser.process(QCoreApplication::arguments());
    MainWindow w;
    if (!commandLineParser.positionalArguments().isEmpty()
        && !w.loadingImage(commandLineParser.positionalArguments().front())) {
        return -1;
    }
    w.show();
    return a.exec();
}
