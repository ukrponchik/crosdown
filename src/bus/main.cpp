#include "database.h"

void clearDisplay();
void pause();
int displayMenu();
void addBus(Database &db);
void displayRoute(Database &db);
void displayFromYear(Database &db);
void displayMileage(Database &db);

int main() {
  Database buses;
  bool done = false;

  while (!done) {
    int selection = displayMenu();
    switch (selection) {
    case 0:
      done = true;
      break;
    case 1:
      addBus(buses);
      break;
    case 2:
      buses.displayAll();
      break;
    case 3:
      displayFromYear(buses);
      break;
    case 4:
      displayRoute(buses);
      break;
    case 5:
      displayMileage(buses);
      break;
    default:
      std::cerr << "Unknown command." << std::endl;
      break;
    }
    if (!done)
      pause();
  }

  return 0;
}

void clearDisplay() {
#ifndef __linux__
  system("cls");
#else
  system("clear");
#endif
}

void pause() {
#ifndef __linux__
  system("pause");
#else
  std::cout << "Press to continue..." << std::endl;
  char c;
  std::cin >> c;
#endif
}

int displayMenu() {
  using namespace std;
  int selection;

  clearDisplay();
  cout << endl;
  cout << "Bus Database" << endl;
  cout << "--------------------" << endl;
  cout << "1) Add a new bus" << endl;
  cout << "2) List all buses" << endl;
  cout << "3) List all buses depends on year" << endl;
  cout << "4) List all buses depends on route" << endl;
  cout << "5) List all buses depends on mileage" << endl;
  cout << "0) Quit" << endl;
  cout << endl;
  cout << "---> ";
  cin >> selection;

  return selection;
}

void addBus(Database &db) {
  std::string brand;
  int year, mileage, route;
  person driver;

  std::cout << "Brand? ";
  std::cin >> brand;

  std::cout << "Year: ";
  std::cin >> year;

  std::cout << "Mileage: ";
  std::cin >> mileage;

  std::cout << "Driver's surname? ";
  std::cin >> driver.surname;

  std::cout << "Driver's initials? ";
  std::cin >> driver.initials;

  std::cout << "Num route: ";
  std::cin >> route;

  auto b = db.addBus(brand, year, mileage, driver, route);
}

void displayRoute(Database &db) {
  int route;

  std::cout << "Number route: ";
  std::cin >> route;

  db.display([&route](const Bus &b) { return b.getRoute() == route; });
}

void displayFromYear(Database &db) {
  int year;

  std::cout << "Year: ";
  std::cin >> year;

  db.display([&year](const Bus &b) { return 2020 - b.getYear() > year; });
}

void displayMileage(Database &db) {
  int mileage;

  std::cout << "Mileage: ";
  std::cin >> mileage;

  db.display([&mileage](const Bus &b) { return b.getMileage() > mileage; });
}
