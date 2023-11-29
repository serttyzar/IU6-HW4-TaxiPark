//
// Created by sertt on 26.11.2023.
//

#include <string>
#include "classes.h"

// TaxiCar functions

void TaxiCar::normilize() {
    if (car_number.size() != 6) { ;
    }
    car_number.resize(6);
    if (65 > car_number[0] || car_number[0] > 90) {
        std::cout << "yes";
    }
    for (size_t i = 1; i < 4; ++i) {
        if (48 > car_number[i] || car_number[i] > 57) { ;
        }
    }
    if (65 > car_number[4] || car_number[4] > 90) {
        std::cout << "yes";
    }
    if (65 > car_number[5] || car_number[5] > 90) {
        std::cout << "yes";
    }
    if (region > 199) {

    }

}

bool TaxiCar::haveChildSeat() const {
    return have_child_seat;
}

bool TaxiCar::isFree() const {
    return is_free;
}

unsigned short TaxiCar::getNumberPassengerSeats() const {
    return number_passenger_seats;
}

unsigned short TaxiCar::getRegion() const {
    return region;
}

std::string TaxiCar::getCarNumber() const {
    return car_number;
}

void TaxiCar::display() const {
    std::cout << "--------Car " << car_number << " information--------"
              << "\nCar region:\t\t\t" << region
              << "\nNumber of passenger seats:\t" << number_passenger_seats
              << "\nChild seat:\t\t\t" << (have_child_seat ? "Yes" : "No")
              << "\nCar is free:\t\t\t" << (is_free ? "Yes" : "No") << std::endl;
}

bool TaxiCar::takeOrder(unsigned short number_passenger, bool have_child) {
    if (checkCarForOrder(number_passenger, have_child)) {
        is_free = false;
        return true;
    } else {
        return false;
    }

}

bool TaxiCar::finalizeOrder() {
    if (is_free) {
        return false;
    }
    is_free = true;
    return true;
}

bool TaxiCar::checkCarForOrder(unsigned short number_passenger, bool have_child) const {
    // return true if car parameters satisfy the order conditions
    return (is_free && number_passenger <= number_passenger_seats && (have_child && have_child_seat || !have_child));
}

TaxiCar::TaxiCar(std::string car_number_, unsigned short region_, unsigned short number_passenger_seats_,
                 bool have_child_seat_, bool is_free_) : car_number(std::move(car_number_)), region(region_),
                                                         number_passenger_seats(number_passenger_seats_),
                                                         have_child_seat(have_child_seat_), is_free(is_free_) {
    normilize();
}


// TaxiPark functions

std::unordered_map<std::string, TaxiCar> TaxiPark::getTaxiParkCars() const {
    return cars;
}

void TaxiPark::addCar(const TaxiCar &car) {
    std::cout << "Adding car with number " << car.getCarNumber() << std::endl;
    cars[car.getCarNumber()] = car;
}

void TaxiPark::display() const {
    std::cout << std::endl;
    for (const auto &[number, car]: cars) {
        car.display();
    }
    std::cout << std::endl;
}

std::string TaxiPark::getSuitableCar(unsigned short number_passenger, bool have_child) const {
    for (auto &[number, car]: cars) {
        if (car.checkCarForOrder(number_passenger, have_child)) {
            return number;
        }
    }
    return "";
}

void TaxiPark::takeOrder(unsigned short number_passenger, bool have_child) {
    std::cout << "Trying to take order..." << std::endl;
    std::string number_ = getSuitableCar(number_passenger, have_child);
    if (number_.empty()) {
        std::cout << "Couldn't take the order, no suitable cars" << std::endl;
    } else {
        cars[number_].takeOrder(number_passenger, have_child);
        std::cout << "The order has been successfully transferred to the car with the number " << number_
                  << std::endl;
    }
}

void TaxiPark::takeOrder(const std::string &number_, unsigned short number_passenger, bool have_child) {
    if (cars.find(number_) != cars.end() && cars[number_].takeOrder(number_passenger, have_child)) {
        std::cout << "The order has been successfully transferred to the car with the number " << number_
                  << std::endl;
    } else {
        std::cout << "Couldn't take the order, car with number " << number_ << " isnt suitable or busy"
                  << std::endl;
    }
}

void TaxiPark::finalizeOrder(const std::string &number_) {
    if (cars.find(number_) != cars.end() && cars[number_].finalizeOrder()) {
        std::cout << "The car " << number_ << " order has been successfully completed" << std::endl;
    } else {
        std::cout << "The car wasnt ordered" << std::endl;
    }
}


