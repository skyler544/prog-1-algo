#include "Controller.h"

void Controller::menu() {
    std::cout << "Welcome to your personal stock controller.\n"
              << "Enter one of the following numbers in order to proceed: \n"
              << "1. ADD: Add a stock to your portfolio.\n"
              << "2. DEL: Delete a stock from your portfolio.\n"
              << "3. IMPORT: Import the stock history of the last month from a file.\n"
              << "4. SEARCH: Locate a stock in the portfolio.\n"
              << "5. PLOT: Graph the stock performance from the past 30 days.\n"
              << "6. SAVE: Save your portfolio to a file.\n"
              << "7. LOAD: Load your portfolio from a file.\n"
              << "8. QUIT: Leave the stock controller.\n";

}

bool Controller::add() { return false; }
bool Controller::del() { return false; }
bool Controller::import() { return false; }
bool Controller::search() { return false; }
bool Controller::plot() { return false; }
bool Controller::save() { return false; }
bool Controller::load() { return false; }
bool Controller::quit() { return false; }
