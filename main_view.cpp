#include "main_view.h"
#include "tampilan_data.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QTableWidgetItem>



main_view::main_view(QWidget *parent)
    : QWidget(parent)
{

    /*Menyiapkan Database*/
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL3");
    db.setDatabaseName("DATA_AKREDITASI");
    db.setHostName("localhost");
    db.setUserName("tubes");
    db.setPassword("tubesbasdat2017");

    if(!db.open()){
         QMessageBox::critical(this,"Mabok",tr("Error : ")+db.lastError().text());
         return;
}


    this->setup_ui();
    db.close();
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

    tutup=new QPushButton("Tutup");
    search_t=new QPushButton("Search");
    nis=new QLineEdit();
    list_sekolah=new QTableWidget();

    list_sekolah->clear();
    list_sekolah->setColumnCount(4);
    list_sekolah->setRowCount(getrow());

    QStringList header_tabel;


    header_tabel << "NIS"<<"Nama Sekolah"<<"Akreditasi"<<"Alamat";
    list_sekolah->setHorizontalHeaderLabels(header_tabel);

    QSqlQuery query;

   query.exec("SELECT *FROM Sekolah");
   int row=0;
   while (query.next()) {
   int column=0;

for(column=0;column<6;column++){
       QTableWidgetItem *item=new QTableWidgetItem();
       item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled); //membuat tabel read only

       if(column==0){
           item->setText(QString::number(query.value(column).toInt()));
           list_sekolah->setItem(row,column,item);

       }

       else if(column==5){
           item->setText(query.value(column).toString());
           list_sekolah->setItem(row,1,item);

       }
       else if(column==2){
           item->setText(query.value(column).toString());
           list_sekolah->setItem(row,2,item);
       }
       else if(column==3){
           item->setText(query.value(column).toString());
           list_sekolah->setItem(row,3,item);
       }

}

row++;
   }
    list_sekolah->resizeColumnToContents(1);
    list_sekolah->resizeColumnToContents(2);
    list_sekolah->resizeColumnToContents(3);
    tampilan_h->addWidget(tutup);
    tampilan_h->addWidget(search_t);
    tampilan_h->addWidget(nis);
    tampilan_v->addWidget(list_sekolah,3);
    tampilan_core->addLayout(tampilan_h,2,0);
    tampilan_core->addLayout(tampilan_v,1,0);


    this->setLayout(tampilan_core);

    connect(tutup,SIGNAL(clicked()),this,SLOT(close()));
    connect(search_t,SIGNAL(clicked()),this,SLOT(search_t_clicked()));



}
void main_view::search_t_clicked(){


tampilan_data::prime_knight=nis->text().toInt();
tampilan_data *jendela=new tampilan_data(NULL);
/*Memakai prosedur menggunakan paramter untuk menset value*/
/*jendela->sebuah_fungsi(value);*/



}


int main_view::getrow(){
QSqlQuery query;
int counter=0;
query.exec("SELECT *FROM Sekolah");
while (query.next()) {
    counter++;

}

    return counter;
}
