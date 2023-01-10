/*
in c++ : Je dán modul implementující uspořádaný seznam s obecnými datovými složkami. Část hlavičkového souboru
        uspor.h má následující obsah:
//odvození typu TypSeznam není pro řešení úlohy podstatné
typedef short (*TypRel)(void *A, void *B); //porovnávací funkce; dává hodnoty -1, 0, 1
typedef void (*TypJak)(void *Data); //procedura pro výpis na standardní výstup
void Zacni(TypSeznam &S, TypRel R); //inicializace seznamu a definice porovnávací funkce
void Vloz(TypSeznam &S, void *Data); //vložení do seznamu uspořádaně
void Vypis(TypSeznam &S, TypJak Jak); //výpis všech prvků seznamu
Použijte tento modul v programu řešícím následující úlohu: Na standardním vstupu je řada trojic údajů: příjmení pracovníka, číslo jeho pracoviště a plat.
Vypište na standardní výstup tento seznam pracovníků uspořádaný podle platu
sestupně.


#include "uspor.h"

// Compare function for sorting employees by salary in descending order
short compare(void *A, void *B) {
    Employee *a = (Employee*) A;
    Employee *b = (Employee*) B;
    if (a->salary > b->salary) return -1;
    if (a->salary < b->salary) return 1;
    return 0;
}

// Print function for printing employee information to standard output
void print(void *Data) {
    Employee *e = (Employee*) Data;
    cout << e->last_name << " " << e->workplace_number << " " << e->salary << endl;
}

int main() {
    TypeList S;

    // Initialize the list and set the compare function
    Start(S, compare);

    // Read employee data from standard input
    while (cin >> last_name >> workplace_number >> salary) {
        Employee *e = new Employee;
        e->last_name = last_name;
        e->workplace_number = workplace_number;
        e->salary = salary;
        Insert(S, e);
    }

    // Print the list of employees sorted by salary in descending order
    List(S, print);

    return 0;
}
 */