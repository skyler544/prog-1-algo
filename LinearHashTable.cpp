#include "LinearHashTable.h"
#include <iostream>

void LinearHashTable::setN(int newVal) { n = newVal; }
void LinearHashTable::setQ(int newVal) { q = newVal; }
void LinearHashTable::setD(int newVal) { d = newVal; }

int LinearHashTable::find(int x) {
  int i = hash(x);
  while (t[i] != EMPTY) {
    if (t[i] != DEL && t[i] == x)
      return t[i];
    i = (i == SIZE - 1) ? 0 : i + 1;
  }
  return EMPTY;
}

bool LinearHashTable::add(int x) {
  if (find(x) != EMPTY)
    return false;
  // if (2*(q+1) > SIZE) resize
  int i = hash(x);
  while (t[i] != EMPTY && t[i] != DEL)
    i = (i == SIZE - 1) ? 0 : i + 1;
  if (t[i] == EMPTY)
    q++;
  n++;
  t[i] = x;
  return true;
}

int LinearHashTable::remove(int x) {
  int i = hash(x);
  while (t[i] != EMPTY) {
    int y = t[i];
    if (y != DEL && x == y) {
      t[i] = DEL;
      n--;
      // if(8*n < SIZE)
      return y;
    }
    i = (i == SIZE - 1) ? 0 : i + 1;
  }
  return EMPTY;
}

int LinearHashTable::hash(int entry) {
  return ((unsigned)(entry % HASH_MODULUS) % SIZE);
}

void LinearHashTable::printTable() {
  for (int i = 0; i < SIZE; i++) {
    std::cout << "Entry " << i << ": " << t[i] << " ";
  }
  std::cout << "\n";
}
