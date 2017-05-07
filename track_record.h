#ifndef TRACK_RECORD_H
#define TRACK_RECORD_H
#include <QDialog>

class track_record :public QDialog
{
public:
    track_record(int id);

 private:
    int nis;
};

#endif // TRACK_RECORD_H
