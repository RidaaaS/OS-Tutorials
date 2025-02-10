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
#include "questions.h"

// Array of Questions
question questions[NUM_QUESTIONS] = {
    {"Science", "What is the chemical symbol for water.", "H2O?", 100, false},
    {"Geography", "What is the capital of France.", "Paris?", 100, false},
    {"History", "Who was the first President of the United States.", "Washington?", 100, false},
    
    {"Science", "Which planet is known as the 'Red Planet'.", "Mars?", 200, false},
    {"Geography", "Name the country that is both an island and a continent.", "Australia?", 200, false},
    {"History", "In which year did the Titanic sink", "1912?", 200, false},
    
    {"Science", "What is the name of the force that causes objects to fall toward the Earth.", "Gravity?", 300, false},
    {"Geography", "Identify the largest ocean by surface area.", "Pacific Ocean?", 300, false},
    {"History", "This Canadian city hosted the 2010 Winter Olympics.", "Vancouver?", 300, false},
    
    {"Science", "The process by which liquid water turns into water vapor.", "Evaporation?", 400, false},
    {"Geography", "Name the capital of Canada.", "Ottawa?", 400, false},
    {"History", "This man was the first Prime Minister of Canada.", "John A. Macdonald?", 400, false},
    
    {"Science", "This scientific field studies fossils.", "Paleontology?", 500, false},
    {"Geography", "This is the hottest continent on Earth.", "Africa?", 500, false},
    {"History", "The name of the submarine that imploded while visiting the remains of the Titanic is named the.", "Titan?", 500, false},
};

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void){
    printf("\t| Science   |   Geography   |   History |\n");
    for(int i=0; i <NUM_QUESTIONS; i++){
        if((questions[i].answered == false)){
            printf("\t   %i\t", questions[i].value);
        }
        else {
            printf("\t   ---\t");
        }
        if ((i+1) % 3==0) {
            printf("\n");
        }
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value){
    for(int i=0; i < NUM_QUESTIONS; i++){
        if(strcmp(questions[i].category, category) == 0 && questions[i].value == value){
            printf("%s\n", questions[i].question);
        }
    }
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer){
    // Look into string comparison functions
    for(int i=0; i < NUM_QUESTIONS; i++){
        if(strcmp(questions[i].category, category) == 0 && questions[i].value == value){
            if(strcmp(questions[i].answer, answer) == 0){
                return true;
            }
        }
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value){
    // lookup the question and see if it's already been marked as answered
    for(int i=0; i < NUM_QUESTIONS; i++){
        if(strcmp(questions[i].category, category) == 0 && questions[i].value == value){
            return questions[i].answered;
        }
    }
    
    return true;
}

bool remove_question(char *category, int value){
    for(int i=0; i < NUM_QUESTIONS; i++){
        if(strcmp(questions[i].category, category) == 0 && questions[i].value == value){
            questions[i].answered = true;
            break;
        }
    }
}

bool check_if_finished(){
    for(int i=0; i < NUM_QUESTIONS; i++){
        if(questions[i].answered == false){
            return false;
        }
    }
    return true;
}

