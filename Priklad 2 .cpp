/*
Uvažujte tabulku s rozptýlenými hesly implementovanou základním polem s dynamickými jednosměrnými lineárními seznamy na jednotlivých indexech.
Do tabulky jsou ukládána reálná čísla. Definujte potřebné datové typy
a napište pouze operaci, která zjistí počty synonym pro neprázdné indexy základního pole a
vypíše seznam indexů a těchto počtů na standardní výstup. Jiné operace nejsou předmětem hodnocení této úlohy.

#include <iostream>

using namespace std;

struct Node {
    double data;
    Node *next;
};

struct List {
    Node *head;
    int count;
};

const int TABLE_SIZE = 10;
List hashTable[TABLE_SIZE];

void findSynonymCounts() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].count > 0) {
            int synonymCount = 0;
            Node *curr = hashTable[i].head;
            while (curr != nullptr) {
                synonymCount++;
                curr = curr->next;
            }
            cout << "Index " << i << ": " << synonymCount << " synonyms" << endl;
        }
    }
}

int main() {
    hashTable[0].head = new Node{1.1, nullptr};
    hashTable[0].count = 1;

    hashTable[1].head = new Node{2.2, new Node{2.2, nullptr}};
    hashTable[1].count = 2;
    findSynonymCounts();
}
 */