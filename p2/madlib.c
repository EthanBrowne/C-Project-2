/**
@file madlib
@author Ethan Browne, efbrowne
This file contains the main method and calls the other files to read the strings and the story and input the words into the story.
*/

#include "input.h"
#include "replace.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
Main function
@return if the program was successfully run
*/
int main()
{   
    char noun1PlaceHolder[] = "<noun1>";
    char noun2PlaceHolder[] = "<noun2>";
    char verbPlaceHolder[] = "<verb>";
    char adjectivePlaceHolder[] = "<adjective>";
    char adverbPlaceHolder[] = "<adverb>";

    //The first noun
    char noun1[FIELD_MAX + 1];
    readWord(noun1);

    //The second noun
    char noun2[FIELD_MAX + 1];
    readWord(noun2);

    //The verb
    char verb[FIELD_MAX + 1];
    readWord(verb);

    //The adjective
    char adjective[FIELD_MAX + 1];
    readWord(adjective);

    //The adverb
    char adverb[FIELD_MAX + 1];
    readWord(adverb);

    //The line that is being read
    char line[LINE_MAX + 1];

    while (readLine(line)){
        //Replace the words
        replaceWord(line, noun1, noun1PlaceHolder);
        replaceWord(line, noun2, noun2PlaceHolder);
        replaceWord(line, verb, verbPlaceHolder);
        replaceWord(line, adjective, adjectivePlaceHolder);
        replaceWord(line, adverb, adverbPlaceHolder);

        printf("%s\n", line);
    }

    return EXIT_SUCCESS;
}