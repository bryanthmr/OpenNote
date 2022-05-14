#ifndef FENETRE_H
#define FENETRE_H

#include <QMenu>
#include <QtWidgets>
#include <QAction>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include <QDateTime>
#include <QProcess>

class Fenetre: public QMainWindow
{
    Q_OBJECT


public:
    Fenetre();
    bool verification();
    void basededonnee();
    void fichierrecent();

protected:
    void closeEvent(QCloseEvent* event);


public slots:
    void enregistrer_sous();
    void enregistrer();
    void ouvrir();
    void fermer();
    void quitter();
    void nouveau();
    void infoEmojis();
    void infoCapture();
    void annuler();
    void refaire();
    void ouvrirRecent1();
    void ouvrirRecent2();
    void ouvrirRecent3();
    void fontdialog();
    void rechercherDialog();
    void rechercher();
    void selectall();
    //void zoom0();
    void aliright();
    void alileft();
    void alicenter();
    void alijustify();
    void couleur();
    void ouvrirFile();
    void etoile();
    void temps();
    void nouveauF();
    void enregistrerFTS();





private:
    QMenu *m_fichier;
    QMenu *m_affichage;
    QMenu *m_edition;
    QWidget *m_zone;
    QAction *m_nouveau;
    QAction *m_nouveauF;
    QAction *m_ouvrir;
    QAction *m_fermer;
    QAction *m_save;
    QAction *m_saveOn;
    QAction *m_quitter;
    QFont *m_defaultfont;
    QAction *m_annuler;
    QAction *m_emojis;
    QAction *m_refaire;
    //QAction *m_rechercher;
    QMenu *m_fichierRecent;
    QMenu *m_alignement;
    QAction *m_aliright;
    QAction *m_alileft;
    QAction *m_alicenter;
    QAction *m_alijustify;
    QAction *m_saveFTS;
    QAction *m_capturedecran;
    QAction *m_fichierR1;
    QAction *m_fichierR2;
    QAction *m_fichierR3;
    QVBoxLayout *m_layout;
    QTextEdit *m_textEdit;
    QString *m_nomfichier;
    QString *m_fichierR;
    QToolBar *m_toolbar;
    QPushButton *m_font;
    QPushButton *m_color;
    QPushButton *m_boutonNouveau;
    QPushButton *m_boutonOuvrir;
    QPushButton *m_boutonEnregistrer;
    QLineEdit *m_lineEdit;
    QAction *m_temps;
    QAction *m_selectall;
    QFont *m_defaultfont2;
    bool *m_siFermer;


};

#endif // FENETRE_H
