#include <future>
#include <chrono>
#include <vector>
#include <string>
#include <iostream>

#include "typingtester.hpp"
#include "timer.hpp"

void displayCurrentWordlist(std::vector<std::string> wl);
void LOG(int type, std::string msg);

int main() {
    
    Timer timer = Timer(60);
    TypingTester tester;
    std::string word;
    std::vector<std::string> curr_word_list;
    // Counts words the user typed in correctly
    int word_count = 0;
    int wrong_count = 0;
    std::string curr_input = "";
    std::string filename;
    
    std::cout << "Path to wordlist file: ";
    std::cin >> filename;
    
    tester.initWordList(filename);
    tester.getRandomWordList(curr_word_list, 20);
    
    system("clear");
    
    displayCurrentWordlist(curr_word_list);
    
    std::cout << "> ";
    
    system("stty raw");
    
    timer.startTimer();
    while(!timer.finished()) {
        
        char c = std::cin.get();
        
        if(c == ' ' || c == '\n') {

            if(curr_input == curr_word_list.at(0)) {
                // Input is correct
                word_count++;
                curr_input = "";
            } else {
                curr_input = "";
                wrong_count++;
            }
            
            curr_word_list.erase(curr_word_list.begin());
            
            if(curr_word_list.size() < 15) {
                tester.getRandomWordList(curr_word_list, 5);
            }

        } else if(c == 127) {
            curr_input = curr_input.substr(0, curr_input.size() - 1);
        } else {
            curr_input += c;
        }
        
        system("stty cooked");
        // Print word list
        system("clear");

        displayCurrentWordlist(curr_word_list);
        
        std::cout << "> " << curr_input;
        
        system("stty raw");
        
    }
    
    system("stty cooked");
    
    std::cout << "\n";
    
    LOG(0, ("Your WPM is: " + std::to_string(word_count)));
    LOG(0, ("You have typed " + std::to_string(wrong_count) + " words wrong."));
    
    LOG(0, "Finished");
    
    return 0;
}

void displayCurrentWordlist(std::vector<std::string> wl) {
    
    for(int i = 0; i < wl.size(); i++) {
        if(i % 5 == 0) {
            std::cout << "\n";
        }
        
        std::cout << wl.at(i) << " ";
    }
    std::cout << "\n";
    
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
