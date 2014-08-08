#include "logger.h"

using namespace qtools;
using namespace std;

Logger::Logger(const string& filename) {
  start(filename);
}

void Logger::start(const string& filename) {
  this->filename = filename;
  ofstream file(this->filename.c_str(), ofstream::out | ofstream::trunc);
  if (!file) {
    cerr << "ERROR: could not open the log file " << filename << " for writing." << endl;
    return;
  }
  time_t now = time(NULL);
  char* date = ctime(&now);
  file << "Log file. Local time: " << date;
  file.close();
}

void Logger::flush() {
  ofstream file(filename.c_str(), ofstream::out | ofstream::app);
  if (!file) {
    cerr << "ERROR: could not open the log file " << filename << " for appending." << endl;
    return;
  }
  string data = logStream.str();
  file << data << endl;
  cout << data << endl;
  logStream.str(string());
  logStream.clear();
  file.close();
}

void Logger::out() {
  logStream << endl;
  string data = partialLogStream.str();
  cout << data << endl;
  partialLogStream.str(string());
  partialLogStream.clear();
}

void Logger::flushError() {
  ofstream file(filename.c_str(), ofstream::out | ofstream::app);
  if (!file) {
    cerr << "ERROR: could not open the log file " << filename << " for appending." << endl;
    return;
  }
  string data = logStream.str();
  file << data << endl;
  cerr << data << endl;
  logStream.str(string());
  logStream.clear();
  file.close();
}

void Logger::file() {
  ofstream file(filename.c_str(), ofstream::out | ofstream::app);
  if (!file) {
    cerr << "ERROR: could not open the log file " << filename << " for appending." << endl;
    return;
  }
  string data = logStream.str();
  file << data;
  logStream.str(string());
  logStream.clear();
  file.close();
}

void Logger::err() {
  logStream << endl;
  string data = partialLogStream.str();
  cerr << data << endl;
  partialLogStream.str(string());
  partialLogStream.clear();
}

