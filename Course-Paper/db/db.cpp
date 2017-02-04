#include<Model/User.h>
#include<Model/Book.h>
#include <db/db.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <search.h>
int DataBase::BookCounter;
std::vector<User> DataBase::users;
std::vector<Book> DataBase::books;
DataBase::DataBase(){
      books = DataBase::readBookDb();
    users = DataBase::readUsersDb();


}
void DataBase::saveAll(){
   writeUserDb(users);
   writeBookDb(books);
}

void DataBase::addBook(Book book) {
    books.push_back(book);
}
void DataBase::addUser(User toAdd) {
    users.push_back(toAdd);
}
int DataBase::getCounter() {return  BookCounter;}
std::vector<User> DataBase::readUsersDb() {
	std::ifstream input("user.txt",std::ios::binary);
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
		while (true)
		{
			input >> bracket;
			if ("]" == bracket) break;
            if(atoi(bracket.c_str())> books.size()) continue;
            doljen.push_back(DataBase::books.at(atoi(bracket.c_str())));
		}
		User* thisUser = new User(login, password, status);
		thisUser->setDoljen(doljen);
		toReturn.push_back(*thisUser);
	}
	return toReturn;
}

std::vector<Book> DataBase::readBookDb() {
	std::ifstream input("book.txt",std::ios::binary);
	if (!input.is_open())
	{
		exit(-2);
	}
	std::string title, author, date;
	std::vector<Book> toReturn;
	int pagecount, price, id;
	while (input >> id)
	{
		input >> title;
		input >> author;
		input >> pagecount;
		input >> price;
		input >> date;
		std::replace(author.begin(), author.end(), '_', ' ');
		std::replace(title.begin(), title.end(), '_', ' ');
		toReturn.push_back(*new Book(id, title, author, pagecount, price, date));
	}
    BookCounter = id;
	return toReturn;
}

bool DataBase::writeUserDb(std::vector<User> whatsWrite) {
	std::ofstream output("user.txt",std::ios::binary);
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
	std::ofstream output("book.txt",std::ios::binary);
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
		output << thisBook.getid() << " " << title << " "
				<< author << " "
				<< thisBook.getpageCount() << " "
				<< thisBook.getPrice() << " "
				<< date << std::endl;
	}
	output.close();
	return 1;
}
bool DataBase::removeUser(std::string username) {
    std::vector<User>::iterator it =
            std::find_if(DataBase::users.begin(), DataBase::users.end(),
                         [username](User const& n) { return n.getLogin() == username; });
    if (it != DataBase::users.end())
    {
       DataBase::users.erase(it);
       return true;
    }
    // данный юзер не найден
    else return false;
}
