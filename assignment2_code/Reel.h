#ifndef REEL_H
#define REEL_H

#include "Post.h"  // Include Post to inherit from it

class Reel : public Post {
private:
    int vidLength;

public:
    Reel(const std::string& title, const std::string& mediaURL, int vidLength);
    virtual ~Reel();

    void display() const override;
};

#endif // REEL_H

