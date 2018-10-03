//this is the interface file of the Money class,
//using the header file money.h
//the Money class handles all money
//for the adventure game
#ifndef MONEY_H
#define MONEY_H
#include <iostream>                      //cin and cout
#include <string>                        //string functions
#include <fstream>                       //for input file                      
#include <cstdlib>                       //for exit success

using namespace std;                 //standard namespace

//******************************************************************
//                                                                  
//  Class: Money                               
//                                                                  
//  Purpose: keeps track of money in game          
//                                        
//  Public Member Variables: none                
//                                           
//  Private Member Variables: money                                           
//  
//  Public Functions: get_money, output_money, add_money      
//                                                                   
//  Private Functions: none                                          
//                   
//  Constructors: none
//                                                
//*******************************************************************
class Money
{
 public:
 void get_money();
//******************************************************************
//                                                                  
//  Function: get_money                              
//                                                                  
//  Purpose: initializes money              
//                                        
//  Parameters: none           
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: none                                
//                                                                   
//  Post Conditions: value is initialized       
//                   
//  Calls: none
//                                                
//*******************************************************************

 void output_money(); 
//******************************************************************
//                                                                  
//  Function: output_money                                
//                                                                  
//  Purpose: outputs money           
//                                        
//  Parameters: none         
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

 void add_money(double& new_money);
//******************************************************************
//                                                                  
//  Function: add_money                             
//                                                                  
//  Purpose: adds money picked up to private member variable          
//                                        
//  Parameters: new_money         
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: player chooses pick up                              
//                                                                   
//  Post Conditions: carries out action       
//                   
//  Calls: none
//                                                
//*******************************************************************
 private:
 double money;          //stores money
};
#endif
