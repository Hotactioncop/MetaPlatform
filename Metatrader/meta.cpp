#include "meta.h"
#include "ui_meta.h"

Meta::Meta(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Meta)
{
    ui->setupUi(this);
    this->setGeometry(448,156,1024,780);

}

Meta::~Meta()
{
    delete ui;
}
