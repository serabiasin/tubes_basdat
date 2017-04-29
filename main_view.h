#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QSqlQueryModel>
#include <QTableView>


class main_view : public QWidget
{
    Q_OBJECT

public:
    main_view(QWidget *parent = 0);
    ~main_view();

    void setup_ui();
    int get_row();
private:
    QGridLayout *tampilan_core;
    QPushButton *tutup;
    QPushButton *search_t;
    QLineEdit *nis;
    QTableView *list_sekolah;

private slots:
    void search_t_clicked();
};

#endif // MAIN_VIEW_H
