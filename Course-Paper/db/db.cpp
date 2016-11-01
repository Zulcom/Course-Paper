#include <db/db.h>
#include <vector>
#include <string>
#include <fstream>
#include<algorithm/User.h>
#include<algorithm/algorithm.cpp>
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
       std::vector<std::string> splitted = split(tempReader,' ');
       //User * newUser = new User(splitted.at(0),splitted.at(1));
       User * newUser = new User("123","321");
       //TODO: Сделай нормальное имя переменной.
       toReturn.push_back(*newUser);
   }
   return toReturn;
}
