#include "addbook.h"
#include "ui_addbook.h"

addBook::addBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addBook)
{
    ui->setupUi(this);
}

addBook::~addBook()
{
    delete ui;
}
