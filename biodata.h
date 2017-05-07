#ifndef BIODATA_H
#define BIODATA_H

#include "tampilan_data.h"

#include <QDialog>
#include <QLabel>
#include <QTextEdit>
#include <QGridLayout>
#include <QLineEdit>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>


class biodata : public QDialog
{
    Q_OBJECT
public:
   biodata();

  void set_data();
  void set_nama_sekolah(int pk);
  void set_alamat_sekolah(int pk);
  void set_nomor_pk(int pk); //nomor induk sekolah
  void set_jumlah_sekolah(int pk); //jumlah siswa
  void set_jkelas_sekolah(int pk);

private:

   QLabel *nama_sekolah;
   QLabel *jumlah;
   QLineEdit *jumlah_siswa;

   QLabel *jumlah_kelas;
   QLineEdit *kelas_jumlah;

   QLineEdit *nama;
   QLabel *alamat;
   QTextEdit *alamat_sekolah;

   QLabel *nomor_induk;
   QLineEdit *nomor_i;

};

#endif // BIODATA_H
