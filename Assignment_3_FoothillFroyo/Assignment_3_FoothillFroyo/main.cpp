//
//  main.cpp
//  Assignment_3_FoothillFroyo
//
//  Created by Travis Alcantara on 5/2/18.
//  Copyright © 2018 Travis Alcantara. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
   // Declare constants
   const int FREE_YOGURT_COST = 10;
   const int MAX_YOGURTS = 10;
   const int MIN_YOGURTS = 1;
   const char VALID_PURCHASE = 'p';
   const char VALID_SHUTDOWN = 's';
   const char VALID_YES = 'y';
   const char VALID_NO = 'n';

   int numStamps, numYogurts;
   string strUserInput;
   char firstLetter;
   bool shutdown;

   // Initialize stamp count to 0, set shutdown condition to false
   numStamps = 0;
   shutdown = false;

   // Begin user input loop, exit when shutdown condition is true
   while (!shutdown) {
      cout << "Menu: \n";
      cout << "  P (Process Purchase) \n";
      cout << "  S (Shut Down) \n";
      cout << "\nYour Choice: ";

      // Get user choice
      getline(cin, strUserInput);
      firstLetter = tolower(strUserInput[0]);

      // Handle user selection, exit loop if shutdown is selected
      if (firstLetter == VALID_SHUTDOWN) {
         cout << "\nGoodbye! \n";
         shutdown = true;
      }
      else if (firstLetter == VALID_PURCHASE) {
         // Check if user has 10 or more stamps
         if (numStamps >= FREE_YOGURT_COST) {
            cout << "\nYou qualify for a free yogurt. Would you like to use ";
            cout << "your credits? (Y or N) ";
            getline(cin, strUserInput);
            firstLetter = tolower(strUserInput[0]);

            // Validate if valid Y or N was entered
            if (firstLetter != VALID_YES && firstLetter != VALID_NO) {
               cout << "\n** Use Y or N, please. ** \n\n";
               continue;
            }
            else if (firstLetter == VALID_YES) {
               // Subtract yogurt cost from numStamps
               numStamps -= FREE_YOGURT_COST;
               cout << "\nYou have just used " << FREE_YOGURT_COST << " stamps";
               cout << " and have " << numStamps << " left. \n";
               cout << "Enjoy your free yogurt! \n\n";
               continue;
            }
         }

         // Ask how many yogurts user wants to purchase and store response
         cout << "\nHow many yogurts would you like to purchase? ";
         getline(cin, strUserInput);
         istringstream(strUserInput) >> numYogurts;

         // Catch input quantity error, return to top of loop
         if (numYogurts < MIN_YOGURTS || numYogurts > MAX_YOGURTS) {
            cout<< "\n** Number of yogurts must be between 1 and 10. ** \n\n";
            continue;
         }

         // Update numStamps by adding numYogurts to it
         numStamps += numYogurts;
         cout << "\nYou just earned " << numYogurts << " stamps and have a ";
         cout << "total of " << numStamps << " to use. \n\n";
      }
      else {
         // Display error if invalid P or S entry
         cout << "\n** Use P or S, please. ** \n\n";
      }
   }

   return 0;
}

/* ------------------------ Paste of Run #1 ------------------------------------

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: Purchase

 How many yogurts would you like to purchase? 4

 You just earned 4 stamps and have a total of 4 to use.

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: m

 ** Use P or S, please. **

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: p

 How many yogurts would you like to purchase? -9

 ** Number of yogurts must be between 1 and 10. **

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: purchase

 How many yogurts would you like to purchase? 11

 ** Number of yogurts must be between 1 and 10. **

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: P

 How many yogurts would you like to purchase? 5

 You just earned 5 stamps and have a total of 9 to use.

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: p

 How many yogurts would you like to purchase? 5

 You just earned 5 stamps and have a total of 14 to use.

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: p

 You qualify for a free yogurt. Would you like to use your credits? (Y or N) n

 How many yogurts would you like to purchase? 10

 You just earned 10 stamps and have a total of 24 to use.

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: p

 You qualify for a free yogurt. Would you like to use your credits? (Y or N) h

 ** Use Y or N, please. **

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: p

 You qualify for a free yogurt. Would you like to use your credits? (Y or N) Y

 You have just used 10 stamps and have 14 left.
 Enjoy your free yogurt!

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: p

 You qualify for a free yogurt. Would you like to use your credits? (Y or N) No thanks

 How many yogurts would you like to purchase? 4

 You just earned 4 stamps and have a total of 18 to use.

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: p

 You qualify for a free yogurt. Would you like to use your credits? (Y or N) yup!!!

 You have just used 10 stamps and have 8 left.
 Enjoy your free yogurt!

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: shutdown

 Goodbye!
 Program ended with exit code: 0

----------------------------------------------------------------------------- */

/* ------------------------ Paste of Run #2 ------------------------------------

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: purchase yogurt

 How many yogurts would you like to purchase? 45

 ** Number of yogurts must be between 1 and 10. **

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: p

 How many yogurts would you like to purchase? 3

 You just earned 3 stamps and have a total of 3 to use.

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: p

 How many yogurts would you like to purchase? 8

 You just earned 8 stamps and have a total of 11 to use.

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: p

 You qualify for a free yogurt. Would you like to use your credits? (Y or N) N

 How many yogurts would you like to purchase? 4

 You just earned 4 stamps and have a total of 15 to use.

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: P

 You qualify for a free yogurt. Would you like to use your credits? (Y or N) YES

 You have just used 10 stamps and have 5 left.
 Enjoy your free yogurt!

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: p

 How many yogurts would you like to purchase? 9

 You just earned 9 stamps and have a total of 14 to use.

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: P

 You qualify for a free yogurt. Would you like to use your credits? (Y or N) 0

 ** Use Y or N, please. **

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: p

 You qualify for a free yogurt. Would you like to use your credits? (Y or N) n

 How many yogurts would you like to purchase? 0

 ** Number of yogurts must be between 1 and 10. **

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: p

 You qualify for a free yogurt. Would you like to use your credits? (Y or N) y

 You have just used 10 stamps and have 4 left.
 Enjoy your free yogurt!

 Menu:
 P (Process Purchase)
 S (Shut Down)

 Your Choice: s

 Goodbye!
 Program ended with exit code: 0

----------------------------------------------------------------------------- */
