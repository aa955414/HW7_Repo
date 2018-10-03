//this is the implementation file
//of the Room class, using the header file room.h
//the Room class gets all the information for each room in the world
#include "room.h"          //room class file    
#include <iostream>        //normal operations
#include <string>          //strings
#include <fstream>         //for input file
#include <cstdlib>         //exit success

using namespace std;       //standard namespace
//******************************************************************
//                                                                  
//  Function: lock_door                                 
//                                                                  
//  Purpose: locks desired door                                        
//                                        
//  Parameters: finder, room_nums, keys         
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: lock door is chosen
//                                                                   
//  Post Conditions: door is locked       
//                   
//  Calls: none
//                                                
//*******************************************************************
void Room::lock_door(string finder[], int& room_nums, int& keys)
{
 if(keys>0)    //check if they have keys
  {
  string s_lock_door;         //stores string for door direction
  cout << "Which door would you like to lock?" <<
    endl << "Enter North, South, East, or West:" << endl;
  getline(cin, s_lock_door);           //read in direction
  if (s_lock_door=="North" &&
      (finder[room_nums].substr(finder[room_nums].find("North")+8, 1))!="l")
    {                        //change unlocked to locked
      finder[room_nums*2].erase(finder[room_nums*2].find("North") + 8, 8);
      finder[room_nums*2].insert(finder[room_nums*2]
				 .find("North") + 8, "locked");
      keys--;
      cout << "You have locked the North door." << endl;
    }
  else if(s_lock_door=="East" &&
	  (finder[room_nums].substr(finder[room_nums].find("East")+7, 1))!="l")
    {
      finder[room_nums*2].erase(finder[room_nums*2].find("East") + 7, 8);
      finder[room_nums*2].insert(finder[room_nums*2]
				 .find("East") + 7, "locked");
      keys--;
      cout << "You have locked the East door." << endl;
    }
  else if(s_lock_door=="South" &&
	  (finder[room_nums].substr(finder[room_nums].find("South")+8, 1))!="l")
    {
      finder[room_nums*2].erase(finder[room_nums*2].find("South") + 8, 8);
      finder[room_nums*2].insert(finder[room_nums*2]
				 .find("South") + 8, "locked");
      keys--;
      cout << "You have locked the South door." << endl;
    }
  else if(s_lock_door=="West" &&
	  (finder[room_nums].substr(finder[room_nums].find("West")+7, 1))!="l")
    {
      finder[room_nums*2].erase(finder[room_nums*2].find("West") + 7, 8);
      finder[room_nums*2].insert(finder[room_nums*2]
				 .find("West") + 7, "locked");
      keys--;
      cout << "You have locked the West door." << endl;
     }
  else                //if door can't be locked
      cout << "That is not an option." << endl;
  }
  else
      {
       	cout << "Sorry, no keys left." << endl;    //no keys available
      }
  return;
}

//******************************************************************
//                                                                  
//  Function: unlock_door                                 
//                                                                  
//  Purpose: unlocks desired door                                        
//                                        
//  Parameters: finder, room_nums, keys           
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: unlock door is chosen
//                                                                   
//  Post Conditions: door is unlocked       
//                   
//  Calls: none
//                                                
//*******************************************************************
void Room::unlock_door(string finder[], int& room_nums, int& keys)
{
 if (keys>0)
  {
  string s_unlock_door;        //stores unlock door string
   cout << "Which door would you like to unlock?"
	<< endl << "Enter North, South, East, or West:" << endl;
   getline(cin, s_unlock_door);           //reads in unlock door string
   if (s_unlock_door=="North" &&           //change locked to unlocked
     (finder[room_nums*2].substr(finder[room_nums*2].find("North")+8, 1))=="l")
    {
      finder[room_nums*2].erase(finder[room_nums*2].find("North") + 8, 6);
      finder[room_nums*2].insert(finder[room_nums*2]
				 .find("North") + 8, "unlocked");
      keys--;
      cout << "You have unlocked the North door." << endl;
    }
  else if(s_unlock_door=="East" &&
	  (finder[room_nums*2].substr(finder[room_nums*2]
				      .find("East")+7, 1))=="l")
    {
      finder[room_nums*2].erase(finder[room_nums*2].find("East") + 7, 6);
      finder[room_nums*2].insert(finder[room_nums*2]
				 .find("East") + 7, "unlocked");
      keys--;
      cout << "You have unlocked the East door." << endl;
    }
  else if(s_unlock_door=="South" &&
	  (finder[room_nums*2].substr(finder[room_nums*2]
				      .find("South")+8, 1))=="l")
    {
      finder[room_nums*2].erase(finder[room_nums*2].find("South") + 8, 6);
      finder[room_nums*2].insert(finder[room_nums*2]
				 .find("South") + 8, "unlocked");
      keys--;
      cout << "You have unlocked the South door." << endl;
    }
  else if(s_unlock_door=="West" &&
	  (finder[room_nums*2].substr(finder[room_nums*2]
				      .find("West")+7, 1))=="l")
    {
      finder[room_nums*2].erase(finder[room_nums*2].find("West") + 7, 6);
      finder[room_nums*2].insert(finder[room_nums*2]
				 .find("West") + 7, "unlocked");
      keys--;
      cout << "You have unlocked the West door." << endl;
    }
  else                                       //if unlocking is not an option
      cout << "That is not an option." << endl;
  }
   else
      {
       	cout << "Sorry, no keys left." << endl;    //no keys available
      }
  return;
}

//******************************************************************
//                                                                  
//  Function: begin_room                                 
//                                                                  
//  Purpose: initial room                                        
//                                        
//  Parameters: room_nums          
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: none
//                                                                   
//  Post Conditions: initial room is set     
//                   
//  Calls: none
//                                                
//*******************************************************************
void Room::begin_room(int& room_nums)
{
  room_nums=0;        //set initial room number
  return;
}

//******************************************************************
//                                                                  
//  Function: room_entry                             
//                                                                  
//  Purpose: outputs room description when user enters     
//                                        
//  Parameters: finder          
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: input file has been opened
//                                                                   
//  Post Conditions: description is output       
//                   
//  Calls: none
//                                                
//*******************************************************************
void Room::room_entry(string finder[])
{
  cout << finder[1].substr(0, finder[1].length()-1) << endl;
  //output initial room description
  return;
}

//******************************************************************
//                                                                  
//  Function: output_room_des                                 
//                                                                  
//  Purpose: outputs description of room              
//                                        
//  Parameters: finder, room_nums          
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: room description chosen or player enters room             
//                                                                   
//  Post Conditions: carries out action       
//                   
//  Calls: none
//                                                
//*******************************************************************
void Room::output_room_des(string finder[], int& room_nums)
{
       string room_des=(finder[(room_nums*2)+1].substr(0,
						       //get room description
        (finder[(room_nums*2)+1].length()-1)));
        cout << room_des  << endl;               //output room description
	return;
}
