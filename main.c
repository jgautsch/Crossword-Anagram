//
//  main.c
//  Crossword_Anagram_lab8
//
//  Created by Jon Gautsch
//  CSE20211
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_OF_WORDS 20
#define MAX_WORD_LENGTH 15

void wordListInput(char wordList[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH]);
void printCharArray(char wordList[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH]);
void capitalizeWordList(char wordList[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH]);

/*************************************************************************/
/*********************        MAIN      **********************************/
/*************************************************************************/

int main(int argc, const char * argv[]){

    printf("Jon's Crossword Puzzle Generator\n----------------------------------\n");
    printf("Enter a list of words (%d words at most):\n", MAX_NUM_OF_WORDS);
    
    char wordList[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH] = {"jump", "test", "leslie", "and", "I", "are", "going", "to", "the", "bookstore", "today", "."};
    
    wordListInput(wordList);
    capitalizeWordList(wordList);
    printCharArray(wordList);
    
    return 0;
}

/*********************     Word List Input     ***************************/

void wordListInput(char wordList[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH]){
    
}

/*********************     Print Char Array    ***************************/

void printCharArray(char wordList[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH]){
    int i;
    for (i=0; i < MAX_NUM_OF_WORDS; i++) {
        printf("%s\n", wordList[i]);
    }
}

/*******************     Capitalize Word List    *************************/

void capitalizeWordList(char wordList[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH]){
    
    int i, j;
    
    for (i=0; i < MAX_NUM_OF_WORDS; i++) {
        for (j=0; j < MAX_WORD_LENGTH; j++) {
            if (wordList[i][j] != '\0') {
                wordList[i][j]  = toupper(wordList[i][j]);
            } else break;
        }
    }
       
}