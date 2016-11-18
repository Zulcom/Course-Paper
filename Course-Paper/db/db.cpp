#include<Model/User.h>
#include<Model/Book.h>
#include <db/db.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

DataBase::DataBase(std::string type,std::string name){
	this->type=type;
	this->name=name;
}
std::vector<User> DataBase::readUsersDb(){
   std::ifstream input("user.txt"); 
   if(!input.is_open()){
	   exit(-2);
   }
   std::string login,password;
   std::vector<User> toReturn;
   int status;
   while (input >> login) {
	   input >> password;
	   input >> status;
	   toReturn.push_back(*new User(login, password,status));
   }
   return toReturn;
}
std::vector<Book> DataBase::readBookDb() {
	std::ifstream input("book.txt");
	if(!input.is_open())
	{
		exit(-2);
	}
	std::string title, author, date;
	std::vector<Book> toReturn;
	int pagecount, price;
	while(input >> title)
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
bool DataBase::writeUserDb(std::vector<User> whatsWrite){
    std::ofstream output("user.txt");
    if(!output.is_open())
    {
        exit(-2);
    }
    for(User thisUser : whatsWrite){
        output << thisUser.getLogin() << " "
               << thisUser.getPassword() << " "
               << thisUser.getStatus()
               << std::endl;
    }
    output.close();
    return 1; //TODO: Е Р Е С Ь
}
