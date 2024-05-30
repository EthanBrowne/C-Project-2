/**
@file input
@author Ethan Browne, efbrowne
The header file for input.c. The purpose of this file is to declare the prototypes and import all useful files
*/

#include "replace.h"

/**
Given a string and replaces the string with input.
@param word a string of length FIELD_MAX + 1 to leave room for string termenator
*/
void readWord(char word[FIELD_MAX + 1]);

/**
Given a string and replaces the string with input.
@param line a string of length LINE_MAX + 1 to leave room for string termenator
@return 
*/
bool readLine(char line[LINE_MAX + 1]);