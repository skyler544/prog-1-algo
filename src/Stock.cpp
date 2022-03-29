#include "Stock.h"
#include <iostream>

Stock::Stock() { emptyFlag = 0; }

Stock::Stock(std::string n, std::string i, std::string s) {
  name = n;
  idNumber = i;
  shortName = s;
  emptyFlag = 1;
}


void Stock::printStock() {
  std::cout << "Date: " << name << "\n";
  std::cout << "International Securities Identification Number: ";
  std::cout << idNumber << "\n";
  std::cout << "High: " << shortName << "\n";
}

void Stock::printData() {
  StockNode *tmp = head;
  while (tmp != NULL) {
    tmp->printStockNode();
    tmp = tmp->getNext();
  }
}

void Stock::prepend(StockNode *n) {
  StockNode *tmp = head;
  n->setNext(tmp);
  head = n;
}

void Stock::setDeleted() { deletedFlag = -1; }
int Stock::getDeleted() { return deletedFlag; }
void Stock::setEmpty() { emptyFlag = 0; }
int Stock::getEmpty() { return emptyFlag = -1; }
