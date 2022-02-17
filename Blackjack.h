#ifndef __BLACKJACK__
#define __BLACKJACK__

#define HUMAN_PLAYER 0
#define HOUSE_PLAYER 1
#define WIN 1
#define TIE 0
#define LOSS -1
#define CONTINUE 2
#define GAME_LOSS 3

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

class BlackJack{
    private:
        int current_player;
        int starting_pool;
        int bet;
        int winnings;
        //int total_money;
        // vector that will be copied into a temp vector during every new instance of Blackjack.
        //std::vector<std::string> Blackjack_cards {"R one","R two","R three","R four","R five","R six","R seven","R eight","R nine","R ten","R jack","R queen","R king","R ace","B one","B two","B three","B four","B five","B six","B seven","B eight","B nine","B ten","B jack","B queen","B king","B ace"};
        std::string Blackjack_cards [28] = {"R one","R two","R three","R four","R five","R six","R seven","R eight","R nine","R ten","R jack","R queen","R king","R ace","B one","B two","B three","B four","B five","B six","B seven","B eight","B nine","B ten","B jack","B queen","B king","B ace"};
        std::vector<std::string> Game_cards;
        std::string given_card;
        /*
        this function will choose a card from a temp vector, and then delete said card from the temp vector,
        so the card can't be chosen again until the game ends.
        */
        std::string random_card();

        // converts the return value from random_card into a number that can be added to the total.
        int card_to_number();

        int game_condition(int Player_total, int House_total);

        // Function that plays the game, is private because couldn't properly define Blackjack_cards vector.
        int play_game();

    public:
        // constructor;
        BlackJack();
        // Function that tells the player about the rules of the game.
        void welcome();
        /*
        allows the player to choose how much money to bet, whether they will take another card or not,
        or whether they choose to play the game or not.
        */
        std::string choose();

        // takes an input from choose function, and runs other functions accordingly.
        //void game_choice(std::string chosen_action);

        /*
        function that will play the game based on the choies made in
        */
        //int play_game(std::vector<std::string> Blackjack_cards);

        // Function that calls the play_game() function.
        int Blackjack_game();
};

#endif