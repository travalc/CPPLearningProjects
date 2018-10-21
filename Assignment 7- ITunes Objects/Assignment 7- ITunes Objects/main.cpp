//
//  main.cpp
//  Assignment 7- ITunes Objects
//
//  Created by Travis Alcantara on 5/31/18.
//  Copyright © 2018 Travis Alcantara. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

// Class Prototype
class ITunes
{
private:
   string name;
   string artist;
   int bitrate;
   int totalTime;

public:
   const static int MIN_BITRATE = 64;
   const static int MAX_BITRATE = 705;
   const static int MIN_STR_LENGTH = 1;
   const static int MAX_STR_LENGTH = 128;
   const static int MIN_PLAY_TIME = 5000;
   const static int MAX_PLAY_TIME = 1000 * 60 * 60;
   const static int DEFAULT_BITRATE = 64;
   const static int DEFAULT_PLAY_TIME = 5000;
   const static string DEFAULT_STRING;

   // Constructors
   ITunes();
   ITunes(string name, string artist, int bitrate, int totalTime);

   // Accessors
   string getName() { return name; }
   string getArtist() { return artist; }
   int getBitrate() { return bitrate; }
   int getTotalTime() { return totalTime; }

   // Mutators
   bool setName(string name);
   bool setArtist(string artist);
   bool setBitrate(int bitrate);
   bool setTotalTime(int totalTime);

   string toString();
   void setDefaults();
   void display();

};

// initialize const static string
const string ITunes::DEFAULT_STRING = " (undefined) ";

int main()
{
   ITunes iTunesObject1, iTunesObject2;
   ITunes iTunesObject3("Thriller", "Michael Jackson", 128, 500000);
   ITunes iTunesObject4("Gods Plan", "Drake", 200, 800000);

   iTunesObject1.display();
   iTunesObject2.display();
   iTunesObject3.display();
   iTunesObject4.display();

   iTunesObject1.setArtist("Chris Brown");
   iTunesObject2.setName("I Feel Good");
   iTunesObject3.setBitrate(250);
   iTunesObject4.setTotalTime(2000000);

   iTunesObject1.display();
   iTunesObject2.display();
   iTunesObject3.display();
   iTunesObject4.display();

   iTunesObject1.setDefaults();
   iTunesObject2.setDefaults();
   iTunesObject3.setDefaults();
   iTunesObject4.setDefaults();

   iTunesObject1.display();
   iTunesObject2.display();
   iTunesObject3.display();
   iTunesObject4.display();

   // Test mutators
   if (!iTunesObject1.setArtist("")) {
      cout << "setArtist() Failed\n\n";
   }
   else {
      cout << "setArtist() Succeeded\n\n";
   }

   if (!iTunesObject1.setArtist("Bob Marley")) {
      cout << "setArtist() Failed\n\n";
   }
   else {
      cout << "setArtist() Succeeded\n\n";
   }

   if (!iTunesObject1.setBitrate(706)) {
      cout << "setBitrate() Failed\n\n";
   }
   else {
      cout << "setBitrate() Succeeded\n\n";
   }

   if(!iTunesObject1.setBitrate(703)) {
      cout << "setBitrate() Failed\n\n";
   }
   else {
      cout << "setBitrate() Succeeded\n\n";
   }

   // Test accessors
   string artist = iTunesObject1.getArtist();
   int bitrate = iTunesObject1.getBitrate();

   cout << "Artist: " << artist << "\n" << "Bitrate: " << bitrate << "\n";
   return 0;
}

// class method definitions
ITunes::ITunes()
{
   setDefaults();
}

ITunes::ITunes(string name, string artist, int bitrate, int totalTime)
{
   setName(name);
   setArtist(artist);
   setBitrate(bitrate);
   setTotalTime(totalTime);
}

bool ITunes::setName(string name)
{
   if (name.length() < MIN_STR_LENGTH || name.length() > MAX_STR_LENGTH) {
      return false;
   }

   this->name = name;
   return true;
}

bool ITunes::setArtist(string artist)
{
   if (artist.length() < MIN_STR_LENGTH || artist.length() > MAX_STR_LENGTH) {
      return false;
   }

   this->artist = artist;
   return true;
}

bool ITunes::setBitrate(int bitrate)
{
   if (bitrate < MIN_BITRATE || bitrate > MAX_BITRATE) {
      return false;
   }

   this->bitrate = bitrate;
   return true;
}

bool ITunes::setTotalTime(int totalTime)
{
   if (totalTime < MIN_PLAY_TIME || totalTime > MAX_PLAY_TIME) {
      return false;
   }

   this->totalTime = totalTime;
   return true;
}

string ITunes::toString()
{
   const int MILLISECONDS_TO_SECONDS_VAL = 1000;
   int totalTimeInSeconds = totalTime / MILLISECONDS_TO_SECONDS_VAL;
   string totalTimeInSecondsString = std::to_string(totalTimeInSeconds);
   string bitrateString = std::to_string(bitrate);

   string returnString = artist + ", " + name + ", " + totalTimeInSecondsString
      + " seconds, " + bitrateString + "k bits per second";
   return returnString;
}

void ITunes::setDefaults()
{
   name = DEFAULT_STRING;
   artist = DEFAULT_STRING;
   bitrate = DEFAULT_BITRATE;
   totalTime = DEFAULT_PLAY_TIME;
}

void ITunes::display()
{
   string displayedString = toString();
   cout << displayedString << "\n\n";
}

/* --------------------------- Paste Of Run ------------------------------------

 (undefined) ,  (undefined) , 5 seconds, 64k bits per second

 (undefined) ,  (undefined) , 5 seconds, 64k bits per second

 Michael Jackson, Thriller, 500 seconds, 128k bits per second

 Drake, Gods Plan, 800 seconds, 200k bits per second

 Chris Brown,  (undefined) , 5 seconds, 64k bits per second

 (undefined) , I Feel Good, 5 seconds, 64k bits per second

 Michael Jackson, Thriller, 500 seconds, 250k bits per second

 Drake, Gods Plan, 2000 seconds, 200k bits per second

 (undefined) ,  (undefined) , 5 seconds, 64k bits per second

 (undefined) ,  (undefined) , 5 seconds, 64k bits per second

 (undefined) ,  (undefined) , 5 seconds, 64k bits per second

 (undefined) ,  (undefined) , 5 seconds, 64k bits per second

 setArtist() Failed

 setArtist() Succeeded

 setBitrate() Failed

 setBitrate() Succeeded

 Artist: Bob Marley
 Bitrate: 703
 Program ended with exit code: 0

----------------------------------------------------------------------------- */
