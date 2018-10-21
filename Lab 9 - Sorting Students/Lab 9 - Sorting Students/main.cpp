//
//  main.cpp
//  Lab 9 - Sorting Students
//
//  Created by Travis Alcantara on 6/14/18.
//  Copyright © 2018 Travis Alcantara. All rights reserved.
//

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

// class Student prototype -----------------------
class Student
{
private:
   string lastName;
   string firstName;
   int totalPoints;
   static int sortKey;

public:
   static const string DEFAULT_NAME;
   static const int DEFAULT_POINTS = 0;
   static const int MAX_POINTS = 1000;
   static const int SORT_BY_FIRST = 88;
   static const int SORT_BY_LAST = 98;
   static const int SORT_BY_POINTS = 108;

public:
   Student( string lst = DEFAULT_NAME, string fst = DEFAULT_NAME,
           long pts = DEFAULT_POINTS);

   // accessors and mutators
   string getLastName() { return lastName; }
   string getFirstName() { return firstName; }
   int getTotalPoints() { return totalPoints; }
   static int getSortKey() { return sortKey; };

   bool setLastName(string last);
   bool setFirstName(string first);
   bool setPoints(int pts);
   static bool setSortKey( int key);

   static int compareTwoStudents( Student firstStud, Student secondStud );

   string toString();

private:
   static bool validString( string testStr );
   static bool validPoints( int testPoints );

};  // end of class Student prototype --------------

int Student::sortKey = SORT_BY_LAST;

// class StudentArrayUtilities prototype -----------------------
class StudentArrayUtilities
{
public:
   static string toString(Student data[], int arraySize);
   static void arraySort(Student array[], int arraySize);
   static double getMedianDestructive(Student array[], int arraySize);

private:
   static bool floatLargestToTop(Student data[], int top);
   static void mySwap(Student &a, Student &b);
};

// static initializations that can't be done in-line
const string Student::DEFAULT_NAME = "zz-error";

int main()
{
   Student arrayOne[] =
   {
      Student("doe","jane", 220),
      Student("smith","jack", 789),
      Student("anderson","mark", 136),
      Student("johnson","sara", 308),
      Student("garcia","richard", 612),
      Student("smith","will", 554),
      Student("jackson","gary", 300),
      Student("rivera","lisa", 945),
      Student("chai","jamie", 935),
      Student("einstein","albert", 1000),
      Student("barker","travis", 267),
      Student("villanueva","mary", 797),
      Student("singh","chris", 621),
      Student("washington","denzel", 958),
      Student("coleman","robert", 387)
   };

   Student arrayTwo[] =
   {
      Student("williams","jack", 340),
      Student("parker","maia", 689),
      Student("lee","david", 420),
      Student("park","maria", 865),
      Student("mayfield","joe", 342),
      Student("montana","joe", 900),
      Student("lu","kelly", 850),
      Student("alcantara","travis", 143),
      Student("myers","jessica", 742),
      Student("patel","david", 832),
      Student("kim","jason", 432),
      Student("rice","jerry", 902),
      Student("gore","frank", 901),
      Student("jefferson","john", 345),
      Student("rios","christina", 965),
      Student("bunny","bugs", 80)
   };

   Student arrayThree[] =
   {
      Student("mouse", "mickey", 564)
   };

   int arrayOneSize = sizeof(arrayOne) / sizeof(arrayOne[0]);
   int arrayTwoSize = sizeof(arrayTwo) / sizeof(arrayTwo[0]);
   int arrayThreeSize = sizeof(arrayThree) / sizeof(arrayThree[0]);

   string arrayTwoString = StudentArrayUtilities::toString(arrayTwo,
                                                           arrayTwoSize);
   cout << "before: " << endl;
   cout << arrayTwoString << endl;

   StudentArrayUtilities::arraySort(arrayTwo, arrayTwoSize);
   arrayTwoString = StudentArrayUtilities::toString(arrayTwo, arrayTwoSize);

   cout << "after default sort: " << endl;
   cout << arrayTwoString << endl;

   Student::setSortKey(Student::SORT_BY_FIRST);
   StudentArrayUtilities::arraySort(arrayTwo, arrayTwoSize);
   arrayTwoString = StudentArrayUtilities::toString(arrayTwo, arrayTwoSize);

   cout << "after sort by first: " << endl;
   cout << arrayTwoString << endl;

   Student::setSortKey(Student::SORT_BY_POINTS);
   StudentArrayUtilities::arraySort(arrayTwo, arrayTwoSize);
   arrayTwoString = StudentArrayUtilities::toString(arrayTwo, arrayTwoSize);

   cout << "after sort by points: " << endl;
   cout << arrayTwoString << endl;

   Student::setSortKey(Student::SORT_BY_FIRST);
   double median = StudentArrayUtilities::getMedianDestructive(arrayTwo,
                                                            arrayTwoSize);

   cout << "median of even class: " <<  median << endl;

   int currentSortKey = Student::getSortKey();
   if (currentSortKey == Student::SORT_BY_FIRST)
      cout << "Succesfully preserved sort key." << endl;

   median = StudentArrayUtilities::getMedianDestructive(arrayOne, arrayOneSize);
   cout << "median of odd class: " << median << endl;

   median = StudentArrayUtilities::getMedianDestructive(arrayThree,
                                                        arrayThreeSize);
   cout << "median of small class: " << median << endl;
}

