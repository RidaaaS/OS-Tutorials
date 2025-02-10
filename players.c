/*
 * Tutorial 4 Jeopardy Project 
 * Group 5
 * Alexy Pichette (100822470)
 * Rida Siddiqi (100825212)
 * Muhammad Mujtaba Madad (100790195)
 * Ishmeet Kaur (100809450)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "players.h"

// Returns true if the player name matches one of the existing players
bool player_exists(player *players, int num_players, char *name){
    for(int i=0; i < num_players; i++){
        if(strcmp(players[i].name, name) == 0){
            return true;
        }
    }
    
    return false;
}

// Go through the list of players and update the score for the 
// player given their name
void update_score(player *players, int num_players, char *name, int score){
    for(int i=0; i < num_players; i++){
        if(strcmp(players[i].name, name) == 0){
            players[i].score += score;
        }
    }
}

void highest_score(player *players, int num_players){
    int highest_score = 0;
    char *winner;
    
    for(int i=0; i < num_players; i++){
        if(players[i].score > highest_score){
            highest_score = players[i].score;
            winner = players[i].name;
        }
    }
    
    printf("\n\nThe Winner of this Game, with an astonishing $%d is %s\n", highest_score, winner);
}
