/*
Vytvořte obdélníkovou datovou strukturu implementující data křížovky o N řádcích a M sloupcích (N, M
budou konstanty, jejichž hodnoty vhodně zvolte). Každé políčko křížovky může obsahovat buď písmeno (obecně jeden
znak, kde mezera znamená nevyplněné písmeno), jednu legendu (libovolný řetězec doplněný informací o směru vodorovném nebo svislém) ,
 dvě legendy (vodorovnou a svislou) nebo může být zcela prázdné (není využito).
Legenda pro
vodorovný směr je vždy vlevo od daného slova nebo sousloví, legenda pro svislý směr je vždy nahoře nad slovem nebo
souslovím. Nad vytvořenou strukturou realizujte operaci, která na základě zadané souřadnice nějaké legendy zjistí, zda
je v křížovce vyplněno odpovídající slovo ve všech požadovaných písmenech.
 */

#include <iostream>
#include <vector>
#include <string>

struct CrosswordSquare
{
    char letter;
    std::string horizontal_legend;
    std::string vertical_legend;
};

class Crossword
{
public:
    Crossword(int num_rows, int num_columns)
            : num_rows_(num_rows), num_columns_(num_columns),
              squares_(num_rows * num_columns)
    {
    }

    // Accessors for the number of rows and columns.
    int num_rows() const { return num_rows_; }
    int num_columns() const { return num_columns_; }

    // Accessor for a square at a given row and column.
    CrosswordSquare& at(int row, int col) { return squares_[row * num_columns_ + col]; }
    const CrosswordSquare& at(int row, int col) const { return squares_[row * num_columns_ + col]; }

    // Determines if a word is filled in based on the coordinate of its legend.
    bool IsWordFilledIn(int row, int col) const
    {
        std::string word;
        std::string legend;
        bool is_horizontal = false;

        // Determine the direction of the word and the legend.
        if (at(row, col).horizontal_legend != "")
        {
            word = at(row, col).horizontal_legend;
            legend = at(row, col).horizontal_legend;
            is_horizontal = true;
        }
        else if (at(row, col).vertical_legend != "")
        {
            word = at(row, col).vertical_legend;
            legend = at(row, col).vertical_legend;
        }
        else
        {
            // There is no legend at this coordinate.
            return false;
        }

        // Check if the word is filled in.
        if (is_horizontal)
        {
            for (int i = 0; i < word.length(); i++)
            {
                if (at(row, col + i).letter != word[i])
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = 0; i < word.length(); i++)
            {
                if (at(row + i, col).letter != word[i])
                {
                    return false;
                }
            }
        }

        return true;
    }

private:
    int num_rows_;
    int num_columns_;
    std::vector<CrosswordSquare> squares_;
};

int main() {
    Crossword crossword(10, 10);

    // Set up a simple crossword puzzle.
    crossword.at(0, 0).horizontal_legend = "HELLO";
    crossword.at(0, 1).letter = 'H';
    crossword.at(0, 2).letter = 'E';
    crossword.at(0,3).letter = 'L';
    crossword.at(0,4).letter = 'L';
    crossword.at(0,5).letter = '0';

    std::cout << crossword.IsWordFilledIn(0, 0) << std::endl; // should output 1
    std::cout << crossword.IsWordFilledIn(1, 0) << std::endl; // should output 0

    return 0;
}