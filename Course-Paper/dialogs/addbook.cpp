#include "addbook.h"
#include "ui_addbook.h"
#include <QMessageBox>
#include <Model/Book.h>
#include <db/db.h>

addBook::addBook(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::addBook) {
	ui->setupUi(this);
	ui->price->setMinimum(0);
	ui->pagecount->setMinimum(1);
	setWindowTitle(boxtitle);
}

//перегружаем функцию, чтобы окно не закрывалось при добавлении
void addBook::accept() {}

addBook::~addBook() {
	delete ui;
}

void addBook::on_buttonBox_accepted() {
	if (
		ui->author->text().isEmpty() ||
		ui->title->text().isEmpty() ||
		ui->date->text().isEmpty() ||
		ui->price->text().isEmpty() ||
		ui->pagecount->text().isEmpty()
	)
	{
		QMessageBox::warning(this, boxtitle,
		                     "Одно из полей не заполнено!");
		return;
	}
	// Поскольку книга новая, её id будет = lastId+1
    Book* book = new Book(DataBase::getCounter()+1,
	                      ui->title->text().toStdString(),
	                      ui->author->text().toStdString(),
	                      ui->pagecount->text().toInt(),
	                      ui->price->text().toInt(),
	                      ui->date->text().toStdString()); // приведение цены из double в int.
   DataBase::addBook(*book);
		QMessageBox::information(this, boxtitle,
		                         "Книга успешно добавлена!");
}
