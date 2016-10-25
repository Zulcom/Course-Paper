#ifndef DB_H
#define DB_H

#include <string>
#include <vector>
#include <algorithm/User.cpp>
#include <algorithm/algorithm.cpp>
#include <fstream>


class DataBase
{
private:
    /**
     * @brief type Datasase type.
     * User is Database contains user data.
     * Book is Database contains all staff about books.
     */
    std::string type;
    std::string name;
    getPath(){
        if(type == "User")
            return "user.txt";
        else
            return "book.txt";
    }

public:
    DataBase(std::string type,std::string name) {
        this->type=type;
        this->name=name;
    }
    std::vector<User> readUsersDb(){
             ifstream input(this.getPath);
            string tempReader;
            std::vector<User> toReturn;
            while (input >> tempReader) {
             std::vector<std::string> splitted = split(input,' ');
                User newUser = new User(splitted.at(0),splitted.at(1));
                toReturn.push_back(newUser);
            }
            // TODO: не обрабатывается случай при котором в файле нет записей.
            return toReturn;
        }

};
#endif // DB_H
