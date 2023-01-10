/*
Na standardním vstupu je řada čísel typu float (tj. formát IEEE single).
 Vypište na výstup všechna čísla,
 která mají ve strojovém (paměťovém) binárním vyjádření v exponentu alespoň 6 binárních jedniček.
 (Víte, že exponent je
v tomto čtyřbajtovém čísle umístěn na 8 bitech počínaje 2. bitem.)


#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

int main() {
    // Read in the input string
    string input;
    getline(cin, input);

    // Split the input string into individual numbers
    stringstream input_stream(input);
    float num;
    while (input_stream >> num) {
        // Convert the float to a char array
        char float_bytes[sizeof(float)];
        memcpy(float_bytes, &num, sizeof(float));

        // Extract the exponent bits
        char exponent_bits = float_bytes[1] & 0x7F;

        // Count the number of ones in the exponent bits
        int ones_count = 0;
        for (int i = 0; i < 8; i++) {
            if (exponent_bits & (1 << i)) {
                ones_count++;
            }
        }

        // Print the number if it has at least 6 ones in the exponent
        if (ones_count >= 6) {
            cout << num << endl;
        }
    }

    return 0;
}
 */