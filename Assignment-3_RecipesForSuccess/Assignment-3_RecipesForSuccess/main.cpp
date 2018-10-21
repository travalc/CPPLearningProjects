//
//  main.cpp
//  Assignment-3_RecipesForSuccess
//
//  Created by Travis Alcantara on 4/25/18.
//  Copyright © 2018 Travis Alcantara. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// main client --------------------------------------------------------
int main()
{
   // food #1 constants
   const string FOOD_1_NAME = "Fish, tilapia, cooked, dry heat";
   const int FOOD_1_CALORIES_P100G = 128; // in calories
   const double FOOD_1_PROTEIN_P100G = 26.1; // in grams
   const double FOOD_1_DIETARY_FIBER_P100G = 0;
   const double FOOD_1_TOTAL_FAT_P100G = 2.7;

   // food #2 constants
   const string FOOD_2_NAME = "Asparagus, cooked, boiled, drained";
   const int FOOD_2_CALORIES_P100G = 22; // in calories
   const double FOOD_2_PROTEIN_P100G = 2.4; // in grams
   const double FOOD_2_DIETARY_FIBER_P100G = 2.0;
   const double FOOD_2_TOTAL_FAT_P100G = 0.2;

   // food #3 constants
   const string FOOD_3_NAME = "Plantains, cooked";
   const int FOOD_3_CALORIES_P100G = 116; // in calories
   const double FOOD_3_PROTEIN_P100G = 0.8; // in grams
   const double FOOD_3_DIETARY_FIBER_P100G = 2.3;
   const double FOOD_3_TOTAL_FAT_P100G = 0.2;

   // food #4 constants
   const string FOOD_4_NAME = "Quinoa, cooked";
   const int FOOD_4_CALORIES_P100G = 120; // in calories
   const double FOOD_4_PROTEIN_P100G = 4.4; // in grams
   const double FOOD_4_DIETARY_FIBER_P100G = 2.8;
   const double FOOD_4_TOTAL_FAT_P100G = 1.9;

   string recipeName, userInputStr;
   int userInputInt, servings;
   double totalCals, totalProtein, totalFiber, totalFat;

   // initialize accumulator variables
   totalCals = 0.;
   totalProtein = 0;
   totalFiber = 0;
   totalFat = 0;

   // print menu
   cout << "---------- List of Possible Ingredients ---------" << endl;
   cout << " Food #1: " << FOOD_1_NAME << endl;
   cout << " Food #2: " << FOOD_2_NAME << endl;
   cout << " Food #3: " << FOOD_3_NAME << endl;
   cout << " Food #4: " << FOOD_4_NAME << endl << endl;

   // name of recipe
   cout << "What are you calling this recipe? ";
   getline(cin, recipeName);

   // get servings
   cout << "How many portions does this recipe serve? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> servings;

   // error testing number of servings
   if (servings < 1 || servings > 10) {
      cout << "ERROR: Number of servings must be between 1 and 10 inclusive\n";
      return 0;
   }

   // food #1 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_1_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;

   // error testing gram amounts
   if (userInputInt < 0 || userInputInt > 1000) {
      cout << "ERROR: Amount of grams must be between 0 and 1000 inclusive\n";
      return 0;
   }

   // update accumulators
   totalCals += userInputInt * (FOOD_1_CALORIES_P100G/100.);
   totalProtein += userInputInt * (FOOD_1_PROTEIN_P100G/100.);
   totalFiber += userInputInt * (FOOD_1_DIETARY_FIBER_P100G/100.);
   totalFat += userInputInt * (FOOD_1_TOTAL_FAT_P100G/100.);

   // food #2 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_2_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;

   // error testing gram amounts
   if (userInputInt < 0 || userInputInt > 1000) {
      cout << "ERROR: Amount of grams must be between 0 and 1000 inclusive\n";
      return 0;
   }

   // update accumulators
   totalCals += userInputInt * (FOOD_2_CALORIES_P100G/100.);
   totalProtein += userInputInt * (FOOD_2_PROTEIN_P100G/100.);
   totalFiber += userInputInt * (FOOD_2_DIETARY_FIBER_P100G/100.);
   totalFat += userInputInt * (FOOD_2_TOTAL_FAT_P100G/100.);

   // food #3 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_3_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;

   // error testing gram amounts
   if (userInputInt < 0 || userInputInt > 1000) {
      cout << "ERROR: Amount of grams must be between 0 and 1000 inclusive\n";
      return 0;
   }

   // update accumulators
   totalCals += userInputInt * (FOOD_3_CALORIES_P100G/100.);
   totalProtein += userInputInt * (FOOD_3_PROTEIN_P100G/100.);
   totalFiber += userInputInt * (FOOD_3_DIETARY_FIBER_P100G/100.);
   totalFat += userInputInt * (FOOD_3_TOTAL_FAT_P100G/100.);

   // food #4 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_4_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;

   // error testing gram amounts
   if (userInputInt < 0 || userInputInt > 1000) {
      cout << "ERROR: Amount of grams must be between 0 and 1000 inclusive\n";
      return 0;
   }

   // update accumulators
   totalCals += userInputInt * (FOOD_4_CALORIES_P100G/100.);
   totalProtein += userInputInt * (FOOD_4_PROTEIN_P100G/100.);
   totalFiber += userInputInt * (FOOD_4_DIETARY_FIBER_P100G/100.);
   totalFat += userInputInt * (FOOD_4_TOTAL_FAT_P100G/100.);

   // get totals per serving
   double totalCalsPerServing = totalCals / servings;
   double totalProteinPerServing = totalProtein / servings;
   double totalFiberPerServing = totalFiber / servings;
   double totalFatPerServing = totalFat / servings;

   // report results --------------------------------------------------
   cout << "\nNutrition for " << recipeName << "------------" << endl;
   cout << " Calories (Per Serving): " << totalCalsPerServing << endl;
   cout << " Protein (Per Serving): " << totalProteinPerServing << endl;
   cout << " Dietary Fiber (Per Serving): " << totalFiberPerServing << endl;
   cout << " Total Fat (Per Serving): " << totalFatPerServing << endl;
   return 0;
}

