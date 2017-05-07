#include "biodata.h"
#include <QDebug>
#include <QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>

biodata::biodata(){
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

this->set_data();

db.close();

}


void biodata::set_data(){
    QGridLayout *layout=new QGridLayout();

    nama_sekolah=new QLabel("Nama Sekolah  ");
    nama=new QLineEdit();
    nama->setReadOnly(true);
    alamat=new QLabel("Alamat");

    alamat_sekolah=new QTextEdit();
    alamat_sekolah->setReadOnly(true);

    nomor_i=new QLineEdit();
    nomor_i->setReadOnly(true);
    nomor_induk=new QLabel("Nomor Induk Sekolah");

    jumlah=new QLabel("Jumlah Siswa  ");
    jumlah_siswa=new QLineEdit();
    jumlah_kelas=new QLabel("Jumlah Kelas");

    jumlah_siswa->setReadOnly(true);
    kelas_jumlah=new QLineEdit();
    kelas_jumlah->setReadOnly(true);

    max_sis=new QLabel("Jumlah Siswa Perkelas  ");
    siswa_pkelas=new QLineEdit();


layout->addWidget(nama_sekolah,0,0);
layout->addWidget(nama,0,1);
layout->addWidget(jumlah,2,0);
layout->addWidget(jumlah_siswa,2,1);

layout->addWidget(max_sis,3,0);
layout->addWidget(siswa_pkelas,3,1);

layout->addWidget(jumlah_kelas,4,0);
layout->addWidget(kelas_jumlah,4,1);
layout->addWidget(nomor_induk,5,0);
layout->addWidget(nomor_i,5,1);
layout->addWidget(alamat,6,0);
layout->addWidget(alamat_sekolah,6,1);

this->set_jumlah_sekolah(tampilan_data::prime_knight);
this->set_nama_sekolah(tampilan_data::prime_knight);
this->set_alamat_sekolah(tampilan_data::prime_knight);
this->set_jkelas_sekolah(tampilan_data::prime_knight);
this->set_nomor_pk(tampilan_data::prime_knight);
this->count_max_sis(tampilan_data::prime_knight);

setLayout(layout);

}

void biodata::set_alamat_sekolah(int pk){
    QSqlQuery query;
    query.prepare("SELECT *FROM Sekolah WHERE NIS = :pk");
    query.bindValue(":pk",pk);
    query.exec();
    query.next();
    alamat_sekolah->setText(query.value(3).toString());

}


void biodata::set_nama_sekolah(int pk){
    QSqlQuery query;
    query.prepare("SELECT *FROM Sekolah WHERE NIS = :pk");
    query.bindValue(":pk",pk);
    query.exec();
    query.next();
    nama->setText(query.value(5).toString());



}

void biodata::set_jkelas_sekolah(int pk){
    QSqlQuery query;
    query.prepare("SELECT *FROM Sekolah WHERE NIS = :pk");
    query.bindValue(":pk",pk);
    query.exec();
    query.next();
    kelas_jumlah->setText(query.value(4).toString());



}

void biodata::set_jumlah_sekolah(int pk)
{
    QSqlQuery query;
    query.prepare("SELECT *FROM Sekolah WHERE NIS = :pk");
    query.bindValue(":pk",pk);
    query.exec();
    query.next();
    jumlah_siswa->setText(query.value(1).toString());



}

void biodata::set_nomor_pk(int pk){

    QSqlQuery query;
    query.prepare("SELECT *FROM Sekolah WHERE NIS = :pk");
    query.bindValue(":pk",pk);
    query.exec();
    query.next();
    nomor_i->setText(query.value(0).toString());


}

void biodata::count_max_sis(int pk){
QSqlQuery jumlah_s; //siswa
QSqlQuery jumlah_k; //kelas
int sis_temp;
int jumlah_temp;
int result;

jumlah_s.prepare("SELECT *FROM Sekolah WHERE NIS=:pk");
jumlah_s.bindValue(":pk",pk);
jumlah_s.exec();
jumlah_s.next();
sis_temp=jumlah_s.value(1).toInt();

jumlah_k.prepare("SELECT *FROM Sekolah WHERE NIS=:pk");
jumlah_k.bindValue(":pk",pk);
jumlah_k.exec();
jumlah_k.next();
jumlah_temp=jumlah_k.value(4).toInt();

result=sis_temp/jumlah_temp;
siswa_pkelas->setText(QString::number(result));

}
