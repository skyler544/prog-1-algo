#ifndef STOCKNODE_H_
#define STOCKNODE_H_
#include <string>
#include <ctime>

class StockNode {
private:
  std::tm date;
  double open;
  double high;
  double low;
  double close;
  double adj_close;
  int volume;

  StockNode *next;

public:
  StockNode(std::tm d, double o, double h, double l,
            double c, double ac, int v);

  void printStockNode();

  StockNode *getNext();
  void setNext(StockNode *n);
};

#endif // STOCKNODE_H_
