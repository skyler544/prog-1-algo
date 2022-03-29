#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <iostream>

class Controller {
public:
    void menu();
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
