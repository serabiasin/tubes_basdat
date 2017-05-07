#include "track_record.h"
#include <QMessageBox>
#include <QSqlError>
track_record::track_record()
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


this->set_record();

db.close();
}

void track_record::set_record(){
    QGridLayout *layout=new QGridLayout();

    nilai_edit=new QLineEdit();
    nilai_edit->setReadOnly(true);
    nilai_rata=new QLabel("Nilai Rata-Rata Sekolah ");

    ipa=new QLabel("NILAI RATA-RATA IPA  ");
    ips=new QLabel("NILAI RATA-RATA IPS  ");

    nilai_ipa=new QLineEdit();
    nilai_ipa->setReadOnly(true);
    nilai_ips=new QLineEdit();
    nilai_ips->setReadOnly(true);

    layout->addWidget(nilai_rata,0,0);
    layout->addWidget(nilai_edit,0,1);
    layout->addWidget(ipa,1,0);
    layout->addWidget(nilai_ipa,1,1);
    layout->addWidget(ips,2,0);
    layout->addWidget(nilai_ips,2,1);

    set_ipa(tampilan_data::prime_knight);
    set_ips(tampilan_data::prime_knight);
    set_rata(tampilan_data::prime_knight);


    setLayout(layout);


}

void track_record::set_ipa(int pk){
    QSqlQuery query;
    query.prepare("SELECT *FROM Peminatan WHERE NIS=:pk and kode_peminatan=:ipa ");
    query.bindValue(":pk",pk);
    QString ipa="IPA";
    query.bindValue(":ipa",ipa);
    query.exec();
    query.next();
    nilai_ipa->setText(query.value(1).toString());

}
void track_record::set_ips(int pk){

    QSqlQuery query;
    query.prepare("SELECT *FROM Peminatan WHERE NIS=:pk and kode_peminatan=:ips ");
    query.bindValue(":pk",pk);
    QString ips="IPS";
    query.bindValue(":ips",ips);
    query.exec();
    query.next();
    nilai_ips->setText(query.value(1).toString());


}

void track_record::set_rata(int pk){
    QSqlQuery query;
    query.prepare("SELECT AVG(nilai_rata_rata) FROM Peminatan WHERE NIS=:pk ");
    query.bindValue(":pk",pk);
    query.exec();
    query.next();
    nilai_edit->setText(query.value(0).toString());


}
