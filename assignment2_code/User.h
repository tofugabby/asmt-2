//TO DO: #include all the standard libraries and your own libraries here
#ifndef User_h
#define User_h


#include <string>
#include "LinkedBag.h"
#include "Post.h"


// To DO: define the class User with the necessary functions and data fields
class User {
private:
    std::string username;
    std::string email;
    std::string password;
    std::string bio;
    std::string profilePic;


    // LinkedBag to hold posts
    LinkedBag<Post*> userPosts;


public:
    User() = default;
    User(std::string username, std::string email, std::string password, std::string bio, std::string profilePic);


    ~User();  // Destructor to handle memory management of userPosts


    std::string getUsername() const;
    std::string getEmail() const { return email; }
    std::string getPassword() const;
    std::string getBio() const { return bio; }


    void displayProfile() const;
    bool modPassword(const std::string& newPassword);
    bool operator==(const User& otherUser) const;


    void addPost(Post* post);
    void deletePost(int index);
    void modifyPostTitle(int index, const std::string& newTitle);
    void displayPosts() const;
    int getNumberOfPosts() const;
    void displayKthPost(int k);


private:
    void clearPosts();   // Helper function to clear all posts in destructor
};


#endif


//manager of post








// This is a function that allows you to compare two users based on their username and email address.
// You may directly include it in your class definition.
// You don't need to modify it but will have to put it inside your class.
// Operator == overloading function prototype:
//bool operator==(const User& otherUser) const;
