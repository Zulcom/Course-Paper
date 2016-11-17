#include<Model/User.h>
#include <db/db.h>
#include <vector>
#include <string>
#include <fstream>

DataBase::DataBase(std::string type,std::string name){
	this->type=type;
	this->name=name;
}
std::string DataBase::getPath(){
	if(type == "User")
		return "user.txt";
	else
		return "book.txt";
}
std::vector<User> DataBase::readUsersDb(){
   std::ifstream input("user.txt"); //this->getPath.c_str()
   if(!input.is_open()){
	   exit(-2);
   }
   std::string tempReader;
   std::vector<User> toReturn;
   while (input >> tempReader) {
	   std::string password;
	   input >> password;
	   User * newUser = new User(tempReader,password);
	   //TODO: Сделай нормальное имя переменной.
	   toReturn.push_back(*newUser);
   }
   return toReturn;
}
