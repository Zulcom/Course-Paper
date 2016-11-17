#include "search.h"
#include "ui_search.h"

search::search(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
    QStringList titles; // названия стоблцов
    titles << "id" << "Название" << "Автор" << "Число страниц" << "Цена" << "Дата возвращения";
    setWindowTitle("АИС Библиотека");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // запретить редактирование ячеек
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(titles); // установка названий столбцов
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
void search::pullRows()
{
   int lastRow = ui->tableWidget->rowCount();
   ui->tableWidget->insertRow(lastRow); // добавить строку в конец
   for(int  i = TITLE;i <= DATE+1;++i){ //заполнение элементов строки
        QTableWidgetItem * item = new QTableWidgetItem("123");  //создание ячейки
         ui->tableWidget->setItem(lastRow,i,item); // добавление её в строку
   }

}
