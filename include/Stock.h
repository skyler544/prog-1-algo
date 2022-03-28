#ifndef STOCK_H_
#define STOCK_H_
#include "StockNode.h"
#include <string>

class Stock {
private:
  std::string name;
  std::string idNumber;
  std::string shortName;

  int deletedFlag; // -1 for deleted stock
  int emptyFlag; // 0 for an empty stock

  StockNode *head;

public:
  Stock();
  Stock(std::string n, std::string i, std::string s);
  StockNode *getHead();
  void setDeleted();
  int getDeleted();
  void setEmpty();
  int getEmpty();
  std::string getShortName();
  void setHead(StockNode *n);
  void prepend(StockNode *n);
  void printList();
  void printStock();
};

#endif // STOCK_H_
