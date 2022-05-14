#include "Fenetre.h"

Fenetre::Fenetre()
{

    //Paramètre de la fenetre
    setGeometry(300,180,1000,500);
    QIcon icon3(QCoreApplication::applicationDirPath()+"principal.ico");
    QSize taille3(25,25);
    this->setIconSize(taille3);
    this->setWindowIcon(icon3);



    //tool bar
    m_toolbar=new QToolBar(this);
    m_boutonNouveau=new QPushButton("",this);
    m_boutonOuvrir=new QPushButton("",this);
    m_boutonEnregistrer=new QPushButton("",this);
    m_font=new QPushButton("",this);
    m_color=new QPushButton("",this);

    m_toolbar->addWidget(m_boutonNouveau);
    m_toolbar->addWidget(m_boutonOuvrir);
    m_toolbar->addWidget(m_boutonEnregistrer);
    m_toolbar->addWidget(m_font);
    m_toolbar->addWidget(m_color);


    //menu
    m_fichier=menuBar()->addMenu("&Fichier");
    m_edition=menuBar()->addMenu("&Edition");
    m_affichage=menuBar()->addMenu("&Affichage");

    m_nouveau=new QAction("&Nouveau",this);
    m_nouveauF=new QAction("&Nouvelle Fenêtre",this);
    m_ouvrir=new QAction("&Ouvrir",this);
    m_fichierRecent=m_fichier->addMenu("&Fichiers Récents");
    m_save=new QAction("&Enregistrer",this);
    m_saveOn=new QAction("&Enregistrer Sous",this);
    m_saveFTS=new QAction("&Enregistrer au format *.txt",this);
    m_quitter=new QAction("&Quitter",this);
    m_fermer=new QAction("&Fermer le fichier",this);

    m_annuler=new QAction("&Annuler",this);
    m_refaire=new QAction("&Refaire",this);
    m_selectall=new QAction("&Tout séléctionner",this);
    m_temps=new QAction("&Date/Heure",this);
    //m_rechercher=new QAction("&Rechercher",this);


    m_alignement=m_affichage->addMenu("&Alignement");
    m_aliright=new QAction("Droite");
    m_alileft=new QAction("Gauche");
    m_alicenter=new QAction("Centre");
    m_alijustify=new QAction("Justifié");
    m_emojis=new QAction("&Emojis",this);
    m_capturedecran=new QAction("&Capture d'écran");

    m_fichierR = new QString("Null");
    m_fichierR1 = new QAction("(vide)",this);
    m_fichierR2 = new QAction("(vide)",this);
    m_fichierR3 = new QAction("(vide)",this);



    m_fichier->addAction(m_nouveau);
    m_fichier->addAction(m_nouveauF);
    m_fichier->addAction(m_ouvrir);
    m_fichier->addMenu(m_fichierRecent);
    m_fichier->addAction(m_save);
    m_fichier->addAction(m_saveOn);
    m_fichier->addAction(m_saveFTS);
    m_fichier->addSeparator();
    m_fichier->addAction(m_fermer);
    m_fichier->addAction(m_quitter);

    m_edition->addAction(m_annuler);
    m_edition->addAction(m_refaire);
    m_edition->addSeparator();
    m_edition->addAction(m_selectall);
    m_edition->addAction(m_temps);
    //m_edition->addAction(m_rechercher);



    m_affichage->addSeparator();
    m_affichage->addAction(m_emojis);
    m_affichage->addAction(m_capturedecran);
    m_alignement->addAction(m_aliright);
    m_alignement->addAction(m_alileft);
    m_alignement->addAction(m_alicenter);
    m_alignement->addAction(m_alijustify);





    m_fichierRecent->addAction(m_fichierR1);
    m_fichierRecent->addAction(m_fichierR2);
    m_fichierRecent->addAction(m_fichierR3);


    m_nouveau->setShortcut(QKeySequence("ctrl+n"));
    m_nouveauF->setShortcut(QKeySequence("ctrl+shift+n"));
    m_ouvrir->setShortcut(QKeySequence("ctrl+O"));
    m_save->setShortcut(QKeySequence("ctrl+S"));
    m_saveOn->setShortcut(QKeySequence("ctrl+shift+S"));
    m_saveFTS->setShortcut(QKeySequence("ctrl+alt+s"));
    m_quitter->setShortcut(QKeySequence("ctrl+Q"));
    m_fermer->setShortcut(QKeySequence("ctrl+F"));



    m_annuler->setShortcut(QKeySequence("ctrl+Z"));
    m_refaire->setShortcut(QKeySequence("ctrl+Y"));
    m_selectall->setShortcut(QKeySequence("ctrl+A"));
    m_temps->setShortcut(QKeySequence("ctrl+T"));
    //m_rechercher->setShortcut(QKeySequence("ctrl+R"));






    //bouton du toolbar
    QIcon icon(QCoreApplication::applicationDirPath()+"/images/font.png");
    QSize taille(40,40);
    m_font->setIcon(icon);
    m_font->setIconSize(taille);
    m_font->setToolTip("Polices d'écriture");
    m_font->setCursor(Qt::PointingHandCursor);


    QIcon icon2(QCoreApplication::applicationDirPath()+"/images/color.png");
    QSize taille2(40,40);
    m_color->setIcon(icon2);
    m_color->setIconSize(taille2);
    m_color->setToolTip("Couleurs");
    m_color->setCursor(Qt::PointingHandCursor);

    QIcon icon4(QCoreApplication::applicationDirPath()+"/images/nouveau.png");
    QSize taille4(40,40);
    m_boutonNouveau->setIcon(icon4);
    m_boutonNouveau->setIconSize(taille4);
    m_boutonNouveau->setToolTip("Créer un nouveau fichier");
    m_boutonNouveau->setCursor(Qt::PointingHandCursor);

    QIcon icon5(QCoreApplication::applicationDirPath()+"/images/ouvrir.png");
    QSize taille5(40,40);
    m_boutonOuvrir->setIcon(icon5);
    m_boutonOuvrir->setIconSize(taille5);
    m_boutonOuvrir->setToolTip("Ouvrir un fichier");
    m_boutonOuvrir->setCursor(Qt::PointingHandCursor);

    QIcon icon6(QCoreApplication::applicationDirPath()+"/images/save.png");
    QSize taille6(40,40);
    m_boutonEnregistrer->setIcon(icon6);
    m_boutonEnregistrer->setIconSize(taille6);
    m_boutonEnregistrer->setToolTip("Enregistrer un fichier");
    m_boutonEnregistrer->setCursor(Qt::PointingHandCursor);

    //connexion
    QObject::connect(m_quitter,SIGNAL(triggered()),this,SLOT(quitter()));
    QObject::connect(m_saveOn,SIGNAL(triggered()),this,SLOT(enregistrer_sous()));
    QObject::connect(m_ouvrir,SIGNAL(triggered()),this,SLOT(ouvrir()));
    QObject::connect(m_save,SIGNAL(triggered()),this,SLOT(enregistrer()));
    QObject::connect(m_fermer,SIGNAL(triggered()),this,SLOT(fermer()));
    QObject::connect(m_nouveau,SIGNAL(triggered()),this,SLOT(nouveau()));
    QObject::connect(m_emojis,SIGNAL(triggered()),this,SLOT(infoEmojis()));
    QObject::connect(m_capturedecran,SIGNAL(triggered()),this,SLOT(infoCapture()));
    QObject::connect(m_annuler,SIGNAL(triggered()),this,SLOT(annuler()));
    QObject::connect(m_refaire,SIGNAL(triggered()),this,SLOT(refaire()));
    QObject::connect(m_fichierR1,SIGNAL(triggered()),this,SLOT(ouvrirRecent1()));
    QObject::connect(m_fichierR2,SIGNAL(triggered()),this,SLOT(ouvrirRecent2()));
    QObject::connect(m_fichierR3,SIGNAL(triggered()),this,SLOT(ouvrirRecent3()));
    //QObject::connect(m_rechercher,SIGNAL(triggered()),this,SLOT(rechercherDialog()));
    QObject::connect(m_font,SIGNAL(clicked()),this,SLOT(fontdialog()));
    QObject::connect(m_selectall,SIGNAL(triggered()),this,SLOT(selectall()));
    QObject::connect(m_aliright,SIGNAL(triggered()),this,SLOT(aliright()));
    QObject::connect(m_alileft,SIGNAL(triggered()),this,SLOT(alileft()));
    QObject::connect(m_alicenter,SIGNAL(triggered()),this,SLOT(alicenter()));
    QObject::connect(m_alijustify,SIGNAL(triggered()),this,SLOT(alijustify()));
    QObject::connect(m_color,SIGNAL(clicked()),this,SLOT(couleur()));
    QObject::connect(m_boutonNouveau,SIGNAL(clicked()),this,SLOT(nouveau()));
    QObject::connect(m_boutonOuvrir,SIGNAL(clicked()),this,SLOT(ouvrir()));
    QObject::connect(m_boutonEnregistrer,SIGNAL(clicked()),this,SLOT(enregistrer()));
    QObject::connect(this,SIGNAL(closeEvent()),qApp,SLOT(quit()));
    QObject::connect(m_temps,SIGNAL(triggered()),this,SLOT(temps()));
    QObject::connect(m_nouveauF,SIGNAL(triggered()),this,SLOT(nouveauF()));
    QObject::connect(m_saveFTS,SIGNAL(triggered()),SLOT(enregistrerFTS()));







    //Zone centrale
    m_textEdit=new QTextEdit(this);
    m_zone=new QWidget;
    m_layout=new QVBoxLayout(this);
    m_layout->addWidget(m_toolbar);
    m_layout->addWidget(m_textEdit);
    m_zone->setLayout(m_layout);
    setCentralWidget(m_zone);
    QObject::connect(m_textEdit,SIGNAL(textChanged()),this,SLOT(etoile()));




    //autre
    m_defaultfont=new QFont(m_textEdit->font());
    m_defaultfont2=new QFont(m_textEdit->currentFont());
    m_nomfichier=new QString("OpenNote");
    setWindowTitle(*m_nomfichier);
    m_siFermer= new bool(false);
    fichierrecent();

    QStringList arguments=QCoreApplication::arguments();



    if(arguments.join(",")!=arguments.at(0).toUtf8().constData())
    {

        ouvrirFile();
    }





}

