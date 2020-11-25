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

  /// Display all buses
  void displayAll() const;
  void display(const std::function<bool(const Bus &bus)> &f) const;
  /// Do 
  void Do(const std::function<void(Bus &bus)> &do_);
private:
  std::vector<Bus> nBuses;
  int nextNumber = DefaultNumber;
};