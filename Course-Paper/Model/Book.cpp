#include <Model/Book.h>
#include <string>
#include <db/db.h>

Book::Book(const std::string& title, const std::string& author, const int pagecount, const int price, const std::string& date)
	: title(title),
	  author(author),
	  pagecount(pagecount),
	  price(price),
	  date(date) {}

bool Book::add(Book book) {
	DataBase* booksdb = new DataBase("Book", "Books");
	std::vector<Book> books = booksdb->readBookDb();
	books.push_back(book);
	bool res = booksdb->writeBookDb(books);
	return res;
}

// Getters
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getpageCount() const { return pagecount; }
int Book::getPrice() const { return price; }
std::string Book::getDate() const { return date; }
