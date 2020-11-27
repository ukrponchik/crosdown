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

void Database::displayAll(std::ostream &os) const {
  if (nBuses.size() == 0)
      return;
  for (const auto &bus : nBuses)
  {
      os << bus;
  }
}

void Database::display(std::ostream &os, const std::function<bool(const Bus &bus)> &f) const {
  for (const auto &bus : nBuses) {
    if (f(bus)) {
        os << bus;
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
