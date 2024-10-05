#include "print.hpp"
#include <phase.hpp>

void selectDeckPhase(File& file, int& user_input, std::vector<std::string>& decks_list) {
    // Open & load & close decks.txt file
    file.changePath("../decks.txt");
    file.open();
    file.load(decks_list);
    file.close();

    // Print
    clearScreen();
    greenText();
    std::cout << "Select a deck: " << '\n';
    resetTextColor();

    for (int i = 0; i < decks_list.size(); i++) {
        std::cout << i+1 << ". " << decks_list[i] << '\n';
    }

    /// -> get user input
    redText();
    std::cout << "-> ";
    resetTextColor();

    std::string user_input_string;
    std::cin >> user_input_string;
    int ui;

    while (true) {
        try {
            ui = std::stoi(user_input_string); // Convert input to an integer

            if (ui <= 0) {
                std::cout << "Invalid input. Please enter a number greater than 0.\n";
                continue; // Ask for input again
            }

        } catch (const std::invalid_argument&) {
            std::cout << "Invalid input! Please enter a valid number.\n";
            continue;
        } catch (const std::out_of_range&) {
            std::cout << "Number is out of range!\n";
            continue;
        }

        break; // Exit loop if input is valid
    }

    user_input = ui;
}

void selectCardPhase(File& file, int& user_input, const std::string& deck_filepath, std::vector<std::string>& selected_deck) {
    // Open & load & close selected deck
    file.changePath(deck_filepath);
    file.open();
    file.load(selected_deck);
    file.close();

    // Print
    clearScreen();
    greenText();
    std::cout << "Select a card: " << '\n';
    resetTextColor();

    for (int i = 0; i < selected_deck.size(); i++) {
        std::cout << i+1 << ". " << selected_deck[i] << '\n';
    }

    /// -> get user input
    redText();
    std::cout << "-> ";
    resetTextColor();

    std::string user_input_string;
    std::cin >> user_input_string;
    int ui;

    while (true) {
        try {
            ui = std::stoi(user_input_string); // Convert input to an integer

            if (ui <= 0) {
                std::cout << "Invalid input. Please enter a number greater than 0.\n";
                continue; // Ask for input again
            }

        } catch (const std::invalid_argument&) {
            std::cout << "Invalid input! Please enter a valid number.\n";
            continue;
        } catch (const std::out_of_range&) {
            std::cout << "Number is out of range!\n";
            continue;
        }

        break; // Exit loop if input is valid
    }

    user_input = ui;
}

void readSelectedCard(File& file, const std::string& card_filepath, std::vector<std::string>& card) {
    std::vector<std::string> card_file;

    // Open & load & close selected deck
    file.changePath(card_filepath);
    file.open();
    file.load(card_file);
    file.close();

    // Filter card based on tags
    std::string line;
    for (const auto& line : card_file) {
        if (line[0] != '@') {
            card.push_back(line);
        }
    }

    // Print
    clearScreen();

    for (const auto& entry : card) {
        std::cout << entry << std::endl;
    }
}
