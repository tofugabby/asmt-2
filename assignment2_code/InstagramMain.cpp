#include <iostream>
#include <string>




// TO DO: #include any other libraries you need
#include "Instagram340.h"
#include "User.h"
#include "Post.h"
#include "Reel.h"
#include "Story.h"



using namespace std;




/**
*
* Displays the application's main menu
* pre create a new object of type User
* @param user object to interact with
*
* */
void displayUserMenu(User& user) {
   int userChoice = 0;
   do {
       cout << "\nHi, " << user.getUsername() << ", what would you like to do:\n"
            << "1. Display Profile\n"
            << "2. Modify Password\n"
            << "3. Create Post\n"
            << "4. Display All Posts\n"
            << "5. Display Kth Post\n"
            << "6. Modify Post\n"
            << "7. Delete Post\n"
            << "0. Logout\n"
            << "Choice: ";
       cin >> userChoice;


       switch (userChoice) {
           case 1: {
               // Display user's profile information
               user.displayProfile();
               break;
           }
           case 2: {
               // Modify user's password
               string newPassword;
               cout << "Enter NEW Password: ";
               cin >> newPassword;
               if (user.modPassword(newPassword)) {
                   cout << "Password changed successfully.\n";
               }
               break;
           }
           case 3: {
               // Create a new post (Reel or Story)
               string title, mediaURL;
               int videoLength = 0;


               cout << "Choose post type:\n1. Reel\n2. Story\nChoice: ";
               cin >> userChoice;


               cout << "Insert Title: ";
               cin.ignore();  // Clear the input buffer
               getline(cin, title);


               cout << "Insert Media URL: ";
               getline(cin, mediaURL);


               cout << "Insert Video Length (in seconds): ";
               cin >> videoLength;


               Post* newPost = nullptr;


               if (userChoice == 1) {
                   // Create a Reel
                   newPost = new Reel(title, mediaURL, videoLength);
               } else if (userChoice == 2) {
                   // Create a Story
                   newPost = new Story(title, mediaURL, videoLength);
               } else {
                   cout << "Invalid post type. Returning to menu.\n";
                   break;
               }


               user.addPost(newPost);
               break;
           }
           case 4: {
               // Display all user's posts
               user.displayPosts();
               break;
           }
           case 5: {
               // Display the Kth post
               int postNumber;
               cout << "Insert post number: ";
               cin >> postNumber;

               user.displayKthPost(postNumber);
               break;
           }
           case 6: {
               // Modify the title of a specific post
               int index;
               cout << "Enter the index of the post you want to modify (1-based index): ";
               cin >> index;


               if (index < 1 || index > user.getNumberOfPosts()) {
                   cout << "Invalid index. The total number of posts is: " << user.getNumberOfPosts() << "\n";
               } else {
                   string newTitle;
                   cout << "Enter the new title: ";
                   cin.ignore();  // Clear the input buffer
                   getline(cin, newTitle);
                   user.modifyPostTitle(index, newTitle);
                   cout << "Post title updated successfully.\n";
               }
               break;
           }
           case 7: {
               // Delete a specific post
               int index;
               cout << "Enter the index of the post you want to delete (1-based index): ";
               cin >> index;


               if (index < 1 || index > user.getNumberOfPosts()) {
                   cout << "Invalid index. The total number of posts is: " << user.getNumberOfPosts() << "\n";
               } else {
                   user.deletePost(index);
                   cout << "Post deleted successfully.\n";
               }
               break;
           }
           case 0: {
               cout << "Logging you out." << endl;
               break;
           }
           default:
               cout << "Invalid choice. Please try again." << endl;
       }


   } while (userChoice != 0);
}




int main(){
  // Instantiating the program using the default constructor
  // With this implementation, the application will only have one user
  Instagram340 instagram;




  cout << "\n Welcome to Instagram340:" << endl;
  // TO DO: Ask the user to enter their information
  //        Instantiate a new User object
  string username,email, password, bio, profilePic;
  cout << " Enter Username: ";
  cin >> username;
  cout << " Enter Email: ";
  cin >> email;
  cout << " Enter Password: ";
  cin >> password;
  cout << " Enter Bio: ";
  cin >> bio;
  cout << " Enter Profile Pic: ";
  cin >> profilePic;
  // call instagram createUser function
  // replace /*...*/ with the right parameters
  instagram.createUser(username, email, password, bio, profilePic);




  // Retrieve the user
  User currentUser = instagram.getUser(0);
  displayUserMenu(currentUser);


  return 0;
}
