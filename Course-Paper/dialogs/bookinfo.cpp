#include "bookinfo.h"
#include "ui_bookinfo.h"

bookInfo::bookInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookInfo)
{
    ui->setupUi(this);
}

bookInfo::~bookInfo()
{
    delete ui;
}
