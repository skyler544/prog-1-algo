#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LHT.h"
#include <iostream>

class Controller {
private:
  LHT table;

public:
  void menu();
  void confirmation(bool result);

  bool add();
  bool del();
  bool import();
  bool search();
  bool plot();
  bool save();
  bool load();
  bool quit();
};

#endif // CONTROLLER_H_
