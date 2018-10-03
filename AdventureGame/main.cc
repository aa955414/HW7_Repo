//******************************************************************
//                                                                  
//  Program: project 6—Adventure Game                                
//                                                                  
//  Author: Alyssa Atkinson                                         
//  Email:  aa955414@ohio.edu                                       
//                                                                  
//  Lab Section: 101(Abdul)                                          
//                                                                   
//  Description: This program creates an adventure game and allows
//               the user to play in a virtual world.
//                                                                   
//  Date: 3 April 2017                                              
//                                                                   
//*******************************************************************
//this is the application file for the adventure game, which includes
//room.h, player.h, exit.h, and money.h, for the Room, Player, Exit,
//and Money classes
#include "room.h"                         //room class
#include "player.h"                       //player class
#include "exit.h"                         //exit class
#include "money.h"                        //money class
#include <iostream>                      //cin and cout
#include <string>                        //string functions
#include <fstream>                       //for input file                      
#include <cstdlib>                       //for exit success
#include <cstring>

using namespace std;                     //standard namespace
void magic_shop();
//******************************************************************
//                                                                  
//  Function: magic_shop                                
//                                                                  
//  Purpose: allows player to purchase something at end of game
//                                        
//  Parameters: none        
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: player wants to exit game
//                                                                   
//  Post Conditions: player gets a magic item     
//                   
//  Calls: none
//                                                
//*******************************************************************

void get_room_info(ifstream& input_file, string finder[], int& i);
//******************************************************************
//                                                                  
//  Function: get_room_info                                
//                                                                  
//  Purpose: gets input file room info                                        
//                                        
//  Parameters: input_file, finder, i         
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: input file read in
//                                                                   
//  Post Conditions: room information is obtained      
//                   
//  Calls: none
//                                                
//*******************************************************************

void play_again(char& choice, string finder[], int i);
//******************************************************************
//                                                                  
//  Function: play_again                                
//                                                                  
//  Purpose: asks player if they would like to play again                     
//                                        
//  Parameters: choice, finder, i           
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: player has chosen to exit game     
//                                                                   
//  Post Conditions: player is prompted to play again         
//                   
//  Calls: none
//                                                
//*******************************************************************

void get_input_file(ifstream& input_file);
//******************************************************************
//                                                                  
//  Function: get_input_file                              
//                                                                  
//  Purpose: asks player for input file                     
//                                        
//  Parameters: input_file           
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: input_file prompted for    
//                                                                   
//  Post Conditions: input file read in         
//                   
//  Calls: none
//                                                
//*******************************************************************

void main_menu(ifstream& input_file,Room& r0,Player& p0,Exit& e0,
	       Money& m0, string finder[], int& room_nums,  int& keys
	       , int& keys_in_room, double& money_in_room, double& new_money);
//******************************************************************
//                                                                  
//  Function: main_menu                                 
//                                                                  
//  Purpose: main menu choices                                        
//                                        
//  Parameters: input_file, r0, p0, e0, m0, finder, room_nums, keys
//              keys_in_room, money_in_room, new_money
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: none
//                                                                   
//  Post Conditions: reads in menu choice and carries out action      
//                   
//  Calls: none
//                                                
//*******************************************************************

void choose_action();
//******************************************************************
//                                                                  
//  Function: choose_action                                 
//                                                                  
//  Purpose: pulls up action choices                                        
//                                        
//  Parameters: none           
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: none
//                                                                   
//  Post Conditions: action choices are output     
//                   
//  Calls: none
//                                                
//*******************************************************************

void world_execution();
//******************************************************************
//                                                                  
//  Function: world_execution                              
//                                                                  
//  Purpose: execution of adventure game                     
//                                        
//  Parameters: none       
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: none    
//                                                                   
//  Post Conditions: allows for execution of game       
//                   
//  Calls: none
//                                                
//*******************************************************************

int main()
//*******************************************************************
//                                                                  
//  Function: main                            
//                                                                  
//  Purpose: main part of program                
//             
//*******************************************************************
{
  world_execution();              //call to execution of world
  return(EXIT_SUCCESS);          //exit program
}

//******************************************************************
//                                                                  
//  Function: play_again                                
//                                                                  
//  Purpose: asks player if they would like to play again                     
//                                        
//  Parameters: choice, finder, i           
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: player has chosen to exit game     
//                                                                   
//  Post Conditions: player is prompted to play again         
//                   
//  Calls: none
//                                                
//*******************************************************************
void play_again(char& choice, string finder[], int i)
{
  cout << "Would you like to play again? Enter Y or N:\n";
  cin >> choice;                          //reads in choice
  choice=toupper(choice);               //converts to uppercase
  while(choice!='Y' && choice!='N')      //go until valid choice read
    {
      cout << "That is not a valid choice. Enter Y or N:\n";
      cin >> choice;                    //read in valid choice
        choice=toupper(choice);
    }
  for (int k=0; k<=i; k++)
    {
      finder[k]="";
    }
  return;
}

