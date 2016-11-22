#include "search.h"
#include "ui_search.h"
#include <db/db.h>
#include <Model/Book.h>
#include <Model/User.h>
#include <string>
#include <vector>
#include <dialogs/adduser.h>
#include <dialogs/deluser.h>
search::search(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::search)
{
	ui->setupUi(this);
	QStringList titles; // названия стоблцов
	titles  << "Название" << "Автор" << "Число страниц" << "Цена" << "Дата возвращения";
	setWindowTitle("АИС Библиотека");
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // запретить редактирование ячеек
	ui->tableWidget->setColumnCount(5);
	ui->tableWidget->setHorizontalHeaderLabels(titles); // установка названий столбцов
	ui->searchType->addItem("Книги");
	ui->searchType->addItem("Читатели");
    connect(ui->searchType, SIGNAL(currentIndexChanged(int)), this, SLOT(pullUsers(int)));
    connect(ui->searchBox,SIGNAL(editingFinished()),this,SLOT(pullRows())); // связываем поисковую строку с обновлением таблицы
    emit pullRows();
}

search::~search()
{
	delete ui;
}
/**
 * @brief search::pullRows
 *  Слот, заполняющий таблицу в интерфейсе.
 */
void search::pullRows()
{
	if(ui->searchType->currentIndex()>=1)
	{
		emit pullUsers(ui->searchType->currentIndex());
		return;
	}
   ui->tableWidget->setRowCount(0); // очистка таблицы
	QStringList titles; // названия стоблцов
	titles  << "Название" << "Автор" << "Число страниц" << "Цена" << "Дата возвращения";
	ui->tableWidget->setColumnCount(5);
	ui->tableWidget->setHorizontalHeaderLabels(titles);
   DataBase * bookdb = new DataBase("Book", "Book");
   std::vector<Book> books = bookdb->readBookDb();
   for(Book thisBook : books)
   {
	   int lastRow = ui->tableWidget->rowCount();
	   ui->tableWidget->insertRow(lastRow); // добавить строку в конец
	   QTableWidgetItem * thisTitle = new QTableWidgetItem(QString::fromStdString(thisBook.getTitle()));
	   QTableWidgetItem * thisAuthor = new QTableWidgetItem(QString::fromStdString(thisBook.getAuthor()));
	   QTableWidgetItem * thisCount = new QTableWidgetItem(QString::number(thisBook.getpageCount()));
	   QTableWidgetItem * thisPrice = new QTableWidgetItem(QString::number(thisBook.getPrice()));
	   QTableWidgetItem * thisDate = new QTableWidgetItem(QString::fromStdString(thisBook.getDate()));
	   ui->tableWidget->setItem(lastRow, Book::TITLE, thisTitle);
	   ui->tableWidget->setItem(lastRow, Book::AUTHOR, thisAuthor); 
	   ui->tableWidget->setItem(lastRow, Book::PAGESCOUNT, thisCount); 
	   ui->tableWidget->setItem(lastRow, Book::PAGESCOUNT, thisCount);
	   ui->tableWidget->setItem(lastRow, Book::PRICE, thisPrice); 
	   ui->tableWidget->setItem(lastRow, Book::DATE, thisDate);
   }

}
void search::pullUsers(int type) {
	if(type<1)
	{
		emit pullRows(); // TODO:прерывает ли емит функцию?
		return;
	}
	ui->tableWidget->setRowCount(0); // очистка таблицы
	QStringList titles; // названия стоблцов
	titles << "Читатель";
	ui->tableWidget->setColumnCount(1);
	ui->tableWidget->setHorizontalHeaderLabels(titles);
	DataBase * userdb = new DataBase("User", "Users");
	std::vector<User> users = userdb->readUsersDb();
	for(User thisUser : users)
	{
		if(thisUser.getStatus() > 0)
		{
			int lastRow = ui->tableWidget->rowCount();
			ui->tableWidget->insertRow(lastRow);
			QTableWidgetItem * thisLogin = new QTableWidgetItem(QString::fromStdString(thisUser.getLogin()));
			ui->tableWidget->setItem(lastRow, 0, thisLogin);
		}
	}
}

void search::on_addBook_triggered()
{
}

void search::on_deleteBook_triggered()
{

}

void search::on_addUser_triggered()
{
    addUser *ad = new addUser(this);
    ad->exec();
}


void search::on_delUser_triggered()
{
    delUser *du = new delUser(this);
    du->exec();
}
