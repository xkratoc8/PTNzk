/*
 Implementujte lineární obousměrný dynamický seznam s datovou složkou typu desetinné číslo. Přečtěte
ze vstupu řadu desetinných čísel a ukládejte ji do tohoto seznamu tak, aby byly hodnoty v každém okamžiku vzestupně
seřazeny. Po přečtení celého vstupu vypište aktuální obsah seznamu do binárního souboru, jehož jméno bude zadáno
jako první parametr z příkazového řádku. Pokud nebude první parametr zadán, výsledek bude vypsán na standardní
výstup.


#include <iostream>
#include <fstream>

struct Node {
    double data;
    Node* next;
    Node* prev;
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(double value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr) {
            // List is empty
            head = newNode;
            tail = newNode;
        } else {
            Node* current = head;
            Node* previous = nullptr;
            while (current != nullptr && current->data < value) {
                previous = current;
                current = current->next;
            }
            if (previous == nullptr) {
                // Insert at the beginning of the list
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else if (current == nullptr) {
                // Insert at the end of the list
                previous->next = newNode;
                newNode->prev = previous;
                tail = newNode;
            } else {
                // Insert in the middle of the list
                previous->next = newNode;
                newNode->prev = previous;
                newNode->next = current;
                current->prev = newNode;
            }
        }
    }

    void writeToFile(const std::string& filename) {
        std::ofstream out(filename, std::ios::binary);
        if (!out) {
            std::cerr << "Error opening file " << filename << std::endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            out.write(reinterpret_cast<char*>(&current->data), sizeof(double));
            current = current->next;
        }

        out.close();
    }
};

int main(int argc, char* argv[]) {
    List list;

    double value;
    while (std::cin >> value) {
        list.insert(value);
    }

    if (argc > 1) {
        list.writeToFile(argv[1]);
    } else {
        list.writeToFile(""); // Write to standard output
    }

    return 0;
}

*/