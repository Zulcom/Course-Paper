#include "bookinfo.h"
#include "ui_bookinfo.h"
#include <Model/Book.h>
#include <Model/User.h>
#include <db/db.h>
#include <string>
#include <QMessageBox>

bookInfo::bookInfo(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::bookInfo) {
	ui->setupUi(this);
	setWindowTitle("Подробная информация о книге");
}

bool changed = false;

bookInfo::~bookInfo() {
	delete ui;
}

/**
 * @brief bookInfo::setData установка placeholder'ов по информации о книге
 * @param book
 */
void bookInfo::setData(Book book, std::string holder) {
	this->bookid = book.getid();
	ui->titleEditor->setPlaceholderText(QString::fromStdString(book.getTitle()));
	ui->authorEditor->setPlaceholderText(QString::fromStdString(book.getAuthor()));
	ui->pageCountSub2Label->setText(QString::fromStdString(std::to_string(book.getpageCount())));
	ui->costEditor->setPlaceholderText(QString::fromStdString(std::to_string(book.getPrice())));
	std::vector<User>::iterator it =
            std::find_if(DataBase::users.begin(), DataBase::users.end(),
			             [holder](User const& n) { return n.getLogin() == holder; });
    if (it != DataBase::users.end()) this->holder = *it;
	if (holder.empty())
	{
        ui->readerSelector->addItem("Выберите пользователя...");
        for (User i :DataBase::users) ui->readerSelector->addItem(QString::fromStdString(i.getLogin()));
		//FIXME:вероятно, выдавать книги можно только читателям
		ui->returnBookButton->setHidden(true);
	}
	else
	{
		ui->giveBookSubLabel->setText("Книга находится у: " + QString::fromStdString(holder));
		ui->readerSelector->addItem(QString::fromStdString(holder));
		ui->readerSelector->setHidden(true);
	}

}

void bookInfo::on_returnBookButton_clicked() {
	int booktoRemove = this->bookid;
	std::vector<Book> mdakek = this->holder.getDoljen();
	std::vector<Book>::iterator it =
			std::find_if(mdakek.begin(), mdakek.end(),
			             [booktoRemove](Book const& n) { return n.getid() == booktoRemove; });
	if (it != mdakek.end())
	{
		mdakek.erase(it);
		QMessageBox::information(this, "Возврат книги", "книга успешно принята");
	}
	else QMessageBox::warning(this, "Возврат книги", "книга не найдена в списке для возврата");
}

void bookInfo::on_buttons_rejected() {
	emit close();
}

void bookInfo::on_buttons_accepted() {
    Book currentBook = DataBase::books.at(this->bookid);
	if (!(ui->titleEditor->text().isEmpty() &&
		ui->authorEditor->text().isEmpty() &&
		ui->costEditor->text().isEmpty() &&
		ui->readerSelector->currentIndex() != 0
	))
	{
		currentBook.setTitle(ui->titleEditor->text().toStdString());
		currentBook.setAuthor(ui->authorEditor->text().toStdString());
		currentBook.setPrice(ui->costEditor->text().toInt());
        for (User i: DataBase::users) if (i.getLogin() == ui->readerSelector->currentText().toStdString()) i.getDoljen().push_back(currentBook);
	}
    else QMessageBox::warning(this, "Выдача или редактирование книги", "поля пустые либо читатель не выбран!");
}
