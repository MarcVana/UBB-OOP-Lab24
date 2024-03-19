#ifndef LAB2_4_REPO_H
#define LAB2_4_REPO_H
#include "car.h"

typedef struct {
    Car* car;

    int length; // lungimea listei
    int capacity; // capacitatea listei
} CarList;
// Lista de masini contine un vector de masini, lungimea si capacitatea listei.

// Se creeaza o lista vida (cu lungimea 0) si se returneaza.
CarList createNew();

// Se adauga o masina la sfarsitul listei.
// Conditii: lista sa existe, si masina sa fie valida.
void addCar(CarList* car_list, Car car);

// Se modifica masina de pe pozitia car_index, cu datele din antet.
// Conditii: Masina sa existe in lista si datele noi sa fie valide.
void modifyCar(CarList* car_list, int car_index, char* new_reg_number, char* new_model, char* new_category);

// Se sterge masina de pe pozitia car_index.
// Conditii: Masina sa existe in lista si pozitia sa fie valida.
void removeCar(CarList* list, int car_index);

// Se sterge lista de masini, eliberand memoria ocupata de aceasta.
// Conditii: Lista sa existe.
void deleteList(CarList* car_list);

// Se redimensioneaza lista de masini, dubland capacitatea acesteia.
// Conditii: Lista sa existe.
void increaseSize(CarList* car_list);

// Se returneaza masina de pe pozitia car_index.
Car getCar(CarList * list, int car_index);

#endif // LAB2_4_REPO_H
