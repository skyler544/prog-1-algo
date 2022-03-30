#ifndef LHT_H_
#define LHT_H_
#include "Stock.h"

// LHT = Linear Hash Table

class LHT {
private:
  // static const int SIZE = 1871;
  static const int SIZE = 593;
  static const int EMPTY = 0;
  static const int DEL = -1;
  static const int LIMIT = 200;

  Stock table[SIZE];
  int numSaved;
  int numSavedOrDeleted;

public:
  LHT();
  void storeHashed(int entry);
  int hash(std::string abbreviation);
  Stock find(Stock entry);
  bool remove(Stock entry);
  bool add(Stock entry);
  bool load(std::string file);
  bool save(std::string file);
  void printTable();
};

#endif // LHT_H_
