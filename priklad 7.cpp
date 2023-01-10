/*
Předpokládejte, že na disku existuje binární soubor, v němž jsou uložena rastrová grafická data. Na začátku
souboru je informace o počtu pixelů v ose x, o počtu pixelů v ose y(dvě čtyřbajtová celá čísla) a o počtu bitů na jeden pixel
(jeden bajt s možnými hodnotami 8, 16, 24, 32). Přečtěte tento soubor a zjistěte, kolik pixelů má stejnou hodnotu jako
první pixel obrazu. Jméno souboru je zadáno jako první parametr z příkazového řádku; pokud parametr chybí, program
pouze vypíše odpovídající chybové hlášení.


#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char* argv[])
{
    // Check if a file name was provided
    if (argc < 2) {
        std::cerr << "Error: No file name provided." << std::endl;
        return 1;
    }

    // Open the file
    std::ifstream file(argv[1], std::ios::binary);
    if (!file) {
        std::cerr << "Error: Failed to open file." << std::endl;
        return 1;
    }

    // Read the width and height of the image
    std::uint32_t width, height;
    file.read(reinterpret_cast<char*>(&width), sizeof(std::uint32_t));
    file.read(reinterpret_cast<char*>(&height), sizeof(std::uint32_t));

    // Read the number of bits per pixel
    std::uint8_t bitsPerPixel;
    file.read(reinterpret_cast<char*>(&bitsPerPixel), sizeof(std::uint8_t));

    // Calculate the number of bytes per pixel
    std::uint32_t bytesPerPixel = bitsPerPixel / 8;

    // Read the first pixel value
    std::uint8_t firstPixel[4] = { 0 };
    file.read(reinterpret_cast<char*>(firstPixel), bytesPerPixel);

    // Count the number of pixels with the same value as the first pixel
    std::uint32_t count = 0;
    std::uint8_t pixel[4] = { 0 };
    for (std::uint32_t y = 0; y < height; ++y) {
        for (std::uint32_t x = 0; x < width; ++x) {
            file.read(reinterpret_cast<char*>(pixel), bytesPerPixel);
            if (std::memcmp(pixel, firstPixel, bytesPerPixel) == 0) {
                ++count;
            }
        }
    }

    std::cout << "Number of pixels with the same value as the first pixel: " << count << std::endl;

    return 0;
}
 */