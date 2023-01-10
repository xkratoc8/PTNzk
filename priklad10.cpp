/*
 Napište program realizující Caesarovu šifru – je-li znak čtený ze standardního vstupu písmeno anglické
abecedy, posune jej v abecedě o zadaný počet pozic (je-li například zadaný počet 3, pak z písmene C udělá F, z písmene X
udělá znovu A atd.). Program zároveň převede všechnamalá písmena na velká, všechny ostatní znaky ze vstupu vypouští.
Výsledek se vypisuje na standardní výstup.
Počet pozic, o které se písmena posouvají, je zadán jako první parametr z příkazového řádku. Pokud parametr chybí,
zjišťuje se, zda je touto hodnotou naplněna proměnná prostředí POSUV . Pokud ani tam žádná použitelná hodnota není,
použije se konstanta 4


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
    // Read the number of positions to shift from the command line or the POSUV environment variable
    int shift = 4;
    if (argc >= 2) {
        shift = atoi(argv[1]);
    } else {
        char* env = getenv("POSUV");
        if (env != nullptr) {
            shift = atoi(env);
        }
    }

    // Read the input string
    string input;
    getline(cin, input);

    // Perform the Caesar cipher
    string output;
    for (char c : input) {
        if (isalpha(c)) {
            char shifted = toupper(c) + shift;
            if (shifted > 'Z') {
                shifted -= 26;
            }
            output += shifted;
        }
    }

    // Print the output
    cout << output << endl;

    return 0;
}
 */