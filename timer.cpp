//
//  timer.cpp
//  TypingTester
//
//  Created by Niklas Tom Hucke on 21.04.19.
//  Copyright © 2019 Niklas Tom Hucke. All rights reserved.
//

#include "timer.hpp"

#include <future>
#include <chrono>

Timer::Timer(int duration) {
    
    this->setDuration(duration);
    
}

void Timer::startTimer() {
    
    this->running = true;
    
    this->timer_thread = std::thread(this->timer, this->duration, &this->running);
    
    this->timer_thread.detach();
    
}

void Timer::timer(int duration, bool *running) {
    
    for(int i = 0; i < duration; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    *running = false;
    
}

bool Timer::finished() {
    return !this->running;
}

void Timer::setDuration(int d) {
    this->duration = d;
}

int Timer::getDuration() {
    return this->duration;
}