void Fenetre::enregistrerFTS()
{
    if (m_zone->isVisible())
    {
        QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier txt", QString("C:/fichier.txt"),QString( "fichier texte(*.txt)"));
        QFile *file= new QFile(fichier);
        if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return;
        }
        QTextStream flux(file);
        flux.setCodec("UTF-8");
        flux<<m_textEdit->toPlainText();
        *m_nomfichier=QString(fichier);
        setWindowTitle("OpenNote-"+*m_nomfichier);
        m_fichierR3->setText(m_fichierR2->text());
        m_fichierR2->setText(m_fichierR1->text());
        file->close();
        m_fichierR1->setText(*m_nomfichier);
        basededonnee();
        m_font->setEnabled(false);
        m_color->setEnabled(false);
        m_font->setCursor(Qt::ForbiddenCursor);
        m_color->setCursor(Qt::ForbiddenCursor);
        m_textEdit->setCurrentFont(*m_defaultfont2);
        m_textEdit->setTextColor(QColor("Black"));


        QFile *file2 = new QFile(fichier);
        QTextStream flux2(file2);
        flux2.setCodec("UTF-8");
        file2->open(QIODevice::ReadOnly | QIODevice::Text);
        QString tout = flux2.readAll();
        m_textEdit->setText(tout);
        *m_nomfichier=QString(fichier);
        setWindowTitle("OpenNote-"+*m_nomfichier);
        m_zone->setVisible(true);
        *m_siFermer=false;
        m_textEdit->setEnabled(true);
        QMessageBox::warning(this," Information sur les Fichiers Textes Simples (*.txt)","Le fichier que vous venez d'enregistrer est un fichier texte simple (.txt). \nCe qui implique que vous ne pouvez pas ajouter de la couleur ou modifier la police par rapport à un Fichier Texte OpenNote(.opn). \nPour enregistrer de votre fichier txt c'est la même chose qu'un fichier .opn");











    }

}



