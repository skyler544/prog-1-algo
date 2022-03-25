#include "LinearHashTable.h"
#include <iostream>

void LinearHashTable::setN(int newVal) { n = newVal; }
void LinearHashTable::setQ(int newVal) { q = newVal; }
void LinearHashTable::setD(int newVal) { d = newVal; }

int LinearHashTable::find(int x) {
  int i = hash(x);
  while (t[i] != 0) {
    if (t[i] != -1 && t[i] == x)
      return t[i];
    i = (i == 10 - 1) ? 0 : i + 1;
  }
  return 0;
}
