#ifndef BIODATA_H
#define BIODATA_H
#include <QDialog>
#include <QLabel>
#include <QTextEdit>
#include <QGridLayout>
#include <QLineEdit>


class biodata : public QDialog
{
    Q_OBJECT
public:
   biodata(int id);

 private:
   int nis_id;

   QLabel *nama_sekolah;
   QLabel *jumlah;
   QLineEdit *jumlah_siswa;

   QLabel *jumlah_kelas;
   QLineEdit *kelas_jumlah;

   QLineEdit *nama;
   QLabel *alamat;
   QTextEdit *alamat_sekolah;

};

#endif // BIODATA_H