// beginning of Student method definitions -------------

// constructor requires parameters - no default supplied
Student::Student( string last, string first, long points)
{
   if ( !setLastName(last) )
      lastName = DEFAULT_NAME;
   if ( !setFirstName(first) )
      firstName = DEFAULT_NAME;
   if ( !setPoints(points) )
      totalPoints = DEFAULT_POINTS;
}

bool Student::setLastName(string last)
{
   if ( !validString(last) )
      return false;
   lastName = last;
   return true;
}

bool Student::setFirstName(string first)
{
   if ( !validString(first) )
      return false;
   firstName = first;
   return true;
}

bool Student::setPoints(int pts)
{
   if ( !validPoints(pts) )
      return false;
   totalPoints = pts;
   return true;
}

bool Student::setSortKey(int key)
{
   if (key != SORT_BY_LAST && key != SORT_BY_FIRST && key != SORT_BY_POINTS)
      return false;
   sortKey = key;
   return true;
}

int Student::compareTwoStudents( Student firstStud, Student secondStud )
{
   const int GREATER_THAN = 1;
   const int LESS_THAN = -1;
   const int SAME_AS = 0;
   int result;

   switch (sortKey) {
      case SORT_BY_FIRST:
         result = firstStud.firstName.compare(secondStud.firstName);
         break;
      case SORT_BY_POINTS:
         if (firstStud.totalPoints > secondStud.totalPoints)
            result = GREATER_THAN;
         else if (firstStud.totalPoints < secondStud.totalPoints)
            result = LESS_THAN;
         else
            result = SAME_AS;
         break;
      default:
         result = firstStud.lastName.compare(secondStud.lastName);
         break;
   }

   return result;
}

string Student::toString()
{
   string resultString;
   ostringstream cnvrtFirst, cnvrtLast, cnvrtPoints;

   cnvrtFirst << firstName;
   cnvrtLast << lastName;
   cnvrtPoints << totalPoints;

   resultString = " "+ cnvrtLast.str()
   + ", " + cnvrtFirst.str()
   + " points: " + cnvrtPoints.str()
   + "\n";
   return resultString;
}

bool Student::validString( string testStr )
{
   if (testStr.length() > 0 && isalpha(testStr[0]))
      return true;
   return false;
}

bool Student::validPoints( int testPoints )
{
   if (testPoints >= 0 && testPoints <= MAX_POINTS)
      return true;
   return false;
}
// end of Student method definitions  --------------

// beginning of StudentArrayUtilities method definitions -------------

string StudentArrayUtilities::toString(Student data[],
                                       int arraySize)
{
   string output = "";

   // build the output string from the individual Students:
   for (int k = 0; k < arraySize; k++)
      output += " "+ data[k].toString();

   return output;
}

