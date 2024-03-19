#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "car.h"


Car createCar(char* reg_number, char* model, char* category) {

    Car new_car;

    int n;
    n = (int)strlen(reg_number) + 1;
    new_car.reg_number = malloc(n * sizeof (char));
    strcpy(new_car.reg_number, reg_number);

    n = (int)strlen(model) + 1;
    new_car.model = malloc(n * sizeof (char));
    strcpy(new_car.model, model);

    n = (int)strlen(category) + 1;
    new_car.category = malloc(n * sizeof (char));
    strcpy(new_car.category, category);

    return new_car;
}

int validateCar(Car car) {
    if ( strlen(car.reg_number) < 6 ||  strlen(car.reg_number) > 8 ) return 0;
    return 1;
}

void deleteCar(Car* car) {
    free(car -> reg_number);
    free(car -> model);
    free(car -> category);

    car -> reg_number = NULL;
    car -> model = NULL;
    car -> category = NULL;
}