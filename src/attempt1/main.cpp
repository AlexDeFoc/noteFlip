#include <file.hpp>
#include <print.hpp>
#include <deck.hpp>
#include <card.hpp>
#include <phase.hpp>

#include <string>
#include <vector>

int main() {
    int user_input;
    std::string user_input_string;
    File file;

    // Phase 1 - read decks.txt
    std::vector<std::string> decks_list;
    selectDeckPhase(file, user_input, decks_list);
    
    // Phase 2 - read selected deck
    std::vector<std::string> selected_deck;
    std::string decks_dir = "../deck/";
    std::string deck_name = decks_list[user_input - 1];
    std::string deck_filepath = decks_dir + deck_name + ".txt";
    selectCardPhase(file, user_input, deck_filepath, selected_deck);

    //===================================================
    // Phase 3 - read selected card

    std::vector<std::string> card;
    std::string cards_dir = "../card/";
    std::string card_name = selected_deck[user_input - 1];
    std::string card_filepath = cards_dir + deck_name + "/" + card_name + ".txt";

    readSelectedCard(file, card_filepath, card, user_input_string);

    return 0;
}
