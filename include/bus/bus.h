#pragma once
#include <string>
#include <iostream>

// TODO: а) список автобусов для заданного номера маршрута;
// TODO: б) список автобусов, которые эксплуатируются больше 10 лет;
// TODO: в) список автобусов, пробег у которых больше 10 000 км.

/// Struct for person
struct person {
  std::string surname;
  std::string
      initials; // Has first letters of name and patronymic (like: "I.V")

  friend std::ostream &operator<<(std::ostream &os, const person &p);

  person() = default;
  person(const std::string &surname, const std::string &initials);
};

// Struct for transport
struct transport {
  std::string brand;
  int year;    // Year of commencemnet of operation
  int mileage; // Mileage in km/h

  transport(const std::string &brand, int year, int mileage);
};

class Bus {
public:
  /**
   * @brief Create bus
   *
   * @param brand     Bus's brand
   * @param year      Bus's year
   * @param mileage   Bus's mileage
   */
  Bus(const std::string &brand, int year, int mileage, int route,
      const std::string &surname, const std::string &initials);

  /// Outputs bus info to console
  void display() const;

  void setDriver(const std::string &surname, const std::string &initials);
  const person &getDriver() const;

  void setNumber(int number);
  int getNumber() const;

  void setRoute(int numRoute);
  int getRoute() const;

  int getYear() const;

  int getMileage() const;

private:
  person driver; // Driver full name
  transport own; // Transport characteristics
  int number = -1;
  int nRoute = -1; // Number of route
};