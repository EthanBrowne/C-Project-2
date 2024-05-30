/**
@file input
@author Ethan Browne, efbrowne
The purpose of this file is to read in the 5 replacement strings and the story
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

/**
Given a string and replaces the string with input.
@param word a string of length FIELD_MAX + 1 to leave room for string termenator
*/
void readWord(char word[FIELD_MAX + 1])
{
    int lastIndex = 0;
    int character = ' ';
    //Reads a string till end of line character
    for (int i = 0; i < FIELD_MAX + 1 && character != '\n'; i++){
        character = getchar();
        //Checks to see if the word has invalid chars
        if (!isalpha(character) && !isdigit(character) && character != '\'' && character != '-' && character != ' ' && character != '\n' && character != EOF){
           exit(WORD_LONG);
        }
        if (character == EOF){
            exit(MISSING_REPLACEMENT);
        } else if (character == '\n'){
            word[i] = '\0';
            lastIndex = i;
        } else {
            word[i] = character;
        }
    }
    if (word[lastIndex] != '\0'){
        exit(WORD_LONG);
    } 
}
/**
Given a string and replaces the string with input.
@param line a string of length LINE_MAX + 1 to leave room for string termenator
@return whether it reached an end of line character
*/
bool readLine(char line[LINE_MAX + 1])
{
    //Reads a string till end of file character
    for (int i = 0; i < LINE_MAX + 1; i++){
        int character = getchar();
        if (character == '\n'){
            line[i] = '\0';
            return true;
        } if (character == EOF){
            if (i != 0){
                line[i] = '\0';
                return true;
            }
            return false;
        } else {
            line[i] = character;
        }
    }
    exit(LINE_LONG);
}