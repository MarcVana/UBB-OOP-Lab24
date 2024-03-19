#ifndef LAB2_4_CAR_H
#define LAB2_4_CAR_H

typedef struct {

    char* reg_number;
    char* model;
    char* category;

} Car;
// Fiecare masina contine un numar de inmatriculare, un model si o categorie.

// Creeaza o cheltuiala prin parametrii dati si o returneaza.
Car createCar(char* reg_number, char* model, char* category);

// Returneaza 0 sau 1 daca datele despre masina sunt valide sau nu.
int validateCar(Car car);

// Sterge o masina, elibereaza memoria ocupata de aceasta.
void deleteCar(Car* car);

#endif //LAB2_4_CAR_H
