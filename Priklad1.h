/*
1: Napište programový modul (hlavičkový i implementační soubor) implementující abstraktní typ „obecný seznam“ prvků libovolného datového typu s operacemi:
1. Start(vytvoření prázdného seznamu); done
2. Pridej(přidání jednoho prvku do seznamu za prvek, na nějž ukazuje ukazatel v parametru, je-li tento parametr
        prázdným ukazatelem, zařadí se nový prvek na začátek);
3. Tiskni(uložení celého seznamu do textového souboru – způsob textového vyjádření obecných hodnot rozhodne
uživatel vně modulu).
Implementaci proveďte pomocí pole.
*/

#ifndef PTNZK_PRIKLAD1_H
#define PTNZK_PRIKLAD1_H


#include <iostream>
#include <fstream>
#include <string>

template <typename T>
class GeneralList {
public:
    // Constructs an empty list
    GeneralList();

    // Adds a new element to the list
    // If the pointer is null, the element is added to the beginning of the list
    void Add(T element, T* prevElement);

    // Prints the entire list to a text file
    // The user must provide a function to convert the elements to strings
    void Print(std::string (*toString)(T element), std::ofstream& file);

public:
    static const int INITIAL_CAPACITY = 4;
    T* elements;
    int capacity;
    int size;
};

#endif //PTNZK_PRIKLAD1_H