//******************************************************************
//                                                                  
//  Function: get_input_file                              
//                                                                  
//  Purpose: asks player for input file                     
//                                        
//  Parameters: input_file           
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: input_file prompted for    
//                                                                   
//  Post Conditions: input file read in         
//                   
//  Calls: none
//                                                
//*******************************************************************
void get_input_file(ifstream& input_file)
  {
   string input_file_name;               //stores name of file
   cout << "Enter the name of the input file:\n";
   cin >> input_file_name;                   //read in file
   input_file.open(input_file_name.c_str());   //open file
   if (input_file.fail())           //check for failure
   {
      cout << "Input file failed to open.\nProgram aborting!" << endl;
      exit(EXIT_FAILURE);           //exit program
   }
   return;
   }

//******************************************************************
//                                                                  
//  Function: world_execution                              
//                                                                  
//  Purpose: execution of adventure game                     
//                                        
//  Parameters: none       
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: none    
//                                                                   
//  Post Conditions: allows for execution of game       
//                   
//  Calls: none
//                                                
//*******************************************************************
void world_execution()
{
  string finder[5000];        //stores lines
  char choice='Y';            //for play again choice
  ifstream input_file;        //input file to read in
  Room r0;                    //Room class object
  Player p0;                  //Player class object
  Exit e0;                    //Exit class object
  Money m0;                   //Money class object
  int keys;                   //stores user keys
  int room_nums;              //stores room numbers
  int keys_in_room;           //stores keys in each room
  double money_in_room;       //stores money in each room
  double new_money=0;          //stores money picked up
  int i=0;                       //stores finder index

  while(choice=='Y')          //go until player doesn't want to play again
    {
     get_input_file(input_file);   //call to get input file
     p0.greeting();                   //call to greeting player function
     p0.get_items(keys);                    //call to get items player function
     m0.get_money();                         //call to get money function
     r0.begin_room(room_nums);                  //call to begin room function
     get_room_info(input_file, finder, i);        //call to get room info
     e0.room_values(finder, room_nums, keys_in_room,
		        money_in_room);     //call to room values function
     p0.get_items(keys);                      //call to initialize function
     r0.room_entry(finder);                       //call to room entry function
     main_menu(input_file, r0, p0, e0, m0, finder, room_nums, keys,
	       keys_in_room,  money_in_room, new_money);
     //call to main menu function
     magic_shop();                       //call to magic shop
     play_again(choice, finder, i);                 //call to play again
    }
  return;
}

//******************************************************************
//                                                                  
//  Function: main_menu                                 
//                                                                  
//  Purpose: main menu choices                                        
//                                        
//  Parameters: input_file, r0, p0, e0, m0, finder, room_nums, keys,
//              keys_in_room, money_in_room, new_money
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: none
//                                                                   
//  Post Conditions: reads in menu choice and carries out action      
//                   
//  Calls: none
//                                                
//*******************************************************************
void main_menu(ifstream& input_file, Room& r0,Player& p0,Exit& e0,
	       Money& m0, string finder[], int& room_nums, int& keys,
	       int& keys_in_room, double& money_in_room, double& new_money)
{
  char menu_choice[100];   //stores menu choice
  cin.getline(menu_choice, 50);
  choose_action();    //call to choose action
  cin.getline(menu_choice, 50);
  while((strcmp(menu_choice, "Try to exit the game") && strcmp(menu_choice,"E"))
	//go until exit game
	|| e0.exit_checker(finder, room_nums)==true)
    {
 
      if (!strcmp(menu_choice, "G") || !strcmp(menu_choice, "Go"))
	//Go is chosen
        {
	  e0.go_choice(finder, room_nums, keys_in_room, money_in_room);
	  //call to go choice
	  cin.getline(menu_choice, 50);
          choose_action();       //choose action
	  cin.getline(menu_choice, 50);        //reads in menu choice
        }
      else if (!strcmp(menu_choice, "Pick up") || !strcmp(menu_choice, "PU"))
	//PU is chosen
        {
	  p0.pick_up(finder, keys, keys_in_room, money_in_room, new_money);
	  if(p0.get_pick_up_item()=="money")
	    {
	  m0.add_money(new_money);
	    }
	  //call to pick up
          choose_action();         //choose action
	  cin.getline(menu_choice, 50);        //reads in menu choice
        }
      else if (!strcmp(menu_choice,"List inventory") ||
	       !strcmp(menu_choice, "LI"))
	//LI is chosen
        {
	  p0.output_inventory(keys);         //outputs keys
	  m0.output_money();                  //outputs money
          choose_action();
	  cin.getline(menu_choice, 50);        //reads in menu choice
	  //choose action
        } 
      else if (!strcmp(menu_choice, "Describe the current room")
	       || !strcmp(menu_choice, "D"))
	//D chosen
        {
	  r0.output_room_des(finder, room_nums);
          choose_action();              //call to choose action
	  cin.getline(menu_choice, 50);        //reads in menu choice
        }
      else if (!strcmp(menu_choice, "Try to exit the game") ||
	       !strcmp(menu_choice, "E"))
	//E chosen
        {
	  e0.exit_check(finder, room_nums);
	  //call to exit check
          choose_action();                    //call to choose action
	  cin.getline(menu_choice, 50);        //reads in menu choice
	}
      else if (!strcmp(menu_choice, "Lock door") || !strcmp(menu_choice, "L"))
	//L chosen
        {
	  r0.lock_door(finder, room_nums, keys);
	  //call to lock door function
	   choose_action();              //call to choose action
	   cin.getline(menu_choice, 50);        //reads in menu choice
         }
      else if(!strcmp(menu_choice, "Unlock door")||
	      !strcmp(menu_choice, "U"))     //U chosen
       {
         r0.unlock_door(finder, room_nums, keys);        //unlock door
         choose_action();        //choose action
	 cin.getline(menu_choice, 50); //reads in menu choice
         }
  else
     {
      cout << "That is not a choice. Please choose a valid action." << endl;
      choose_action();              //choose action
      cin.getline(menu_choice, 50);        //reads in menu choice
      } 
     }
  input_file.close();                 //close the input file
  return;
}

