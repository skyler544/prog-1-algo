#ifndef STOCK_H_
#define STOCK_H_
#include "StockNode.h"
#include <string>

class Stock {
private:
  std::string name;
  std::string idNumber;
  std::string shortName;
  int deletedFlag;
  StockNode *head;

public:
  Stock(std::string n, std::string i, std::string s);
  StockNode *getHead();
  void setDeleted();
  int getDeleted();
  void setHead(StockNode *n);
  void prepend(StockNode *n);
  void printList();
};

#endif // STOCK_H_
