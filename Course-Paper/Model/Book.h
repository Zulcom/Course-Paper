#ifndef BOOK_H
#define BOOK_H
#include<string>

//
class Book
{
public:
	Book(const std::string& title, const std::string& author, const int pagecount, const int price, const std::string& date);
	// getters
	std::string getTitle() const;
	std::string getAuthor() const;
	int getpageCount() const;
	int getPrice() const;
	std::string getDate() const;
	static bool add(Book book);

	enum // столбцы таблицы
	{
		TITLE,
		AUTHOR,
		PAGESCOUNT,
		PRICE,
		DATE
	};

private:

	std::string title;
	std::string author;
	int pagecount;
	int price;
	std::string date;
};
#endif // BOOK_H
