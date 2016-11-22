#include "addbook.h"
#include "ui_addbook.h"
#include <QMessageBox>
#include <Model/Book.h>

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
	Book* book = new Book(
	                      ui->title->text().toStdString(),
	                      ui->author->text().toStdString(),
	                      ui->pagecount->text().toInt(),
	                      ui->price->text().toInt(),
	                      ui->date->text().toStdString()); // приведение цены из double в int.
	bool res = Book::add(*book);
	if (res)
		QMessageBox::information(this, boxtitle,
		                         "Книга успешно добавлена!");
	else
		QMessageBox::warning(this, boxtitle,
		                     "Книга не был добавлена!");

}
