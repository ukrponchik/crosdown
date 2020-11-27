#include "bus.h"
std::ostream &operator<<(std::ostream &os, const person &p) {
  os << p.surname << " " << p.initials;
  return os;
}

transport::transport(const std::string &brand, int year, int mileage)
    : brand(brand), year(year), mileage(mileage) {}

person::person(const std::string &surname, const std::string &initials)
    : surname(surname), initials(initials) {}

Bus::Bus(const std::string &brand, int year, int mileage, int route,
         const std::string &surname, const std::string &initials)
    : own(brand, year, mileage), driver(surname, initials), nRoute(route) {}

void Bus::display() const {
  std::cout << "Bus: " << getNumber() << ", " << getRoute() << std::endl;
  std::cout << "-------------------------------------------" << std::endl;
  std::cout << "Driver: " << getDriver() << std::endl;
  std::cout << "Characters: " << own.brand << ", year: " << own.year << ", "
            << own.mileage << " km/h" << std::endl;
  std::cout << std::endl;
}

void Bus::setDriver(const std::string &surname, const std::string &initials) {
  driver.surname = surname;
  driver.initials = initials;
}

const person &Bus::getDriver() const { return driver; }

void Bus::setNumber(int number) { this->number = number; }

int Bus::getNumber() const { return number; }

void Bus::setRoute(int numRoute) { nRoute = numRoute; }

int Bus::getRoute() const { return nRoute; }

int Bus::getYear() const { return own.year; }

int Bus::getMileage() const { return own.mileage; }

std::istream &operator>>(std::istream &is, person &p) {
  is >> p.surname >> p.initials;
  return is;
}

std::istream &operator>>(std::istream &is, transport &t) {
  is >> t.brand >> t.mileage >> t.year;
  return is;
}

std::istream &operator>>(std::istream &is, Bus &b) {
  is >> b.own >> b.driver >> b.number >> b.nRoute;
  return is;
}

std::ostream &operator<<(std::ostream &os, const Bus &b) {
  os << "Bus: " << b.getNumber() << ", " << b.getRoute() << std::endl;
  os << "-------------------------------------------" << std::endl;
  os << "Driver: " << b.getDriver() << std::endl;
  os << "Characters: " << b.own.brand << ", year: " << b.own.year << ", "
     << b.own.mileage << " km/h" << std::endl;
  os << std::endl;
}
