#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "modules/searcherOfRootWords.h"

int main() {
    std::vector<std::string> test{ "packNumberOne.txt", "packNumberTwo.txt", "packNumberThree.txt", "packNumberFour.txt" };
    
    for ( auto current_file : test ) {
        std::vector<std::string> root_words;
        std::ifstream inputFile("files/" + current_file);

        std::string current_line;
        if (inputFile.is_open()) {
            do {
                getline(inputFile, current_line);
                root_words.push_back(current_line);
            } while ( !inputFile.eof() );

            inputFile.close();
            root_words.pop_back();

            std::cout << "There are words: ";
            for (int count = 0; count < root_words.size(); ++count) {
                std::cout << root_words[count] << " ";
            } std::cout << '\n';
        }

        search_rw_longest(root_words);
        search_rw_major(root_words);

        std::cout << '\n';
    }
}
