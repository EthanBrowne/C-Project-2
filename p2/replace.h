/**
@file replace
@author Ethan Browne, efbrowne
The header file for replace.c. The purpose of this file is insert the replacement strings into the story.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Maximum length for replacement string. */
#define FIELD_MAX 24

/** Maximum length for line of text. */
#define LINE_MAX 100

/** If any of the five replacement strings is missing exit with this status*/
#define MISSING_REPLACEMENT 101

/** If any of the replacement words is over 24 characters long or contains characters other than letters, numbers, hyphens, apostrophes or spaces exit with this status*/
#define WORD_LONG 102

/** If the line expands to become longer than 100 characters exit with this status*/
#define LINE_LONG 103

/** If a story line has an invalid placeholder exit with this status*/
#define BAD_PLACEHOLDER 104

/**
Replaces a placeholder in the line with a replacement string
@param line the string with the placeholder
@param word the replacement string
@param the placeholders string
*/
void replaceWord(char line[LINE_MAX + 1], char word[FIELD_MAX + 1], char placeholder[]);

/**
Computes the length of the line after removing placeholder and adding word to see if it is over 100 characters
@param line the string of the line
@param word the string of the word that is passed in
@param placeholder the placeholder string
@return if the total length of the new sequence is over 100 characters
*/
bool computeLen(char line[LINE_MAX + 1], char word[FIELD_MAX + 1], char placeholder[]);