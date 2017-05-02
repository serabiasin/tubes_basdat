#include "biodata.h"

biodata::biodata(int id){
    nis_id=id;
    QGridLayout *layout=new QGridLayout();

    nama_sekolah=new QLabel("Nama Sekolah : ");
    nama=new QLineEdit();
    nama->setReadOnly(true);
    alamat=new QLabel("Alamat");
    alamat_sekolah=new QTextEdit();
    alamat_sekolah->setReadOnly(true);
    jumlah=new QLabel("Jumlah Siswa : ");
    jumlah_siswa=new QLineEdit();
    jumlah_kelas=new QLabel("Jumlah Kelas");
    jumlah_siswa->setReadOnly(true);
    kelas_jumlah=new QLineEdit();
    kelas_jumlah->setReadOnly(true);


layout->addWidget(nama_sekolah,0,0);
layout->addWidget(nama,0,1);
layout->addWidget(jumlah,2,0);
layout->addWidget(jumlah_siswa,2,1);
layout->addWidget(jumlah_kelas,3,0);
layout->addWidget(kelas_jumlah,3,1);
layout->addWidget(alamat,4,0);
layout->addWidget(alamat_sekolah,4,1);

setLayout(layout);


}