void Fenetre::nouveauF()
{
   QProcess newFenetre(this);
   newFenetre.startDetached(QCoreApplication::applicationFilePath());


}

void Fenetre::temps()
{

    QTime heures(QTime::currentTime());
    QDate date(QDate::currentDate());
    m_textEdit->append("le "+date.toString()+" à "+heures.toString());
}


void Fenetre::closeEvent(QCloseEvent *event)
{



    bool verif(verification());
    if (*m_siFermer==false)
    {
        if (verif==false)
        {
            int reponse(QMessageBox::question(this,"Enregistrer ?","⚠Voulez vous quitter <strong>sans enregistrer</strong> ?⚠"));
            if (reponse==QMessageBox::Yes)
            {
                event->accept();
            }
            else if (reponse==QMessageBox::No)
            {

                enregistrer();
                if(verification()==true)
                {
                  event->accept();
                }
                else
                {
                    event->ignore();
                }

            }
        }
        else{
            event->accept();
        }
    }
    else
    {
        event->accept();
    }



}
void Fenetre::etoile()
{
    int lenght(windowTitle().length());
    QChar *car=new QChar(windowTitle().at(lenght-1));

    if(*car!="*")
    {
        setWindowTitle(windowTitle()+"*");
    }

}

void Fenetre::ouvrirFile()
{

    QStringList arguments=QCoreApplication::arguments();
    QString nomFichier=arguments.at(1).toUtf8().constData();


    QFile *file = new QFile(nomFichier);
    QTextStream flux(file);
    flux.setCodec("UTF-8");
    file->open(QIODevice::ReadOnly | QIODevice::Text);
    QString tout = flux.readAll();
    m_textEdit->setText(tout);
    *m_nomfichier=QString(nomFichier);
    setWindowTitle("OpenNote-"+*m_nomfichier);
    m_zone->setVisible(true);
    *m_siFermer=false;
    m_textEdit->setEnabled(true);
    int lenght(m_nomfichier->length());
    if(m_nomfichier->at(lenght-1)=="t")
    {
        m_textEdit->setCurrentFont(*m_defaultfont2);
        m_textEdit->setTextColor(QColor("Black"));
        m_font->setEnabled(false);
        m_color->setEnabled(false);
        m_font->setCursor(Qt::ForbiddenCursor);
        m_color->setCursor(Qt::ForbiddenCursor);


    }
    else if(m_nomfichier->at(lenght-1)=="n")
    {
        m_font->setEnabled(true);
        m_color->setEnabled(true);
        m_font->setCursor(Qt::PointingHandCursor);
        m_color->setCursor(Qt::PointingHandCursor);
    }


}

