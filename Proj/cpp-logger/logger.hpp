#include <iostream>
#include <fstream>
#include <ctime>

namespace will {
     enum level_t {
                debug,
                info,
                warning,
                error,
                none,
                fatal
            };
    class logger {
            private:
                int out(std::string message) {

                    std::cout <<message << std::endl;
                    log_file << message << std::endl;
                    return 0;
                }
            public:
                std::ofstream log_file;
                level_t log_level;
                struct tm datetime;
                time_t timestamp;
                logger(level_t level, std::string file_name) {
                    log_level = level;
                    log_file.open(file_name, std::ios::app);
                    if (!log_file.is_open()) {
                        std::cerr << "Failed to open log file: " << file_name << std::endl;
                    }
                    datetime.tm_hour = 0; datetime.tm_min = 0; // datetime.tm_sec = 0;
                    timestamp = mktime(&datetime);
                }
                int quit() {
                    if (log_file.is_open()) {
                        log_file.close();
                    }
                    return 0;
                }

                int log(const std::string message, level_t level) {
                switch (level) {
                    case debug:
                        if (out(std::string("\033[35m")+ "[" + std::to_string(time(&timestamp)) + "]" + "[DEBUG] " + message + "\033[0m") != 0) {
                            return -1; // Failed to write debug message
                        }
                        return 0;
                    case info:
                        if (out(std::string("\033[0m")+ "[" + std::to_string(time(&timestamp)) + "]" + "[INFO] " + message + "\033[0m") != 0) {
                            return -1; // Failed to write info message
                        }
                        return 0;
                    case warning:
                       if (out(std::string("\033[33m") + "[" + std::to_string(time(&timestamp)) + "]" + "[WARNING] " + message + "\033[0m") != 0) {
                            return -1; // Failed to write warning message
                        }
                        return 0;
                    case error:
                        if (out(std::string("\033[31m") + "[" + std::to_string(time(&timestamp)) + "]" + "[ERROR] " + message + "\033[0m") != 0) {
                            return -1; // Failed to write error message
                        }
                        return 0;
                    case fatal:
                        if (out(std::string("\033[31;44m") + "[" + std::to_string(time(&timestamp)) + "]" +  "[FATAL] " + message + "\033[0m") != 0) {
                            return -1; // Failed to write fatal message
                        }
                        return 0;
                    case none:
                        // Do not log anything for 'none' level
                        return 0;
                    default:

                        return -1; // Invalid log level
                }

            }
    };


}