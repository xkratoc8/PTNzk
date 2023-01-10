/*
In C++ napište modul (hlavičkový i implementační soubor), který představuje abstraktní datový typ „řetězec znaků UTF-8“, v němž jsou zaznamenány znaky v kódování UTF-8.
Pro jednoduše předpokládejte, že znak v kódu
UTF-8 je pouze buď původní ASCII, tj. je uložen na jednom bytě a v jeho nejvyšším bitu má nulu, nebo je složen právě
ze dvou bytů, kde oba mají v nejvyšším bitu jedničku. Tento řetězec implementujte obyčejným polem, u kterého předpokládejte maximální délku 2000 bajtů, a napište následující operaci: UInit (vytvoří prázdný řetězec), ULength (zjistíte
počet znaků řetězce), UDelete (smaže z řetězce N znaků počínaje K -tým znakem; v případě, že tyto zadané hodnoty
jsou příliš velké, operace nebude dělat nic)


#include <iostream>
#include <cstring>

// Header file for the UTF-8 character string ADT

const int MAX_LENGTH = 2000;  // Maximum length of the string

class UTF8String {
public:
    // Constructs an empty string
    void UInit();

    // Returns the number of characters in the string
    int ULength() const;

    // Deletes N characters starting from the K-th character
    void UDelete(int k, int n);

    // Overloaded output operator for printing the string
    friend std::ostream& operator<<(std::ostream& out, const UTF8String& str);

private:
    char data[MAX_LENGTH];  // Array to store the characters in the string
    int length;  // Number of characters in the string
};

 #include "utf8string.h"

// Constructs an empty string
void UTF8String::UInit() {
    length = 0;
}

// Returns the number of characters in the string
int UTF8String::ULength() const {
    return length;
}

// Deletes N characters starting from the K-th character
void UTF8String::UDelete(int k, int n) {
    if (k < 0 || k >= length || n < 0) {
        // Do nothing if the specified values are too big or negative
        return;
    }

    if (k + n > length) {
        // Only delete up to the end of the string
        n = length - k;
    }

    // Shift the characters after the deleted section to the left by N characters
    for (int i = k; i < length - n; i++) {
        data[i] = data[i + n];
    }

    length -= n;
}

// Overloaded output operator for printing the string
std::ostream& operator<<(std::ostream& out, const UTF8String& str) {
    for (int i = 0; i < str.length; i++) {
        out << str.data[i];
    }
    return out;
}

























 */
