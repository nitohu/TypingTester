//
//  timer.hpp
//  TypingTester
//
//  Created by Niklas Tom Hucke on 21.04.19.
//  Copyright © 2019 Niklas Tom Hucke. All rights reserved.
//

#ifndef timer_hpp
#define timer_hpp

#include <stdio.h>
#include <thread>

class Timer {
    
private:
    int duration;
    
    bool running;
    
    std::thread timer_thread;
    
    static void timer(int duration, bool *running);
    
public:
    Timer();
    Timer(int duration);
    
    void startTimer();
    bool finished();
    void setDuration(int d);
    
    int getDuration();
    
};

#endif /* timer_hpp */
