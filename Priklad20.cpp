/*
Implementujte hešovací tabulku (operace: inicializace, hešování, vložení, vyhledání) a aplikujte ji na řešení
následující úlohy:
Na standardním vstupu se nachází řada řetězců, přičemž některé semohou vyskytovat opakovaně.Vypište na standardní
výstup seznam vstupních řetězců (každý jednou) s informací, kolikrát se vyskytoval na standardním vstupu.
(Do hešovací tabulky budete ukládat záznamy obsahující daný řetězec a počet jeho výskytů. Pro hešování navrhněte
vhodnou funkci.

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // Initialize a hash table
    unordered_map<string, int> hash_table;

    // Read strings from standard input
    string s;
    while (cin >> s) {
        // Insert the string into the hash table, or increment its count if it's already present
        hash_table[s]++;
    }

    // Print the results
    for (const auto& [key, value] : hash_table) {
        cout << key << ": " << value << endl;
    }

    return 0;
}


#include <iostream>
#include <string>
#include <unordered_map>

// Use a hash table to count the number of occurrences of each string
void count_strings(std::istream& in) {
  // Initialize the hash table
  std::unordered_map<std::string, int> counts;

  // Read in the strings and count their occurrences
  std::string s;
  while (in >> s) {
    counts[s]++;
  }

  // Write the results to standard output
  for (const auto& p : counts) {
    std::cout << p.first << ": " << p.second << std::endl;
  }
}

int main() {
  count_strings(std::cin);
  return 0;
}
použítí mapy

 */
