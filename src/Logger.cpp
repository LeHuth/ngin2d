//
// Created by leona on 2/6/2024.
//

#include "Logger.h"
#include <iostream>
#include <ctime>
#include <iomanip>

Logger::Logger() {
    log("Logger constructor called");
}

Logger::~Logger() {
    log("Logger destructor called");
}

void Logger::log(const char *message) {
    // LOG: [2024-02-06 12:00:00] Logger message

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::cout << "LOG: [" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "] " << " " << message << std::endl;
}
