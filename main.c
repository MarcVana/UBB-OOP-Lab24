#include <stdio.h>
#include <string.h>
#include "service.h"
#include "tests.h"

// Afiseaza catre utilizator optiunile valabile.
void menu_Print() {
    printf("\n\nA. Adaugare\nB. Modificare\nC. Stergere\nD. Filtrare\nE. Ordonare\nP. Predefinite adaugare\n0. Afisare cheltuieli\nQ. Iesire\n\n");
}

// Ofera utilizatorului sansa de a alege o optiune din meniu.
char menu_ChooseOption() {
    printf("> Introduceti optiunea: ");
    char option;
    scanf(" %c", &option);
    return option;
}

void read_string(char* string) {
    fflush(stdin);
    fgets(string, 50, stdin);
    string[strlen(string) - 1] = '\0';
}

// Utilizatorul introducele datele unei masini.
void getData(char* reg_number, char* model, char* category) {
    char* read_reg_number = NULL;
    char* read_model = NULL;
    char* read_category = NULL;

    printf(">>> Introduceti nr. inreg.: ");
    //scanf(" %s", read_reg_number);
    //read_string(read_reg_number);
    getchar();
    fgets(read_reg_number, sizeof(read_reg_number), stdin);
    read_reg_number[strcspn(read_reg_number, "\n")] = '\0';

    printf(">>> Introduceti modelul: ");
    read_string(read_model);

    printf(">>> Introduceti categoria: ");
    read_string(read_category);

    strcpy(reg_number, read_reg_number);
    strcpy(model, read_model);
    strcpy(category, read_category);
}

void printList(CarList* car_list) {
    if (car_list -> length == 0) printf("Nu exista masini.");
    else
        for (int i = 0; i < car_list -> length ; i++) {
            printf("%d. ", i + 1);
            printf("nr. inreg.: %s, model: %s, categorie: %s\n", car_list->car[i].reg_number, car_list->car[i].model, car_list->car[i].category);
        }
    printf("\n");
}

void menu_Add(CarList* car_list) {
    char* add_reg_number;
    char* add_model;
    char* add_category;

    getData(add_reg_number, add_model, add_category);
    int ok = newCar(car_list, add_reg_number, add_model, add_category);
    if (ok) printf("Adaugarea a fost realizata cu succes.\n\n");
    else printf("Date invalide. Reincercati.\n\n");
}

void menu_Modify(CarList* car_list) {
    printList(car_list);

    printf("Introduceti numarul masinii ce doriti sa o modificati: ");
    int car_index;
    scanf("%d", &car_index);
    car_index--;

    if (car_index < 0 || car_index >= car_list -> length) printf("Numarul introdus e invalid.\n\n");
    else {
        printf("Masina %d a fost selectata cu succes.\n", car_index + 1);

        char* new_reg_number;
        char* new_model;
        char* new_category;

        getData(new_reg_number, new_model, new_category);

        int ok = editCar(car_list, car_index, new_reg_number, new_model, new_category);
        if (ok) printf("Modificarea a fost realizata cu succes.\n\n");
        else printf("Date invalide. Reincercati.\n\n");
    }
}

void menu_Delete(CarList* car_list) {
    printList(car_list);

    printf("Introduceti numarul masinii ce doriti sa o stergeti: ");
    int car_index;
    scanf("%d", &car_index);
    car_index--;

    int ok = eraseCar(car_list, car_index);

    if (ok) printf("Stergerea a fost realizata cu succes.\n\n");
    else printf("Date invalide. Reincercati.\n\n");
}

void menu_Filter(CarList* car_list) {
    printf("1. Model\n2. Categorie\n");

    char option = menu_ChooseOption();

    char* reg_number = NULL;
    char* model = NULL;
    char* category = NULL;
    int is_okay = 1;

    if (car_list -> length == 0) {
        printf("Nu exista masini.");
        is_okay = 0;
    }
    else if (option == '1') {
        printf("Introduceti modelul: ");
        getchar();
        fgets(model, sizeof(model), stdin);
        model[strcspn(model, "\n")] = '\0';
    }
    else if (option == '2') {
        printf("Introduceti categoria: ");
        getchar();
        fgets(category, sizeof(category), stdin);
        category[strcspn(category, "\n")] = '\0';
    }
    else {
        printf("Optiune invalida.");
        is_okay = 0;
    }

    if (is_okay) {
        printf("Lista filtrata: \n");
        CarList result_list = createNew();
        filterCars(car_list, &result_list, model, category);

        if (result_list.length != 0) printList(&result_list);
        else printf("Nu exista masini cu datele cerute.");

        //deleteList(&result_list);
    }
}

void menu_Sort(CarList* car_list) {
    printf("1. Model\n2. Categorie\n");
    char option = menu_ChooseOption();

    printf("1. Crescator\n2. Descrescator\n");
    char option_2 = menu_ChooseOption();

    int direction;
    int is_okay = 1;

    if (car_list -> length == 0) {
        printf("Nu exista masini.");
        is_okay = 0;
    }
    else if (option_2 == '1') direction = -1;
    else if (option_2 == '2') direction = 1;

    CarList result_list = createNew();

    if (option == '1' && is_okay) {
        printf("Lista ordonata dupa model este: \n");
        sortCars(&result_list, direction, "model");
    }
    else if (option == '2' && is_okay) {
        printf("Lista ordonata dupa categorie este: \n");
        sortCars(&result_list, direction, "category");
    }
    else {
        printf("Optiune invalida!");
        is_okay = 0;
    }

    if (is_okay) printList(&result_list);
    //deleteList(&result_list);
}

void addPredefinedCars(CarList* car_list) {
    addCar(car_list, createCar("CJ96VMV", "Mercedes", "Coupe"));
    addCar(car_list, createCar("CJ99VMV", "BMW", "Sedan"));
}

// Meniul ce se afiseaza la pornirea aplicatiei.
void startApp() {
    CarList list = createNew();

    while (1) {
        menu_Print();
        char option = menu_ChooseOption();

        if (option == '0') printList(&list);
        else if (option == 'a' || option == 'A') menu_Add(&list);
        else if (option == 'b' || option == 'B') menu_Modify(&list);
        else if (option == 'c' || option == 'C') menu_Delete(&list);
        else if (option == 'd' || option == 'D') menu_Filter(&list);
        else if (option == 'e' || option == 'E') menu_Sort(&list);
        else if (option == 'p' || option == 'P') addPredefinedCars(&list);
        else if (option == 'q' || option == 'Q') break;
        else printf("Optiune invalida. Incercati din nou.\n\n");
    }
    deleteList(&list);
}

int main() {
    startApp();
    //runTests();
    return 0;
}
