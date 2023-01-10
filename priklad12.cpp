/*
Implementujte dvourozměrné řídké pole o rozměrech milion krát milion celočíselných hodnot s majoritní
hodnotou nula. Napište potřebné datové typy a dále pouze operaci umožňující vyhledání hodnoty na zadaných indexech
v nejvýše logaritmickém čase

#include <map>

using namespace std;

// Define a pair of integers as the key for the map
using Key = pair<int, int>;

// Define a map that maps keys (row and column indices) to values (non-zero elements)
map<Key, int> sparse_array;

// Default value for elements not in the map
const int DEFAULT_VALUE = 0;

// Number of rows and columns in the sparse array
const int NUM_ROWS = 1000000;
const int NUM_COLS = 1000000;

// Returns the element at the given indices in the sparse array
int get(int i, int j) {
    // Look up the element at the given indices in the map
    auto it = sparse_array.find(Key{i, j});
    // If the element is not found, return the default value
    if (it == sparse_array.end()) return DEFAULT_VALUE;
    // Otherwise, return the element
    return it->second;
}

// Sets the element at the given indices in the sparse array
void set(int i, int j, int value) {
    // If the value is the default value, remove the element from the map
    if (value == DEFAULT_VALUE) {
        sparse_array.erase(Key{i, j});
    }
        // Otherwise, insert or update the element in the map
    else {
        sparse_array[Key{i, j}] = value;
    }
}
*/