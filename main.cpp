#include "logger.h"

using namespace qtools;
using namespace std;

int main() {

  Logger logger("log.txt");

  logger << "Info test" << Logger::INFO;
  logger << "Error test" << Logger::ERROR;
  logger << "Other" << " information " << 5 << Logger::INFO;
  logger << Logger::FILE;

  return 0;
}

