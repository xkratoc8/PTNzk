/*
Napište funkci, která je schopna spočítat počet znaků v kódování UTF-8 přečtených ze standardního vstupu.
Víte, že znak v kódování UTF-8 může být buď jednobajtový – v tom případě má v nejvyšším bitu nulu, nebo může být
vícebajtový – pak má jeho první bajt v nejvyšších bitech tolik binárních jedniček, kolik bajtů zabírá, a v dalších bajtech
má v nejvyšších dvou bitech binární hodnotu 10 . Používají se nejvýše čtyřbajtové znaky.
Funkce zároveň kontroluje, zda jsou vstupní znaky správné, tj. všechny pokračující bajty musí mít uvedený prefix.
Chybné znaky do celkového počtu nezapočítává

#include <iostream>
#include <sstream>

int count_utf8_chars() {
    int count = 0;
    char c;
    while (std::cin.get(c)) {
        // Check if the most significant bit is 0
        if ((c & 0x80) == 0) {
            // Single-byte character
            ++count;
        } else {
            // Multibyte character
            // Determine the number of bytes it occupies
            int num_bytes = 0;
            while ((c & (1 << (7 - num_bytes))) != 0) {
                ++num_bytes;
            }
            // Check if the character is correct
            bool correct = true;
            for (int i = 1; i < num_bytes; ++i) {
                if (!std::cin.get(c) || (c & 0xC0) != 0x80) {
                    correct = false;
                    break;
                }
            }
            if (correct) {
                ++count;
            }
        }
    }
    return count;
}
  */