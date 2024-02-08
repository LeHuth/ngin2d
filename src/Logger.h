//
// Created by leona on 2/6/2024.
//

#ifndef INC_2DGAMEENGINE_LOGGER_H
#define INC_2DGAMEENGINE_LOGGER_H


class Logger {
public:
    Logger();
    ~Logger();
    static void log(const char *message);
    //static void log(const char *message, int value);
    void error(const char *message);
    //void error(const char *message, int value);
private:
    const char *tag = "Logger";
};


#endif //INC_2DGAMEENGINE_LOGGER_H
