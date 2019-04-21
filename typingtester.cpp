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
    
    while(file.get(c)) {
        if(c != '\n') {
            curr_word += c;
        } else {
            word_list.push_back(curr_word);
            curr_word = "";
        }
    }
}

std::string TypingTester::getRandomWord() {

    std::string word = "";

    std::random_device d;
    std::default_random_engine generator(d());
    std::uniform_int_distribution<int> random(0, (int)(word_list.size() - 1));

    word = word_list.at(random(generator));

    return word;
}
