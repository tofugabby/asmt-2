
#ifndef INSTAGRAM340_H
#define INSTAGRAM340_H
#include "LinkedBagDS/LinkedBag.h"
// TO DO include necessary libraries
#include "User.h"
//#include "LinkedBag.h"
#include <string>






// This class only contains a list of users
// It should allow clients to add users and retrieve a user from the list
class Instagram340 {
    LinkedBag<User> userList;


public:
    Instagram340();
    ~Instagram340(); // Implement destructor


    void createUser(const std::string& username, const std::string& email, const std::string& password,
                    const std::string& bio, const std::string& profilePicture);


    User getUser(const int& indexK) const;
};


#endif// INSTAGRAM340_H
