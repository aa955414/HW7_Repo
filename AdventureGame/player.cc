//this is the implementation file
//of the Player class, using the header file player.h
//the Player class gets all the information for the player of the adventure game
#include "player.h"        //player class
#include <iostream>       //normal operations
#include <string>         //string
#include <fstream>        //input file
#include <cstdlib>       //exit success

using namespace std;      //standard namespace

//******************************************************************
//                                                                  
//  Function: greeting                                
//                                                                  
//  Purpose: welcomes user and prompts for name              
//                                        
//  Parameters: none           
//                                           
//  Member/Global Variables: none      
//  
//  Pre Conditions: none                                
//                                                                   
//  Post Conditions: player is welcomed and name is obtained       
//                   
//  Calls: none
//                                                
//*******************************************************************
void Player::greeting()
{
  cout << "Welcome to the Adventure game!\n"            
       << "Please enter a character name to begin your quest:\n";
  cin >> name;                          //stores user name
  cout << "That's a fine name. For that, I will give you "
       << "one unicorn sticker!" << endl
       << "You can use this in the magic shop" << endl
       << "at the end of the game :)" << endl;
  unicorn_stickers++;                  //increase unicor stickers
  cout << "Ok, " << name << ", let's begin." << endl
       << "You will start with $50.00 and 5 keys." << endl
       << "You will begin in the first room, room 0." << endl;
  return;
}

//******************************************************************
//                                                                  
//  Function: get_items                              
//                                                                  
//  Purpose: initializes keys and stickers              
//                                        
//  Parameters: keys           
//                                           
//  Member/Global Variables: none                     
//  
//  Pre Conditions: none                                
//                                                                   
//  Post Conditions: values are initialized       
//                   
//  Calls: none
//                                                
//*******************************************************************
void Player::get_items(int& keys)
{
  keys=5;
  unicorn_stickers=0;
  return;
}

//******************************************************************
//                                                                  
//  Function: output_inventory                                
//                                                                  
//  Purpose: outputs inventory               
//                                        
//  Parameters: keys           
//                                           
//  Member/Global Variables: none         
//  
//  Pre Conditions: player chooses list inventory   
//                                                                   
//  Post Conditions: carries out action       
//                   
//  Calls: none
//                                                
//*******************************************************************
void Player::output_inventory(int& keys)
{
        cout << "Number of keys: " << keys << endl;    //outputs keys
	return;
}

//******************************************************************
//                                                                  
//  Function: pick_up                                
//                                                                  
//  Purpose: allows user to pick up items            
//                                        
//  Parameters: finder, keys, keys_in_room, money_in_room, new_money
//                                           
//  Member/Global Variables: none                  
//  
//  Pre Conditions: pick up is chosen
//                                                                   
//  Post Conditions: item is picked up      
//                   
//  Calls: none
//                                                
//*******************************************************************
void Player::pick_up(string finder[], int& keys, int& keys_in_room,
		     double& money_in_room, double& new_money)
{
  if (keys_in_room==0 && money_in_room==0)     //if nothing in room 
    {
      cout << "Nothing to pick up in this room.\n";
      return;
    }
  else       //prompt for pick up item
    {
      cout << "What would you like to pick up? Enter keys or money:\n";   
      getline(cin, pick_up_item);             //read in pick up item
    } 
  
  if(pick_up_item=="keys" && keys_in_room==0)       //if no keys in room
    {
      cout << "That is not an option. No keys in this room.\n";
    }

  else if (pick_up_item=="money" && money_in_room==0)  //if no money in room
    {
      cout << "That is not an option. No money in this room.\n";
    }
  else if(pick_up_item=="keys" && keys_in_room>0)    //pick up keys
    {
      keys++;
      keys_in_room--;
      cout << "You now have " << keys << " keys." << endl;
    }
  else if(pick_up_item=="money" && money_in_room>0)   //pick up money
    {
      new_money=money_in_room;
      money_in_room=0;
      cout.setf(ios::fixed);
      cout.setf(ios::showpoint);
      cout.precision(2);
      cout << "You have picked up $" << new_money << endl;
    }
  else                                   //invalid pick up item entered
    {
      cout << "That is not an option.\n";
    }
  return;
}

//******************************************************************
//                                                                  
//  Function: get_pick_up_item                               
//                                                                  
//  Purpose: returns the pick up item      
//                                        
//  Parameters: none
//                                           
//  Member/Global Variables: none                  
//  
//  Pre Conditions: pick up is chosen
//                                                                   
//  Post Conditions: pick up item returned    
//                   
//  Calls: none
//                                                
//*******************************************************************
string Player::get_pick_up_item()
{
  return(pick_up_item);           //return the string
}
