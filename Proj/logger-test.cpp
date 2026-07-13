#include <string>
#include "cpp-logger/logger.hpp"

int main() {
    will::logger logger(will::debug, "Test.log");
    logger.log("This is a debug message.", will::debug);
    logger.log("This is an info message.", will::info);
    logger.log("This is a warning message.", will::warning);
    logger.log("This is an error message.", will::error);
    logger.log("This is a fatal message.", will::fatal);
    logger.log("This message should not be logged.", will::none);
    logger.log("GEORGE", will::error);
    logger.log("WILLIAM", will::debug);
    logger.log("A^2 + B^2 = C^2", will::info);
    logger.log("The quick brown fox jumps over the lazy dog.", will::warning);
    logger.log("Lorem ipsum dolor sit amet, consectetur adipiscing elit.", will::error);
    logger.quit();
    return 0;
}