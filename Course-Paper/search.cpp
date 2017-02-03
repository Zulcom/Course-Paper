#include "search.h"
#include "ui_search.h"
#include <db/db.h>
#include <Model/Book.h>
#include <Model/User.h>
#include <vector>
#include <sstream>
#include <dialogs/adduser.h>
#include <dialogs/deluser.h>
#include <dialogs/addbook.h>
#include <dialogs/bookinfo.h>
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
	if(User::thisStatus  == 2 ){
	ui->searchType->setVisible(false);
	ui->addBook->setVisible(false);
	}
	if(User::thisStatus  > 0){
	ui->delUser->setVisible(false);
	ui->addUser->setVisible(false);
	}
	if(User::thisStatus < 2){
		ui->searchType->addItem("Книги");
		ui->searchType->addItem("Читатели");
	};
	//DataBase::serialize(books);
	//books = DataBase::deserialize();
	connect(ui->searchType, SIGNAL(currentIndexChanged(int)), this, SLOT(pullUsers(int)));
	connect(ui->searchBox,SIGNAL(editingFinished()), this,SLOT(pullRows())); // связываем поисковую строку с обновлением таблицы
    connect(ui->tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(displayRowInfo(int,int)));
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(selectAll(int,int)));
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
		ui->tableWidget->setItem(lastRow, Book::PRICE, thisPrice);
		ui->tableWidget->setItem(lastRow, Book::DATE, thisDate);
	}

}
void search::selectAll(int row, int col){ui->tableWidget->selectRow(row);}
void search::pullUsers(int type) {
	if (type < 1)
	{
        emit pullRows();
		return;
	}
	ui->tableWidget->setRowCount(0); // очистка таблицы
	QStringList titles; // названия стоблцов
    titles << "Читатель" << "Количество взятых книг";
    ui->tableWidget->setColumnCount(2);
	ui->tableWidget->setHorizontalHeaderLabels(titles);
    for (User thisUser : users)
	{
		if (thisUser.getStatus() > 0)
		{
			int lastRow = ui->tableWidget->rowCount();
			ui->tableWidget->insertRow(lastRow);
            QTableWidgetItem* thisLogin = new QTableWidgetItem(QString::fromStdString(thisUser.getLogin()));
            QTableWidgetItem * thisBooks = new QTableWidgetItem(QString::fromStdString(std::to_string(thisUser.getDoljen().size())));
            ui->tableWidget->setItem(lastRow, 0, thisLogin);
            ui->tableWidget->setItem(lastRow, 1, thisBooks);
		}
	}
}

void search::displayRowInfo(int row, int col){
     ui->tableWidget->selectRow(row); // при нажатии выделяй всю строку, а не одну ячейку
    bookInfo* bki = new bookInfo(this);
    QModelIndexList selection = ui->tableWidget->selectionModel()->selectedRows();
    Book thisRowBook = books.at(row+1);
    int thisRowBookId = thisRowBook.getid();
    std::string holder = "";
    bool br = false;
    for(User i : users){
        if(br) break;
        for(Book j : i.getDoljen()){
            if(j.getid() == thisRowBookId){
                holder = i.getLogin();
                br = true;
                break;
            }
        }
    }
//    std::vector<Book>::iterator it =
//            std::find_if(i.getDoljen().begin(),i.getDoljen().end(),
//                         [thisRowBookId](Book const& n){ return thisRowBookId == n.getid();});

//    if(it != i.getDoljen().end()){
//        holder = i.getLogin() ;
//        break;
//        }
//    }

    bki->setData(thisRowBook,holder);


    bki->exec();
}


void search::on_addBook_triggered() {
	addBook* adb = new addBook(this);
	adb->exec();
}

//void search::on_deleteBook_triggered() {}

void search::on_addUser_triggered() {
	addUser* ad = new addUser(this);
	ad->exec();
}


void search::on_delUser_triggered() {
	delUser* du = new delUser(this);
	du->exec();
}
