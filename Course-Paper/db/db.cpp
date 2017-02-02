#include<Model/User.h>
#include<Model/Book.h>
#include <db/db.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <search.h>

DataBase::DataBase(std::string type, std::string name) {
	this->type = type;
	this->name = name;
}

std::vector<User> DataBase::readUsersDb() {
	std::ifstream input("user.txt");
	if (!input.is_open())
	{
		exit(-2);
	}
	std::string login, password;
	std::vector<User> toReturn;
	int status;
	while (input >> login)
	{
		input >> password;
		input >> status;
		std::string bracket;
		input >> bracket;
		std::vector<Book> doljen;
		std::vector<Book> books = readBookDb();
		while(true)
		{
			input >> bracket;
			if("]" == bracket) break;
			doljen.push_back(books.at(atoi(bracket.c_str())));
		}
		User *thisUser = new User(login, password, status);
		thisUser->setDoljen(doljen);
        toReturn.push_back(*thisUser);
	}
	return toReturn;
}

std::vector<Book> DataBase::readBookDb() {
	std::ifstream input("book.txt");
	if (!input.is_open())
	{
		exit(-2);
	}
	std::string title, author, date;
	std::vector<Book> toReturn;
    int pagecount, price,id;
    while (input >> id)
	{
        input >> title;
		input >> author;
		input >> pagecount;
		input >> price;
		input >> date;
		std::replace(author.begin(), author.end(), '_', ' ');
		std::replace(title.begin(), title.end(), '_', ' ');
        toReturn.push_back(*new Book(id,title, author, pagecount, price, date));
	}
	Book::setCounter(id);
	return toReturn;
}

bool DataBase::writeUserDb(std::vector<User> whatsWrite) {
	std::ofstream output("user.txt");
	if (!output.is_open())
	{
		exit(-2);
	}
	for (User thisUser : whatsWrite)
	{
		std::vector<Book> doljen = thisUser.getDoljen();
		output << thisUser.getLogin() << " "
			<< thisUser.getPassword() << " "
			<< thisUser.getStatus() << " [ ";
		for (Book i : doljen)
		{
			output << i.getid() << " ";
		}
		output << "]\n";
	}
	output.close();
	return true;
}

bool DataBase::writeBookDb(std::vector<Book> whatsWrite) {
	std::ofstream output("book.txt");
	std::string title;
	std::string author;
	std::string date;
	if (!output.is_open())
	{
		exit(-2);
	}
	for (Book thisBook: whatsWrite)
	{
		title = thisBook.getTitle();
		author = thisBook.getAuthor();
		date = thisBook.getDate();
		std::replace(title.begin(), title.end(), ' ', '_');
		std::replace(author.begin(), author.end(), ' ', '_');
		std::replace(date.begin(), date.end(), ' ', '_');
		output <<thisBook.getid() << " "  << title << " "
				<< author << " "
				<< thisBook.getpageCount() << " "
				<< thisBook.getPrice() << " "
				<< date << std::endl;
	}
	output.close();
    return 1;
}
