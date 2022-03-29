#include "Stock.h"
#include "StockNode.h"
#include <iostream>
#include <fstream>

Stock::Stock() { emptyFlag = 0; }

Stock::Stock(std::string n, std::string i, std::string s) {
  name = n;
  idNumber = i;
  shortName = s;
  emptyFlag = 1;
}

bool loadData(std::string file) { return false; }

void Stock::printStock() {
  std::cout << "Date: " << name << "\n";
  std::cout << "ISIN (WKN): ";
  std::cout << idNumber << "\n";
  std::cout << ": " << shortName << "\n";
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

void Stock::readFile(std::string fileName) {
  std::ifstream inf(fileName);

  int count = 0;

  while (!inf.eof()) {
    count++;
  }

  for (int i = count - 30; !inf.eof() && i < 30; i++) {
    std::string date, open, high, low, close, adj_close, volume;
    getline(inf, date, ',');
    getline(inf, open, ',');
    getline(inf, high, ',');
    getline(inf, low, ',');
    getline(inf, close, ',');
    getline(inf, adj_close, ',');
    getline(inf, volume, '\n');

    StockNode tmp(date, open, high, low, close, adj_close, volume);
    kursdaten[i] = tmp;
  }
}

std::string Stock::getShortName() { return shortName; }
void Stock::setDeleted() { deletedFlag = -1; }
int Stock::getDeleted() { return deletedFlag; }
void Stock::setEmpty() { emptyFlag = 0; }
int Stock::getEmpty() { return emptyFlag = -1; }
