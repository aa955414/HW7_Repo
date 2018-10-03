//this is the interface file of the Exit class,
//using the header file exit.h
//the Exit class gets/executes all the exit/door information
//for the adventure game
#ifndef EXIT_H
#define EXIT_H
#include <iostream>                      //cin and cout
#include <string>                        //string functions
#include <fstream>                       //for input file                      
#include <cstdlib>                       //for exit success

using namespace std;      //normal operations

//******************************************************************
//                                                                  
//  Class: Exit                               
//                                                                  
//  Purpose: keeps track of exit statuses in games          
//                                        
//  Public Member Variables: none              
//                                           
//  Private Member Variables: dir                                             
//  
//  Public Functions: exit_checker, check_choice, room_values, go_choice,
//                    exit_check, get_exit_numbers
//                                                                   
//  Private Functions: none                                          
//                   
//  Constructors: none
//                                                
//*******************************************************************
class Exit
{
public:
bool exit_checker(string finder[], int& room_nums);
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
 
void check_choice(string finder[], int& room_nums);
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
      
void room_values(string finder[], int& room_nums, int& keys_in_room,
			 double& money_in_room);
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
    
void go_choice(string finder[],int& room_nums, int& keys_in_room,
			 double& money_in_room);
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
     
void exit_check(string finder[], int& room_nums);
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
        
void get_exit_numbers(string finder[], int& room_nums);
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
private:
string dir;                //stores direction
};
#endif
