
#include "tampilan_data.h"
#include <QDebug>

 int tampilan_data::prime_knight=0; //menandakan bahwa ini fungsi statis

tampilan_data::tampilan_data(QWidget *parent) : QWidget(parent)
{

    this->setWindowTitle("Tampilan Data");
    this->resize(450,350);
    tab_view=new QTabWidget();
    biodata *bio=new biodata();
    tab_view->addTab(bio,"Biodata");
//    tab_view->addTab(new track_record(),"Data Akademik");
    //track record nya diotak-atik tadi
    tab_view->setParent(this);

    this->show();


}

