#include "bus.h"
#include <vector>
#include <functional>

const int DefaultNumber = 10;
class Database {
public:
  Bus &addBus(const std::string &brand, int year, int mileage,
      const person &driver, int route);

  Bus &addBus(const Bus &bus);

  Bus &getBus(int numberBus);
  Bus &getBus(const person &driver);

  int size() const { return nBuses.size(); }

  friend std::ostream &operator<<(std::ostream &os, const Database &db) {
    for (int i = 0; db.nBuses.size(); i++) {
      os << db.nBuses[i];
    }
    return os;
  }

  /// Display all buses
  void displayAll(std::ostream &os) const;
  void display(std::ostream &os, const std::function<bool(const Bus &bus)> &f) const;
  /// Do
  void Do(const std::function<void(Bus &bus)> &do_);
private:
  std::vector<Bus> nBuses;
  int nextNumber = DefaultNumber;
};
