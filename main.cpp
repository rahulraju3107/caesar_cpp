#include <iostream>
#include <string>
#include <cctype>   // For std::isalpha & std::isupper

char rotate(char c, int n);

int main()
{
    int k;
    std::cout << "Enter Caesar cipher key (integer): ";
    std::cin >> k;
    std::cin.ignore(); // clear newline left in input buffer
    
    // Prompt for plaintext
    std::string plaintext;
    std::cout << "plaintext:  ";
    std::getline(std::cin, plaintext);
    
    // Rotate characters
    std::cout << "ciphertext: ";
    for (char c : plaintext)
    {
        std::cout << rotate(c, k);
    }
    std::cout << std::endl;
    
    return 0;
}

char rotate(char c, int n)
{
    // Return characters that are not letters
    if (!std::isalpha(static_cast<unsigned char>(c)))
    {
        return c;
    }
    
    if (std::isupper(static_cast<unsigned char>(c)))
    {
        return 'A' + (c - 'A' + n) % 26;
    }
    else
    {
        return 'a' + (c - 'a' + n) % 26;
    }
}
