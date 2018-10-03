//this is the implementation file of the Money class,
//using the header file money.h
//the Money class handles all money
//for the adventure game
#include "money.h"                  //money file
#include <iostream>                 //normal operations
#include <string>                  //string functions
#include <fstream>                 //for input file
#include <cstdlib>                 //exit success      

using namespace std;                //standard namespace

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
void Money::get_money()                  
{
  money=50;
  return;
}

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
void Money::output_money()
{
        cout.setf(ios::fixed);       //set to two digits after decimal
        cout.setf(ios::showpoint);
        cout.precision(2);
	cout << "Amount of money: $" << money << endl; //outputs money
	return;
}

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
void Money::add_money(double& new_money)
 {
   money+=new_money;          //add money
   new_money=0;              //set new money to 0
   return;
 }
