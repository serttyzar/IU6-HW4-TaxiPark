//
// Created by sertt on 26.11.2023.
//

#include "classes.h"

int test_1(){
    TaxiPark park;
    TaxiCar car1("A123BC", 73, 3);
    TaxiCar car2("D123EF", 99, 4, true);
    park.addCar(car1);
    park.addCar(car2);

    park.takeOrder(3, true);
    park.takeOrder(3, false);
    park.display();

    park.takeOrder(1, false);
    park.finalizeOrder("A123BC");
    park.takeOrder(1, true);
    park.takeOrder(2, false);
    park.display();

    park.finalizeOrder("A123BC");
    park.finalizeOrder("D123EF");

    park.takeOrder("D777NO", 1, false);
    park.finalizeOrder("D666NO");
    park.display();
    return 0;
}

int main() {
    test_1();
}
