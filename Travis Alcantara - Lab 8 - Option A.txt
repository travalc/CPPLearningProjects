//
//  main.cpp
//  Assignment 8 - Dating For Us Geeks
//
//  Created by Travis Alcantara on 6/7/18.
//  Copyright © 2018 Travis Alcantara. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// class prototype
class DateProfile
{
private:
   char gender;
   char searchGender;
   int romance;
   int finance;
   string name;

   // private methods
   double determineGenderFit(DateProfile partner);
   double determineRomanceFit(DateProfile partner);
   double determineFinanceFit(DateProfile partner);

public:
   // constants
   const static char VALID_FEMALE_GENDER = 'F';
   const static char VALID_MALE_GENDER = 'M';
   const static int MIN_ROMANCE_OR_FINANCE = 1;
   const static int MAX_ROMANCE_OR_FINANCE = 10;
   const static int MIN_NAME_LENGTH = 2;

   const static char DEFAULT_GEND = 'F';
   const static char DEFAULT_SEARCH_GEND = 'M';
   const static int DEFAULT_ROMANCE_OR_FINANCE = 5;
   const static string DEFAULT_NAME;

   const static double PERFECT_FIT;
   const static double BAD_FIT;
   const static double POWER_OF_TEN;

   // constructors
   DateProfile();
   DateProfile(char gender, char searchGender, int romance, int finance,
               string name);

   // mutators
   bool setGender(char gender);
   bool setSearchGender(char searchGender);
   bool setRomance(int romance);
   bool setFinance(int finance);
   bool setName(string name);
   void setAll(char gender, char searchGender, int romance, int finance,
               string name);
   void setDefaults();

   // accessors
   char getGender() { return gender; }
   char getSearchGender() { return searchGender; }
   int getRomance() { return romance; }
   int getFinance() { return finance; }
   string getName() { return name; }

   // other public methods
   double fitValue(DateProfile partner);
};

// initialize static constants from class
const string DateProfile::DEFAULT_NAME = "User";
const double DateProfile::PERFECT_FIT = 1.0;
const double DateProfile::BAD_FIT = 0;
const double DateProfile::POWER_OF_TEN = 10;

// global method
void displayTwoProfiles(DateProfile profile1, DateProfile profile2);

int main()
{
   DateProfile applicant1('M', 'F', 10, 10, "Mike");
   DateProfile applicant2('F', 'M', 1, 1, "Maria");
   DateProfile applicant3('M', 'F', 6, 4, "Jose");
   DateProfile applicant4('F', 'M', 9, 8, "Carla");

   displayTwoProfiles(applicant1, applicant1);
   displayTwoProfiles(applicant1, applicant2);
   displayTwoProfiles(applicant1, applicant3);
   displayTwoProfiles(applicant1, applicant4);

   displayTwoProfiles(applicant2, applicant1);
   displayTwoProfiles(applicant2, applicant2);
   displayTwoProfiles(applicant2, applicant3);
   displayTwoProfiles(applicant2, applicant4);

   displayTwoProfiles(applicant3, applicant1);
   displayTwoProfiles(applicant3, applicant2);
   displayTwoProfiles(applicant3, applicant3);
   displayTwoProfiles(applicant3, applicant4);

   displayTwoProfiles(applicant4, applicant1);
   displayTwoProfiles(applicant4, applicant2);
   displayTwoProfiles(applicant4, applicant3);
   displayTwoProfiles(applicant4, applicant4);

   // Test Mutators
   if (!applicant1.setRomance(0))
      cout << "setRomance failed" << endl;
   else
      cout << "setRomance succeeded" << endl;

   if (!applicant1.setSearchGender('T'))
      cout << "setGender failed" << endl;
   else
      cout << "setGender succeded" << endl;

   if (!applicant1.setName("a"))
      cout << "setName failed" << endl;
   else
      cout << "setName succeeded" << endl;

   return 0;
}

// global method definition
void displayTwoProfiles(DateProfile profile1, DateProfile profile2)
{
   string name1 = profile1.getName();
   string name2 = profile2.getName();
   double fitValue = profile1.fitValue(profile2);

   cout << "Fit between " << name1 << " and " << name2 << ": \n";
   cout << fitValue << "\n\n";
}