void Fenetre::couleur()
{
    QColor couleur(QColorDialog::getColor(Qt::white,this,"Choisissez une couleur"));
    m_textEdit->setTextColor(couleur);


}
void Fenetre::fontdialog()
{
  bool ok(false);
  QFont police(QFontDialog::getFont(&ok,*m_defaultfont,this,"Choisissez une police"));
  if (ok){
      *m_defaultfont=police;
      m_textEdit->setCurrentFont(police);



   }
}


void Fenetre::aliright()
{
    m_textEdit->setAlignment(Qt::AlignRight);

}

void Fenetre::alileft()
{
    m_textEdit->setAlignment(Qt::AlignLeft);

}

void Fenetre::alicenter()
{
    m_textEdit->setAlignment(Qt::AlignCenter);

}

void Fenetre::alijustify()
{
    m_textEdit->setAlignment(Qt::AlignJustify);

}


void Fenetre::selectall()
{
    m_textEdit->selectAll();





}



void Fenetre::rechercher()
{

    m_textEdit->find(m_lineEdit->text().toHtmlEscaped());


}



void Fenetre::rechercherDialog()
{
    QWidget *recherchefenetre=new QWidget;
    QLabel *label = new QLabel("Rechercher:");
    QGridLayout *layout=new QGridLayout(recherchefenetre);
    m_lineEdit=new QLineEdit(recherchefenetre);
    QPushButton *recherche=new QPushButton("&Rechercher",recherchefenetre);
    layout->addWidget(label,0,0);
    layout->addWidget(m_lineEdit,1,0);
    layout->addWidget(recherche,2,0);
    recherchefenetre->setLayout(layout);
    recherchefenetre->setWindowTitle("Rechercher");
    recherchefenetre->setFixedSize(250,125);
    QObject::connect(recherche,SIGNAL(clicked()),this,SLOT(rechercher()));
    recherchefenetre->show();


}




void Fenetre::annuler()
{
    m_textEdit->undo();
}



void Fenetre::refaire()
{
    m_textEdit->redo();
}


void Fenetre::nouveau()
{
    if (*m_siFermer==false)
    {
        if (verification()==true)
        {

            m_font->setEnabled(true);
            m_color->setEnabled(true);
            m_textEdit->setText(QString(""));
            m_zone->setVisible(true);
            *m_siFermer=false;
            m_textEdit->setEnabled(true);
            *m_nomfichier=QString("OpenNote");
            setWindowTitle("OpenNote");
            m_font->setCursor(Qt::PointingHandCursor);
            m_color->setCursor(Qt::PointingHandCursor);



        }
        else
        {
            int reponse=QMessageBox::question(this,"Enregistrer ?","Créer un nouveau fichier <strong>sans enregistrer l'actuel</strong> ?");
            if (reponse==QMessageBox::Yes){
                m_font->setEnabled(true);
                m_color->setEnabled(true);
                m_textEdit->setText(QString(""));
                m_zone->setVisible(true);
                *m_siFermer=false;
                m_textEdit->setEnabled(true);
                *m_nomfichier=QString("OpenNote");
                setWindowTitle("OpenNote");
                m_font->setCursor(Qt::PointingHandCursor);
                m_color->setCursor(Qt::PointingHandCursor);
            }
            else if(reponse==QMessageBox::No){
                enregistrer();
                if(verification()==true){
                    m_font->setEnabled(true);
                    m_color->setEnabled(true);
                    m_textEdit->setText(QString(""));
                    m_zone->setVisible(true);
                    *m_siFermer=false;
                    m_textEdit->setEnabled(true);
                    *m_nomfichier=QString("OpenNote");
                    setWindowTitle("OpenNote");
                    m_font->setCursor(Qt::PointingHandCursor);
                    m_color->setCursor(Qt::PointingHandCursor);


                }

            }
        }

    }


    else
    {
        m_font->setEnabled(true);
        m_color->setEnabled(true);
        m_textEdit->setText(QString(""));
        m_zone->setVisible(true);
        *m_siFermer=false;
        m_textEdit->setEnabled(true);
        *m_nomfichier=QString("OpenNote");
        setWindowTitle("OpenNote");

        m_font->setCursor(Qt::PointingHandCursor);
        m_color->setCursor(Qt::PointingHandCursor);
    }
}











