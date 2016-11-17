#ifndef DB_H
#define DB_H

#include <string>
#include <vector>
#include<Model/User.h>

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
    std::string getPath();

public:
    DataBase(std::string type,std::string name);
    std::vector<User> readUsersDb();

};
#endif // DB_H