/* -------------------------- Paste of Run 1 -----------------------------------

 ---------- List of Possible Ingredients ---------
 Food #1: Fish, tilapia, cooked, dry heat
 Food #2: Asparagus, cooked, boiled, drained
 Food #3: Plantains, cooked
 Food #4: Quinoa, cooked

 What are you calling this recipe? Healthy Fish Plate
 How many portions does this recipe serve? 2
 How many grams of Fish, tilapia, cooked, dry heat? 355
 How many grams of Asparagus, cooked, boiled, drained? 124
 How many grams of Plantains, cooked? 115
 How many grams of Quinoa, cooked? 256

 Nutrition for Healthy Fish Plate------------
 Calories (Per Serving): 461.14
 Protein (Per Serving): 53.9075
 Dietary Fiber (Per Serving): 6.1465
 Total Fat (Per Serving): 7.4635
 Program ended with exit code: 0

----------------------------------------------------------------------------- */

/* ------------------------- Paste of Run 2 ------------------------------------

 ---------- List of Possible Ingredients ---------
 Food #1: Fish, tilapia, cooked, dry heat
 Food #2: Asparagus, cooked, boiled, drained
 Food #3: Plantains, cooked
 Food #4: Quinoa, cooked

 What are you calling this recipe? Basic Fish and Quinoa
 How many portions does this recipe serve? 4
 How many grams of Fish, tilapia, cooked, dry heat? 500
 How many grams of Asparagus, cooked, boiled, drained? 0
 How many grams of Plantains, cooked? 0
 How many grams of Quinoa, cooked? 400

 Nutrition for Basic Fish and Quinoa------------
 Calories (Per Serving): 280
 Protein (Per Serving): 37.025
 Dietary Fiber (Per Serving): 2.8
 Total Fat (Per Serving): 5.275
 Program ended with exit code: 0

----------------------------------------------------------------------------- */

/* -------------------------- Paste of Run 3 -----------------------------------

 ---------- List of Possible Ingredients ---------
 Food #1: Fish, tilapia, cooked, dry heat
 Food #2: Asparagus, cooked, boiled, drained
 Food #3: Plantains, cooked
 Food #4: Quinoa, cooked

 What are you calling this recipe? Vegetarian Quinoa Plate
 How many portions does this recipe serve? 3
 How many grams of Fish, tilapia, cooked, dry heat? 0
 How many grams of Asparagus, cooked, boiled, drained? 432
 How many grams of Plantains, cooked? 397
 How many grams of Quinoa, cooked? 600

 Nutrition for Vegetarian Quinoa Plate------------
 Calories (Per Serving): 425.187
 Protein (Per Serving): 13.3147
 Dietary Fiber (Per Serving): 11.5237
 Total Fat (Per Serving): 4.35267
 Program ended with exit code: 0

----------------------------------------------------------------------------- */

/* --------------------------- Paste of Run 4 (Error) --------------------------

 ---------- List of Possible Ingredients ---------
 Food #1: Fish, tilapia, cooked, dry heat
 Food #2: Asparagus, cooked, boiled, drained
 Food #3: Plantains, cooked
 Food #4: Quinoa, cooked

 What are you calling this recipe? Too Many Servings
 How many portions does this recipe serve? 11
 ERROR: Number of servings must be between 1 and 10 inclusive
 Program ended with exit code: 0

----------------------------------------------------------------------------- */

/* ---------------------------- Paste of Run 5 ---------------------------------

 ---------- List of Possible Ingredients ---------
 Food #1: Fish, tilapia, cooked, dry heat
 Food #2: Asparagus, cooked, boiled, drained
 Food #3: Plantains, cooked
 Food #4: Quinoa, cooked

 What are you calling this recipe? Sweet Plantains And Fish
 How many portions does this recipe serve? 10
 How many grams of Fish, tilapia, cooked, dry heat? 900
 How many grams of Asparagus, cooked, boiled, drained? 0
 How many grams of Plantains, cooked? 800
 How many grams of Quinoa, cooked? 0

 Nutrition for Sweet Plantains And Fish------------
 Calories (Per Serving): 208
 Protein (Per Serving): 24.13
 Dietary Fiber (Per Serving): 1.84
 Total Fat (Per Serving): 2.59
 Program ended with exit code: 0

----------------------------------------------------------------------------- */