void Fenetre::enregistrer_sous()
{
    if (m_zone->isVisible())
    {
        QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString("C:/fichier.opn"),QString( "fichier texte(*.opn *.txt)"));
        int longueur(fichier.length());
        if(fichier.at(longueur-1)=="n")
        {
            QFile *file= new QFile(fichier);
            if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
            {
                return;
            }
            QTextStream flux(file);
            flux.setCodec("UTF-8");

            flux<<m_textEdit->toHtml();
            *m_nomfichier=QString(fichier);
            setWindowTitle("OpenNote-"+*m_nomfichier);
            m_fichierR3->setText(m_fichierR2->text());
            m_fichierR2->setText(m_fichierR1->text());
            m_fichierR1->setText(*m_nomfichier);
            basededonnee();

        }
        else if(fichier.at(longueur-1)=="t")
        {
            QFile *file= new QFile(fichier);
            if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
            {
                return;
            }
            QTextStream flux(file);
            flux.setCodec("UTF-8");

            flux<<m_textEdit->toPlainText();
            *m_nomfichier=QString(fichier);
            setWindowTitle("OpenNote-"+*m_nomfichier);
            m_fichierR3->setText(m_fichierR2->text());
            m_fichierR2->setText(m_fichierR1->text());
            file->close();
            m_fichierR1->setText(*m_nomfichier);
            basededonnee();
            m_font->setEnabled(false);
            m_color->setEnabled(false);
            m_font->setCursor(Qt::ForbiddenCursor);
            m_color->setCursor(Qt::ForbiddenCursor);
            //ouvrirRecent1();
            //m_textEdit->setFont(*m_defaultfont2);
            //QString text(m_textEdit->toPlainText());
            //m_textEdit->setText(text);
            m_textEdit->setCurrentFont(*m_defaultfont2);
            m_textEdit->setTextColor(QColor("Black"));


            QFile *file2 = new QFile(fichier);
            QTextStream flux2(file2);
            flux2.setCodec("UTF-8");
            file2->open(QIODevice::ReadOnly | QIODevice::Text);
            QString tout = flux2.readAll();
            m_textEdit->setText(tout);
            *m_nomfichier=QString(fichier);
            setWindowTitle("OpenNote-"+*m_nomfichier);
            m_zone->setVisible(true);
            *m_siFermer=false;
            m_textEdit->setEnabled(true);
            QMessageBox::warning(this," Information sur les Fichiers Textes Simples (*.txt)","Le fichier que vous venez d'enregistrer est un fichier texte simple (.txt). \nCe qui implique que vous ne pouvez pas ajouter de la couleur ou modifier la police par rapport à un Fichier Texte OpenNote(.opn).");




        }



    }


}

void Fenetre::enregistrer()
{
    if (m_zone->isVisible())
    {
        if(*m_nomfichier!=QString("OpenNote")){
            int length(m_nomfichier->length());
            if(m_nomfichier->at(length-1)=="n")
            {
                QFile *file=new QFile(*m_nomfichier);
                if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
                {
                    return;
                }
                QTextStream flux(file);
                flux.setCodec("UTF-8");
                flux<<m_textEdit->toHtml();
                if (*m_nomfichier!=m_fichierR1->text())
                {
                    m_fichierR3->setText(m_fichierR2->text());
                    m_fichierR2->setText(m_fichierR1->text());
                    m_fichierR1->setText(*m_nomfichier);

                }

                basededonnee();
                int lenght(windowTitle().length());
                QChar car(windowTitle().at(lenght-1));

                if(car=="*")
                {
                    setWindowTitle("OpenNote-"+*m_nomfichier);
                }
                QMessageBox::information(this,"Enregistré","Fichier enregistré");

            }
            else if(m_nomfichier->at(length-1)=="t")
            {
                QFile *file=new QFile(*m_nomfichier);
                if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
                {
                    return;
                }
                QTextStream flux(file);
                flux.setCodec("UTF-8");
                flux<<m_textEdit->toPlainText();
                if (*m_nomfichier!=m_fichierR1->text())
                {
                    m_fichierR3->setText(m_fichierR2->text());
                    m_fichierR2->setText(m_fichierR1->text());
                    m_fichierR1->setText(*m_nomfichier);

                }

                basededonnee();
                int lenght(windowTitle().length());
                QChar car(windowTitle().at(lenght-1));

                if(car=="*")
                {
                    setWindowTitle("OpenNote-"+*m_nomfichier);
                }
                QMessageBox::information(this,"Enregistré","Fichier enregistré");
            }


        }
        else{
            enregistrer_sous();
        }


    }



}

