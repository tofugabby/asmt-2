#include "Story.h"
#include <iostream>

Story::Story(const std::string& title, const std::string& mediaURL, int vidDuration)
    : Post(title, mediaURL), vidDuration(vidDuration) {}

Story::~Story() {
    std::cout << "Story deleted." << std::endl;
}

void Story::display() const {
    std::cout << "Story: " << title << " with duration " << vidDuration << " seconds." << std::endl;
}
