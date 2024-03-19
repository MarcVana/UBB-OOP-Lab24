#include "repo.h"
#include "car.h"
#include "service.h"
#include <string.h>

int newCar(CarList* car_list, char* reg_number, char* model, char* category) {
    Car new_car = createCar(reg_number, model, category);

    if (validateCar(new_car) == 0) {
        deleteCar(&new_car);
        return 0;
    }

    addCar(car_list, new_car);
    return 1;
}

int editCar(CarList* car_list, int car_index, char* new_reg_number, char* new_model, char* new_category) {
    Car new_car = createCar(new_reg_number, new_model, new_category);

    if (validateCar(new_car) == 0 ) {
        deleteCar(&new_car);
        return 0;
    }

    modifyCar(car_list, car_index, new_reg_number, new_model, new_category);
    return 1;
}

int eraseCar(CarList* car_list, int car_index) {
    if (car_index < 0 || car_index >= car_list -> length)
        return 0;

    removeCar(car_list, car_index);
    return 1;
}

CarList* filterCars(CarList* car_list, CarList* result_list, char* model, char* category) {
    // filtrare dupa model
    if (model != NULL)
        for (int i = 0; i < car_list -> length; i++)
            if (strcmp(car_list -> car[i].model, model) == 0)
                addCar(result_list, car_list -> car[i]);

    // filtrare dupa categorie
    if (category != NULL)
        for (int i = 0; i < car_list -> length; i++)
            if (strcmp(car_list -> car[i].category, category) == 0)
                addCar(result_list, car_list -> car[i]);

    return result_list;
}

void sortCars(CarList* car_list, int direction, char* criteria) {
    for (int i = 0; i < car_list -> length - 1; i++) {
        for (int j = i + 1; j < car_list -> length; j++) {
            if (direction * strcmp(criteria, "model") == 0) {
                if (direction * strcmp(car_list -> car[i].model, car_list -> car[j].model) > 0) {
                    Car aux = car_list -> car[i];
                    car_list -> car[i] = car_list -> car[j];
                    car_list -> car[j] = aux;
                }
            } else if (direction * strcmp(criteria, "category") == 0) {
                if (direction * strcmp(car_list->car[i].category, car_list->car[j].category) > 0) {
                    Car aux = car_list -> car[i];
                    car_list -> car[i] = car_list -> car[j];
                    car_list -> car[j] = aux;
                }
            }
        }
    }
}