void Fenetre::ouvrir()
{
    if (m_fichierR==QString("Null"))
    {
        QString fichier = QFileDialog::getOpenFileName(this,"Ouvrir un fichier",QString("C:"),"fichier texte (*.opn *.txt)");
        if (*m_siFermer==false)
        {
            if (fichier!=QString(""))
            {
                if (verification()==true)
                {

                    QFile *file = new QFile(fichier);
                    QTextStream flux(file);
                    flux.setCodec("UTF-8");
                    file->open(QIODevice::ReadOnly | QIODevice::Text);
                    QString tout = flux.readAll();
                    m_textEdit->setText(tout);
                    *m_nomfichier=QString(fichier);
                    setWindowTitle("OpenNote-"+*m_nomfichier);
                    m_zone->setVisible(true);
                    *m_siFermer=false;
                    m_textEdit->setEnabled(true);

                    int lenght(m_nomfichier->length());
                    if(m_nomfichier->at(lenght-1)=="t")
                    {
                        m_textEdit->setCurrentFont(*m_defaultfont2);
                        m_textEdit->setTextColor(QColor("Black"));
                        m_font->setEnabled(false);
                        m_color->setEnabled(false);
                        m_font->setCursor(Qt::ForbiddenCursor);
                        m_color->setCursor(Qt::ForbiddenCursor);



                    }
                    else if(m_nomfichier->at(lenght-1)=="n")
                    {
                        m_font->setEnabled(true);
                        m_color->setEnabled(true);
                        m_font->setCursor(Qt::PointingHandCursor);
                        m_color->setCursor(Qt::PointingHandCursor);
                    }



                }
                else
                {
                    int reponse=QMessageBox::question(this,"Enregistrer ?","Ouvrir un nouveau fichier <strong>sans enregistrer l'actuel</strong> ?");
                    if (reponse==QMessageBox::Yes){
                        QFile *file = new QFile(fichier);
                        QTextStream flux(file);
                        flux.setCodec("UTF-8");
                        file->open(QIODevice::ReadOnly | QIODevice::Text);
                        QString tout = flux.readAll();
                        m_textEdit->setText(tout);
                        *m_nomfichier=QString(fichier);
                        setWindowTitle("OpenNote-"+*m_nomfichier);
                        m_zone->setVisible(true);
                        *m_siFermer=false;
                        m_textEdit->setEnabled(true);
                        int lenght(m_nomfichier->length());
                        if(m_nomfichier->at(lenght-1)=="t")
                        {
                            m_textEdit->setCurrentFont(*m_defaultfont2);
                            m_textEdit->setTextColor(QColor("Black"));
                            m_font->setEnabled(false);
                            m_color->setEnabled(false);
                            m_font->setCursor(Qt::ForbiddenCursor);
                            m_color->setCursor(Qt::ForbiddenCursor);


                        }
                        else if(m_nomfichier->at(lenght-1)=="n")
                        {
                            m_font->setEnabled(true);
                            m_color->setEnabled(true);
                            m_font->setCursor(Qt::PointingHandCursor);
                            m_color->setCursor(Qt::PointingHandCursor);
                         }
                      }
                    else if(reponse==QMessageBox::No){
                        enregistrer();
                        if(verification()==true){
                            QFile *file = new QFile(fichier);
                            QTextStream flux(file);
                            flux.setCodec("UTF-8");
                            file->open(QIODevice::ReadOnly | QIODevice::Text);
                            QString tout = flux.readAll();
                            m_textEdit->setText(tout);
                            *m_nomfichier=QString(fichier);
                            setWindowTitle("OpenNote-"+*m_nomfichier);
                            m_zone->setVisible(true);
                            *m_siFermer=false;
                            m_textEdit->setEnabled(true);
                            int lenght(m_nomfichier->length());
                            if(m_nomfichier->at(lenght-1)=="t")
                            {
                                m_textEdit->setCurrentFont(*m_defaultfont2);
                                m_textEdit->setTextColor(QColor("Black"));
                                m_font->setEnabled(false);
                                m_color->setEnabled(false);
                                m_font->setCursor(Qt::ForbiddenCursor);
                                m_color->setCursor(Qt::ForbiddenCursor);


                            }
                            else if(m_nomfichier->at(lenght-1)=="n")
                            {

                                m_font->setEnabled(true);
                                m_color->setEnabled(true);
                                m_font->setCursor(Qt::PointingHandCursor);
                                m_color->setCursor(Qt::PointingHandCursor);
                            }

                        }

                    }

                }

           }
        }

        else
        {
            if(fichier!=QString(""))
            {
                QFile *file = new QFile(fichier);
                QTextStream flux(file);
                flux.setCodec("UTF-8");
                file->open(QIODevice::ReadOnly | QIODevice::Text);
                QString tout = flux.readAll();
                m_textEdit->setText(tout);
                *m_nomfichier=QString(fichier);
                setWindowTitle("OpenNote-"+*m_nomfichier);
                m_zone->setVisible(true);
                *m_siFermer=false;
                m_textEdit->setEnabled(true);
                int lenght(m_nomfichier->length());
                if(m_nomfichier->at(lenght-1)=="t")
                {
                    m_textEdit->setCurrentFont(*m_defaultfont2);
                    m_textEdit->setTextColor(QColor("Black"));
                    m_font->setEnabled(false);
                    m_color->setEnabled(false);
                    m_font->setCursor(Qt::ForbiddenCursor);
                    m_color->setCursor(Qt::ForbiddenCursor);


                }
                else if(m_nomfichier->at(lenght-1)=="n")
                {
                    m_font->setEnabled(true);
                    m_color->setEnabled(true);
                    m_font->setCursor(Qt::PointingHandCursor);
                    m_color->setCursor(Qt::PointingHandCursor);
                 }

            }


         }

    }

    else
    {
        if (*m_siFermer==false)
        {
            if (m_fichierR!=QString(""))
            {
                if (verification()==true)
                {

                    QFile *file = new QFile(*m_fichierR);
                    QTextStream flux(file);
                    flux.setCodec("UTF-8");
                    file->open(QIODevice::ReadOnly | QIODevice::Text);
                    QString tout = flux.readAll();
                    m_textEdit->setText(tout);
                    *m_nomfichier=QString(*m_fichierR);
                    setWindowTitle("OpenNote-"+*m_nomfichier);
                    m_zone->setVisible(true);
                    *m_siFermer=false;
                    m_textEdit->setEnabled(true);
                    *m_fichierR=QString("Null");
                    int lenght(m_nomfichier->length());
                    if(m_nomfichier->at(lenght-1)=="t")
                    {
                        m_textEdit->setCurrentFont(*m_defaultfont2);
                        m_textEdit->setTextColor(QColor("Black"));
                        m_font->setEnabled(false);
                        m_color->setEnabled(false);
                        m_font->setCursor(Qt::ForbiddenCursor);
                        m_color->setCursor(Qt::ForbiddenCursor);


                    }
                    else if(m_nomfichier->at(lenght-1)=="n")
                    {
                        m_font->setEnabled(true);
                        m_color->setEnabled(true);
                        m_font->setCursor(Qt::PointingHandCursor);
                        m_color->setCursor(Qt::PointingHandCursor);


                    }

                }
                else
                {
                    int reponse=QMessageBox::question(this,"Enregistrer ?","Ouvrir un nouveau fichier <strong>sans enregistrer l'actuel</strong> ?");
                    if (reponse==QMessageBox::Yes){
                        QFile *file = new QFile(*m_fichierR);
                        QTextStream flux(file);
                        flux.setCodec("UTF-8");
                        file->open(QIODevice::ReadOnly | QIODevice::Text);
                        QString tout = flux.readAll();
                        m_textEdit->setText(tout);
                        *m_nomfichier=QString(*m_fichierR);
                        setWindowTitle("OpenNote-"+*m_nomfichier);
                        m_zone->setVisible(true);
                        *m_siFermer=false;
                        m_textEdit->setEnabled(true);
                        *m_fichierR=QString("Null");
                        int lenght(m_nomfichier->length());
                        if(m_nomfichier->at(lenght-1)=="t")
                        {
                            m_textEdit->setCurrentFont(*m_defaultfont2);
                            m_textEdit->setTextColor(QColor("Black"));

                            m_font->setEnabled(false);
                            m_color->setEnabled(false);
                            m_font->setCursor(Qt::ForbiddenCursor);
                            m_color->setCursor(Qt::ForbiddenCursor);


                        }
                        else if(m_nomfichier->at(lenght-1)=="n")
                        {
                            m_font->setEnabled(true);
                            m_color->setEnabled(true);
                            m_font->setCursor(Qt::PointingHandCursor);
                            m_color->setCursor(Qt::PointingHandCursor);


                        }
                    }

                    else if(reponse==QMessageBox::No){
                        enregistrer();
                        if(verification()==true){
                            QFile *file = new QFile(*m_fichierR);
                            QTextStream flux(file);
                            flux.setCodec("UTF-8");
                            file->open(QIODevice::ReadOnly | QIODevice::Text);
                            QString tout = flux.readAll();
                            m_textEdit->setText(tout);
                            *m_nomfichier=QString(*m_fichierR);
                            setWindowTitle("OpenNote-"+*m_nomfichier);
                            m_zone->setVisible(true);
                            *m_siFermer=false;
                            m_textEdit->setEnabled(true);
                            *m_fichierR=QString("Null");
                            int lenght(m_nomfichier->length());
                            if(m_nomfichier->at(lenght-1)=="t")
                            {
                                m_textEdit->setCurrentFont(*m_defaultfont2);
                                m_textEdit->setTextColor(QColor("Black"));
                                m_font->setEnabled(false);
                                m_color->setEnabled(false);
                                m_font->setCursor(Qt::ForbiddenCursor);
                                m_color->setCursor(Qt::ForbiddenCursor);


                            }
                            else if(m_nomfichier->at(lenght-1)=="n")
                            {
                                m_font->setEnabled(true);
                                m_color->setEnabled(true);
                                m_font->setCursor(Qt::PointingHandCursor);
                                m_color->setCursor(Qt::PointingHandCursor);

                            }

                           }
                    }


                }
           }
      }

        else
        {
            QFile *file = new QFile(*m_fichierR);
            QTextStream flux(file);
            flux.setCodec("UTF-8");
            file->open(QIODevice::ReadOnly | QIODevice::Text);
            QString tout = flux.readAll();
            m_textEdit->setText(tout);
            *m_nomfichier=QString(*m_fichierR);
            setWindowTitle("OpenNote-"+*m_nomfichier);
            m_zone->setVisible(true);
            *m_siFermer=false;
            m_textEdit->setEnabled(true);
            *m_fichierR=QString("Null");
            int lenght(m_nomfichier->length());
            if(m_nomfichier->at(lenght-1)=="t")
            {
                m_textEdit->setCurrentFont(*m_defaultfont2);
                m_textEdit->setTextColor(QColor("Black"));
                m_font->setEnabled(false);
                m_color->setEnabled(false);
                m_font->setCursor(Qt::ForbiddenCursor);
                m_color->setCursor(Qt::ForbiddenCursor);


            }
            else if(m_nomfichier->at(lenght-1)=="n")
            {
                m_font->setEnabled(true);
                m_color->setEnabled(true);
                m_font->setCursor(Qt::PointingHandCursor);
                m_color->setCursor(Qt::PointingHandCursor);


            }


        }

    }





}
void Fenetre::fermer()
{
    bool verif(verification());
    if (verif==false)
    {
        int reponse(QMessageBox::question(this,"Enregistrer ?","Voulez vous fermer le fichier <strong>sans enregistrer </strong>?"));
        if (reponse==QMessageBox::Yes)
        {
            m_zone->setVisible(false);
            setWindowTitle("OpenNote");
            *m_nomfichier=QString("OpenNote");
            *m_siFermer=true;
            m_textEdit->setEnabled(false);
            QFile file(*m_nomfichier);
            file.close();
            m_font->setEnabled(false);
            m_color->setEnabled(false);

        }
        else if (reponse==QMessageBox::No) {
            enregistrer();
            if (verification()!=false)
            {
                    m_zone->setVisible(false);
                    setWindowTitle("OpenNote");
                    *m_nomfichier=QString("OpenNote");
                    *m_siFermer=true;
                    m_textEdit->setEnabled(false);
                    QFile file(*m_nomfichier);
                    file.close();
                    m_font->setEnabled(false);
                    m_color->setEnabled(false);

            }


        }

    }
    else
    {
        m_zone->setVisible(false);
        setWindowTitle("OpenNote");
        *m_nomfichier=QString("OpenNote");
        *m_siFermer=true;
        m_textEdit->setEnabled(false);
        QFile file(*m_nomfichier);
        file.close();
        m_font->setEnabled(false);
        m_color->setEnabled(false);


    }

}

