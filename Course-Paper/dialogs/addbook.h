#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QDialog>

namespace Ui
{
	class addBook;
}

class addBook : public QDialog
{
	Q_OBJECT

public:
	explicit addBook(QWidget* parent = 0);
	~addBook();
	void accept();
private slots:

	void on_buttonBox_accepted();

private:
	QString boxtitle = "Добавление книги";
	Ui::addBook* ui;
};

#endif // ADDBOOK_H
