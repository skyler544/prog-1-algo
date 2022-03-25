#include "LinearHashTable.h"
#include <iostream>

int main(int argc, char *argv[]) {

  LinearHashTable table;
  // table.setD(0);
  table.setN(0);
  table.setQ(0);

  table.add(41025703);
  table.add(41025717);
  table.add(41025749);
  table.add(41025773);

  table.printTable();

  return 0;
}
