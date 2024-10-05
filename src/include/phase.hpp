#pragma once
#include <file.hpp>
#include <print.hpp>

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void selectDeckPhase(File& file, int& user_input, std::vector<std::string>& decks_list);
void selectCardPhase(File& file, int& user_input, const std::string& deck_filepath, std::vector<std::string>& selected_deck);
void readSelectedCard(File& file, const std::string& card_filepath, std::vector<std::string>& card);
