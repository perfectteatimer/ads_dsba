#include <iostream>
#include <vector>
#include <string>

std::string constructWordFromPrefix(const std::vector<int>& prefixFunction) {
    std::string word = "a";  // Start with an arbitrary character
    char nextChar = 'b';     // Next character for the case of 0 in prefix function

    for (size_t i = 1; i < prefixFunction.size(); ++i) {
        if (prefixFunction[i] == 0) {
            // If the prefix function is 0, add a new character
            word += nextChar;
            // Move to the next character
            nextChar++;
        } else {
            // If the prefix function is not 0, repeat the character from the corresponding position
            word += word[prefixFunction[i] - 1];
        }
    }

    return word;
}

int main() {
    // Example usage
    std::vector<int> prefixFunction = {0, 0, 1, 0, 1, 2, 3, 1};
    std::string constructedWord = constructWordFromPrefix(prefixFunction);

    std::cout << "Constructed Word: " << constructedWord << std::endl;

    return 0;
}
