#include "Blackjack.h"

#define HUMAN_PLAYER 0
#define HOUSE_PLAYER 1
#define WIN 1
#define TIE 0
#define LOSS -1
#define CONTINUE 2
#define GAME_LOSS 3

// g++ -std=c++11 -Wall Blackjack.cpp main.cpp -o B

// House always has to hit on 16 and lower, and stand on 17 and higher.

BlackJack::BlackJack(){
    this->current_player = HUMAN_PLAYER;
    this->starting_pool = 100;
    this->bet = 0;
    this->winnings = starting_pool;
    this->Game_cards = Game_cards;
    this->given_card = " ";
}

void BlackJack::welcome(){
    std::cout << "===========================================================Welcome to a C++ version of Blackjack============================================================" << std::endl;
    std::cout << "This particular game has you playing against an ai, defined as the House." << std::endl;
    std::cout << "The rules are simple: " << std::endl;
    std::cout << "1. Get as close to 21 as possible without going over." << std::endl;
    std::cout << "\t" << "There are red and black cards, with number cards from 1-10, as well as Jack, Queen, King and Ace cards." <<std::endl;
    std::cout << "\t" << "Jack, Queen and King cards all have a value of 10, and the Ace cards will have a value of 11 for simplicities sake." << std::endl;
    std::cout << "2. Four initial random cards will be dealt. Two to the player, and two to the House." << std::endl;
    std::cout << "3. The player starts with an initial pool of $100, and must bet some of it, up to the total amount they have." << std::endl;
    std::cout << "4. The player can choose to either stand or hit." << std::endl;
    std::cout << "\t" << "Standing means the player is happy with their total, and will not recieve anymore cards." << std::endl;
    std::cout << "\t" << "Hitting means that the player will get another random card, and can perform this action as many times as they like," << std::endl;
    std::cout << "\t" << "as long as their total doesn't go above 21." << std::endl;
    std::cout << "5. After the player has chosen to stand, the House will then begin drawing random cards," << std::endl;
    std::cout << "   always hitting if their total is 16 or less, and always standing if their total is 17 or more." << std::endl;
    std::cout << "6. If the player wins the game, they will earn money equal to their bet." << std::endl;
    std::cout << "7. If the House wins the game, the player will lose money equal to their bet." << std::endl;
    std::cout << "8. There are no limits to how many times the player can play, but if the total amount of money owned ever reaches $0, the player loses the game." << std::endl;
}

std::string BlackJack::choose(){
    std::string potential_choice;
    std::string choice = " ";
    std::cout << " " << std::endl;
    std::cout << "If you would like to play Blackjack, please enter 'Blackjack' (without the quotations)." << std::endl;
    std::cout << "If you would like to see your total earnings for this session, please enter 'Show-me-the-money' (without the quotations)." << std::endl;
    std::cout << "If you would like to exit this program, please enter 'Quit'." << std::endl;
    std::cin >> potential_choice;
    while (choice == " "){
        if (potential_choice == "Blackjack" || potential_choice == "Show-me-the-money" || potential_choice == "Quit"){
            choice = potential_choice;
        }
        else{
            std::cout << "That choice isn't an option, please enter an acceptable choice" << std::endl;
            std::cin >> potential_choice;
        }
    }
    return choice;
}

// returns a random card from the Game_cards vector, and then deletes that card, so it can't be drawn during the same round.
std::string BlackJack::random_card(){
    srand(time(0));
    int given_random = rand() % Game_cards.size();
    std::string given_card = Game_cards[given_random];
    Game_cards.erase(Game_cards.begin() + given_random);
    return given_card;
}

int BlackJack::game_condition(int Player_total, int House_total){
    if (current_player == HUMAN_PLAYER){
        if (winnings == 0){
            return GAME_LOSS;
        }
        else if (Player_total == 21){
            return WIN;
        }
        else if (House_total == 21 || Player_total > 21){
            return LOSS;
        }
        else if (Player_total == 21 && House_total == 21){
            return TIE;
        }
    }
    else if (current_player == HOUSE_PLAYER){
        if (Player_total > House_total || House_total > 21){
            return WIN;
        }
        else if (Player_total < House_total){
            return LOSS;
        }
        else if (Player_total == House_total){
            return TIE;
        }
    }
    return CONTINUE;
}

