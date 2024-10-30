#ifndef STORY_H
#define STORY_H

#include "Post.h"  // Include Post to inherit from it

class Story : public Post {
private:
    int vidDuration;

public:
    Story(const std::string& title, const std::string& mediaURL, int vidDuration);
    virtual ~Story();

    void display() const override;
};

#endif // STORY_H
