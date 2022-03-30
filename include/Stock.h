#ifndef STOCK_H_
#define STOCK_H_
#include "StockNode.h"
#include <string>

class Stock {
private:
  std::string name;
  std::string isin; // International Securities Identification Number (WKN)
  std::string abbreviation;

  int deletedFlag; // -1 for deleted stock
  int emptyFlag;   // 0 for an empty stock

  StockNode kursdaten[30];

  StockNode *head;

public:
  Stock();
  Stock(std::string n, std::string i, std::string s);

  StockNode *getHead();
  std::string getAbbreviation();
  void setHead(StockNode *n);
  void prepend(StockNode *n);
  void append(StockNode *n);

  void readFile(std::string fileName);
  void printData();
  void printStock();

  void setDeleted();
  int getDeleted();
  void setEmpty(int val);
  int getEmpty();
};

#endif // STOCK_H_
