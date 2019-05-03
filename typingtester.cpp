//
//  typingtester.cpp
//  TypingTester
//
//  Created by Niklas Tom Hucke on 20.04.19.
//  Copyright © 2019 Niklas Tom Hucke. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <future>
#include <random>
#include <thread>
#include <chrono>

#include "typingtester.hpp"

void TypingTester::initWordList(std::string filename) {
    std::ifstream file;
    char c;
    std::string curr_word;
    
    file.open(filename);
    
    if(!file.is_open()) {
        std::cout << "Wasn't able to open file " + filename << std::endl;
        exit(1);
    }
    
    while(file.get(c)) {
        if(c != '\n') {
            curr_word += c;
        } else {
            this->word_list.push_back(curr_word);
            curr_word = "";
        }
    }
}

void TypingTester::saveWPM(int wpm) {
    
    std::ofstream file;
    
    file.open("data/best.txt");
    
    if(!file.is_open()) {
        std::cout << "Wasn't able to save data" << std::endl;
        exit(1);
    }
    
    
    file << wpm;
    
    file.close();
    
}

int TypingTester::getBestScore() {
    std::ifstream file;
    char c;
    std::string score;
    
    
    file.open("data/best.txt");
    
    if(!file.is_open()) {
        std::cout << "There was an error opening your 'db'. Please make sure that the folder data/ exists." << std::endl;
    }
    
    while(file.get(c)) {
        score += c;
    }
    
    if(score.size() > 0) {
        return std::stoi(score);
    }
    return 0;
}

void TypingTester::getRandomWordList(std::vector<std::string> &wl, unsigned int amount) {

    std::random_device d;
    std::default_random_engine generator(d());
    std::uniform_int_distribution<int> random(0, ((int)this->word_list.size() - 1));
    
    for(unsigned int i = 0; i < amount; i++) {
        
        wl.push_back(this->word_list.at(random(generator)));
        
    }
    
}
