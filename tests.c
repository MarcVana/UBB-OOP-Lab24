#include <string.h>
#include "service.h"
#include "repo.h"
#include "car.h"
#include <assert.h>

void test_createCar() {
    Car car = createCar("CJ96VMV", "Mercedes", "Coupe");
    assert(strcmp(car.reg_number, "CJ96VMV") == 0);
    assert(strcmp(car.model, "Mercedes") == 0);
    assert(strcmp(car.category, "Coupe") == 0);
    deleteCar(&car);
}

void test_validateCar() {
    Car car = createCar("CJ96VMV", "Mercedes", "Coupe");
    assert(validateCar(car) == 1);
    deleteCar(&car);
}

void test_createNew() {
    CarList car_list = createNew();
    assert(car_list.length == 0);
    assert(car_list.capacity == 32);
    deleteList(&car_list);
}

void test_addCar() {
    CarList car_list = createNew();
    Car car = createCar("CJ96VMV", "Mercedes", "Coupe");
    addCar(&car_list, car);
    assert(car_list.length == 1);
    deleteList(&car_list);
}

void test_modifyCar() {
    CarList car_list = createNew();
    Car car = createCar("CJ96VMV", "Mercedes", "Coupe");
    addCar(&car_list, car);
    modifyCar(&car_list, 0, "CJ99VMV", "BMW", "Sedan");
    assert(strcmp(car_list.car[0].reg_number, "CJ99VMV") == 0);
    assert(strcmp(car_list.car[0].model, "BMW") == 0);
    assert(strcmp(car_list.car[0].category, "Sedan") == 0);
    deleteList(&car_list);
}

void test_removeCar() {
    CarList car_list = createNew();
    Car car = createCar("CJ96VMV", "Mercedes", "Coupe");
    addCar(&car_list, car);
    removeCar(&car_list, 0);
    assert(car_list.length == 0);
    deleteList(&car_list);
}

void test_newCar() {
    CarList car_list = createNew();
    assert(newCar(&car_list, "CJ96VMV", "Mercedes", "Coupe") == 1);
    assert(car_list.length == 1);
    deleteList(&car_list);
}

void test_editCar() {
    CarList car_list = createNew();
    newCar(&car_list, "CJ96VMV", "Mercedes", "Coupe");
    assert(editCar(&car_list, 0, "CJ99VMV", "BMW", "Sedan") == 1);
    assert(strcmp(car_list.car[0].reg_number, "CJ99VMV") == 0);
    assert(strcmp(car_list.car[0].model, "BMW") == 0);
    assert(strcmp(car_list.car[0].category, "Sedan") == 0);
    deleteList(&car_list);
}

void test_eraseCar() {
    CarList car_list = createNew();
    newCar(&car_list, "CJ96VMV", "Mercedes", "Coupe");
    assert(eraseCar(&car_list, 0) == 1);
    assert(car_list.length == 0);
    deleteList(&car_list);
}

void test_filterCars() {
    CarList car_list = createNew();
    CarList result_list = createNew();
    newCar(&car_list, "CJ96VMV", "Mercedes", "Coupe");
    newCar(&car_list, "CJ99VMV", "BMW", "Sedan");
    filterCars(&car_list, &result_list, "Mercedes", NULL);
    assert(result_list.length == 1);
    assert(strcmp(result_list.car[0].model, "Mercedes") == 0);
    result_list = createNew();
    filterCars(&car_list, &result_list, NULL, "Sedan");
    assert(strcmp(result_list.car[0].model, "BMW") == 0);
    deleteList(&car_list);
}

void test_sortCars() {
    CarList car_list = createNew();
    newCar(&car_list, "CJ96VMV", "BMW", "Coupe");
    newCar(&car_list, "CJ99VMV", "Mercedes", "Sedan");
    sortCars(&car_list, 1, "model");
    assert(strcmp(car_list.car[0].model, "BMW") == 0);
    assert(strcmp(car_list.car[1].model, "Mercedes") == 0);
    sortCars(&car_list, 1, "category");
    assert(strcmp(car_list.car[0].category, "Coupe") == 0);
    assert(strcmp(car_list.car[1].category, "Sedan") == 0);
    deleteList(&car_list);
}

int runTests() {
    test_createCar();
    test_validateCar();
    test_createNew();
    test_addCar();
    test_modifyCar();
    test_removeCar();
    test_newCar();
    test_editCar();
    test_eraseCar();
    test_filterCars();
    test_sortCars();
    return 0;
}