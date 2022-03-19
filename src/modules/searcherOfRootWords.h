#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#ifndef SEARCHEROFROOTWOORDS_H
#define SEARCHEROFROOTWOORDS_H

void search_rw_longest(std::vector<std::string> root_words) {
    std::string longest_word;
    int count_lw_main = 0;
    int count_lw_sub = 0;

    for (auto current_word : root_words) {
        const auto begin_lw = 0;
        std::string sub_lw;

        for (auto end_lw = (current_word.size() - 1); end_lw > 0; end_lw--) {
            sub_lw = current_word.substr(begin_lw, end_lw);

            for (auto inner_cw : root_words) {
                if ( inner_cw.find(sub_lw) != std::string::npos && inner_cw[0] == sub_lw[0]) {
                    ++count_lw_sub;
                }
            }

            if ( count_lw_sub > count_lw_main ) {
                count_lw_main = count_lw_sub;
                longest_word = sub_lw;
            } 

            count_lw_sub = 0;
        }
    }

    if ( count_lw_main > 1 ) {
        std::cout << "The longest word: ";
        std::cout << "=> " << longest_word << " (" << count_lw_main << ")" << '\n';

        std::ofstream file_lw("files/file_lw.txt");
        file_lw << longest_word << " (" << count_lw_main << ")" << '\n';
        file_lw.close();
    } else {
        std::cout << "The longest word: None" << '\n';

        std::ofstream file_lw("files/file_lw.txt");
        file_lw << "None" << '\n';
        file_lw.close();
    }
}

void search_rw_major(std::vector<std::string> root_words) {
    std::string major_word;
    int count_mw_main = 0;
    int count_mw_sub = 0;

    for (auto current_word : root_words) {
        const auto begin_mw = 0;
        std::string sub_mw;

        for (auto end_mw = 1; end_mw < current_word.size(); end_mw++) {
            sub_mw = current_word.substr(begin_mw, end_mw);

            for (auto inner_cw : root_words) {
                if ( inner_cw.find(sub_mw) != std::string::npos && inner_cw[0] == sub_mw[0]) {
                    ++count_mw_sub;
                }
            }

            if ( count_mw_sub > count_mw_main ) {
                count_mw_main = count_mw_sub;
                major_word = sub_mw;
            } 

            count_mw_sub = 0;
        }
    }

    if ( count_mw_main > 1 ) {
        std::cout << "The major word: ";
        std::cout << "=> " << major_word << " (" << count_mw_main << ")" << '\n';

        std::ofstream file_mw("files/file_mw.txt");
        file_mw << major_word << " (" << count_mw_main << ")" << '\n';
        file_mw.close();
    } else {
        std::cout << "The major word: None" << '\n';

        std::ofstream file_mw("files/file_mw.txt");
        file_mw << "None" << '\n';
        file_mw.close();
    }
}

#endif
