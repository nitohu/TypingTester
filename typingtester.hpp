//
//  typingtester.hpp
//  TypingTester
//
//  Created by Niklas Tom Hucke on 20.04.19.
//  Copyright © 2019 Niklas Tom Hucke. All rights reserved.
//

#ifndef typingtester_hpp
#define typingtester_hpp

#include <stdio.h>
#include <vector>
#include <string>

//namespace tt {
//
//    static std::vector<std::string> word_list;
//
//    void LOG(int type, std::string msg);
//
//    void initWordList(std::string filename);
//    std::string getRandomWord();
//
//}

class TypingTester {
    
private:
    std::vector<std::string> word_list;
    
public:
    void initWordList(std::string filename);
    
    std::string getRandomWord();
    std::vector<std::string> getWordList();
    
};

#endif /* typingtester_hpp */
