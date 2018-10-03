//this is the implementation file of the Exit class,
//using the header file exit.h
//the Exit class gets/executes all the exit/door information
//for the adventure game
#include "exit.h"
#include <iostream>                      //cin and cout
#include <string>                        //string functions
#include <fstream>                       //for input file                      
#include <cstdlib>                       //for exit success

using namespace std;                    //standard namespace

//******************************************************************
//                                                                  
//  Function: go_choice                                 
//                                                                  
//  Purpose: reads in where player wants to go               
//                                        
//  Parameters: finder, room_nums, keys_in_room, money_in_room           
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: player chooses to go                                  
//                                                                   
//  Post Conditions: player moves through that room        
//                   
//  Calls: none
//                                                
//*******************************************************************
void Exit::go_choice(string finder[], int& room_nums, int& keys_in_room,
			 double& money_in_room)
{
  cout << "In what direction would you like to go?\n";
  //prompts for direction
  cout << "Enter North, South, East, or West:\n";
  cin >> dir;                                           //read in direction
  if (dir=="North" &&
      (finder[room_nums*2].substr(finder[room_nums*2].
				  //check to see if door is locked
      find("North")+8, 1))=="l")
    {
      cout << "Sorry, that door is locked." << endl;
    }
  else if (dir== "South" &&
	   (finder[room_nums*2].substr(finder[room_nums*2].
	    find("South")+8, 1))=="l")
    {
      cout << "Sorry, that door is locked." << endl;
    }
  else if(dir=="East" &&  (finder[room_nums*2].substr(finder[room_nums*2].
		    find("East")+7, 1))=="l")
    {
      cout << "Sorry, that door is locked." << endl;
    }
  else if(dir=="West" &&
		   (finder[room_nums*2].substr(finder[room_nums*2].
		    find("West")+7, 1))=="l")
    {
      cout << "Sorry, that door is locked." << endl;
    }
  else
    {
      check_choice(finder, room_nums);            //call to check choice
      get_exit_numbers(finder, room_nums);             //call to get exit numbers
      room_values(finder, room_nums, keys_in_room, money_in_room);
      //call to get room values
    }
  return;
}

//******************************************************************
//                                                                  
//  Function: get_exit_numbers                                 
//                                                                  
//  Purpose: finds exit room numbers                                       
//                                        
//  Parameters: finder, room_nums         
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: input file has been read in
//                                                                   
//  Post Conditions: exit numbers are found      
//                   
//  Calls: none
//                                                
//*******************************************************************
void Exit::get_exit_numbers(string finder[], int& room_nums)
{
  //sets room number to appropriate exit door
  if (dir=="North")
    {
   room_nums=stoi((finder[room_nums*2].substr(finder[room_nums*2]
					      .find("North")+6, 1)));
    }
  else if (dir=="South")
    {
    room_nums=stoi((finder[room_nums*2].substr(finder[room_nums*2]
					       .find("South")+6, 1)));
    }
  else if (dir=="East")
    {
     room_nums=stoi((finder[room_nums*2].substr(finder[room_nums*2]
						.find("East")+5, 1)));
    }
  else if (dir=="West")
    {
    room_nums=stoi((finder[room_nums*2].substr(finder[room_nums*2]
					       .find("West")+5, 1)));
    }
  cout << "Ok, you have entered room: " << room_nums << endl
       << (finder[(room_nums*2)+1].substr(0, (finder[(room_nums*2)+1]
					      .length()-1))) << endl;
  return;
}

//******************************************************************
//                                                                  
//  Function: check_choice                                
//                                                                  
//  Purpose: checks direction input                                        
//                                        
//  Parameters: finder, room_nums          
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: player has entered a direction    
//                                                                   
//  Post Conditions: disallows bad input         
//                   
//  Calls: none
//                                                
//*******************************************************************
void Exit::check_choice(string finder[], int& room_nums)
{
  while(finder[room_nums*2].find(dir)==string::npos || ((dir!= "North")
							//check for bad input
     && (dir!= "East") && (dir!= "South") && (dir!="West")))
    {
      cout << "Sorry, that is not an available direction." << endl
	   << "Please enter a different direction:" << endl;
      cin >> dir;                                  //read in direction
    }
  return;
}

//******************************************************************
//                                                                  
//  Function: exit_check                                 
//                                                                  
//  Purpose: checks if player can exit game           
//                                        
//  Parameters: finder, room_nums           
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: player tries to exit                                 
//                                                                   
//  Post Conditions: determines if player can exit & carries out
//                   action
//                   
//  Calls: none
//                                                
//*******************************************************************
void Exit::exit_check(string finder[], int& room_nums)
{
  if (finder[room_nums*2].find("no_exit_game")!=string::npos)
    //check to see if room is an exit room
    { 
      cout << "Sorry, this is not an exit room." << endl;
    }
  else
    {
     exit(EXIT_SUCCESS);            //exit program
    } 
  return;
}

//******************************************************************
//                                                                  
//  Function: exit_checker                                 
//                                                                  
//  Purpose: returns true/false depending on if player can exit               
//                                        
//  Parameters: finder, room_nums          
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: player chooses to exit                                
//                                                                   
//  Post Conditions: carries out action       
//                   
//  Calls: none
//                                                
//*******************************************************************
bool Exit::exit_checker(string finder[], int& room_nums)
{
  return((finder[room_nums*2].find("no_exit_game")!=string::npos));
}

//******************************************************************
//                                                                  
//  Function: room_values                                 
//                                                                  
//  Purpose: finds room values for keys & money          
//                                        
//  Parameters: finder, room_nums, keys_in_room, money_in_room           
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: none                                
//                                                                   
//  Post Conditions: room values are found         
//                   
//  Calls: none
//                                                
//*******************************************************************
void Exit::room_values(string finder[], int& room_nums, int& keys_in_room,
			 double& money_in_room)
{        //set keys & money in room          
  keys_in_room=stoi((finder[room_nums*2].substr(finder[room_nums*2]
						.find("keys")+5, 1)));
  money_in_room=stod((finder[room_nums*2].substr(finder[room_nums*2]
						 .find("money")+6, 3)));
  return;
}
