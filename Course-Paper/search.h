#ifndef SEARCH_H
#define SEARCH_H

#include <QMainWindow>
#include <string>
namespace Ui {
class search;
}

class search : public QMainWindow
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = 0);
    ~search();
private slots:
    void pullRows(); // заполнение таблицы
private:
    Ui::search *ui;
    enum // столбцы таблицы
    {
      TITLE,AUTHOR,PAGESCOUNT,PRICE,DATE
    };
};

#endif // SEARCH_H
