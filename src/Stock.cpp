#include "Stock.h"
#include "StockNode.h"
#include <fstream>
#include <iostream>

Stock::Stock() {
  name = "";
  idNumber = "";
  shortName = "";
  deletedFlag = 1;
  emptyFlag = 0;
}

Stock::Stock(std::string n, std::string i, std::string s) {
  name = n;
  idNumber = i;
  shortName = s;
  emptyFlag = 1;
  deletedFlag = 1;
}

bool loadData(std::string file) { return false; }

void Stock::printStock() {
  std::cout << "Date: " << name << "\n";
  std::cout << "ISIN (WKN): ";
  std::cout << idNumber << "\n";
  std::cout << "Abbreviation: " << shortName << "\n";
}

void Stock::printData() {
  StockNode *tmp = head;
  while (tmp != NULL) {
    tmp->printStockNode();
    tmp = tmp->getNext();
  }
}

void Stock::append(StockNode *n) {
  if (head == NULL) {
    head = n;
  } else {
    StockNode *tmp = head;
    while (tmp->getNext() != NULL) {
      tmp = tmp->getNext();
    }
    tmp->setNext(n);
  }
}

void Stock::prepend(StockNode *n) {
  if (head == NULL) {
    head = n;
  } else {
    StockNode *tmp = head;
    n->setNext(tmp);
    head = n;
  }
}

void Stock::readFile(std::string fileName) {
  std::ifstream inf;
  inf.open(fileName);

  int count = 0;
  std::string line;

  while (!inf.eof()) {
    getline(inf, line);
    count++;
  }

  inf.close();

  inf.open(fileName);

  int mark = 0;

  while (mark < count - 30) {
    getline(inf, line);
    mark++;
  }

  for (int i = 0; !inf.eof(); i++) {
    std::string date, open, high, low, close, adj_close, volume;
    getline(inf, date, ',');
    getline(inf, open, ',');
    getline(inf, high, ',');
    getline(inf, low, ',');
    getline(inf, close, ',');
    getline(inf, adj_close, ',');
    getline(inf, volume, '\n');

    // StockNode *tmp = new StockNode(date, open, high, low, close, adj_close, volume);
    prepend(new StockNode(date, open, high, low, close, adj_close, volume));

    // StockNode tmp(date, open, high, low, close, adj_close, volume);
    // kursdaten[i] = tmp;
    // kursdaten[i].printStockNode();
  }

  printData();
}

std::string Stock::getShortName() { return shortName; }
void Stock::setDeleted() { deletedFlag = -1; }
int Stock::getDeleted() { return deletedFlag; }
void Stock::setEmpty() { emptyFlag = 0; }
int Stock::getEmpty() { return emptyFlag; }
