#ifndef LHT_H_
#define LHT_H_
#include "Stock.h"

class LHT {
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
  int hash(std::string shortName);
  Stock find(Stock entry);
  bool remove(Stock entry);
  bool add(Stock entry);
  void printTable();
};

#endif // LHT_H_
