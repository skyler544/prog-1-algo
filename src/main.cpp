#include "Controller.h"
#include "LHT.h"
#include "Stock.h"
#include <iostream>

int main(int argc, char *argv[]) {

  LHT table;

  Controller controller;

  // std::cout << sizeof(Stock);

  // Stock test;

  // test.readFile("aux/MSFT.csv");

  controller.menu();

  // table.add(41025703);
  // table.add(41025717);
  // table.add(41025749);
  // table.add(41025773);

  // table.printTable();

  return 0;
}
