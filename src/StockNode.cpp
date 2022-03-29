#include "StockNode.h"
#include <iostream>

StockNode::StockNode(std::string d, std::string o, std::string h, std::string l,
                     std::string c, std::string v, std::string ac) {
  date = d;
  open = o;
  high = h;
  low = l;
  close = c;
  volume = v;
  adj_close = ac;

  next = NULL;
}

void StockNode::printStockNode() {
  std::cout << "====================\n";
  std::cout << "Date: " << date << "\n";
  std::cout << "Open: " << open << "\n";
  std::cout << "High: " << high << "\n";
  std::cout << "Low: " << low << "\n";
  std::cout << "Close: " << close << "\n";
  std::cout << "Volume: " << volume << "\n";
  std::cout << "Adjusted Close: " << adj_close << "\n";
}

StockNode *StockNode::getNext() { return next; }
void StockNode::setNext(StockNode *n) { next = n; }
