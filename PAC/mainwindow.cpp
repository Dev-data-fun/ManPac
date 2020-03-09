#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maze.cpp"


Maze* maze = new Maze;

vector<Node*>* mynodes = maze->getNodes();

int MPdir=0;
int MP_nextdir=-1;
int MPanim=1;
int lives=3;

int score=0;
double score_mult;

int RAVE=0;     //RAVE BOIIIIIIIII
int RAVE_cycle=0;
int back_cycle=0;

int RED_move1[]= {2,1,1,1,2,2,2,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,3,3,3,3,3,3,3,2,2,2,2,2,3,3,3,3,3,3,2,2,2,3,3,3,3,3,3,2,2,2,3,3,3,2,2,2,1,1,1,2,2,2,2,2,2,3,3,3,0,0,0,3,3,3,0,0,0,3,3,3,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,2,2,2,2,2};
//size of Array = 125

int RED_release=100;
int RED_move1_cur=0;
int REDanim=0;

int BLUE_move1[]= {0,0,1,1,1,0,0,0,1,1,1,0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,2,2,2,2,2,3,3,3,0,0,3,3,3,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0};


int BLUE_release=150;
int BLUE_move1_cur=0;
int BLUEanim=0;

int PINK_move1[]= {2,2,2,2,3,3,3,3,3,3,3,3,3,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,1,1,1,0,0,1,1,1,2,2,2,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,1,1,1,0,0,0,0,0,0,0,0,3,3,3,0,0,0,3,3,3,0};


int PINK_release=200;
int PINK_move1_cur=0;
int PINKanim=0;


int ORAN_move1[]= {2,2,2,2,3,3,3,2,2,2,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,3,3,3,2,2,2,1,1,1,2,2,2,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2};


int ORAN_release=250;
int ORAN_move1_cur=0;
int ORANanim=0;


int fruit=0;
bool cherry_spawn=false;
bool apple_spawn=false;
bool orange_spawn=false;
bool paused=false;


int smoothing=1;
int smoothing_ghosts=0;
int bluesmoothing_ghosts=0;
int pinksmoothing_ghosts=0;
int oransmoothing_ghosts=0;


QSoundEffect waka;
QSoundEffect begin;
QSoundEffect chomp;
QSoundEffect death;
QSoundEffect eat_ghost;
QSoundEffect intermission;

bool isPaused=false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setStyleSheet("background-color: black;");
    ui->score_val->setStyleSheet("QLabel { color : yellow; }");
    ui->endgametxt->setStyleSheet("QLabel { color : yellow; }");
    ui->name_label->setStyleSheet("QLabel { color : yellow; }");
    ui->score_label->setStyleSheet("QLabel { color : yellow; }");
    ui->highscores->setStyleSheet("QLabel { color : yellow; }");
    ui->wintxt->setStyleSheet("QLabel { color : yellow; }");
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QImage(":/images/images/layout.png"));
    scene->setSceneRect(0,0,560,620);
    ui->graphicsView->setScene(scene);
    const QPixmap pm(":/images/images/layout.png");
    ui->graphicsView->setFixedSize(pm.width(),pm.height());

    ui->wintxt->hide();
    ui->trophy->hide();
    ui->highscores->hide();
    ui->HSview->hide();
    ui->name->setStyleSheet("QPlainTextEdit { color : black; background-color: yellow; }");
    ui->HSview->setStyleSheet("QTextBrowser { color : yellow; background-color: black; }");
    ui->Pause->setStyleSheet("QPushButton { color : black; background-color: yellow; }");
    ui->textBrowser->setStyleSheet("QTextBrowser {color : yellow}");
    ui->Ready_Easy->setStyleSheet("QPushButton { color : black; background-color: yellow; }");
    ui->Ready_Medium->setStyleSheet("QPushButton { color : black; background-color: yellow; }");
    ui->Ready_Hard->setStyleSheet("QPushButton { color : black; background-color: yellow; }");
    ui->Ready_Insane->setStyleSheet("QPushButton { color : black; background-color: yellow; }");
    ui->CDown->setStyleSheet("QLabel { color : yellow;  background-color: rgba(0,0,0,0%); }");
    ui->score_val->hide();
    ui->Pause->hide();
    ui->graphicsView->hide();
    ui->score_label->hide();
    ui->CDown->hide();
    ui->endgametxt->hide();


    waka.setSource(QUrl::fromLocalFile(":/sounds/Sound/waka_two_long.wav"));

    chomp.setSource(QUrl::fromLocalFile(":/sounds/Sound/pacman_chomp_tw.wav"));
    death.setSource(QUrl::fromLocalFile(":/sounds/Sound/pacman_death_tw.wav"));
    eat_ghost.setSource(QUrl::fromLocalFile(":/sounds/Sound/pacman_eatghost_tw.wav"));
    intermission.setSource(QUrl::fromLocalFile(":/sounds/Sound/pacman_intermission_tw.wav"));


    srand(time(NULL));



    draw_nodes();

    QPixmap pause(":/images/images/Pause.png");
    ui->Pause->setIcon(pause);

    QPixmap mpmap(":/images/images/MPRO1.png");
    QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);

    QGraphicsPixmapItem *MP = scene->addPixmap(mpmap2);


    QPixmap redmap(":/images/images/red-down.png");
    QPixmap red_scaled = redmap.scaled(QSize(18,24),Qt::KeepAspectRatio);

    QGraphicsPixmapItem *RED = scene->addPixmap(red_scaled);

    QPixmap bluemap(":/images/images/blue.png");
    QPixmap blue_scaled = bluemap.scaled(QSize(18,24),Qt::KeepAspectRatio);

    QPixmap pinkmap(":/images/images/pink.png");
    QPixmap pink_scaled = pinkmap.scaled(QSize(18,24),Qt::KeepAspectRatio);

    QPixmap oranmap(":/images/images/oran.png");
    QPixmap oran_scaled = oranmap.scaled(QSize(18,24),Qt::KeepAspectRatio);

    QGraphicsPixmapItem *BLUE = scene->addPixmap(blue_scaled);

    QGraphicsPixmapItem *PINK = scene->addPixmap(pink_scaled);

    QGraphicsPixmapItem *ORAN = scene->addPixmap(oran_scaled);

    RED->setPos(291,258); //-5,-10 for const offset needed in movements
    BLUE->setPos(231,278); //-5,-10 for const offset needed in movements
    PINK->setPos(251,258); //-5,-10 for const offset needed in movements
     ORAN->setPos(281,288); //-5,-10 for const offset needed in movements


    MP->setPos(maze->getManPac()->getx()-6,maze->getManPac()->gety()-7);

    int i = maze->getManPac()->getIndex();

    if(mynodes->at(i)->getconsumed()==false) {
        mynodes->at(i)->setConsumed(true);
        if(mynodes->at(i)->getSpecial()==false) {
        score+=10;
        }
        else {
        score+=40;
        }
    }
    ui->score_val->setText(QString::number(score));


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));



}

