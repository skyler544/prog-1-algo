#include "LHT.h"
#include "Stock.h"
#include <iostream>

// are these methods needed? it seems like this will never be used
void LHT::setNumSaved(int newVal) { numSaved = newVal; }
void LHT::setNumSavedOrDeleted(int newVal) {
  numSavedOrDeleted = newVal;
}
// void LinearHashTable::setD(int newVal) { d = newVal; }


/* Find an entry in the hash table. */
Stock LHT::find(Stock entry) {

  // first, find the appropriate index
  int i = hash(entry.getShortName());
  // prepare a counter for the linear probing
  int step = 0;

  // if we reach en empty index,  we know that the element
  // we want is not in the table
  while (table[i].getEmpty() != EMPTY) {

    if (table[i].getDeleted() != DEL &&
        table[i].getShortName() == entry.getShortName())
      return table[i];

    i = (i == SIZE - 1) ? 0 : i + 1; // quadratic probing here
  }
  // should be an empty Stock; TODO check this
  return table[i];
}

bool LHT::add(Stock entry) {
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

bool LHT::remove(Stock entry) {
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

int LHT::hash(std::string shortName) {
  int sum = 0;
  for (int i = 0; i < shortName.length(); i++)
    sum = sum + int(shortName[i]);
  return sum % SIZE;
  // return ((unsigned)(entry % HASH_MODULUS) % SIZE);
}

void LHT::printTable() {
  for (int i = 0; i < SIZE; i++) {
    std::cout << "Entry " << i << ": ";
    table[i].printStock();
  }
  std::cout << "\n";
}
