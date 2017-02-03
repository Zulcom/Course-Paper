#include "bookinfo.h"
#include "ui_bookinfo.h"
#include <Model/Book.h>
#include <Model/User.h>
#include <search.h>
#include <string>
#include <QStyleFactory>
bookInfo::bookInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookInfo)
{
    ui->setupUi(this);
    setWindowTitle("Подробная информация о книге");
    this->setPalette(this->style()->standardPalette());
    this->setStyle(QStyleFactory::create("cde"));
    this->setStyleSheet("");
}

bookInfo::~bookInfo()
{
    delete ui;
}
/**
 * @brief bookInfo::setData установка placeholder'ов по информации о книге
 * @param book
 */
void bookInfo::setData(Book book,std::string holder) {
  ui->titleEditor->setPlaceholderText(QString::fromStdString( book.getTitle()));
  ui->authorEditor->setPlaceholderText(QString::fromStdString( book.getAuthor()));
  ui->pageCountSub2Label->setText(QString::fromStdString(std::to_string(book.getpageCount())));
  ui->costEditor->setPlaceholderText(QString::fromStdString(std::to_string( book.getPrice())));

  if(holder.empty()){
  for(User i :search::users) ui->readerSelector->addItem(QString::fromStdString( i.getLogin()));
  //FIXME:вероятно, выдавать книги можно только читателям
  ui->returnBookButton->setHidden(true);
  }
  else{
  ui->giveBookSubLabel->setText("Книга находится у: "+QString::fromStdString(holder));
  ui->readerSelector->addItem(QString::fromStdString(holder));
  ui->readerSelector->setHidden(true);
  }
}