MainWindow::~MainWindow()
{
    scene->clear();
    delete mynodes;
    delete ui;
}

void MainWindow::tick() {


    check_win();

    scene->clear();

    if(MPanim<5) { MPanim++;}
    else { MPanim=0;}

    if(smoothing==0) {

    RAVE_time();

    int i = maze->getManPac()->getIndex();

    if(allow_move(mynodes->at(i)->getNT(),MP_nextdir)==true) {

        MPdir=MP_nextdir;

    }

    if(allow_move(mynodes->at(i)->getNT(),MPdir)==true) {

        int next = next_location(i,MPdir);
        maze->setMP(next);

        int smooth_i = maze->getManPac()->getIndex();


        if(allow_move(mynodes->at(smooth_i)->getNT(),MPdir)==true && mynodes->at(smooth_i)->getIndex()!=128 && mynodes->at(smooth_i)->getIndex()!=147) { smoothing ++;}

        QPixmap newmap = animate(MPdir, MPanim, 0);
        QGraphicsPixmapItem *MP = scene->addPixmap(newmap); MP->setPos(maze->getManPac()->getx()-6,maze->getManPac()->gety()-7);MP->setZValue(6);
        draw_fruit(MP);



    }

    else {



        QPixmap newmap = animate(MPdir, MPanim, 0);
        QGraphicsPixmapItem *MP = scene->addPixmap(newmap); MP->setPos(maze->getManPac()->getx()-6,maze->getManPac()->gety()-7);MP->setZValue(6);
        draw_fruit(MP);
    }


    i = maze->getManPac()->getIndex();
    if(mynodes->at(i)->getconsumed()==false) {
        mynodes->at(i)->setConsumed(true);
        if(mynodes->at(i)->getSpecial()==false) {

        if(RAVE==0) {
         waka.play();
        }
        score+=10;
        fruit+=1;
        }
        else {
        RAVE=930;
        score+=40;
        fruit+=1;
        intermission.play();
        }
    }

    ui->score_val->setText(QString::number(score));

    draw_nodes();



    }

    else {

        RAVE_time();

        int i = maze->getManPac()->getIndex();

        if(allow_move(mynodes->at(i)->getNT(),MP_nextdir)==true) {

            MPdir=MP_nextdir;

        }

        draw_MP_smooth();

        draw_nodes();

        if(smoothing<3) { smoothing ++; }
        else {
        smoothing =0;
        }

    }



    /*
     * Below lines check whether the ghost has been releasd and then
     * draws them appropriately on the maze
     */

    if(RED_release==0) {

    if(smoothing_ghosts==0) {

       draw_ghosts();
       smoothing_ghosts+=1;

    }

    else {

                draw_ghosts_smooth();

       if(smoothing_ghosts<3) {

           smoothing_ghosts+=1;

       }



       else { smoothing_ghosts=0; }

    }
    }

    else {RED_release-=1;

        QPixmap redmap(":/images/images/red-down.png");
        QPixmap red_scaled = redmap.scaled(QSize(18,24),Qt::KeepAspectRatio);

        QGraphicsPixmapItem *RED = scene->addPixmap(red_scaled);
        RED->setZValue(5);

        if(RED_release==0) {

            RED->setPos(maze->getRED()->getx()-5,maze->getRED()->gety()-9);

        }

        else {
             RED->setPos(291,258);

        }
        }


    if(BLUE_release==0) {

    if(bluesmoothing_ghosts==0) {

       bluedraw_ghosts();
       bluesmoothing_ghosts+=1;

    }

    else {

                bluedraw_ghosts_smooth();

       if(bluesmoothing_ghosts<3) {

           bluesmoothing_ghosts+=1;

       }



       else { bluesmoothing_ghosts=0; }

    }
    }

    else {BLUE_release-=1;

        QPixmap bluemap(":/images/images/blue.png");
        QPixmap blue_scaled = bluemap.scaled(QSize(18,24),Qt::KeepAspectRatio);

        QGraphicsPixmapItem *BLUE = scene->addPixmap(blue_scaled);
        BLUE->setZValue(4);

        if(BLUE_release==0) {

           BLUE->setPos(maze->getBLUE()->getx()-5,maze->getBLUE()->gety()-9);

        }

        else {
             BLUE->setPos(231,278);

        }
        }


    if(PINK_release==0) {

    if(pinksmoothing_ghosts==0) {

       pinkdraw_ghosts();
       pinksmoothing_ghosts+=1;

    }

    else {

               pinkdraw_ghosts_smooth();

       if(pinksmoothing_ghosts<3) {

           pinksmoothing_ghosts+=1;

       }



       else { pinksmoothing_ghosts=0; }

    }
    }

    else {PINK_release-=1;

        QPixmap pinkmap(":/images/images/pink.png");
        QPixmap pink_scaled = pinkmap.scaled(QSize(18,24),Qt::KeepAspectRatio);

        QGraphicsPixmapItem *PINK = scene->addPixmap(pink_scaled);
        PINK->setZValue(3);

        if(PINK_release==0) {

           PINK->setPos(maze->getPINK()->getx()-5,maze->getPINK()->gety()-9);

        }

        else {
             PINK->setPos(251,258);

        }
        }








    if(ORAN_release==0) {

    if(oransmoothing_ghosts==0) {

       orandraw_ghosts();
       oransmoothing_ghosts+=1;

    }

    else {

               orandraw_ghosts_smooth();

       if(oransmoothing_ghosts<3) {

           oransmoothing_ghosts+=1;

       }



       else { oransmoothing_ghosts=0; }

    }
    }

    else {ORAN_release-=1;

        QPixmap oranmap(":/images/images/oran.png");
        QPixmap oran_scaled = oranmap.scaled(QSize(18,24),Qt::KeepAspectRatio);

        QGraphicsPixmapItem *ORAN = scene->addPixmap(oran_scaled);
        ORAN->setZValue(2);

        if(ORAN_release==0) {

           ORAN->setPos(maze->getORAN()->getx()-5,maze->getORAN()->gety()-9);

        }

        else {
             ORAN->setPos(281,288);

        }
        }


    collide();              //Check collision after every tick is made

    draw_lives();

    if(lives!=0) {

    timer->start(60);           //Reset the timer and continue the game only if the player has lives

    }

    }




