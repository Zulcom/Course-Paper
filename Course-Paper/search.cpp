#include "search.h"
#include "ui_search.h"
#include <db/db.h>
#include <Model/Book.h>
#include <string>
#include <vector>

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
	connect(ui->searchType, SIGNAL(currentIndexChanged(int)), this, SLOT(pullRows(int)));
	connect(ui->searchBox,
			SIGNAL(editingFinished()),this,
			SLOT(pullRows())); // связываем поисковую строку с обновлением таблицы
}

search::~search()
{
	delete ui;
}
/**
 * @brief search::pullRows
 *  Слот, заполняющий таблицу в интерфейсе.
 */
void search::pullRows(int type = -1)
{
   ui->tableWidget->setRowCount(0); // очистка таблицы
   DataBase * bookdb = new DataBase("Book", "Book");
   std::vector<Book> books = bookdb->readBookDb();
   for(Book thisBook : books)
   {
	   int lastRow = ui->tableWidget->rowCount();
	   ui->tableWidget->insertRow(lastRow); // добавить строку в конец
	   /* Не стоит беспокоиться насчёт удаления этих ссылок, поскольку table::clear() удалит их сам.*/
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