int BlackJack::card_to_number(){
    std::string card = random_card();
    //Red cards
    if (card == "R one"){
        return 1;
    }
    if (card == "R two"){
        return 2;
    }
    if (card == "R three"){
        return 3;
    }
    if (card == "R four"){
        return 4;
    }
    if (card == "R five"){
        return 5;
    }
    if (card == "R six"){
        return 6;
    }
    if (card == "R seven"){
        return 7;
    }
    if (card == "R eight"){
        return 8;
    }
    if (card == "R nine"){
        return 9;
    }
    if (card == "R ten"){
        return 10;
    }
    if (card == "R jack"){
        return 10;
    }
    if (card == "R queen"){
        return 10;
    }
    if (card == "R king"){
        return 10;
    }
    if (card == "R ace"){
        return 11;
    }
    // Black cards
    if (card == "B one"){
        return 1;
    }
    if (card == "B two"){
        return 2;
    }
    if (card == "B three"){
        return 3;
    }
    if (card == "B four"){
        return 4;
    }
    if (card == "B five"){
        return 5;
    }
    if (card == "B six"){
        return 6;
    }
    if (card == "B seven"){
        return 7;
    }
    if (card == "B eight"){
        return 8;
    }
    if (card == "B nine"){
        return 9;
    }
    if (card == "B ten"){
        return 10;
    }
    if (card == "B jack"){
        return 10;
    }
    if (card == "B queen"){
        return 10;
    }
    if (card == "B king"){
        return 10;
    }
    if (card == "B ace"){
        return 11;
    }
    return 0;
}

int BlackJack::Blackjack_game(){
    return play_game();
}

int BlackJack::play_game(){
    int Player_total = 0;
    int House_total = 0;
    this->current_player = HUMAN_PLAYER;
    int status = CONTINUE;
    int potential_bet = 0;
    this->bet = 0;
    winnings = winnings;
    std::cout << "Current winnings are " << winnings << std::endl;
    for (int i = 0; i < 28; i++){
        Game_cards.push_back(Blackjack_cards[i]);
    }
    Player_total = card_to_number() + card_to_number();
    House_total = card_to_number() + card_to_number();
    std::cout << "The Player's total is " << Player_total << " and the Houses total is " << House_total << std::endl;
    status = game_condition(Player_total, House_total);
    if (winnings == 0){
        std::cout << "You have no more money to bet, you've gone bust." << std::endl;
        return 0;
    }
    std::cout << "Please enter an amount you would like to bet." << std::endl;
    std::cin >> potential_bet;
    while (bet == 0){
        if (potential_bet <= winnings){
            bet = potential_bet;
        }
        else{
            std::cout << "You don't have that much money to bet, please enter an acceptable bet." << std::endl;
            std::cin >> potential_bet;
        }
    }
    while (status == CONTINUE){
        if (current_player == HUMAN_PLAYER){
            std::string game_choice = " ";
            // std::cout << "Would you like to stand or hit?" << std::endl;
            // std::cin >> game_choice;
            while (game_choice != "stand" || game_choice != "Stand" || game_choice != "STAND"){
                std::cout << "Would you like to stand or hit?" << std::endl;
                std::cin >> game_choice;
                if (game_choice == "stand" || game_choice == "Stand" || game_choice == "STAND"){
                    break;
                }
                else if (game_choice == "hit" || game_choice == "Hit" || game_choice == "HIT"){
                    Player_total = Player_total + card_to_number();
                    std::cout << "The Player's total is now " << Player_total << std::endl;
                    status = game_condition(Player_total, House_total);
                    //std::cin >> game_choice;
                }
                else{
                    std::cout << "invalid choice, please enter a choice again." << std::endl;
                    std::cin >> game_choice;
                }
            }
        }
        else if (current_player == HOUSE_PLAYER){
            std::cout << "It's the Houses turn now." << std::endl;
            while (House_total < 17){
                House_total = House_total + card_to_number();
                std::cout << "The Houses total is now " << House_total << std::endl;
            }
        }
        status = game_condition(Player_total, House_total);
        current_player = !current_player;
    }
    if (status == WIN){
        std::cout << "The Player wins, Congradulations!!" << std::endl;
        winnings = winnings + bet;
        std::cout << "Your winnings are " << winnings << std::endl;
        //total_money = winnings;
        char continue_choice;
        std::cout << "Would you like to play again? (Y/N)" << std::endl;
        std::cin >> continue_choice;
        if (continue_choice == 'Y'){
            play_game();
        }
        else if (continue_choice == 'N'){
            return winnings;
        }
    }
    else if (status == LOSS){
        std::cout << "The House wins, sorry." << std::endl;
        winnings = winnings - bet;
        std::cout << "Your winnings are " << winnings << std::endl;
        //total_money = winning;
        std::string continue_choice = " ";
        std::cout << "Would you like to play again? (Y/N)" << std::endl;
        std::cin >> continue_choice;
        if (continue_choice == "Y"){
            play_game();
        }
        else if (continue_choice == "N"){
            return winnings;
        }
    }
    else if (status == TIE){
        std::cout << "The impossible just happened, it's a tie." << std::endl;
        winnings = winnings;
        std::cout << "Your winnings are " << winnings << std::endl;
        char continue_choice;
        std::cout << "Would you like to play again? (Y/N)" << std::endl;
        std::cin >> continue_choice;
        if (continue_choice == 'Y'){
            play_game();
        }
        else if (continue_choice == 'N'){
            return winnings;
        }
    }
    else if (status == GAME_LOSS){
        std::cout << "You have no more money to bet, you've gone bust." << std::endl;
        return 0;
    }
    return 0;
}