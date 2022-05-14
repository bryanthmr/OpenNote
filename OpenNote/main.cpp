#include <QApplication>
#include <QtWidgets>
#include "Fenetre.h"
#include <QTranslator>
#include <QLocale>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);




    Fenetre fenetre;

    fenetre.show();


    return app.exec();
}


