#include "database.h"
#include <fstream>

std::ifstream in{"data.txt"};
std::ofstream outf{"out.txt", std::ios::out | std::ios::trunc};

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

  while (!in.eof()) {
    Bus b{};
    in >> b;
    buses.addBus(b);
  }
  in.close();

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
      // outf.close();
      // outf.open("out.txt", std::ios::out | std::ios::trunc);
      buses.displayAll(std::cout);
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
    if (!done) {
      pause();
    }
  }

  buses.displayAll(outf);
  outf.close();
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
  std::fflush(stdin);
  std::getchar();
  std::getchar();
#endif
}

int displayMenu() {
  using namespace std;
  int selection;

  // FIXME: Після команди "clear" у дебагері, появляється помилка term not set
  // @see .gdbinit
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
  std::ofstream f3{"route.txt"};

  std::cout << "Number route: ";
  std::cin >> route;

  db.display(f3, [&route](const Bus &b) { return b.getRoute() == route; });
  f3.close();
  db.display(std::cout,
             [&route](const Bus &b) { return b.getRoute() == route; });
}

void displayFromYear(Database &db) {
  int year;
  std::ofstream f1{"year.txt"};

  std::cout << "Year: ";
  std::cin >> year;

  db.display(f1, [&year](const Bus &b) { return 2020 - b.getYear() > year; });
  f1.close();
  db.display(std::cout,
             [&year](const Bus &b) { return 2020 - b.getYear() > year; });
}

void displayMileage(Database &db) {
  int mileage;
  std::ofstream f2{"mileage.txt"};

  std::cout << "Mileage: ";
  std::cin >> mileage;

  db.display(f2, [&mileage](const Bus &b) { return b.getMileage() > mileage; });
  f2.close();
  db.display(std::cout,
             [&mileage](const Bus &b) { return b.getMileage() > mileage; });
}
