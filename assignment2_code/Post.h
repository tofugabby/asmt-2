#ifndef POST_H
#define POST_H

#include <chrono>
#include <string>
#include <iostream>

class Post {
protected:
    std::string title;
    std::string mediaURL;
    std::chrono::time_point<std::chrono::steady_clock> time_stamp;

private:
    int computeTimeToExpiration() const;

public:
    Post();
    Post(const std::string& title, const std::string& mediaURL);
    virtual ~Post();

    std::string getTitle() const { return title; }
    void setTitle(const std::string& newTitle) { title = newTitle; }

    bool operator==(const Post& otherPost) const;

    virtual void display() const = 0;
};

#endif // POST_H
