/*
 Napište proceduru, která seřadí lineární jednosměrný dynamický seznam řetězcových hodnot sestupně metodou Bubble sort

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// A dynamic one-way linear list node
struct Node {
    string data;
    Node* next;
};

// Function prototype
void bubbleSort(Node* head);

int main() {
    // Create a dynamic one-way linear list
    vector<Node> list = {{"apple", &list[1]}, {"banana", &list[2]}, {"cherry", &list[3]}, {"date", &list[4]}, {"elderberry", nullptr}};

    // Get the head of the list
    Node* head = &list[0];

    // Sort the list using bubble sort
    bubbleSort(head);

    // Print the sorted list
    for (Node* p = head; p != nullptr; p = p->next) {
        cout << p->data << endl;
    }

    return 0;
}

// Function to sort a dynamic one-way linear list of strings using bubble sort
void bubbleSort(Node* head) {
    // Check for empty list
    if (head == nullptr) {
        return;
    }

    bool sorted = false;
    while (!sorted) {
        sorted = true;
        Node* p = head;
        while (p->next != nullptr) {
            // Compare adjacent nodes
            if (p->data > p->next->data) {
                // Swap the nodes
                string temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                sorted = false;
            }
            p = p->next;
        }
    }
}
 */