#include "main_view.h"
#include "tampilan_data.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QDebug>

main_view::main_view(QWidget *parent)
    : QWidget(parent)
{

    /*Menyiapkan Database*/
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL3");
    db.setDatabaseName("DATA_AKREDITASI");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("enaksekali");

    if(!db.open()){
         QMessageBox::critical(this,"Mabok",tr("Error : ")+db.lastError().text());
         return;
}



    this->setup_ui();
}

main_view::~main_view()
{
    delete tampilan_core;
    delete tutup;

}

void main_view::setup_ui(){
    /*Setting Umum*/
    this->setWindowTitle("Data Akreditasi Sekolah");
    this->resize(700,900);
    this->move(500,500);


    tampilan_core=new QGridLayout();

    QVBoxLayout *tampilan_v=new QVBoxLayout();
    QHBoxLayout *tampilan_h=new QHBoxLayout();


    QSqlQueryModel *model=new QSqlQueryModel();
    tutup=new QPushButton("Tutup");
    search_t=new QPushButton("Search");
    list_sekolah=new QTableView();
     nis=new QLineEdit();

    model->setQuery("SELECT *FROM Sekolah");
    list_sekolah->setModel(model);
    QStringList header_tabel;
   header_tabel << "NIS"<<"Akreditasi"<<"Nama Sekolah"<<"Alamat";

    tampilan_h->addWidget(tutup);
    tampilan_h->addWidget(search_t);
    tampilan_h->addWidget(nis);
    tampilan_v->addWidget(list_sekolah);
    tampilan_core->addLayout(tampilan_h,2,0);
    tampilan_core->addLayout(tampilan_v,1,0);

//    QSqlQuery query;

    /*PAKEK SQLTABLEVIEW aja !*/


//    query.exec("SELECT *FROM Sekolah");





    this->setLayout(tampilan_core);

    connect(tutup,SIGNAL(clicked()),this,SLOT(close()));
    connect(search_t,SIGNAL(clicked()),this,SLOT(search_t_clicked()));



}
void main_view::search_t_clicked(){
tampilan_data *jendela=new tampilan_data(NULL);

jendela->show();
}


int main_view::get_row(){


}
