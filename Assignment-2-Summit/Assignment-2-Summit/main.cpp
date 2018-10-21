//
//  main.cpp
//  Assignment-2-Summit
//
//  Created by Travis Alcantara on 4/20/18.
//  Copyright © 2018 Travis Alcantara. All rights reserved.
//

#include <iostream>
#include <string>

int main() {
   const int myID = 20352899;
   const int myFirstNameLen = 6;
   const int myLastNameLen = 9;
   int a = myFirstNameLen;
   double d = (double)myFirstNameLen / myLastNameLen;
   int n = myID % 1000;
   double sum = (double)n/2 * (2 * a + (n - 1) * d);

   std::string aString = std::to_string(a);
   std::string dString = std::to_string(d);
   std::string nString = std::to_string(n);
   std::string sumString = std::to_string(sum);

   std::cout << "The sum of the first " + nString + " terms of the AP with ";
   std::cout << "first term " + aString + " and difference " + dString + " = ";
   std::cout << sumString;
   std::cout << "\n";

   return 0;
}

/* ------------------------------ paste of run ---------------------------------------------------

The sum of the first 899 terms of the AP with first term 6 and difference 0.666667 = 274494.666667
Program ended with exit code: 0

------------------------------------------------------------------------------------------------ */
