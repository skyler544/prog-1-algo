#ifndef LHT_H_
#define LHT_H_
#include "Stock.h"

// LHT = Linear Hash Table

class LHT {
private:
  static const int SIZE = 1847;
  static const int EMPTY = 0;
  static const int DEL = -1;
  // static const int HASH_MODULUS = 100;
  static const int LIMIT = 200;
  Stock table[SIZE];
  int numSaved;
  int numSavedOrDeleted;
  /* int d; */

public:
  void storeHashed(int entry);
  int hash(std::string abbreviation);
  Stock find(Stock entry);
  bool remove(Stock entry);
  bool add(Stock entry);
  void printTable();
};

#endif // LHT_H_