void Fenetre::quitter()
{
    bool verif(verification());
    if (*m_siFermer==false)
    {
        if (verif==false)
        {
            int reponse(QMessageBox::question(this,"Enregistrer ?","Voulez vous quitter <strong>sans enregistrer</strong> ?"));
            if (reponse==QMessageBox::Yes)
            {
                qApp->quit();
            }
            else if (reponse==QMessageBox::No)
            {

                enregistrer();
                if(verification()!=false)
                {
                  qApp->quit();
                }

            }
        }
        else{
            qApp->quit();
        }
    }
    else
    {
        qApp->quit();
    }



}



bool Fenetre::verification()
{
    if(*m_nomfichier==QString("OpenNote"))
    {
        if(m_textEdit->toPlainText()=="")
        {
          return true;
        }
     else if(windowTitle()==QString("OpenNote*"))
        {
            return false;
        }


    }
    int longueur(m_nomfichier->length());
    if(m_nomfichier->at(longueur-1)=="n")
    {
        QFile *file= new QFile(*m_nomfichier);
        QTextStream flux(file);
        flux.setCodec("UTF-8");
        file->open(QIODevice::ReadOnly | QIODevice::Text);
        QString fichier(flux.readAll());

        if (fichier==m_textEdit->toHtml())
        {
            return true;
        }
        else
        {

            return false;
        }

    }
    else if(m_nomfichier->at(longueur-1)=="t")
    {
        QFile *file= new QFile(*m_nomfichier);
        QTextStream flux(file);
        flux.setCodec("UTF-8");
        file->open(QIODevice::ReadOnly | QIODevice::Text);
        QString fichier(flux.readAll());

        if (fichier==m_textEdit->toPlainText())
        {
            return true;
        }
        else
        {

            return false;
        }


    }


}

