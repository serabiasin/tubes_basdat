#include "prestasi.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QTableWidgetItem>

prestasi::prestasi()
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



this->set_prestasi( tampilan_data::prime_knight);

db.close();
}

void prestasi::set_prestasi(int pk){
   QVBoxLayout *layout_v=new QVBoxLayout;
   QGridLayout *layout=new QGridLayout;


QSqlQuery query;
    query.prepare("SELECT *FROM Prestasi WHERE NIS = :pk");
    query.bindValue(":pk",pk);
    query.exec();

    tabel_prestasi=new QTableWidget();
    tabel_prestasi->clear();
    tabel_prestasi->setColumnCount(2);
    tabel_prestasi->setRowCount(getrow());

    layout_v->addWidget(tabel_prestasi);
    layout->addLayout(layout_v,0,0);

     QStringList header_tabel; //hanya menampilkan judul dan kategori saja
    header_tabel << "Prestasi Yang Diraih" <<"Jenis (Akademik/Non)";
    tabel_prestasi->setHorizontalHeaderLabels(header_tabel);

int row=0;
int column=0;
while(query.next()){

    for(column=0;column<3;column++){
           QTableWidgetItem *item=new QTableWidgetItem();
           item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled); //membuat tabel read only

           if(column==1){
               item->setText(query.value(column).toString());
               tabel_prestasi->setItem(row,column-1,item);

           }
           else if(column==2){
               item->setText(query.value(column).toString());
               tabel_prestasi->setItem(row,column-1,item);
           }


    }

    row++;

}
tabel_prestasi->resizeColumnToContents(0);
tabel_prestasi->resizeColumnToContents(1);
this->setLayout(layout);
}


int prestasi::getrow(){

int key=tampilan_data::prime_knight;
int counter=0;

QSqlQuery query;
query.prepare("SELECT *FROM Prestasi WHERE NIS = :pk");
query.bindValue(":pk",key);
query.exec();

while (query.next()) {

counter++;
}
return counter;

}
