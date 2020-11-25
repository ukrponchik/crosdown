#include "database.h"
#include <stdexcept>

Bus &Database::addBus(const std::string &brand, int year, int mileage,
  const person &driver, int route) {
  Bus b(brand, year, mileage, route, driver.surname, driver.initials);
  b.setNumber(nextNumber++);
  nBuses.push_back(b);
  return nBuses[nBuses.size() - 1];
}

Bus &Database::getBus(int numberBus)  {
  for (auto &bus : nBuses) {
    if (bus.getNumber() == numberBus)
      return bus;
  }
  throw std::logic_error("No bus found.");
}

void Database::displayAll() const {
  for (const auto &bus : nBuses) {
    bus.display();
  }
}

void Database::display(const std::function<bool(const Bus &bus)> &f) const {
  for (const auto &bus : nBuses) {
    if (f(bus)) {
      bus.display();
    }
  }
}

void Database::Do(const std::function<void(Bus &bus)> &do_) {
  for (auto &bus : nBuses) {
    do_(bus);
  }
}

Bus &Database::addBus(const Bus &bus) {
  nBuses.push_back(bus);
  return nBuses[nBuses.size() - 1];
}