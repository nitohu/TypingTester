#include <future>
#include <chrono>
#include <vector>
#include <string>

#include "typingtester.hpp"
#include "timer.hpp"

void LOG(int type, std::string msg);

int main() {
    
    Timer timer = Timer(3);
    TypingTester tester;
    std::string word;
    std::vector<std::string> curr_word_list;
    // List of words the user completed
    std::vector<std::string> user_complete;
    
    tester.initWordList("words.txt");
    curr_word_list = tester.getRandomWordList(20);
    
    LOG(0, "Wordlist initialized");
    
    timer.startTimer();
    
    while(!timer.finished()) {
        
    }
    
    LOG(0, "Finished");
    
    return 0;
}

void LOG(int type, std::string msg) {
    
    /*
    Types:
    0 = [INFO]
    1 = [ERROR]
    2 = [WARNING]
    */
    
    if(type == 0) {
        printf("[INFO] ");
    } else if(type == 1) {
        printf("[ERROR] ");
    } else if(type == 2) {
        printf("[WARNING] ");
    }
    
    printf("%s \n", msg.c_str());
}
