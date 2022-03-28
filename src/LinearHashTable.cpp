#include "LinearHashTable.h"
#include <iostream>

void LinearHashTable::setNumSaved(int newVal) { numSaved = newVal; }
void LinearHashTable::setNumSavedOrDeleted(int newVal) { numSavedOrDeleted = newVal; }
// void LinearHashTable::setD(int newVal) { d = newVal; }

int LinearHashTable::find(int x) {
  int i = hash(x);
  while (table[i] != EMPTY) {
    if (table[i] != DEL && table[i] == x)
      return table[i];
    i = (i == SIZE - 1) ? 0 : i + 1; // quadratic probing here
  }
  return EMPTY;
}

bool LinearHashTable::add(int x) {
  if (find(x) != EMPTY)
    return false;
  // if (2*(q+1) > SIZE) resize
  int i = hash(x);
  while (table[i] != EMPTY && table[i] != DEL)
    i = (i == SIZE - 1) ? 0 : i + 1; // quadratic probing here
  if (table[i] == EMPTY)
    numSavedOrDeleted++;
  numSaved++;
  table[i] = x;
  return true;
}

int LinearHashTable::remove(int x) {
  int i = hash(x);
  while (table[i] != EMPTY) {
    int y = table[i];
    if (y != DEL && x == y) {
      table[i] = DEL;
      numSaved--;
      // if(8*n < SIZE)
      return y;
    }
    i = (i == SIZE - 1) ? 0 : i + 1; // quadratic probing here
  }
  return EMPTY;
}

int LinearHashTable::hash(int entry) {
  return ((unsigned)(entry % HASH_MODULUS) % SIZE);
}

void LinearHashTable::printTable() {
  for (int i = 0; i < SIZE; i++) {
    std::cout << "Entry " << i << ": " << table[i] << " ";
  }
  std::cout << "\n";
}
