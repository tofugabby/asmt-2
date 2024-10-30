#include <iostream>
#include <stdexcept>
#include "Instagram340.h"

// Constructor
Instagram340::Instagram340() {
    // TO DO: implement constructor
    std::cout << "Instagram340 instance created successfully." << std::endl;
}


// Destructor
Instagram340::~Instagram340() {
    std::cout << "Instagram340 destroyed successfully." << std::endl;
}


// Create a new user and add to the user list
void Instagram340::createUser(const std::string& username, const std::string& email, const std::string& password,
                             const std::string& bio, const std::string& profilePicture) {
    // Ensure parameters are passed in correct order for User constructor
    User newUser(username, email, password, bio, profilePicture);
    userList.add(newUser);
    std::cout << "User added, current user list size: " << userList.getCurrentSize() << std::endl;
}


// Retrieve a user based on the index
User Instagram340::getUser(const int& indexK) const {
    std::cout << "Trying to get user at index: " << indexK << std::endl;
    if (indexK < 0 || indexK >= userList.getCurrentSize()) {
        std::cerr << "Error: Index out of range, current size: " << userList.getCurrentSize() << std::endl;
        throw std::out_of_range("Index out of range");
    }


    // Using indexK directly to match LinkedBag's expected indexing (assuming 0-based)
    Node<User>* current = userList.findKthItem(indexK);
    if (current == nullptr) {
        std::cerr << "Error: Node retrieval failed for index: " << indexK << std::endl;
        throw std::out_of_range("Index out of range");
    }


    return current->getItem();
}