// class constructor definitions
DateProfile::DateProfile()
{
   setDefaults();
}

DateProfile::DateProfile(char gender, char searchGender, int romance,
                         int finance, string name)
{
   setAll(gender, searchGender, romance, finance, name);
}

// class method definitions
bool DateProfile::setGender(char gender)
{
   if (gender != VALID_MALE_GENDER && gender != VALID_FEMALE_GENDER)
      return false;

   this->gender = gender;
   return true;
}

bool DateProfile::setSearchGender(char searchGender)
{
   if (searchGender != VALID_FEMALE_GENDER && searchGender != VALID_MALE_GENDER)
      return false;

   this->searchGender = searchGender;
   return true;
}

bool DateProfile::setRomance(int romance)
{
   if (romance < MIN_ROMANCE_OR_FINANCE || romance > MAX_ROMANCE_OR_FINANCE)
      return false;

   this->romance = romance;
   return true;
}

bool DateProfile::setFinance(int finance)
{
   if (finance < MIN_ROMANCE_OR_FINANCE || finance > MAX_ROMANCE_OR_FINANCE)
      return false;

   this->finance = finance;
   return true;
}

bool DateProfile::setName(string name)
{
   if (name.length() < MIN_NAME_LENGTH)
      return false;

   this->name = name;
   return true;
}

void DateProfile::setAll(char gender, char searchGender, int romance,
                         int finance, string name)
{
   setGender(gender);
   setSearchGender(searchGender);
   setRomance(romance);
   setFinance(finance);
   setName(name);
}

void DateProfile::setDefaults()
{
   setAll(DEFAULT_GEND, DEFAULT_SEARCH_GEND, DEFAULT_ROMANCE_OR_FINANCE,
          DEFAULT_ROMANCE_OR_FINANCE, DEFAULT_NAME);
}

double DateProfile::fitValue(DateProfile partner)
{
   const double NUM_OF_VALS = 2;
   double genderFit = determineGenderFit(partner);
   double romanceFit = determineRomanceFit(partner);
   double financeFit = determineFinanceFit(partner);
   double fitValue;

   if (genderFit != PERFECT_FIT)
      return BAD_FIT;

   fitValue = (romanceFit + financeFit) / NUM_OF_VALS;
   return fitValue;
}

double DateProfile::determineGenderFit(DateProfile partner)
{
   char partnerGender = partner.getGender();
   char partnerSearchGender = partner.getSearchGender();

   if (partnerGender == searchGender && gender == partnerSearchGender)
      return PERFECT_FIT;

   return BAD_FIT;
}

double DateProfile::determineRomanceFit(DateProfile partner)
{
   int partnerRomance = partner.getRomance();
   double romanceDifference = abs(romance - partnerRomance) / POWER_OF_TEN;
   double romanceFit = (PERFECT_FIT - romanceDifference);

   return romanceFit;
}

double DateProfile::determineFinanceFit(DateProfile partner)
{
   int partnerFinance = partner.getFinance();
   double financeDifference = abs(finance - partnerFinance) / POWER_OF_TEN;
   double financeFit = (PERFECT_FIT - financeDifference);

   return financeFit;
}


/* ---------------------------- Paste of Run -----------------------------------

 Fit between Mike and Mike:
 0

 Fit between Mike and Maria:
 0.1

 Fit between Mike and Jose:
 0

 Fit between Mike and Carla:
 0.85

 Fit between Maria and Mike:
 0.1

 Fit between Maria and Maria:
 0

 Fit between Maria and Jose:
 0.6

 Fit between Maria and Carla:
 0

 Fit between Jose and Mike:
 0

 Fit between Jose and Maria:
 0.6

 Fit between Jose and Jose:
 0

 Fit between Jose and Carla:
 0.65

 Fit between Carla and Mike:
 0.85

 Fit between Carla and Maria:
 0

 Fit between Carla and Jose:
 0.65

 Fit between Carla and Carla:
 0

 setRomance failed
 setGender failed
 setName failed
 Program ended with exit code: 0

----------------------------------------------------------------------------- */
