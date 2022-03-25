#ifndef LINEARHASHTABLE_H_
#define LINEARHASHTABLE_H_

class LinearHashTable {
private:
  static const int SIZE = 13;
  static const int EMPTY = 0;
  static const int DEL = -1;
  static const int HASH_MODULUS = 100;
  int t[SIZE];
  int n;
  int q;
  int d;

public:
  int *getT();
  int getN();
  int getQ();
  int getD();
  void setN(int newVal);
  void setQ(int newVal);
  void setD(int newVal);
  void storeHashed(int entry);
  int hash(int entry);
  int find(int x);
  int remove(int x);
  bool add(int x);
  void printTable();
};

#endif // LINEARHASHTABLE_H_
