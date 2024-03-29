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

CarList* filterCars_model(CarList* car_list, CarList* result_list, char* model) {
    for (int i = 0; i < car_list -> length; i++) {
        if (strcmp(car_list -> car[i].model, model) == 0) {
            addCar(result_list, car_list -> car[i]);
        }
    }
    return result_list;
}

CarList* filterCars_category(CarList* car_list, CarList* result_list, char* category) {
    for (int i = 0; i < car_list -> length; i++) {
        if (strcmp(car_list -> car[i].category, category) == 0) {
            addCar(result_list, car_list -> car[i]);
        }
    }
    return result_list;
}

CarList* filterCars(CarList* car_list, CarList* result_list, char* model, char* category) {
    if (model != NULL) {
        result_list = filterCars_model(car_list, result_list, model);
    }
    if (category != NULL) {
        result_list = filterCars_category(car_list, result_list, category);
    }
    return result_list;
}

void sortCars_model(CarList* car_list, int direction) {
    for (int i = 0; i < car_list -> length - 1; i++) {
        for (int j = i + 1; j < car_list -> length; j++) {
            if (direction * strcmp(car_list -> car[i].model, car_list -> car[j].model) > 0) {
                Car aux = car_list -> car[i];
                car_list -> car[i] = car_list -> car[j];
                car_list -> car[j] = aux;
            }
        }
    }
}

void sortCars_category(CarList* car_list, int direction) {
    for (int i = 0; i < car_list -> length - 1; i++) {
        for (int j = i + 1; j < car_list -> length; j++) {
            if (direction * strcmp(car_list -> car[i].category, car_list -> car[j].category) > 0) {
                Car aux = car_list -> car[i];
                car_list -> car[i] = car_list -> car[j];
                car_list -> car[j] = aux;
            }
        }
    }
}

void sortCars(CarList* car_list, int direction, char* criteria) {
    if (strcmp(criteria, "model") == 0) {
        sortCars_model(car_list, direction);
    } else if (strcmp(criteria, "category") == 0) {
        sortCars_category(car_list, direction);
    }
}