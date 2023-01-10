//
// Created by karel on 10.01.2023.
//

#ifndef PTNZK_PRIKLAD9_H
#define PTNZK_PRIKLAD9_H


#include <vector>

class MultiSet {
public:
    // Creates an empty multiset with the possibility to store non-negative numbers of size K
    explicit MultiSet(int K);

    // Inserts an element C into the multiset
    void Insert(int C);

    // Prints the contents of the multiset to the standard output (a sequence of numbers separated by a comma and one space)
    void Print() const;

private:
    std::vector<int> elements_;
    int max_size_;
};

#endif //PTNZK_PRIKLAD9_H
