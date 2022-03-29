#ifndef STOCKNODE_H_
#define STOCKNODE_H_
#include <ctime>
#include <string>

class StockNode {
private:
  // std::tm date;
  // double open;
  // double high;
  // double low;
  // double close;
  // double adj_close;
  // int volume;
  std::string date;
  std::string open;
  std::string high;
  std::string low;
  std::string close;
  std::string volume;
  std::string adj_close;

  StockNode *next;

public:
  StockNode();
  StockNode(std::string d, std::string o, std::string h, std::string l,
            std::string c, std::string v, std::string ac);
  // StockNode(std::tm d, double o, double h, double l, double c, double ac, int
  // v);

  void printStockNode();

  StockNode *getNext();
  void setNext(StockNode *n);
};

#endif // STOCKNODE_H_
