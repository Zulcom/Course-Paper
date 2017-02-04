#include <Model/Book.h>
#include <string>
#include <db/db.h>
#include <search.h>
Book::Book(const int id,
	const std::string& title,
	const std::string& author,
	const int pagecount,
	const int price,
	const std::string& date)
    : title(title),
      author(author),
	  pagecount(pagecount),
	  price(price),
	  date(date),
	id(id){	}
// Getters
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getpageCount() const { return pagecount; }
int Book::getPrice() const { return price; }
std::string Book::getDate() const { return date; }
int Book::getid() const { return id;}

