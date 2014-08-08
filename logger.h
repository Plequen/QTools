#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <ctime>


namespace qtools {

class Logger {

  public:
    Logger() {}
    Logger(const std::string& filename);

    void start(const std::string& filename);

    void flush();
    void out();
    void flushError();
    void err();
    void file();

    std::stringstream logStream;
    std::stringstream partialLogStream;

    enum LogFlow { INFO=0, ERROR=1, FILE=2 };


  private:
    std::string filename;

};


template <typename T>
Logger& operator <<(Logger& logger, T const& value) {
  std::string typeString = typeid(T).name();
  std::string flowTypeString = typeid(Logger::LogFlow).name();

  if (typeString.compare(flowTypeString) != 0) {
    logger.logStream << value;
    logger.partialLogStream << value;
  }
  else {
    Logger::LogFlow* logFlow = (Logger::LogFlow*) &value;
    if (*logFlow == Logger::INFO)
      logger.out();
    else if (*logFlow == Logger::ERROR)
      logger.err();
    else if (*logFlow == Logger::FILE)
      logger.file();
  }
  return logger;
}

}

#endif // LOGGER_H
