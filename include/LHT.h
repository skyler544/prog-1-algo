#ifndef LHT_H_
#define LHT_H_
#include "Stock.h"

// LHT = Linear Hash Table

class LHT {
private:
  int SIZE = 1847;
  static const int EMPTY = 0;
  static const int DEL = -1;
  static const int LIMIT = 200;

  Stock table[SIZE];
  int numSaved;
  int numSavedOrDeleted;

public:
  void storeHashed(int entry);
  int hash(std::string abbreviation);
  Stock find(Stock entry);
  bool remove(Stock entry);
  bool add(Stock entry);
  void printTable();
};

#endif // LHT_H_
