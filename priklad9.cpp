/*
tvořte programový modul (hlavičkový i implementační soubor) implementující celočíselnou multimnožinu M (množinu s možností vícenásobného výskytu prvků) datového typu s názvem MultiSet . Multimnožina má mít
        schopnost ukládat nezáporná čísla o maximální velikosti Max (to je implementační proměnná). Požadované operace:
• Start(M, K) – vytvoří prázdnou multimnožinu M s možností ukládat nezáporná čísla do velikosti K
• Vloz(M, C) – vloží prvek C do multimnožiny M
• Vypis(M) – vypíše obsah multimnožiny M do standardního výstupu (posloupnost čísel oddělených čárkou
                                                                  a jednou mezerou)
//

#include "priklad9.h"
#include <iostream>

MultiSet::MultiSet(int K) : max_size_(K) {}

void MultiSet::Insert(int C) {
    if (elements_.size() < max_size_) {
        elements_.push_back(C);
    }
}

void MultiSet::Print() const {
    for (size_t i = 0; i < elements_.size(); ++i) {
        std::cout << elements_[i];
        if (i < elements_.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}
int main() {
    MultiSet set(5); // Create a multiset with a maximum size of 5 elements
    set.Insert(1);
    set.Insert(2);
    set.Insert(3);
    set.Insert(2);
    set.Print(); // Outputs: 1, 2, 3, 2
    return 0;
}
 */