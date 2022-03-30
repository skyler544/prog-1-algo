#include "Controller.h"
#include "Stock.h"

void Controller::menu() {
  bool loop = true;
  while (loop) {
    std::cout << "Welcome to your personal stock controller.\n"
              << "Enter one of the following numbers in order to proceed: \n"
              << "1. ADD: Add a stock to your portfolio.\n"
              << "2. DEL: Delete a stock from your portfolio.\n"
              << "3. IMPORT: Import the stock history of the last month from a "
                 "file.\n"
              << "4. SEARCH: Locate a stock in the portfolio.\n"
              << "5. PLOT: Graph the stock performance from the past 30 days.\n"
              << "6. SAVE: Save your portfolio to a file.\n"
              << "7. LOAD: Load your portfolio from a file.\n"
              << "8. QUIT: Leave the stock controller.\n";

    int input;
    std::cin >> input;

    switch (input) {
    case (1):
      confirmation(loop = add(false, ""));
      break;
    case (2):
      confirmation(loop = del());
      break;
    case (3):
      confirmation(loop = import());
      break;
    case (4):
      confirmation(loop = search(false, ""));
      break;
    case (5):
      confirmation(loop = plot());
      break;
    case (6):
      confirmation(loop = save());
      break;
    case (7):
      confirmation(loop = load());
      break;
    case (8):
      loop = quit();
      break;
    }
  }
}

void Controller::confirmation(bool result) {
  result ? std::cout << "Success\n" : std::cout << "Failure\n";
}

bool Controller::add(bool withCSV, std::string file) {

  std::string name, isin, abbreviation;

  std::cout << "Enter the name of the stock: ";
  std::cin >> name;
  std::cout << "Enter the ISIN (WKN): ";
  std::cin >> isin;
  std::cout << "Enter the abbreviated name: ";
  std::cin >> abbreviation;

  Stock newEntry(name, isin, abbreviation);

  if (withCSV) {
    newEntry.readFile(file);
    newEntry.printData();
  }

  table.add(newEntry);
  table.printTable();

  return true;
}

bool Controller::del() { return false; }

bool Controller::import() {
  std::string file;
  std::cout
      << "Enter the filename, including the path and the file extension:\n";
  std::cout << "Example: aux/MSFT.csv\n";
  std::cin >> file;

  std::cout << "Would you like to add this data to an existing entry?\n";
  std::cout << "y / n\n";
  char choice;
  std::cin >> choice;

  bool result;
  if (choice == 'y') {
    result = search(true, file);
  } else {
    result = add(true, file);
  }
  return result;
}

bool Controller::search(bool withCSV, std::string file) {
  std::string abbreviation;
  std::cout << "Enter the abbreviated name: ";
  std::cin >> abbreviation;

  Stock result = table.find(Stock("", "", abbreviation));

  bool found = result.getEmpty() != 0 ? true : false;

  if (found) {
    result.printStock();
  }
  if (withCSV && found) {
    result.readFile(file);
    result.printData();
  }

  return found;
}

bool Controller::plot() { return false; }
bool Controller::save() { return false; }
bool Controller::load() { return false; }
bool Controller::quit() {
  std::cout << "Goodbye\n";
  return false;
}
