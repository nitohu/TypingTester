#include <future>
#include <chrono>

#include "typingtester.hpp"
#include "timer.hpp"

int main() {
    
    Timer timer = Timer(1);
    std::string word;
    
//    tt::initWordList("words.txt");
//    tt::LOG(0, "Wordlist initialized");
    
    timer.startTimer();
    
    while(!timer.finished()) {
        tt::LOG(0, "Not finished");
    }
    
    tt::LOG(0, "Finished");
    
    return 0;
}
