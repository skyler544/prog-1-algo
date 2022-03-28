#include "LinearHashTable.h"
#include "Stock.h"
#include <iostream>

void LinearHashTable::setNumSaved(int newVal) { numSaved = newVal; }
void LinearHashTable::setNumSavedOrDeleted(int newVal) {
  numSavedOrDeleted = newVal;
}
// void LinearHashTable::setD(int newVal) { d = newVal; }

Stock LinearHashTable::find(Stock entry) {
  int i = hash(entry.getShortName());
  while (table[i].getEmpty() != EMPTY) {
    if (table[i].getDeleted() != DEL &&
        table[i].getShortName() == entry.getShortName())
      return table[i];
    i = (i == SIZE - 1) ? 0 : i + 1; // quadratic probing here
  }
  return table[i]; // should be an empty Stock; TODO check this
}

bool LinearHashTable::add(Stock entry) {
  if (find(entry).getDeleted() != EMPTY)
    return false;
  // if (2*(q+1) > SIZE) resize
  int i = hash(entry.getShortName());
  while (table[i].getEmpty() != EMPTY && table[i].getDeleted() != DEL)
    i = (i == SIZE - 1) ? 0 : i + 1; // quadratic probing here
  if (table[i].getDeleted() == EMPTY)
    numSavedOrDeleted++;
  numSaved++;
  table[i] = entry;
  return true;
}

bool LinearHashTable::remove(Stock entry) {
  int i = hash(entry.getShortName());
  while (table[i].getEmpty() != EMPTY) {
    Stock curr = table[i];
    if (curr.getDeleted() != DEL &&
        entry.getShortName() == curr.getShortName()) {
      table[i].setDeleted();
      numSaved--;
      // if(8*n < SIZE)
      return true;
    }
    i = (i == SIZE - 1) ? 0 : i + 1; // quadratic probing here
  }
  return false;
}

int LinearHashTable::hash(std::string shortName) {
  int sum = 0;
  for (int i = 0; i < shortName.length(); i++)
    sum = sum + int(shortName[i]);
  return sum % SIZE;
  // return ((unsigned)(entry % HASH_MODULUS) % SIZE);
}

void LinearHashTable::printTable() {
  for (int i = 0; i < SIZE; i++) {
    std::cout << "Entry " << i << ": ";
    table[i].printStock();
  }
  std::cout << "\n";
}
