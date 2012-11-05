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
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_OF_WORDS 20
#define MAX_WORD_LENGTH 15
#define BOARD_SIZE 15

int wordListInput(char wordList[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH]);
void printCharArray(char wordList[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH], int numberOfWordsInList);
void capitalizeWordList(char wordList[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH]);
void initSolutionBoard(char solutionBoard[BOARD_SIZE][BOARD_SIZE], char c);
void printBoard(char boardToPrint[BOARD_SIZE][BOARD_SIZE]);
void scrambleLetters(char wordListToScramble[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH], int numberOfWordsInList);
void putWordsOnSolutionBoard(char solutionBoard[BOARD_SIZE][BOARD_SIZE], char wordList2[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH], int numberOfWordsInList);
//void 

/*************************************************************************/
/*********************        MAIN      **********************************/
/*************************************************************************/

int main(int argc, const char * argv[]){

    printf("Jon's Crossword Puzzle Generator\n----------------------------------\n");
    printf("Enter a list of words (%d words at most):\n", MAX_NUM_OF_WORDS);
    
    char wordList[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH] = {"jump", "test", "leslie", "and", "I", "are", "going", "to", "the", "bookstore", "today", "."};
    
    int numberOfWordsInList = wordListInput(wordList);
    capitalizeWordList(wordList);
    
    char solutionBoard[BOARD_SIZE][BOARD_SIZE];
    initSolutionBoard(solutionBoard, '.');
    
        
    //copy wordList to wordList2, which will be used to scramble up the words
    char wordList2[numberOfWordsInList][MAX_WORD_LENGTH];
    int i;
    for (i=0; i < numberOfWordsInList; i++) {
        strcpy(wordList2[i], wordList[i]);
    }
    //now wordList2 is a copy of wordList, 
    
    putWordsOnSolutionBoard(solutionBoard, wordList2, numberOfWordsInList);
    
    //printBoard(solutionBoard);

    
    scrambleLetters(wordList2, numberOfWordsInList);
    
    printf("\nNow the scrambled list:\n");
    printCharArray(wordList2, numberOfWordsInList-1);
    
    return 0;
}

/****************     Put Words On Solution Board    *********************/

void putWordsOnSolutionBoard(char solutionBoard[BOARD_SIZE][BOARD_SIZE], char wordList2[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH], int numberOfWordsInList){
    
}

/*********************     Scramble Letters    ***************************/

void scrambleLetters(char wordListToScramble[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH], int numberOfWordsInList){
    int i, j, length, r;
    double dbl_length;
    
    srand((int)time(NULL)); //seed the random num generator
    
    char temp[numberOfWordsInList][MAX_WORD_LENGTH];
    
    for (i = 0; i < numberOfWordsInList; i++) {
        //mix up letters of wordListToScramble[i]
            //first find the number of letters
        
        dbl_length = strnlen(wordListToScramble[i], MAX_WORD_LENGTH); //strnlen returns double
        length = (int)dbl_length; //typecast int on dbl_length
        
            //now mix up the letters using the Knuth Shuffle algorithm
        for (j = 0; j <= length - 1; j++) {
            r = (rand() % length);
            //swap wordListToScramble[i] and wordListToScramble[r]
            temp[i][j] = wordListToScramble[i][j];
            wordListToScramble[i][j] = wordListToScramble[i][r];
            wordListToScramble[i][r] = temp[i][j];
            
        }
    }
}

/*********************     Word List Input     ***************************/

int wordListInput(char wordList[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH]){
    int i;
    for (i=0; i < MAX_NUM_OF_WORDS; i++) {
        scanf("%s", wordList[i]);
        if (wordList[i][0] == '.') {
            return i;
        }
    }
    return MAX_NUM_OF_WORDS;
}

/*********************     Print Char Array    ***************************/

void printCharArray(char wordList[MAX_NUM_OF_WORDS][MAX_WORD_LENGTH], int numberOfWordsInList){
    int i;
    printf("\n");
    for (i=0; i <= numberOfWordsInList; i++) {
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

/*****************     Initialize Solution Board    **********************/

void initSolutionBoard(char solutionBoard[BOARD_SIZE][BOARD_SIZE], char c){
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            solutionBoard[i][j] = c;
        }
    }
}

/*********************        Print Board       **************************/

void printBoard(char boardToPrint[BOARD_SIZE][BOARD_SIZE]){
    int i;
    int j;
    
    printf("  ");
    for(i = 1; i <= BOARD_SIZE; i++){
        printf("%3d", i);
    }
    printf("\n");
    for(i = 0; i < BOARD_SIZE; i++){ //two loops print all the elements of the 2D array
        printf("%2d", 1+i);
        for(j = 0; j < 15; j++){
            printf("%3c", boardToPrint[i][j]);
        }
        printf("\n");
    }
}



