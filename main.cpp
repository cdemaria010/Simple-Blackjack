#include "Blackjack.h"

// Need to create objects for the other functions to work

int total_money = 0;

int main(){
    BlackJack game;
    game.welcome();
    std::string chosen_action = game.choose();
    while(chosen_action != /* whatever the chosen string for quitting the program is */ "Quit"){
        if (chosen_action == /* command for playing the game */ "Blackjack"){
            //std::cout << "chosen action test" << std::endl;
            int result = game.Blackjack_game();
            total_money = total_money + result;
            //std::cout << "Your total winnings are: " << total_money << std::endl;
            chosen_action = game.choose();
        }
        else if (chosen_action == /* command to view total money */ "Show-me-the-money"){
            std::cout << "Wow, look at all that money. Why, it's $" << total_money << std::endl;
            chosen_action = game.choose();
        }
        else{
            std::cout << "Invalid choice, please enter an acceptable choice." << std::endl;
            chosen_action = game.choose();
        }
    }
    return 0;
}