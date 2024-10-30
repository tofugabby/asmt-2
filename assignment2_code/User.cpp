// Include necessary standard libraries and header files
#include <iostream>
#include <string>
#include "User.h"  // Only include what is necessary


// Constructor with correct order of member initializers
User::User(std::string username, std::string email, std::string password, std::string bio, std::string profilePic)
   : username(std::move(username)), email(std::move(email)), password(std::move(password)),
     bio(std::move(bio)), profilePic(std::move(profilePic)) {}


// Destructor to deallocate post pointers
User::~User() {
   clearPosts();
}


// Getter for username
std::string User::getUsername() const {
   return username;
}


// Getter for password
std::string User::getPassword() const {
   return password;
}


// Display user's profile information
void User::displayProfile() const {
   std::cout << "Name: " << username << "\n";
   std::cout << "Email: " << email << "\n";
   std::cout << "Bio: " << bio << "\n";
   std::cout << "Profile Picture: " << profilePic << "\n";
}


// Modify user's password
bool User::modPassword(const std::string& newPassword) {
   if (password == newPassword) {
       std::cout << "Password must be different\n";
       return false;
   } else {
       password = newPassword;
       std::cout << "Password changed!\n";
       return true;
   }
}


// Overload operator==
bool User::operator==(const User& otherUser) const {
   return (username == otherUser.username) && (email == otherUser.email);
}


// Add a new post to the user's posts
void User::addPost(Post* post) {
   userPosts.append(post);
   std::cout << "Post added successfully.\n";
}


// Delete a post by index
void User::deletePost(int index) {
   Node<Post*>* postNode = userPosts.findKthItem(index);
   if (postNode != nullptr) {
       Post* postToDelete = postNode->getItem();
       userPosts.remove(postToDelete);
       delete postToDelete;
       std::cout << "Post deleted successfully.\n";
   } else {
       std::cout << "Invalid index. The total number of posts is: " << userPosts.getCurrentSize() << "\n";
   }
}


// Modify post title by index
void User::modifyPostTitle(int index, const std::string& newTitle) {
   Node<Post*>* postNode = userPosts.findKthItem(index);
   if (postNode != nullptr) {
       postNode->getItem()->setTitle(newTitle);
       std::cout << "Post title updated successfully.\n";
   } else {
       std::cout << "Invalid index. The total number of posts is: " << userPosts.getCurrentSize() << "\n";
   }
}


// Display all posts for the user
void User::displayPosts() const {
   std::vector<Post*> posts = userPosts.toVector();
   for (size_t i = 0; i < posts.size(); ++i) {
       std::cout << "Post " << i + 1 << ":\n";
       posts[i]->display();
       std::cout << "----------------\n";
   }
}

// Display the Kth post for the user
void User::displayKthPost(int k) {
   int index = k - 1;  // Convert from 1-based to 0-based indexing

   // Boundary check for index validity
   if (index < 0 || index >= userPosts.getCurrentSize()) {
      std::cout << "Invalid index. You only have " << userPosts.getCurrentSize() << " posts.\n";
      return;
   }

   // Find the k-th post using the adjusted index
   Node<Post*>* postNode = userPosts.findKthItem(index);
   if (postNode != nullptr) {
      std::cout << "Post " << k << ":\n";  // Display the post number as the user entered it
      postNode->getItem()->display();  // Assuming Post has a `display()` method
   } else {
      std::cout << "Error retrieving the post.\n";
   }
}

// Get the number of posts the user has
int User::getNumberOfPosts() const {
   return userPosts.getCurrentSize();
}


// Clear all posts
void User::clearPosts() {
   std::vector<Post*> posts = userPosts.toVector();
   for (Post* post : posts) {
       delete post;
   }
   userPosts.clear();
}
