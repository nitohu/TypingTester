#include <future>
#include <chrono>
#include <vector>
#include <string>
#include <iostream>

#include "typingtester.hpp"
#include "timer.hpp"

void displayCurrentWordlist(std::vector<std::string> wl);
void LOG(int type, std::string msg);

void setupGame(TypingTester *tt, std::vector<std::string> *wl);
// Returns the WPM
int playGame(TypingTester *tt, std::vector<std::string> *wl);

int main() {
    
    TypingTester tester;
    std::vector<std::string> curr_word_list;
    
    int choice = 0;
    
    while(choice >= 0) {
        std::cout << "Welcome to this Typing Tester." << std::endl;
        std::cout << "You can specify custom word files/banks at the beginning of a game." << std::endl;
        std::cout << "\n\tM E N U\n" << std::endl;
        std::cout << " 1 - Play game" << std::endl;
        std::cout << " 2 - Get best WPM" << std::endl;
        std::cout << " 9 - Quit game" << std::endl;
        
        std::cout << "> ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                setupGame(&tester, &curr_word_list);
                playGame(&tester, &curr_word_list);
                break;
            case 2:
                std::cout << "Your best WPM is " << tester.getBestScore() << std::endl;
                break;
            case 9:
                choice = -1;
                break;
            default:
                std::cout << choice << " is not a valid answer." << std::endl;
                break;
        }
    }
    
    LOG(0, "Bye bye");
    
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



void setupGame(TypingTester *tt, std::vector<std::string> *wl) {
    std::string filename;
    
    std::cout << "Path to wordlist file: ";
    std::cin >> filename;
    
    tt->initWordList(filename);
    
}

int playGame(TypingTester *tt, std::vector<std::string> *wl) {
    
    Timer t = Timer(60);
    
    std::string curr_input = "";
    int word_count = 0;
    int wrong_count = 0;
    int highscore = tt->getBestScore();
    
    system("clear");
    
    tt->getRandomWordList(*wl, 20);
    displayCurrentWordlist(*wl);
    
    std::cout << "> ";
    
    system("stty raw");
    
    t.startTimer();
    while(!t.finished()) {
        
        char c = std::cin.get();
        
        if(c == ' ' || c == '\n') {
            
            if(curr_input == wl->at(0)) {
                // Input is correct
                word_count++;
                curr_input = "";
            } else {
                curr_input = "";
                wrong_count++;
            }
            
            wl->erase(wl->begin());
            
            if(wl->size() < 15) {
                tt->getRandomWordList(*wl, 5);
            }
            
        } else if(c == 127) {
            curr_input = curr_input.substr(0, curr_input.size() - 1);
        } else {
            curr_input += c;
        }
        
        system("stty cooked");
        // Print word list
        system("clear");
        
        displayCurrentWordlist(*wl);
        
        std::cout << "> " << curr_input;
        
        system("stty raw");
        
    }
    
    system("stty cooked");
    
    std::cout << "\n";
    
    if(highscore < word_count) {
        tt->saveWPM(word_count);
        std::cout << "\t*** New Highscore ***" << std::endl;
    }
    
    LOG(0, ("Your WPM is: " + std::to_string(word_count)));
    LOG(0, ("You have typed " + std::to_string(wrong_count) + " words wrong."));
    
    return word_count;
}
