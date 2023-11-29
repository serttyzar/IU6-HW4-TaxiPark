// classes.h
// Created by sertt on 26.11.2023.
//

#ifndef HW4_CLASSES_H
#define HW4_CLASSES_H

#include <iostream>
#include <string>
#include <unordered_map>

class TaxiCar {
private:
    std::string car_number; // only rus number, format A000AA
    unsigned short region{};
    unsigned short number_passenger_seats{};
    bool have_child_seat{};
    bool is_free{};
    void normilize();

public:

    TaxiCar() = default;
    TaxiCar(std::string car_number_, unsigned short region_, unsigned short number_passenger_seats_,
            bool have_child_seat_ = false,
            bool is_free_ = true);

    std::string getCarNumber() const;

    unsigned short getRegion() const;

    unsigned short getNumberPassengerSeats() const;

    bool haveChildSeat() const;

    bool isFree() const;

    void display() const;

    bool checkCarForOrder(unsigned short number_passenger, bool have_child) const;

    bool takeOrder(unsigned short number_passenger, bool have_child);

    bool finalizeOrder();
};

class TaxiPark {
private:
    std::unordered_map<std::string, TaxiCar> cars;

public:
    TaxiPark() = default;

    std::unordered_map<std::string, TaxiCar> getTaxiParkCars() const;

    void addCar(const TaxiCar &car);

    void display() const;

    std::string getSuitableCar(unsigned short number_passenger, bool have_child) const;

    void takeOrder(unsigned short number_passenger, bool have_child);

    void takeOrder(const std::string &number_, unsigned short number_passenger, bool have_child);

    void finalizeOrder(const std::string &number_);
};

#endif //HW4_CLASSES_H
