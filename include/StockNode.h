#ifndef STOCKNODE_H_
#define STOCKNODE_H_
#include <string>

class StockNode {
private:
  std::string date;
  std::string open;
  std::string high;
  std::string low;
  std::string close;
  std::string volume;
  std::string adj_close;
  StockNode *next;

public:
  StockNode(std::string d, std::string o, std::string h, std::string l,
            std::string c, std::string v, std::string ac);
  void printStockNode();
  /* void setVal(int v); */
  StockNode *getNext();
  void setNext(StockNode *n);
};

#endif // STOCKNODE_H_
