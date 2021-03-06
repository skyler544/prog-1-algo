#include "Stock.h"
#include "StockNode.h"
#include <fstream>
#include <iostream>

Stock::Stock() {
  name = "";
  isin = "";
  abbreviation = "";
  deletedFlag = 1;
  emptyFlag = 0;
}

Stock::Stock(std::string n, std::string i, std::string s) {
  name = n;
  isin = i;
  abbreviation = s;
  emptyFlag = 1;
  deletedFlag = 1;
}


void Stock::printStock() {
  std::cout << "====================\n";
  std::cout << "        Name: " << name << "\n";
  std::cout << "  ISIN (WKN): ";
  std::cout << isin << "\n";
  std::cout << "Abbreviation: " << abbreviation << "\n";
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

  // TODO: figure out how to remove the weekends

  for (int i = 0; !inf.eof(); i++) {
    std::string date, open, high, low, close, adj_close, volume;
    getline(inf, date, ',');
    getline(inf, open, ',');
    getline(inf, high, ',');
    getline(inf, low, ',');
    getline(inf, close, ',');
    getline(inf, adj_close, ',');
    getline(inf, volume, '\n');

    // StockNode *tmp = new StockNode(date, open, high, low, close, adj_close,
    // volume);
    prepend(new StockNode(date, open, high, low, close, adj_close, volume));

    // StockNode tmp(date, open, high, low, close, adj_close, volume);
    // kursdaten[i] = tmp;
    // kursdaten[i].printStockNode();
  }

  inf.close();
  printData();
}

std::string Stock::getAbbreviation() { return abbreviation; }
void Stock::setDeleted() { deletedFlag = -1; }
int Stock::getDeleted() { return deletedFlag; }
void Stock::setEmpty(int val) { emptyFlag = val; }
int Stock::getEmpty() { return emptyFlag; }
