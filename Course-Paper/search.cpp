#include "search.h"
#include "ui_search.h"
#include <db/db.h>
#include <Model/Book.h>
#include <Model/User.h>
#include <string>
#include <vector>
#include <dialogs/adduser.h>
#include <dialogs/deluser.h>
#include <dialogs/addbook.h>
std::vector<User> search::users = DataBase::readUsersDb();
std::vector<Book> search::books = DataBase::readBookDb();
search::search(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::search) {
	ui->setupUi(this);
	QStringList titles; // названия стоблцов
	titles << "Название" << "Автор" << "Число страниц" << "Цена" << "Дата возвращения";
	setWindowTitle("АИС Библиотека");
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // запретить редактирование ячеек
	ui->tableWidget->setColumnCount(5);
	ui->tableWidget->setHorizontalHeaderLabels(titles); // установка названий столбцов
	ui->searchType->addItem("Книги");
	ui->searchType->addItem("Читатели");
    if(User::thisStatus >0){
    ui->delUser->setVisible(false);
    ui->addUser->setVisible(false);
    }
    if(User::thisStatus >1){
    ui->addBook->setVisible(false);
    }
	connect(ui->searchType, SIGNAL(currentIndexChanged(int)), this, SLOT(pullUsers(int)));
	connect(ui->searchBox,SIGNAL(editingFinished()), this,SLOT(pullRows())); // связываем поисковую строку с обновлением таблицы
	emit pullRows();
}

search::~search() {
	delete ui;
}

/**
 * @brief search::pullRows
 *  Слот, заполняющий таблицу в интерфейсе.
 */
void search::pullRows() {
	if (ui->searchType->currentIndex() >= 1)
	{
		emit pullUsers(ui->searchType->currentIndex());
		return;
	}
	ui->tableWidget->setRowCount(0); // очистка таблицы
	QStringList titles; // названия стоблцов
	titles << "Название" << "Автор" << "Число страниц" << "Цена" << "Дата возвращения";
	ui->tableWidget->setColumnCount(5);
	ui->tableWidget->setHorizontalHeaderLabels(titles);
    for (Book thisBook : search::books)
	{
		int lastRow = ui->tableWidget->rowCount();
		ui->tableWidget->insertRow(lastRow); // добавить строку в конец
		QTableWidgetItem* thisTitle = new QTableWidgetItem(QString::fromStdString(thisBook.getTitle()));
		QTableWidgetItem* thisAuthor = new QTableWidgetItem(QString::fromStdString(thisBook.getAuthor()));
		QTableWidgetItem* thisCount = new QTableWidgetItem(QString::number(thisBook.getpageCount()));
		QTableWidgetItem* thisPrice = new QTableWidgetItem(QString::number(thisBook.getPrice()));
		QTableWidgetItem* thisDate = new QTableWidgetItem(QString::fromStdString(thisBook.getDate()));
		ui->tableWidget->setItem(lastRow, Book::TITLE, thisTitle);
		ui->tableWidget->setItem(lastRow, Book::AUTHOR, thisAuthor);
		ui->tableWidget->setItem(lastRow, Book::PAGESCOUNT, thisCount);
		ui->tableWidget->setItem(lastRow, Book::PAGESCOUNT, thisCount);
		ui->tableWidget->setItem(lastRow, Book::PRICE, thisPrice);
		ui->tableWidget->setItem(lastRow, Book::DATE, thisDate);
	}

}

void search::pullUsers(int type) {
	if (type < 1)
	{
		emit pullRows(); // TODO:прерывает ли емит функцию?
		return;
	}
	ui->tableWidget->setRowCount(0); // очистка таблицы
	QStringList titles; // названия стоблцов
	titles << "Читатель";
	ui->tableWidget->setColumnCount(1);
	ui->tableWidget->setHorizontalHeaderLabels(titles);
    for (User thisUser : search::users)
	{
		if (thisUser.getStatus() > 0)
		{
			int lastRow = ui->tableWidget->rowCount();
			ui->tableWidget->insertRow(lastRow);
			QTableWidgetItem* thisLogin = new QTableWidgetItem(QString::fromStdString(thisUser.getLogin()));
			ui->tableWidget->setItem(lastRow, 0, thisLogin);
		}
	}
}

void search::on_addBook_triggered() {
	addBook* adb = new addBook(this);
	adb->exec();
}

void search::on_deleteBook_triggered() {}

void search::on_addUser_triggered() {
	addUser* ad = new addUser(this);
	ad->exec();
}


void search::on_delUser_triggered() {
	delUser* du = new delUser(this);
	du->exec();
}