void Fenetre::infoEmojis()
{
    QMessageBox::information(this,"Information emojis","[INFO]: Faites (Windows + la touche ;) pour ouvrir le menu emojis ");
}


void Fenetre::infoCapture()
{
    QMessageBox::information(this,"Information capture d'écran","[INFO]: Faites (Windows + Shift + la touche s) pour ouvrir le menu de capture d'écran Windows ");
}

void Fenetre::basededonnee()
{
    QString nom=QCoreApplication::applicationDirPath();
    QString nomComplet(nom+"/openData.opnd");
    QFile *file=new QFile(nomComplet);
    if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
    {
         return;
    }
    QTextStream flux(file);
    flux.setCodec("UTF-8");
    flux<<m_fichierR1->text()+"\n";
    flux<<m_fichierR2->text()+"\n";
    flux<<m_fichierR3->text()+"\n";


}

void Fenetre::fichierrecent()
{
    QString nom=QCoreApplication::applicationDirPath();
    QString nomComplet(nom+"/openData.opnd");
    QFile file(nomComplet);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream flux(&file);
    flux.setCodec("UTF-8");
    m_fichierR1->setText(flux.readLine(0));
    m_fichierR2->setText(flux.readLine(0));
    m_fichierR3->setText(flux.readLine(0));


}

void Fenetre::ouvrirRecent1()
{
    *m_fichierR=m_fichierR1->text();
    ouvrir();


}

void Fenetre::ouvrirRecent2()
{
    *m_fichierR=m_fichierR2->text();
    ouvrir();


}

void Fenetre::ouvrirRecent3()
{
    *m_fichierR=m_fichierR3->text();
    ouvrir();


}




