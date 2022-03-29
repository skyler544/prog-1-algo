#include "StockNode.h"
#include <iomanip>
#include <iostream>

StockNode::StockNode() {}
// StockNode::StockNode(std::tm d, double o, double h, double l,
//                      double c, double ac, int v) {
StockNode::StockNode(std::string d, std::string o, std::string h, std::string l,
                     std::string c, std::string v, std::string ac) {
  date = d;
  open = o;
  high = h;
  low = l;
  close = c;
  adj_close = ac;
  volume = v;

  next = NULL;
}

void StockNode::printStockNode() {
  std::cout << "====================\n";
  std::cout << "Date: " << date << "\n";
//  std::cout << "Date: " << std::put_time(&date, "%d.%m.%Y") << "\n";
  std::cout << "Open: " << open << "\n";
  std::cout << "High: " << high << "\n";
  std::cout << "Low: " << low << "\n";
  std::cout << "Close: " << close << "\n";
  std::cout << "Adjusted Close: " << adj_close << "\n";
  std::cout << "Volume: " << volume << "\n";
}

StockNode *StockNode::getNext() { return next; }
void StockNode::setNext(StockNode *n) { next = n; }
