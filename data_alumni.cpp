#include "data_alumni.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>

data_alumni::data_alumni(){
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


    this->set_alumni(tampilan_data::prime_knight);
    db.close();

}

void data_alumni::set_alumni(int pk){
    QSqlQuery query;
    list_alumni=new QTableWidget;
    QVBoxLayout *layout_v=new QVBoxLayout;
    QGridLayout *layout=new QGridLayout;

layout_v->addWidget(list_alumni);
layout->addLayout(layout_v,0,0);

/*bikin tabel lagi --"*/
    QStringList header_alumni;
    header_alumni<<"Angkatan"<<"PTN"<<"PTS"<<"PTK";
    list_alumni->clear();
    list_alumni->setColumnCount(3);
    list_alumni->setRowCount(getrow(pk));
    list_alumni->setHorizontalHeaderLabels(header_alumni);

    query.prepare("SELECT *FROM alumni WHERE NIS=:pk");
    query.bindValue(":pk",pk);
    query.exec();
    int row=0;
    int column=0;
    while (query.next()) {
        for(column=0;column<5;column++){
               QTableWidgetItem *item=new QTableWidgetItem();
               item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled); //membuat tabel read only

               if(column==0){
                   item->setText(QString::number(query.value(column).toInt()));
                   list_alumni->setItem(row,column,item);

               }
               else if(column==1){
                   item->setText(QString::number(query.value(column).toInt()));
                   list_alumni->setItem(row,column,item);

               }
               else if(column==2){
                   item->setText(QString::number(query.value(column).toInt()));
                   list_alumni->setItem(row,column,item);

               }

               else if(column==3){
                   item->setText(QString::number(query.value(column).toInt()));
                   list_alumni->setItem(row,column,item);

               }
               else if(column==4){
                   item->setText(QString::number(query.value(column).toInt()));
                   list_alumni->setItem(row,column,item);

               }



        }

        row++;

    }

setLayout(layout);
}


int data_alumni::getrow(int pk){
QSqlQuery query;

query.prepare("SELECT *FROM alumni WHERE NIS=:pk");
query.bindValue(":pk",pk);
query.exec();
int row=0;
while (query.next()) {
row++;
}

return row;
}
