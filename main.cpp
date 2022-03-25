#include "LinearHashTable.h"
#include <iostream>

int main(int argc, char *argv[]) {

  LinearHashTable table;
  // table.setD(0);
  table.setNumSaved(0);
  table.setNumSavedOrDeleted(0);

  table.add(41025703);
  table.add(41025717);
  table.add(41025749);
  table.add(41025773);

  table.printTable();

  return 0;
}
