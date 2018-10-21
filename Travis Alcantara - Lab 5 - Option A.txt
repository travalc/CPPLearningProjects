//
//  main.cpp
//  Lab-5-String Theory
//
//  Created by Travis Alcantara on 5/10/18.
//  Copyright © 2018 Travis Alcantara. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

char getKeyLetter();
string getString();
string maskLetter(string theString, char keyLetter);
string removeLetter(string theString, char keyLetter);
int countKey(string theString, char keyLetter);

int main() {
   string userString, maskedCharString, removedCharString;
   char keyLetter;
   int keyLetterCount;

   keyLetter = getKeyLetter();
   userString = getString();

   maskedCharString = maskLetter(userString, keyLetter);
   removedCharString = removeLetter(userString, keyLetter);
   keyLetterCount = countKey(userString, keyLetter);

   cout << "\n\n";
   cout << "String with '" << keyLetter << "' masked:\n" << maskedCharString;
   cout << "\n\n";
   cout << "Count of " << keyLetter << "'s: " << keyLetterCount;
   cout << "\n\n";
   cout << "String with '" << keyLetter << "' removed:\n" << removedCharString;
   cout << "\n\n";

   return 0;
}

char getKeyLetter() {
   const int VALID_STRING_LENGTH = 1;
   const int FIRST_LETTER_INDEX = 0;
   string strUserInput;
   char firstLetter;

   do {
      cout << "Please enter a SINGLE letter to act as key: ";
      getline(cin, strUserInput);
   }
   while(strUserInput.length() != VALID_STRING_LENGTH);

   firstLetter = strUserInput[FIRST_LETTER_INDEX];

   return firstLetter;
}

string getString() {
   const int VALID_STRING_LENGTH = 4;
   string strUserInput;

   do {
      cout << "Please enter a phrase or sentence >= " << VALID_STRING_LENGTH;
      cout << " letters:\n";
      getline(cin, strUserInput);
   }
   while(strUserInput.length() < VALID_STRING_LENGTH);

   return strUserInput;
}

string maskLetter(string theString, char keyLetter) {
   char currentChar;
   string replacement = "";

   for (int i = 0; i < theString.length(); i++) {
      currentChar = theString[i];

      if (currentChar == keyLetter) {
         replacement += '-';
      }
      else {
         replacement += currentChar;
      }
   }

   return replacement;
}

string removeLetter(string theString, char keyLetter) {
   char currentChar;
   string replacement = "";

   for (int i = 0; i < theString.length(); i++) {
      currentChar = theString[i];

      if (currentChar != keyLetter) {
         replacement += currentChar;
      }
   }

   return replacement;
}

int countKey(string theString, char keyLetter) {
   char currentChar;
   int counter = 0;

   for (int i = 0; i < theString.length(); i++) {
      currentChar = theString[i];

      if (currentChar == keyLetter) {
         counter++;
      }
   }

   return counter;
}

/* ------------------------- Paste of Run # 1 ----------------------------------

 Please enter a SINGLE letter to act as key: jm
 Please enter a SINGLE letter to act as key:
 Please enter a SINGLE letter to act as key: e
 Please enter a phrase or sentence >= 4 letters:
 cat
 Please enter a phrase or sentence >= 4 letters:
 c
 Please enter a phrase or sentence >= 4 letters:

 Please enter a phrase or sentence >= 4 letters:
 bear


 String with 'e' masked:
 b-ar

 Count of e's: 1

 String with 'e' removed:
 bar

 Program ended with exit code: 0

----------------------------------------------------------------------------- */

/* ------------------------- Paste of Run # 2 ----------------------------------

 Please enter a SINGLE letter to act as key: a
 Please enter a phrase or sentence >= 4 letters:
 California


 String with 'a' masked:
 C-liforni-

 Count of a's: 2

 String with 'a' removed:
 Cliforni

 Program ended with exit code: 0

----------------------------------------------------------------------------- */

/* ------------------------- Paste of Run # 3 ----------------------------------

 Please enter a SINGLE letter to act as key: to
 Please enter a SINGLE letter to act as key: o
 Please enter a phrase or sentence >= 4 letters:
 Android Phone


 String with 'o' masked:
 Andr-id Ph-ne

 Count of o's: 2

 String with 'o' removed:
 Andrid Phne

 Program ended with exit code: 0

----------------------------------------------------------------------------- */

/* ------------------------- Paste of Run # 4 ----------------------------------

 Please enter a SINGLE letter to act as key:
 Please enter a phrase or sentence >= 4 letters:
 dog
 Please enter a phrase or sentence >= 4 letters:
 Let's go to the movies tomorrow!


 String with ' ' masked:
 Let's-go-to-the-movies-tomorrow!

 Count of  's: 5

 String with ' ' removed:
 Let'sgotothemoviestomorrow!

 Program ended with exit code: 0

----------------------------------------------------------------------------- */