void StudentArrayUtilities::arraySort(Student array[], int arraySize)
{
   for (int k = 0; k < arraySize; k++)
      // compare with method def to see where inner loop stops
      if (!floatLargestToTop(array, arraySize-1-k))
         return;
}

// returns true if a modification was made to the array
bool StudentArrayUtilities::floatLargestToTop(Student data[], int top)
{
   bool changed = false;

   // compare with client call to see where the loop stops
   for (int k =0; k < top; k++)
      if (  Student::compareTwoStudents(data[k], data[k+1]) > 0 )
      {
         mySwap(data[k], data[k+1]);
         changed = true;
      }
   return changed;
}

void StudentArrayUtilities::mySwap(Student &a, Student &b)
{
   Student temp("", "", 0);

   temp = a;
   a = b;
   b = temp;
}

double StudentArrayUtilities::getMedianDestructive(Student array[],
                                                   int arraySize)
{
   int remainder = arraySize % 2;
   int middleIndex = arraySize / 2;
   int otherMiddleIndex;
   Student middleStudent, otherMiddleStudent;
   double median;
   int currentSortKey = Student::getSortKey();

   if (currentSortKey != Student::SORT_BY_POINTS)
      Student::setSortKey(Student::SORT_BY_POINTS);

   StudentArrayUtilities::arraySort(array, arraySize);
   Student::setSortKey(currentSortKey);

   if (remainder == 0)
   {
      otherMiddleIndex = middleIndex - 1;
      middleStudent = array[middleIndex];
      otherMiddleStudent = array[otherMiddleIndex];

      median = (middleStudent.getTotalPoints() +
                otherMiddleStudent.getTotalPoints()) / 2.0;
   }
   else
   {
      median = array[middleIndex].getTotalPoints();
   }

   return median;
}

/* -------------------------- Paste of Run -------------------------------------

 before:
 williams, jack points: 340
 parker, maia points: 689
 lee, david points: 420
 park, maria points: 865
 mayfield, joe points: 342
 montana, joe points: 900
 lu, kelly points: 850
 alcantara, travis points: 143
 myers, jessica points: 742
 patel, david points: 832
 kim, jason points: 432
 rice, jerry points: 902
 gore, frank points: 901
 jefferson, john points: 345
 rios, christina points: 965
 bunny, bugs points: 80

 after default sort:
 alcantara, travis points: 143
 bunny, bugs points: 80
 gore, frank points: 901
 jefferson, john points: 345
 kim, jason points: 432
 lee, david points: 420
 lu, kelly points: 850
 mayfield, joe points: 342
 montana, joe points: 900
 myers, jessica points: 742
 park, maria points: 865
 parker, maia points: 689
 patel, david points: 832
 rice, jerry points: 902
 rios, christina points: 965
 williams, jack points: 340

 after sort by first:
 bunny, bugs points: 80
 rios, christina points: 965
 lee, david points: 420
 patel, david points: 832
 gore, frank points: 901
 williams, jack points: 340
 kim, jason points: 432
 rice, jerry points: 902
 myers, jessica points: 742
 mayfield, joe points: 342
 montana, joe points: 900
 jefferson, john points: 345
 lu, kelly points: 850
 parker, maia points: 689
 park, maria points: 865
 alcantara, travis points: 143

 after sort by points:
 bunny, bugs points: 80
 alcantara, travis points: 143
 williams, jack points: 340
 mayfield, joe points: 342
 jefferson, john points: 345
 lee, david points: 420
 kim, jason points: 432
 parker, maia points: 689
 myers, jessica points: 742
 patel, david points: 832
 lu, kelly points: 850
 park, maria points: 865
 montana, joe points: 900
 gore, frank points: 901
 rice, jerry points: 902
 rios, christina points: 965

 median of even class: 715.5
 Succesfully preserved sort key.
 median of odd class: 612
 median of small class: 564
 Program ended with exit code: 0

----------------------------------------------------------------------------- */
