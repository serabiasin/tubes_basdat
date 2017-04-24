#include "main_view.h"

main_view::main_view(QWidget *parent)
    : QWidget(parent)
{
    this->setup_ui();
}

main_view::~main_view()
{

}

void main_view::setup_ui(){
this->setWindowTitle("Data Akreditasi Sekolah");
this->resize(700,700);
this->move(500,500);

}
