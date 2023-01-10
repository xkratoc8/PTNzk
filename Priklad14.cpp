/*
 V C++ Napište programový modul (oba soubory) implementující abstraktní datový typ „obecný seznam“ prvků
s daty typu obecný ukazatel a s operacemi: Init (vytvoření prázdného seznamu), Add (vložení jednoho prvku na n-tou
pozici v seznamu, je-li n větší než dosavadní počet prvků seznamu, ukládá se nový prvek na konec; ukazatel na data a pozice v seznamu jsou parametry operace),
Save (uložení celého seznamu do textového souboru). Pro převod datového
prvku do textového tvaru připravte operaci, jejíž tělo bude definováno mimo tento modul.



// Header file
#include <iostream>
#include <fstream>

template <typename T>
class List {
public:
    // Constructs an empty list
    List();

    // Destructor
    ~List();

    // Inserts an element at the specified position in the list
    // If the position is greater than the current number of elements,
    // the element is inserted at the end of the list
    void Add(T* data, int pos);

    // Saves the entire list to a text file
    void Save(const std::string& filename) const;

    // Converts an element to its text representation
    std::string ToText(const T& elem) const;

private:
    struct Node {
        T* data;
        Node* next;
    };

    Node* head_;
    Node* tail_;
    int size_;
};

// Source file
template <typename T>
List<T>::List() : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename T>
List<T>::~List() {
    Node* curr = head_;
    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
}

template <typename T>
void List<T>::Add(T* data, int pos) {
    Node* new_node = new Node{data, nullptr};
    if (pos == 0) {
        // Insert at the beginning of the list
        new_node->next = head_;
        head_ = new_node;
        if (tail_ == nullptr) {
            // List was empty, update the tail
            tail_ = head_;
        }
    } else if (pos >= size_) {
        // Insert at the end of the list
        tail_->next = new_node;
        tail_ = new_node;
    } else {
        // Insert in the middle of the list
        Node* prev = head_;
        for (int i = 0; i < pos - 1; ++i) {
            prev = prev->next;
        }
        new_node->next = prev->next;
        prev->next = new_node;
    }
    ++size_;
}

template <typename T>
void List<T>::Save(const std::string& filename) const {
    std::ofstream out(filename);
    Node* curr = head_;
    while (curr != nullptr) {
        out << ToText(*curr->data) << std::endl;
        curr = curr->next;
    }
    out.close();
}

template <typename T>
std::string List<T>::ToText(const T& elem) const {
    // This function must be defined by the user
    return std::to_string(elem);
}
*/