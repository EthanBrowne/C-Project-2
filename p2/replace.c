/**
@file input
@author Ethan Browne, efbrowne
The purpose of this file is insert the replacement strings into the story.
*/

#include "replace.h"


/**
Replaces a placeholder in the line with a replacement string
@param line the string with the placeholder
@param word the replacement string
@param the placeholders string
*/
void replaceWord(char line[LINE_MAX + 1], char word[FIELD_MAX + 1], char placeholder[])
{
    //All possible placeholders
    char noun1PlaceHolder[] = "<noun1>";
    char noun2PlaceHolder[] = "<noun2>";
    char verbPlaceHolder[] = "<verb>";
    char adjectivePlaceHolder[] = "<adjective>";
    char adverbPlaceHolder[] = "<adverb>";

    //Iterates through the entire loop
    for (int i = 0; i < strlen(line); i++){
        bool accurate = false;
        //Checks to see if the placeholder is present
        if (line[i] == '<'){

            char possiblePlaceholder[FIELD_MAX + 1];
            bool endCharacter = false;
            for (int j = i; j < strlen(line) && !endCharacter; j++){
                possiblePlaceholder[j - i] = line[j];
                endCharacter = line[j] == '>';
                if (endCharacter) {
                   possiblePlaceholder[(j - i) + 1] = '\0';
                }
            }
            if (strcmp(possiblePlaceholder, placeholder) == 0){
                accurate = true;
            } else if (strcmp(noun1PlaceHolder, possiblePlaceholder) != 0 && strcmp(noun2PlaceHolder, possiblePlaceholder) != 0 && strcmp(verbPlaceHolder, possiblePlaceholder) != 0 && strcmp(adjectivePlaceHolder, possiblePlaceholder) != 0 && strcmp(adverbPlaceHolder, possiblePlaceholder) != 0){
                exit(BAD_PLACEHOLDER);
            }
        }
        
        //If the word is placeholder
        if (accurate){
            //If the replacement causes the line to be over 100 characters exit
            if (computeLen(line, word, placeholder)){
               exit(LINE_LONG);
            }

            //Creates a copy of the line to reference later
            char oldline[LINE_MAX + 1];
            strcpy(oldline, line);

            //Adds in the word to where the placeholder began
            for (int k = i; k < strlen(word) + i; k++){
                line[k] = word[k - i];
            }

            //Reads the rest of the old line after the word
            for (int l = strlen(word) + i; l < strlen(line) + strlen(word); l++) {
                line[l] = oldline[(l - strlen(word)) + strlen(placeholder)];
            }
        }
    }
}

/**
Computes the length of the line after removing placeholder and adding word to see if it is over 100 characters
@param line the string of the line
@param word the string of the word that is passed in
@param placeholder the placeholder string
@return if the total length of the new sequence is over 100 characters
*/
bool computeLen(char line[LINE_MAX + 1], char word[FIELD_MAX + 1], char placeholder[])
{
    return (strlen(line) - strlen(placeholder)) + strlen(word) > LINE_MAX;
}