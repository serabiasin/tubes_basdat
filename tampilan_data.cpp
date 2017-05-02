
#include "tampilan_data.h"

tampilan_data::tampilan_data(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Tampilan Data");
    this->resize(350,350);
    tab_view=new QTabWidget();

    tab_view->addTab(new biodata(get_nis()),"Biodata");
    tab_view->addTab(new track_record(),"Data Akademik");

    tab_view->setParent(this);

}


void tampilan_data::set_nis(int x){

    nis_sekolah=x;

}

int tampilan_data::get_nis(){
    return nis_sekolah;
}
