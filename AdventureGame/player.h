//this is the interface file for the Player class,
//using the header file player.h
//the Player class gets all the information for the player of the adventure game
#ifndef PLAYER_H      
#define PLAYER_H
#include <iostream>       //normal operations
#include <string>         //string
#include <fstream>        //input file
#include <cstdlib>       //exit success

using namespace std;     //standard namespace

//******************************************************************
//                                                                  
//  Class: Player                              
//                                                                  
//  Purpose: keeps track of all info for the player            
//                                        
//  Public Member Variables: none                
//                                           
//  Private Member Variables: name, unicorn_stickers, pick_up_item  
//  
//  Public Functions: greeting, get_items, output_inventory, pick_up,
//                    get_pick_up_item
//                                                                   
//  Private Functions: none                                          
//                   
//  Constructors: none
//                                                
//*******************************************************************
class Player
{
public:
 string get_pick_up_item();
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
void greeting();
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
    
void get_items(int& keys);
//******************************************************************
//                                                                  
//  Function: get_items                              
//                                                                  
//  Purpose: initializes keys, money, stickers              
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

void output_inventory(int& keys);
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
 
 void pick_up(string finder[], int& keys, int& keys_in_room,
	      double& money_in_room, double& new_money);
//******************************************************************
//                                                                  
//  Function: pick_up                                
//                                                                  
//  Purpose: allows user to pick up items                                       
//                                        
//  Parameters: keys, keys_in_room, money_in_room, finder,  new_money        
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
private:
    string name;                  //stores name
    int unicorn_stickers;         //stores unicorn stickers
    string pick_up_item;          //stores user pick up item
};
#endif
