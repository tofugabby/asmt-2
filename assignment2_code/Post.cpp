#include "Post.h"

Post::Post() : time_stamp(std::chrono::steady_clock::now()) {}

Post::Post(const std::string& title, const std::string& mediaURL)
    : title(title), mediaURL(mediaURL), time_stamp(std::chrono::steady_clock::now()) {}

Post::~Post() {
    std::cout << "Post deleted." << std::endl;
}

bool Post::operator==(const Post& otherPost) const {
    return title == otherPost.title;
}

int Post::computeTimeToExpiration() const {
    const int secondsInHour = 3600;
    const int expiresAfter = 24 * secondsInHour;
    auto time_now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = time_now - time_stamp;
    int timeToExpiration = static_cast<int>((expiresAfter - elapsed_seconds.count()) / secondsInHour);
    return timeToExpiration > 0 ? timeToExpiration : 0;
}