//******************************************************************
//                                                                  
//  Function: choose_action                                 
//                                                                  
//  Purpose: pulls up action choices                                        
//                                        
//  Parameters: none           
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: none
//                                                                   
//  Post Conditions: action choices are output     
//                   
//  Calls: none
//                                                
//*******************************************************************
void choose_action()
{
  cout << "What do you want to do?\n"        //action choices
       << "Go (G)\n"
       << "Pick up (PU)\n"
       << "List inventory (LI)\n"
       << "Describe the current room (D)\n"
       << "Try to exit the game (E)\n"
       << "Lock door (L)\n"
       << "Unlock door (U)\n";
  return;
}

//******************************************************************
//                                                                  
//  Function: get_room_info                                
//                                                                  
//  Purpose: gets input file room info                                        
//                                        
//  Parameters: input_file, finder, i       
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: input file read in
//                                                                   
//  Post Conditions: room information is obtained      
//                   
//  Calls: none
//                                                
//*******************************************************************
void get_room_info(ifstream& input_file, string finder[], int& i)
{
  i=0;                   //stores count
  string line;              //stores line
  while (!input_file.eof())     //go until end of file
    {
      getline(input_file, line);      //get the line
      if(line.find("//")!=string::npos)    //find comment lines
	{
	  line.erase(line.find("//"), line.length());   //erase them
	}
      else if (line.find("#")!=string::npos && i%2!=0)
	{
	  if (finder[i]!="")
	    {
	     finder[i]+= " ";
	    }
	  finder[i]+=line;       //get other lines and store in array
	  i++;          //increase count
	}
      else if (line.find("#")==string::npos && i%2!=0)
	{
	finder[i]+=line;       //get other lines and store in array
	}
      else
	{
	  finder[i]=line;
	  i++;
	}
     }
    return;
}

//******************************************************************
//                                                                  
//  Function: magic_shop                                
//                                                                  
//  Purpose: allows player to purchase something at end of game
//                                        
//  Parameters: none        
//                                           
//  Member/Global Variables: none                                              
//  
//  Pre Conditions: player wants to exit game
//                                                                   
//  Post Conditions: player gets a magic item     
//                   
//  Calls: none
//                                                
//*******************************************************************
void magic_shop()
{
  cout << "You can now use your unicorn sticker" << endl
       << "to buy something from the magic shop!" << endl;
  int magic;             //reads in magic shop choice
  cout << "Do you want:" << endl << "1) Deck of cards\n2) Magic dice\n"
       <<"3) White rabbit\n4) Keep the sticker\nEnter the number" 
       <<" of the desired object:" << endl;
  cin >> magic;
  while (magic!=1 && magic!=2 && magic!=3 && magic!=4) //go until valid choice
    {
      cout << "That is not a choice. Please choose 1-4:" << endl;
      cin >> magic;
    }
  cout << "Ok, you have obtained";        //outputs what they chose
  if (magic==1)
    {
      cout << " the deck of cards." << endl;
    }
  else if(magic==2)
    {
      cout << " the magic dice." << endl;
    }
  else if(magic==3)
    {
      cout << " the white rabbit." << endl;
    }
  else if(magic==4)
    {
      cout << " nothing." << endl << "You chose to keep the sticker." << endl;
    }
  cout << "Thanks for playing :D" << endl;
  return;
}



