/*
Napište podprogram, který dostane jako parametr pole bajtů. Předpokládejte, že hodnoty jednotlivých bajtů
nepřekračují 127. Podprogram zabezpečí každý bajt tohoto pole sudou paritou a vypočte kontrolní výhradní součet
(XOR) všech takto upravených bajtů. Upravené pole a kontrolní součet jsou výstupy podprogramu. Definujte rovněž
potřebné datové typy. (Sudá parita: počet binárních jedniček v každém bajtu je sudý.)



 #include <cstdint>

// Define a type for the array of bytes
typedef std::uint8_t byte;

// Define a type for the checksum
typedef std::uint8_t checksum;

void secure_with_parity_and_calculate_checksum(const byte* bytes, std::size_t size, byte* secured_bytes, checksum& xor_checksum)
{
    // Initialize the checksum with zero
    xor_checksum = 0;

    for (std::size_t i = 0; i < size; ++i)
    {
        // Secure the current byte with even parity
        secured_bytes[i] = bytes[i] | (count_ones(bytes[i]) % 2 == 0);

        // Update the checksum
        xor_checksum ^= secured_bytes[i];
    }
}

int count_ones(byte b)
{
    int count = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (b & (1 << i))
            ++count;
    }
    return count;
}


















 */