#include <array>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void clearScreen() {
    std::cout << "\e[1;1H\e[2J";
};

void greenText() {
    std::cout << "\033[1;32m";
}

void redText() {
    std::cout << "\033[1;31m";
}

void resetTextColor() {
    std::cout << "\033[0m";
}

int main() {
    std::string user_input;
    int temp_user_input;

    std::ifstream deck_list_file;
    std::ifstream deck_file;
    std::ifstream card_file;

    std::string filepath;
    const std::string deck_list_path = "../decks.txt";
    const std::string deck_dir = "../deck/";
    std::string deck_name;
    const std::string card_dir = "../card/";
    int card_index;

    std::string line;

    std::vector<std::string> deck_list;
    std::vector<std::string> deck;
    std::array<std::string, 3> card;


    // Phase 1 - open deck list
    deck_list_file.open(deck_list_path);

    while(std::getline(deck_list_file, line)) {
        deck_list.push_back(line);
    }

    clearScreen();
    greenText();
    std::cout << "Select a deck" << '\n'; 
    resetTextColor();

    for (int i = 0; i < deck_list.size(); i++)
        std::cout << i+1 << ". " << deck_list[i] << '\n';

    redText();
    while (true) {
        std::cout << "-> ";
        std::cin >> user_input;
        try {
            temp_user_input = std::stoi(user_input);
            if (temp_user_input <= 0) {
                std::cout << "Invalid input: too low" << '\n';
                continue;
            } else if (temp_user_input > deck_list.size()) {
                std::cout << "Invalid input: too high" << '\n';
                continue;
            }
        } catch (const std::invalid_argument&) {
            std::cout << "Invalid input: not int" << '\n';
            continue;
        }

        break;
    }
    resetTextColor();

    deck_list_file.close();

    // Phase 2 - open deck file
    deck_name = deck_list[std::stoi(user_input) - 1];
    filepath = deck_dir + deck_name + ".txt";
    deck_file.open(filepath);

    while(std::getline(deck_file, line)) {
        deck.push_back(line);
    }

    clearScreen();
    greenText();
    std::cout << "Select a card" << '\n'; 
    resetTextColor();

    for (int i = 0; i < deck.size(); i++)
        std::cout << i+1 << ". " << deck[i] << '\n';

    redText();
    while (true) {
        std::cout << "-> ";
        std::cin >> user_input;
        try {
            temp_user_input = std::stoi(user_input);
            if (temp_user_input <= 0) {
                std::cout << "Invalid input: too low" << '\n';
                continue;
            } else if (temp_user_input > deck_list.size()) {
                std::cout << "Invalid input: too high" << '\n';
                continue;
            }
        } catch (const std::invalid_argument&) {
            std::cout << "Invalid input: not int" << '\n';
            continue;
        }

        break;
    }
    card_index = std::stoi(user_input);
    resetTextColor();

    deck_file.close();

    // Phase 3 - open card file
    while (1) {
        filepath = card_dir + deck_name + "/" + deck[card_index-1] + ".txt";
        card_file.open(filepath);

        if (!card_file.is_open()) {
            std::cerr << "Error opening file: " << filepath << std::endl;
            break;  // Exit if the card file can't be opened
        }

        // Reset the card array
        card.fill("");

        int index = -1;

        while (std::getline(card_file, line)) {
            if (line == "@title") {
                index = 0;
            } else if (line == "@front") {
                index = 1;
            } else if (line == "@back") {
                index = 2;
            } else if (index != -1) {
                // Allow multiline content for each section
                if (!card[index].empty()) {
                    card[index] += "\n";  // Add new line if content exists
                }
                card[index] += line;
            }
        }

        card_file.close();  // Move the close here after reading
        
        bool card_revealed = false;
        
        while (1) {
            clearScreen();

            // Display title & front by default
            std::cout << card[0] << "\n\n";
            std::cout << card[1] << '\n';

            // Display back text if wanting to reveal
            if (card_revealed) {
                std::cout << card[2] << "\n\n";
            }

            // Ask for navigation or back reveal
            greenText();
            std::cout << "<a> <s> <d>" << '\n';
            resetTextColor();

            // Ask for user input
            redText();
            std::cout << "-> ";
            std::cin >> user_input;
            resetTextColor();

            // Exit loop if want to change card
            if (user_input == "a" || user_input == "d") break;

            // Reveal back of card
            if (user_input == "s" && card_revealed) {
                card_revealed = false;
            } else if (user_input == "s") {
                card_revealed = true;
            }
        }
 
        // Change card
        if (user_input == "a") {
            card_index--;
            if (card_index < 1) {
                card_index = deck.size();
            }
        } else if (user_input == "d") {
            card_index++;
            if (card_index > deck.size()) {
                card_index = 1;
            }
        }
    }
}
