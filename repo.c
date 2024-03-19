#include <stdlib.h>
#include <string.h>
#include "repo.h"

CarList createNew() {
    CarList new_car_list;

    new_car_list.length = 0;
    new_car_list.capacity = 32;
    new_car_list.car = (Car*)malloc(new_car_list.capacity * sizeof(Car));

    return new_car_list;
}

void deleteList(CarList* car_list) {
    if (car_list == NULL) return;

    for (int i = 0; i < car_list -> length; i++) {
        Car car_index = getCar(car_list, i);
        deleteCar(&car_index);
    }
    car_list -> length = 0;

    free(car_list -> car);
}

void increaseSize(CarList * car_list) {
    Car* new_car = (Car*)malloc(2 * car_list -> capacity * sizeof (Car));

    if (new_car == NULL) return;

    for (int i = 0; i < car_list -> length; i++) new_car[i] = car_list -> car[i];

    car_list -> capacity = 2 * car_list -> capacity;
    free(car_list -> car);
    car_list -> car = new_car;
}

void addCar(CarList* car_list, Car car) {
    if (car_list -> length == car_list -> capacity) increaseSize(car_list);

    car_list -> car[car_list -> length] = car;
    car_list -> length++;
}

void modifyCar(CarList* car_list, int car_index, char* new_reg_number, char* new_model, char* new_category) {
    strcpy(car_list -> car[car_index].reg_number, new_reg_number);
    strcpy(car_list -> car[car_index].model, new_model);
    strcpy(car_list -> car[car_index].category, new_category);
}

void removeCar(CarList* car_list, int car_index) {
    for (int i = car_index + 1; i < car_list -> length; i++) car_list -> car[i - 1] = car_list -> car[i];
    car_list -> length--;
}

Car getCar(CarList* car_list, int car_index) {
    return car_list->car[car_index];
}