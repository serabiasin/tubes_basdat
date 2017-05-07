
#include "tampilan_data.h"
#include <QDebug>

 int tampilan_data::prime_knight=0; //menandakan bahwa ini fungsi statis

tampilan_data::tampilan_data(QWidget *parent) : QWidget(parent)
{

    this->setWindowTitle("Tampilan Data");
    this->resize(450,390);
    tab_view=new QTabWidget();
    biodata *bio=new biodata();

    tab_view->addTab(bio,"Biodata");
    tab_view->addTab(new track_record(),"Data Akademik");
    tab_view->addTab(new prestasi(),"Prestasi Sekolah");
    tab_view->addTab(new data_alumni,"Data Alumni");
    tab_view->setParent(this);

    this->show();


}

