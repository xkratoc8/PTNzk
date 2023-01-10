/*
Předpokládejte binární soubor,
v němž jsou uloženy údaje o knihách – název knihy, autor (řetězce v kódování UTF-8 uložené jako posloupnosti bajtů zakončené bajtem s hodnotou nula) a kód EAN (13 znaků).
Diskové jméno souboru je zadáno jako první parametr z příkazového řádku. Pokud není parametr zadán nebo je chybný, program pouze
vypíše chybové hlášení a nastaví výstupní kód 2. Je-li vše v pořádku, čtěte zadaný soubor, získané záznamy seřaďte podle
kódu EAN a vypište vhodnou formou na standardní výstup. Pro řazení použijte libovolnou metodu pracující v lineárně
logaritmickém čase


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Book {
    std::string name;
    std::string author;
    std::string ean;
};

int main(int argc, char** argv) {
    // Check if a file name was provided
    if (argc < 2) {
        std::cerr << "Error: No file name provided." << std::endl;
        return 2;
    }

    // Open the file
    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 2;
    }

    // Read the file and store the data in a vector of Books
    std::vector<Book> books;
    while (file) {
        Book book;
        std::getline(file, book.name, '\0');
        std::getline(file, book.author, '\0');
        std::getline(file, book.ean, '\0');
        books.push_back(book);
    }

    // Sort the books by EAN code using a linear time sorting algorithm
    std::sort(books.begin(),books.end(), [](const Book& a, const Book& b){
        return a.ean < b.ean;
    });
    // Write the sorted data to the standard output
    for (const Book& book : books) {
        std::cout << book.name << '\0' << book.author << '\0' << book.ean << '\0';
    }

    return 0;
}
*/