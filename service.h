#ifndef LAB2_4_SERVICE_H
#define LAB2_4_SERVICE_H
#include "repo.h"

// Adauga o masina in lista din antet.
// Parametrii: lista de masini, numarul de inmatriculare, modelul si categoria masinii.
// Conditii: lista sa existe si masina sa fie valida.
int newCar(CarList * car_list, char* reg_number, char* model, char* category);

int editCar(CarList* car_list, int car_index, char* new_reg_number, char* new_model, char* new_category);
// Modifica o masina in lista din antet.
// Parametrii: lista de masini, indexul masinii, noile date ale masinii.
// Conditii: lista sa existe si masina sa fie valida.

int eraseCar(CarList* list, int car_index);
// Sterge o masina din lista din antet.
// Parametrii: lista de masini, indexul masinii.
// Conditii: lista sa existe si indexul sa fie valid.

CarList* filterCars(CarList* car_list, CarList* result_list, char* model, char* category);
// Filtreaza lista de masini dupa optiunile dorite de utilizator.
// Parametrii: lista de masini, lista rezultat, numarul de inmatriculare, modelul si categoria masinii.
// Conditii: lista sa existe, doar un parametru din model/category sa fie ales.

void sortCars(CarList* car_list, int direction, char* criteria);
// Sorteaza lista de masini dupa criteriul dat de utilizator.
// Parametrii: lista de masini, directia de sortare, criteriul de sortare.
// Conditii: lista sa existe, directia sa fie valida, criteriul sa fie categorie/model.

#endif //LAB2_4_SERVICE_H
