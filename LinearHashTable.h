#ifndef LINEARHASHTABLE_H_
#define LINEARHASHTABLE_H_

class LinearHashTable {
private:
  int t[10];
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
};

#endif // LINEARHASHTABLE_H_
