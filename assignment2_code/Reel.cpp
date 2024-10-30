#include "Reel.h"
#include <iostream>

Reel::Reel(const std::string& title, const std::string& mediaURL, int vidLength)
    : Post(title, mediaURL), vidLength(vidLength) {}

Reel::~Reel() {
    std::cout << "Reel deleted." << std::endl;
}

void Reel::display() const {
    std::cout << "Reel: " << title << " with length " << vidLength << " seconds." << std::endl;
}
