//this is the interface file for the Room class, using the header file room.h
//the Room class gets all the information for each room in the world
#ifndef ROOM_H
#define ROOM_H
#include <iostream>                      //cin and cout
#include <string>                        //string functions
#include <fstream>                       //for input file                      
#include <cstdlib>                       //for exit success

using namespace std;         //standard namespace
//******************************************************************
//                                                                  
//  Class: Room                              
//                                                                  
//  Purpose: keeps track of all info for the rooms            
//                                        
//  Public Member Variables: none                
//                                           
//  Private Member Variables: none                
//  
//  Public Functions: lock_door, unlock_door, begin_room, room_entry,
//                    output_room_des
//                                                                   
//  Private Functions: none                                          
//                   
//  Constructors: none
//                                                
//*******************************************************************
class Room
{
public:
void output_room_des(string finder[], int& room_nums);
//******************************************************************
//                                                                  
//  Function: output_room_des                                 
//                                                                  
//  Purpose: outputs room description                                        
//                                        
//  Parameters: finder, room_nums          
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: describe room chosen
//                                                                   
//  Post Conditions: room description output     
//                   
//  Calls: none
//                                                
//*******************************************************************
    
 void lock_door(string finder[], int& room_nums, int& keys);
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
    
void unlock_door(string finder[], int& room_nums, int& keys);
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
    
void begin_room(int& room_nums);
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
    
void room_entry(string finder[]);
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
private:
};
#endif
