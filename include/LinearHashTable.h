#ifndef LINEARHASHTABLE_H_
#define LINEARHASHTABLE_H_
#include "Stock.h"

class LinearHashTable {
private:
  static const int SIZE = 13;
  static const int EMPTY = 0;
  static const int DEL = -1;
  static const int HASH_MODULUS = 100;
  Stock table[SIZE];
  int numSaved;
  int numSavedOrDeleted;
  /* int d; */

public:
  // int *getTable();
  int getNumSaved();
  int getNumSavedOrDeleted();
  /* int getD(); */
  void setNumSaved(int newVal);
  void setNumSavedOrDeleted(int newVal);
  /* void setD(int newVal); */
  void storeHashed(int entry);
  int hash(Stock entry);
  Stock find(Stock entry);
  bool remove(Stock entry);
  bool add(Stock entry);
  void printTable();
};

#endif // LINEARHASHTABLE_H_
