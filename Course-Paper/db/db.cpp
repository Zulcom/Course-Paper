#include<Model/User.h>
#include<Model/Book.h>
#include <db/db.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>

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
		toReturn.push_back(*new User(login, password, status));
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
	int pagecount, price;
	while (input >> title)
	{
		input >> author;
		input >> pagecount;
		input >> price;
		input >> date;
		std::replace(author.begin(), author.end(), '_', ' ');
		std::replace(title.begin(), title.end(), '_', ' ');
		toReturn.push_back(*new Book(title, author, pagecount, price, date));
	}
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
		output << thisUser.getLogin() << " "
				<< thisUser.getPassword() << " "
				<< thisUser.getStatus()
				<< std::endl;
	}
	output.close();
	return 1; //TODO: Е Р Е С Ь
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
		output << title << " "
				<< author << " "
				<< thisBook.getpageCount() << " "
				<< thisBook.getPrice() << " "
				<< date << std::endl;
	}
	output.close();
	return 1; // TODO: ЕРЕСЬ
}
//bool DataBase::serialize(std::vector<Book> whatSerialize) {
//	std::ofstream binOut("book.bin", std::ios::binary);
//	binOut << whatSerialize.size();
//	std::copy(whatSerialize.begin(), whatSerialize.end(),
//		std::ostream_iterator<Book>(binOut, "\n"));
//	return  true;
//}
//std::vector<Book> DataBase::deserialize() {
//	std::vector<Book> toReturn;
//	int size;
//	std::ifstream BinIn("book.bin", std::ios::binary);
//	BinIn >> size;
//	std::istream_iterator<Book> file_iter(BinIn);
//	std::istream_iterator<Book> end_of_stream;
//	std::copy(file_iter, end_of_stream, std::back_inserter(toReturn));
//	return toReturn;
//
//	
//}

