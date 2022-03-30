#include "LHT.h"
#include "Stock.h"
#include <iostream>

// are these methods needed? it seems like this will never be used
void LHT::setNumSaved(int newVal) { numSaved = newVal; }
void LHT::setNumSavedOrDeleted(int newVal) { numSavedOrDeleted = newVal; }
// void LinearHashTable::setD(int newVal) { d = newVal; }

// TODO add a condition that stops the search after x amount of time
// TODO add a condition that prevents the table from becoming overly full
// TODO do we need that condition if the table is large enough?

/* Find an entry in the hash table. */
Stock LHT::find(Stock entry) {

  // first, find the appropriate index
  int i = hash(entry.getAbbreviation());
  // prepare a counter and a step size for the linear probing
  int step = 0;
  int base = i;

  // std::cout << "i: " << i << "\n";

  // if we reach en empty index,  we know that the element
  // we want is not in the table
  while (table[i].getEmpty() != EMPTY && step < LIMIT) {

    // we can take advantage of short circuit evaluation to
    // condense this logic. in the case that the current
    // index has been deleted, there's no need to evaluate
    // the right hand side of the && operator, so it simply
    // isn't evaluated.
    if (table[i].getDeleted() != DEL &&
        table[i].getAbbreviation() == entry.getAbbreviation()) {
      // found the element; return it
      return table[i];
    }

    // the element hasn't been found yet, so we'll use
    // quadratic probing to look for another place to put it
    step++;
    i = (base + (step * step)) % SIZE;

    // std::cout << "i probe: " << i << "\n";
  }
  // std::cout << "i after failing find: " << i << "\n";
  // table[i].printStock();
  // std::cout << table[i].getDeleted() << "|" << table[i].getEmpty() << "\n";
  // return an empty Stock
  return table[i];
}

/* Add a new Stock to the table. */
bool LHT::add(Stock entry) {

  // std::cout << "made it\n";
  // Don't try to add a duplicate element
  if (find(entry).getEmpty() != EMPTY) {
    // std::cout << find(entry).getEmpty();
    return false;
  }

  // find the appropriate index
  int i = hash(entry.getAbbreviation());
  // prepare a counter and a step size for the linear probing
  int step = 0;
  int base = i;

  // std::cout << table[i].getEmpty() << table[i].getDeleted();

  // if the position is occupied, we use quadratic
  // probing to look for another place to put it
  while (table[i].getEmpty() != EMPTY && table[i].getDeleted() != DEL) {
    step++;
    i = (base + (step * step)) % SIZE;
  }

  // increment the counters...
  // is this check even necessary? the logic is clear enough:
  // if we made it through the while loop up above, then there
  // should be no question as to whether we found a place to
  // insert the new entry; we should just insert it. IF however,
  // the search took too long and we couldn't find a free position,
  // we won't add the entry and will leave this function by returning
  // false. Both cases make this boolean check redundant.

  // TODO: refactor this piece of shit

  if (table[i].getEmpty() == EMPTY) {
    numSavedOrDeleted++;
  }

  numSaved++;
  table[i] = entry;
  table[i].setEmpty(1);
  return true;
}

/* Remove an entry from the table. */
bool LHT::remove(Stock entry) {

  // find the appropriate index
  int i = hash(entry.getAbbreviation());
  // prepare a counter and a step size for the quadratic probing
  int step = 0;
  int base = i;

  // look for the entry until ...
  // TODO: add a condition to stop after a long (?) time
  while (table[i].getEmpty() != EMPTY && step < LIMIT) {

    Stock curr = table[i];

    if (curr.getDeleted() != DEL &&
        entry.getAbbreviation() == curr.getAbbreviation()) {

      // we found the element we want to remove, so
      // go ahead and delete it.
      // TODO: think about the details of the delete function
      table[i].setDeleted();
      numSaved--;

      return true;
    }

    // quadratic probing; see comments in other functions
    step++;
    i = (base + (step * step)) % SIZE;
  }

  // didn't find it, give up and return false
  return false;
}

// hash the given word by converting each letter
// to an int and then adding them together.
// TODO: how much should this be truncated? not at all?
// TODO: does having a prime number as the table length
//       and quadratic probing ensure that even if all
//       the resulting indexes were below 200 or something,
//       even large indexes like 790 are feasibly addressed?
//       does this lead to too much clustering?
int LHT::hash(std::string abbreviation) {
  int sum = 0;
  for (long unsigned int i = 0; i < abbreviation.length(); i++) {
    sum = sum + int(abbreviation[i]);
  }
  return sum % SIZE;
}

void LHT::printTable() {
  for (int i = 0; i < SIZE; i++) {
    std::cout << "====================\n";
    std::cout << "Entry " << i << ": ";
    std::cout << "\n";
    table[i].printStock();
  }
  // std::cout << "\n";
}
