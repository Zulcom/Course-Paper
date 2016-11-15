#include "search.h"
#include "ui_search.h"

search::search(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
    QStringList titles;
    titles << "id" << "Название" << "Автор" << "Число страниц" << "Цена" << "Дата возвращения";
    setWindowTitle("АИС Библиотека");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(titles);
    connect(ui->searchBox,
            SIGNAL(editingFinished()),this,
            SLOT(pullRows()));
}

search::~search()
{
    delete ui;
}

void search::pullRows()
{
   int fila = ui->tableWidget->rowCount() ;
   ui->tableWidget->insertRow(ui->tableWidget->rowCount());
   for(int  i = TITLE;i <= DATE+1;++i){
        QTableWidgetItem * item = new QTableWidgetItem("123");
         ui->tableWidget->setItem(fila,i,item);
   }

}
