/*
 IN C++ Uvažujte implementaci hry v šachy.Údaje ookamžitém stavu hryjsouobsaženy v binárním souboru,kde bude
potřeba pro každou figuru evidovat tyto údaje: druh figury (pěšec, jezdec, střelec, věž, dáma, král), barva (černá/bílá)
a pozice na šachovnici, je-li figura ještě ve hře (v obvyklém tvaru, např. e4).
 Pokud byla figura již vyřazena ze hry, má na
místě pozice řetězec „ -- “. Při každém tahu se tento soubor aktualizuje.
1. Navrhněte vhodný způsob uložení dat v souboru a definujte odpovídající datové typy reprezentující šachovou
hru.
2. Implementujte operaci pro zjištění údaje o zvoleném poli zadaném obvyklým tvarem, např. e4 . Způsob, jakým
tato operace sdělí výsledek, si definuje uživatel podprogramem, který je předán do operace jako parametr


#include <iostream>
using namespace std;

enum PieceType { Pawn, Knight, Bishop, Rook, Queen, King};

struct ChessPiece {
    PieceType type;
    bool color;
    string position;
};

const int BOARD_SIZE = 8;
ChessPiece chessboard[BOARD_SIZE][BOARD_SIZE];

ChessPiece getFieldData(const string& position){
    // Convert the position string (e.g. "e4") to row and column indices.
    int row = BOARD_SIZE - (position [1] - '0');
    int col = position[0] - 'a';
    return chessboard[row][col];
}

void printFieldData(const ChessPiece& piece) {
    std::cout << "Type: " << piece.type << std::endl;
    std::cout << "Color: " << (piece.color ? "Black" : "White") << std::endl;
    std::cout << "Position: " << piece.position << std::endl;
}

int main() {
    // Find the data of the field at position "e4".
    ChessPiece piece = getFieldData("e4");
    // Print the field data using the user-defined function.
    printFieldData(piece);
    return 0;
}
*/