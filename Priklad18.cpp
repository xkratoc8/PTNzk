/*
Předpokládejte neuspořádaný binární strom, jehož datové složky jsou obecné ukazatele. Napište funkci,
která vrátí počet datových prvků stromu, jež mají větší hodnotu než zadaný prvek. Parametrem funkce je ukazatel na
kořen stromu, dále ukazatel na prvek stromu, jehož hodnota se s ostatními má porovnávat, a logická funkce definující
uspořádání na množině dat. Doplňte všechny potřebné datové typy.

 For example, you could put the function definition in a file called tree_utils.hpp:

 // header

Copy code
#ifndef TREE_UTILS_HPP
#define TREE_UTILS_HPP

template <typename T>
int countGreater(Node<T>* root, T* element, bool (*compare)(T*, T*));

#endif

 //source



 #include "tree_utils.hpp"

template <typename T>
int countGreater(Node<T>* root, T* element, bool (*compare)(T*, T*)) {
  if (root == nullptr) {
    return 0;
  }

  int count = 0;
  if (compare(root->data, element)) {
    count++;
  }
  count += countGreater(root->left, element, compare);
  count += countGreater(root->right, element, compare);
  return count;
}
 */