void MainWindow::keyPressEvent(QKeyEvent *k) {

    //Controls ManPac's movement by changing his direction based on keyboard input


    if(k->key()==Qt::Key_W && MPdir!=1) {

        MP_nextdir=1;

    }

    else if(k->key()==Qt::Key_S && MPdir!=3) {

        MP_nextdir=3;


    }
    else if(k->key()==Qt::Key_D && MPdir!=0) {

        MP_nextdir=0;


    }
    else if(k->key()==Qt::Key_A && MPdir!=2) {

            MP_nextdir=2;


}
    else if(k->key()==Qt::Key_Space) {

        on_Pause_clicked();
    }
}
int MainWindow::next_location(int index, int dir) {

    //Finds the next node ManPac will move to based on his move direction

    switch(dir) {

        case 0: if(index==147) {return 128;}
                else { return index+1;}
    case 1: {int new_idex=maze->find_node(index,-20); return new_idex;}

    case 2:  if(index==128) { return 147;}
             else { return index-1; }
    case 3: {int new_idex=maze->find_node(index,20); return new_idex;}
    }

    return 0;

}


QPixmap MainWindow::animate(int dir, int anim, int type) {

    /*
     *Animates the various game characters by using direction and animation counters
     * to determine which pixmap to use. The type var determines which character we
     * are dealing with.
     */

    switch(type) {

        case 0: {


        switch(dir) {

            case 0:
                    switch(anim) {

                        case 0: {   QPixmap mpmap(":/images/images/MPW.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2; }
                        case 1: {   QPixmap mpmap(":/images/images/MPRO1.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}
                        case 2: {   QPixmap mpmap(":/images/images/MPRO2.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}
                        case 3: {   QPixmap mpmap(":/images/images/MPRO3.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio); return mpmap2;}
                        case 4: {   QPixmap mpmap(":/images/images/MPRO2.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}
                        case 5: {   QPixmap mpmap(":/images/images/MPRO1.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}


                    }


            case 1: {

                    switch(anim) {

                        case 0: {   QPixmap mpmap(":/images/images/MPW.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}
                        case 1: {   QPixmap mpmap(":/images/images/MPUO1.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}
                        case 2: {   QPixmap mpmap(":/images/images/MPUO2.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}
                        case 3: {   QPixmap mpmap(":/images/images/MPUO3.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}
                        case 4: {   QPixmap mpmap(":/images/images/MPUO2.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio); return mpmap2; }
                        case 5: {   QPixmap mpmap(":/images/images/MPUO1.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}


                    }


        }

            case 2:
                    switch(anim) {

                        case 0: {   QPixmap mpmap(":/images/images/MPW.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}
                        case 1: {   QPixmap mpmap(":/images/images/MPLO1.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}
                        case 2: {   QPixmap mpmap(":/images/images/MPLO2.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}
                        case 3: {   QPixmap mpmap(":/images/images/MPLO3.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}
                        case 4: {   QPixmap mpmap(":/images/images/MPLO2.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}
                        case 5: {   QPixmap mpmap(":/images/images/MPLO1.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}


                }




            case 3: {

                switch(anim) {

                    case 0: {   QPixmap mpmap(":/images/images/MPW.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}
                    case 1: {   QPixmap mpmap(":/images/images/MPDO1.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}
                    case 2: {   QPixmap mpmap(":/images/images/MPDO2.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}
                    case 3: {   QPixmap mpmap(":/images/images/MPDO3.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}
                    case 4: {   QPixmap mpmap(":/images/images/MPDO2.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio); return mpmap2;}
                    case 5: {   QPixmap mpmap(":/images/images/MPDO1.png"); QPixmap mpmap2 = mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);  return mpmap2;}


                    }


            }

        }



        }

    case 1: { switch(REDanim) {

                case 0: { QPixmap mpmap(":/images/images/red-down.png"); QPixmap mpmap2 = mpmap.scaled(QSize(18,24),Qt::KeepAspectRatio); REDanim++; return mpmap2;}

                case 1: { QPixmap mpmap(":/images/images/red-down-2.png"); QPixmap mpmap2 = mpmap.scaled(QSize(18,24),Qt::KeepAspectRatio); REDanim=0; return mpmap2;}
        }

    }

    case 2: { switch(BLUEanim) {

                   case 0: { QPixmap mpmap(":/images/images/blue.png"); QPixmap mpmap2 = mpmap.scaled(QSize(18,24),Qt::KeepAspectRatio); BLUEanim++; return mpmap2;}

                   case 1: { QPixmap mpmap(":/images/images/blue.png"); QPixmap mpmap2 = mpmap.scaled(QSize(18,24),Qt::KeepAspectRatio); BLUEanim=0; return mpmap2;}
           }

       }
       case 3: { switch(PINKanim) {

                   case 0: { QPixmap mpmap(":/images/images/pink.png"); QPixmap mpmap2 = mpmap.scaled(QSize(18,24),Qt::KeepAspectRatio); PINKanim++; return mpmap2;}

                   case 1: { QPixmap mpmap(":/images/images/pink.png"); QPixmap mpmap2 = mpmap.scaled(QSize(18,24),Qt::KeepAspectRatio); PINKanim=0; return mpmap2;}
           }

       }

       case 4: { switch(ORANanim) {

                   case 0: { QPixmap mpmap(":/images/images/oran.png"); QPixmap mpmap2 = mpmap.scaled(QSize(18,24),Qt::KeepAspectRatio); ORANanim++; return mpmap2;}

                   case 1: { QPixmap mpmap(":/images/images/oran.png"); QPixmap mpmap2 = mpmap.scaled(QSize(18,24),Qt::KeepAspectRatio); ORANanim=0; return mpmap2;}
           }

       }


    }
    QPixmap mpmap(":/images/images/error.png");
    return mpmap.scaled(QSize(20,20),Qt::KeepAspectRatio);

}

bool MainWindow::allow_move(const int& nt, int movedir) {

    //Checks whether a move is allowed to be made by checking the node type and then which move directions are possible at it

    switch(nt) {

    case 0: if(movedir==0 || movedir==3) {return true;} else {return false;}
            break;
    case 1: if(movedir==2 || movedir==3) {return true;} else {return false;}
            break;
    case 2: if(movedir==0 || movedir==1) {return true;} else {return false;}
            break;
    case 3: if(movedir==1 || movedir==2) {return true;} else {return false;}
            break;
    case 4: if(movedir==0 || movedir==2 || movedir==3) {return true;} else {return false;}
            break;
    case 5: if(movedir==0 || movedir==1 || movedir==2) {return true;} else {return false;}
            break;
    case 6: if(movedir==1 || movedir==2 || movedir==3) {return true;} else {return false;}
            break;
    case 7: if(movedir==0 || movedir==1 || movedir==3) {return true;} else {return false;}
            break;
    case 8: if(movedir==1 || movedir==3) {return true;} else {return false;}
            break;
    case 9: if(movedir==0 || movedir==2) {return true;} else {return false;}
            break;
    case 10: if(movedir==0 || movedir==1 || movedir==2 || movedir==3) {return true;} else {return false;}
            break;
    default: return false;

    }

    return false;
}



void MainWindow::on_Pause_clicked() {

    //Manages to pause button and switches the state of the icon based on whether the game is paused or playing

    if(paused==false) {
        timer->stop();
        QPixmap play(":/images/images/Play.png");
        ui->Pause->setIcon(play);
        paused=true;
    }

    else {

        timer->start(30);
        QPixmap pause(":/images/images/Pause.png");
        ui->Pause->setIcon(pause);
        paused=false;
    }
}

void delay() {

    //Delay method to add a constant 1 second delay to certain events without calling timers

    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


void MainWindow::draw_fruit(QGraphicsPixmapItem *MP){

    /*
     * Draws the various fruit in the game based on how many nodes ManPac has eaten.
     * Initialises the spawn variables to true once the requirement is met and
     * only sets them to false once they have been eaten.
     */

    switch(fruit) {

    case 70: cherry_spawn=true; break;
    case 140: apple_spawn=true; break;
    case 210: orange_spawn=true; break;

    }

    if(cherry_spawn==true) {

        QPixmap cherry(":/images/images/Cherry.png");
        QPixmap cherry_scaled = cherry.scaled(QSize(22,22),Qt::KeepAspectRatio);
        QGraphicsPixmapItem *cherry_item = scene->addPixmap(cherry_scaled);
        cherry_item->setPos(270,338);
        if(eat_fruit(MP, cherry_item)==true) {
            cherry_spawn=false;
            score+=100;

        }
    }

    else if(apple_spawn==true) {

        QPixmap apple(":/images/images/Apple.png");
        QPixmap apple_scaled = apple.scaled(QSize(24,24),Qt::KeepAspectRatio);
        QGraphicsPixmapItem *apple_item = scene->addPixmap(apple_scaled);
        apple_item->setPos(270,338);
        if(eat_fruit(MP, apple_item)==true) {
            apple_spawn=false;
            score+=250;

        }

    }

    else if(orange_spawn==true) {

        QPixmap orange(":/images/images/Orange.png");
        QPixmap orange_scaled = orange.scaled(QSize(24,24),Qt::KeepAspectRatio);
        QGraphicsPixmapItem *orange_item = scene->addPixmap(orange_scaled);
        orange_item->setPos(270,338);
        if(eat_fruit(MP,orange_item)==true) {
            orange_spawn=false;
            score+=500;

        }

    }

}

bool MainWindow::eat_fruit(QGraphicsPixmapItem *MP,QGraphicsPixmapItem *fruit){

    //Checks whether ManPac has collided with a fruit => Eat the fruit.

    if(MP->collidesWithItem(fruit)==true) {

        chomp.play();

        return true;
    }

    return false;

}

void MainWindow::draw_nodes() {

    /*
     * Draws the nodes in the game in various colours using a constant pattern if a special node has not been eaten.
     * If a special node has been eaten then Rave>0 and the nodes will alternate between colors randomly
     * using the SRand seed and a random number generated from it.
     * Nodes are not drawn if they have been eaten (i.e node.consumed==true)
     */

    QColor aqua(0, 255, 255);
    QColor chartreuse(127, 255, 0);
    QColor deepPink(255, 20, 147);
    QColor magenta(255, 0, 255);
    QColor orangeRed(255, 69, 0);
    QColor yellow(255, 255, 0);
    QColor blue(0, 0, 255);
    QColor springGreen(0, 255, 127);
    QColor orange(255, 165, 0);

    QVector<QColor> colors;

    colors.append(aqua);
    colors.append(chartreuse);
    colors.append(deepPink);
    colors.append(magenta);
    colors.append(orangeRed);
    colors.append(yellow);
    colors.append(blue);
    colors.append(springGreen);
    colors.append(orange);

    int pattern=0;

    for(std::size_t counter=0;counter<mynodes->size();counter++) {

        if(RAVE>0) {

            if(mynodes->at(counter)->getconsumed()==false) {

                int r=rand()%9;

                if(mynodes->at(counter)->getSpecial()==true) {scene->addEllipse(mynodes->at(counter)->getx()-5,mynodes->at(counter)->gety()-5,15,15)->setBrush(QBrush(colors.at(r))); }
                else {
                scene->addEllipse(mynodes->at(counter)->getx(),mynodes->at(counter)->gety(),5,5)->setBrush(QBrush(colors.at(r)));
                }



            }

        }

        else {

        if(pattern==9) {pattern=0;}

        if(mynodes->at(counter)->getconsumed()==false) {

            if(mynodes->at(counter)->getSpecial()==true) {scene->addEllipse(mynodes->at(counter)->getx()-5,mynodes->at(counter)->gety()-5,15,15)->setBrush(QBrush(colors.at(pattern))); }
            else {
            scene->addEllipse(mynodes->at(counter)->getx(),mynodes->at(counter)->gety(),5,5)->setBrush(QBrush(colors.at(pattern)));
            }



        }
                    pattern ++;


    }
    }

}

void MainWindow::RAVE_time() {

    //Controls the flashing background and maze when a pellet is eaten by cycling through values in a switch statement

    if(RAVE>0) {
        RAVE--;


        back_cycle++;

        int c = back_cycle%5;

        switch (c) {
        case 0: scene->setBackgroundBrush(QImage(":/images/images/layout.png"));
            break;
        case 1: scene->setBackgroundBrush(QImage(":/images/images/layout2.png"));
            break;
        case 2: scene->setBackgroundBrush(QImage(":/images/images/layout3.png"));
            break;
        case 3: scene->setBackgroundBrush(QImage(":/images/images/layout4.png"));
            break;
        case 4: scene->setBackgroundBrush(QImage(":/images/images/layout5.png"));
            break;

        }




        if (RAVE==0) { this->setStyleSheet("background-color: black;");}

        else {
        switch(RAVE_cycle) {

            case 0: this->setStyleSheet("background-color: red;"); RAVE_cycle+=1; break;
            case 1: this->setStyleSheet("background-color: orange;"); RAVE_cycle+=1; break;
            case 2: this->setStyleSheet("background-color: yellow;"); RAVE_cycle+=1; break;
            case 3: this->setStyleSheet("background-color: green;"); RAVE_cycle+=1; break;
            case 4: this->setStyleSheet("background-color: blue;"); RAVE_cycle+=1; break;
            case 5: this->setStyleSheet("background-color: magenta;"); RAVE_cycle+=1; break;
            case 6: this->setStyleSheet("background-color: chartreuse;"); RAVE_cycle+=1; break;
            case 7: this->setStyleSheet("background-color: indigo;"); RAVE_cycle+=1; break;
            case 8: this->setStyleSheet("background-color: deeppink;"); RAVE_cycle+=1; break;
            case 9: this->setStyleSheet("background-color: mediumturquoise;"); RAVE_cycle+=1; break;
            case 10: this->setStyleSheet("background-color: cyan;"); RAVE_cycle=0; break;

        }
        }
    }

}


void MainWindow::check_win(){

    //Checks whether the player has eaten all of the nodes and then presents the 'win' screen

    if(fruit==244) {   //244 nodes on screen

        timer->stop();
        ui->graphicsView->hide();
        ui->score_label->hide();
        ui->score_val->hide();
        ui->Pause->hide();
        lives=0;
        scorer();
        ui->wintxt->show();
        ui->trophy->show();
    }

}


void MainWindow::draw_ghosts() {

    //Draws the ghosts at the normal nodes

    if(RED_move1_cur==126) {

        RED_move1_cur=0;
    }

    int next_R = next_location(maze->getRED()->getIndex(),RED_move1[RED_move1_cur]);
    maze->setRED(next_R);

    QPixmap redmap(":/images/images/red-down.png");
    QPixmap red_scaled = redmap.scaled(QSize(18,24),Qt::KeepAspectRatio);

    QGraphicsPixmapItem *RED = scene->addPixmap(red_scaled);
    RED->setPos(maze->getRED()->getx()-5,maze->getRED()->gety()-9);
    RED->setZValue(5);
    RED_move1_cur+=1;

}

void MainWindow::bluedraw_ghosts() {

    if(BLUE_move1_cur==80) {

        BLUE_move1_cur=0;
    }

    int next_B = next_location(maze->getBLUE()->getIndex(),BLUE_move1[BLUE_move1_cur]);
    maze->setBLUE(next_B);

    QPixmap bluemap(":/images/images/blue.png");
    QPixmap blue_scaled = bluemap.scaled(QSize(18,24),Qt::KeepAspectRatio);

    QGraphicsPixmapItem *BLUE = scene->addPixmap(blue_scaled);
    BLUE->setPos(maze->getBLUE()->getx()-5,maze->getBLUE()->gety()-9);
    BLUE->setZValue(4);
    BLUE_move1_cur+=1;

}

void MainWindow::pinkdraw_ghosts() {

    if(PINK_move1_cur==98) {

        PINK_move1_cur=0;
    }

    int next_B = next_location(maze->getPINK()->getIndex(),PINK_move1[PINK_move1_cur]);
    maze->setPINK(next_B);

    QPixmap pinkmap(":/images/images/pink.png");
    QPixmap pink_scaled = pinkmap.scaled(QSize(18,24),Qt::KeepAspectRatio);

    QGraphicsPixmapItem *PINK = scene->addPixmap(pink_scaled);
    PINK->setPos(maze->getPINK()->getx()-5,maze->getPINK()->gety()-9);
    PINK->setZValue(3);
    PINK_move1_cur+=1;

}

void MainWindow::orandraw_ghosts() {

    if(ORAN_move1_cur==126) {

        ORAN_move1_cur=0;
    }

    int next_B = next_location(maze->getORAN()->getIndex(),ORAN_move1[ORAN_move1_cur]);
    maze->setORAN(next_B);

    QPixmap oranmap(":/images/images/oran.png");
    QPixmap oran_scaled = oranmap.scaled(QSize(18,24),Qt::KeepAspectRatio);

    QGraphicsPixmapItem *ORAN = scene->addPixmap(oran_scaled);
    ORAN->setPos(maze->getORAN()->getx()-5,maze->getORAN()->gety()-9);
    ORAN->setZValue(2);
    ORAN_move1_cur+=1;

}

void MainWindow::draw_MP_smooth() {

    //Draws ManPac at the 3 smoothing nodes between each real node

    QPixmap newmap = animate(MPdir, MPanim, 0);
    switch(MPdir) {

    case 0:  {QGraphicsPixmapItem *MP = scene->addPixmap(newmap); MP->setPos(maze->getManPac()->getx()-6+5*smoothing,maze->getManPac()->gety()-7);MP->setZValue(6);draw_fruit(MP);break;}
    case 1:  {QGraphicsPixmapItem *MP = scene->addPixmap(newmap); MP->setPos(maze->getManPac()->getx()-6,maze->getManPac()->gety()-7-5*smoothing);MP->setZValue(6);draw_fruit(MP);break;}
    case 2:  {QGraphicsPixmapItem *MP = scene->addPixmap(newmap); MP->setPos(maze->getManPac()->getx()-6-5*smoothing,maze->getManPac()->gety()-7);MP->setZValue(6);draw_fruit(MP);break;}
    case 3:  {QGraphicsPixmapItem *MP = scene->addPixmap(newmap); MP->setPos(maze->getManPac()->getx()-6,maze->getManPac()->gety()-7+5*smoothing);MP->setZValue(6);draw_fruit(MP);break;}
    }


}

void MainWindow::draw_ghosts_smooth() {

     //Draws ghosts at the 3 smoothing nodes between each real node

    if(RED_move1_cur==126) {

        RED_move1_cur=0;
    }


    QPixmap newmap = animate(0,REDanim,1);
    switch(RED_move1[RED_move1_cur]) {

    case 0:  {QGraphicsPixmapItem *RED = scene->addPixmap(newmap); RED->setPos(maze->getRED()->getx()-5+5*smoothing_ghosts,maze->getRED()->gety()-9);RED->setZValue(5);break;}
    case 1:  {QGraphicsPixmapItem *RED = scene->addPixmap(newmap); RED->setPos(maze->getRED()->getx()-5,maze->getRED()->gety()-9-5*smoothing_ghosts);RED->setZValue(5);break;}
    case 2:  {QGraphicsPixmapItem *RED = scene->addPixmap(newmap); RED->setPos(maze->getRED()->getx()-5-5*smoothing_ghosts,maze->getRED()->gety()-9);RED->setZValue(5);break;}
    case 3:  {QGraphicsPixmapItem *RED = scene->addPixmap(newmap); RED->setPos(maze->getRED()->getx()-5,maze->getRED()->gety()-9+5*smoothing_ghosts);RED->setZValue(5);break;}
    }


}

void MainWindow::bluedraw_ghosts_smooth() {

    if(BLUE_move1_cur==80) {

       BLUE_move1_cur=0;
    }


    QPixmap bluenewmap = animate(0,BLUEanim,2);
    switch(BLUE_move1[BLUE_move1_cur]) {

    case 0:  {QGraphicsPixmapItem *BLUE = scene->addPixmap(bluenewmap); BLUE->setPos(maze->getBLUE()->getx()-5+5*bluesmoothing_ghosts,maze->getBLUE()->gety()-9);BLUE->setZValue(4);break;}
    case 1:  {QGraphicsPixmapItem *BLUE = scene->addPixmap(bluenewmap); BLUE->setPos(maze->getBLUE()->getx()-5,maze->getBLUE()->gety()-9-5*bluesmoothing_ghosts);BLUE->setZValue(4);break;}
    case 2:  {QGraphicsPixmapItem *BLUE= scene->addPixmap(bluenewmap); BLUE->setPos(maze->getBLUE()->getx()-5-5*bluesmoothing_ghosts,maze->getBLUE()->gety()-9);BLUE->setZValue(4);break;}
    case 3:  {QGraphicsPixmapItem *BLUE = scene->addPixmap(bluenewmap); BLUE->setPos(maze->getBLUE()->getx()-5,maze->getBLUE()->gety()-9+5*bluesmoothing_ghosts);BLUE->setZValue(4);break;}
    }


}

void MainWindow::pinkdraw_ghosts_smooth() {

    if(PINK_move1_cur==98) {

       PINK_move1_cur=0;
    }


    QPixmap pinknewmap = animate(0,PINKanim,3);
    switch(PINK_move1[PINK_move1_cur]) {

    case 0:  {QGraphicsPixmapItem *PINK = scene->addPixmap(pinknewmap); PINK->setPos(maze->getPINK()->getx()-5+5*pinksmoothing_ghosts,maze->getPINK()->gety()-9);PINK->setZValue(3);break;}
    case 1:  {QGraphicsPixmapItem *PINK = scene->addPixmap(pinknewmap); PINK->setPos(maze->getPINK()->getx()-5,maze->getPINK()->gety()-9-5*pinksmoothing_ghosts);PINK->setZValue(3);break;}
    case 2:  {QGraphicsPixmapItem *PINK= scene->addPixmap(pinknewmap); PINK->setPos(maze->getPINK()->getx()-5-5*pinksmoothing_ghosts,maze->getPINK()->gety()-9);PINK->setZValue(3);break;}
    case 3:  {QGraphicsPixmapItem *PINK = scene->addPixmap(pinknewmap); PINK->setPos(maze->getPINK()->getx()-5,maze->getPINK()->gety()-9+5*pinksmoothing_ghosts);PINK->setZValue(3);break;}
    }


}



void MainWindow::orandraw_ghosts_smooth() {

    if(ORAN_move1_cur==126) {

       ORAN_move1_cur=0;
    }


    QPixmap orannewmap = animate(0,ORANanim,4);
    switch(ORAN_move1[ORAN_move1_cur]) {

    case 0:  {QGraphicsPixmapItem *ORAN = scene->addPixmap(orannewmap);ORAN->setPos(maze->getORAN()->getx()-5+5*oransmoothing_ghosts,maze->getORAN()->gety()-9);ORAN->setZValue(2);break;}
    case 1:  {QGraphicsPixmapItem *ORAN = scene->addPixmap(orannewmap); ORAN->setPos(maze->getORAN()->getx()-5,maze->getORAN()->gety()-9-5*oransmoothing_ghosts);ORAN->setZValue(2);break;}
    case 2:  {QGraphicsPixmapItem *ORAN= scene->addPixmap(orannewmap); ORAN->setPos(maze->getORAN()->getx()-5-5*oransmoothing_ghosts,maze->getORAN()->gety()-9);ORAN->setZValue(2);break;}
    case 3:  {QGraphicsPixmapItem *ORAN = scene->addPixmap(orannewmap); ORAN->setPos(maze->getORAN()->getx()-5,maze->getORAN()->gety()-9+5*oransmoothing_ghosts);ORAN->setZValue(2);break;}
    }


}

void MainWindow::draw_lives() {

    //Draws the life icons at the base of the screen

    switch (lives) {
    case 1: {QPixmap life(":/images/images/lives.png"); QPixmap life2=life.scaled(QSize(32,32),Qt::KeepAspectRatio); ui->lives_label->setPixmap(life2);}

        break;
    case 2: {QPixmap life(":/images/images/lives2.png");QPixmap life2=life.scaled(QSize(64,32),Qt::KeepAspectRatio); ui->lives_label->setPixmap(life2);}
        break;

    case 3: {QPixmap life(":/images/images/lives3.png");QPixmap life2=life.scaled(QSize(96,32),Qt::KeepAspectRatio); ui->lives_label->setPixmap(life2);}
        break;

    }
}

void MainWindow::collide() {

    /*
     * Checks whether ManPac has collided with a ghost by using the QList of items in the scene
     * ManPac is set to the highest z-index, with each ghost 1 value behind ManPac,
     * allowing for collision detection in by accessing the first 5 elements of the list
     */

    QList<QGraphicsItem*> mylist = scene->items(Qt::SortOrder(1));

    if((mylist.at(0)->collidesWithItem(mylist.at(1))==true) || (mylist.at(0)->collidesWithItem(mylist.at(2))==true) || (mylist.at(0)->collidesWithItem(mylist.at(3))==true) || (mylist.at(0)->collidesWithItem(mylist.at(4))==true)) {

        if(RAVE>0) {

            while(1==1) {

            eat_ghost.play();
            score+=200;


            if(mylist.at(0)->collidesWithItem(mylist.at(1))==true) {
            maze->setRED(113);
            RED_move1_cur=0;
            RED_release=100;
            break;

            }

            else if(mylist.at(0)->collidesWithItem(mylist.at(2))==true) {
            BLUE_move1_cur=0;
            BLUE_release=100;
            maze->setBLUE(113);
            break;
            }

            else if(mylist.at(0)->collidesWithItem(mylist.at(4))==true) {
            ORAN_move1_cur=0;
            ORAN_release=100;
            maze->setORAN(113);
            break;
            }

            else if(mylist.at(0)->collidesWithItem(mylist.at(3))==true) {
            PINK_move1_cur=0;
            PINK_release=100;
            maze->setPINK(113);
            break;
            }
            break;
            }

        }

        else {

            death_anim();

            if(lives>0) {

                lives--;
                maze->setMP(133);
                MPdir=0;
                MP_nextdir=0;
                score-=200;
                maze->setRED(113);
                RED_move1_cur=0;
                RED_release=100;
                BLUE_move1_cur=0;
                BLUE_release=100;
                maze->setBLUE(113);
                ORAN_move1_cur=0;
                ORAN_release=100;
                maze->setORAN(113);
                PINK_move1_cur=0;
                PINK_release=100;
                maze->setPINK(113);

            }

            else {

                ui->graphicsView->hide();
                ui->lives_label->hide();
                timer->stop();

                endgame();

            }

        }

    }

}

void MainWindow::death_anim(){

    //Plays the death sound and gives a delay when ManPac has died

    death.play();
    timer->stop();
    delay();
    timer->start(30);

}

void MainWindow::endgame() {

    //Draws the 'lost' game screen

    ui->endgametxt->show();
    ui->score_label->hide();
    ui->score_val->hide();
    ui->Pause->hide();
    scorer();


}

void MainWindow::scorer() {

    // Writes the score and name of the player to the txt file and loads the file displaying the scores of all games played.
    score=score*score_mult;
    ui->highscores->show();

    QFile file("scores.txt");

    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream in( &file );
    in <<text<<'\t'<<'\t'<<'\t'<<'\t'<<QString::number(score)<< endl;

    file.close();

    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString content = stream.readAll();
    file.close();
    ui->HSview->setText(content);

    ui->HSview->show();

}

void MainWindow::begingamediff(){

//
    //begin.play();//
    ui->graphicsView->show();
    ui->score_val->show();
    text = ui->name->toPlainText();
    ui->name->hide();
    ui->name_label->hide();
    ui->score_label->show();
    ui->textBrowser->hide();
    ui->Ready_Easy->hide();
    ui->Ready_Medium->hide();
    ui->Ready_Hard->hide();
    ui->Ready_Insane->hide();
    ui->splash->hide();
    ui->CDown->show();
    delay();
    ui->CDown->setText("2");
    delay();
    ui->CDown->setText("1");
    delay();
    ui->CDown->setText("GO!");
    delay();
    ui->CDown->hide();
    ui->Pause->show();
    draw_lives();

    timer->start(30);


}

void MainWindow::on_Ready_Easy_clicked()
{
    RED_release = 100;
    BLUE_release = 200;
    PINK_release = 300;
    ORAN_release = 400;
    score_mult = 1;

begingamediff();


}
void MainWindow::on_Ready_Medium_clicked()
{
    RED_release = 100;
    BLUE_release = 150;
    PINK_release = 250;
    ORAN_release = 350;
    score_mult = 1.2;

 begingamediff();
}

void MainWindow::on_Ready_Hard_clicked()
{
    RED_release = 100;
    BLUE_release = 150;
    PINK_release = 200;
    ORAN_release = 250;
    score_mult = 1.4;

  begingamediff();
}

void MainWindow::on_Ready_Insane_clicked()
{
    RED_release = 50;
    BLUE_release = 50;
    PINK_release = 50;
    ORAN_release = 50;
    score_mult = 1.6;

   begingamediff() ;
}
