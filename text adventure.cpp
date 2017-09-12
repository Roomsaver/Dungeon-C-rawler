//text-based adventure engine
//written by Wesley Lesher
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <cctype>
#include <boost/algorithm/string.hpp>

using namespace std;
//this function parses the user response, compares it to all dictionary entries, and returns their response as an integer
//to find what command the user tried, call "parse(user input string)" and check the ids in the list below.
//if the parser returns 0, it means the user did not enter a valid command
//ask for input again
int parse(string response){
    boost::algorithm::to_lower(response);
    //dictionary
    if(response == "yes"){
        return 1;
    }
    else if(response == "no"){
        return 2;
    }
    else if(response == "north"){
        return 3;
    }
    else if(response == "go north"){
        return 3;
    }
    else if(response == "n"){
        return 3;
    }
    else if(response == "east"){
        return 4;
    }
    else if(response == "go east"){
        return 4;
    }
    else if(response == "e"){
        return 4;
    }
    else if(response == "south"){
        return 5;
    }
    else if(response == "go south"){
        return 5;
    }
    else if(response == "s"){
        return 5;
    }
    else if(response == "west"){
        return 6;
    }
    else if(response == "go west"){
        return 6;
    }
    else if(response == "w"){
        return 6;
    }
    else if(response == "i"){
        return 7;
    }
    else if(response == "inv"){
        return 7;
    }
    else if(response == "inventory"){
        return 7;
    }
    else if(response == "check inventory"){
        return 7;
    }
    else if(response == "help"){
        return 8;
    }
    else if(response == "h"){
        return 8;
    }
    else if(response == "look"){
        return 9;
    }
    else if(response == "use"){
        return 10;
    }
    else{
        return 0;
    }
    return 0;
}

int main(){

//variables

bool loopagain = false;
string response = "";
string ask = "\nWhat will you do? ";
string help =  "-----Help-----\nAvailable commands: yes, no:confirmation\n(go) [n]orth, [s]outh, [e]ast, [w]est: travel to a different room\n[[i]nv]entory: check inventory\n[h]elp: display this message\nlook: repeat description message\nuse: use an item\n";
int reparsed;
int way = 0;
bool alive = true;

//story
string first = "You find yourself in a dimly lit dungeon\nThe only light is coming from a small torch mounted to the wall\nThere's an exit to the \"east\" and the \"south\"";
string second = "\nYou went east\nThere's an exit to the west and \nThere is also a giant troll in this room";
string third = "\nYou went south\n";

//game

while(parse(response) == 0 || loopagain == true){
    cout << first <<ask;
    getline(cin,response);
    reparsed = parse(response);
    
    if(reparsed==8){
        cout << help;
        loopagain = true;
    }
    else if(reparsed==4){
        way = 1;
        loopagain = false;
    }
    else if(reparsed==5){
        way = 2;
        loopagain = false;
    }
}

    if(way == 1){
        response = "";
        while(parse(response) == 0|| loopagain == true){
            cout << second << ask;
            getline(cin,response);
            reparsed = parse(response);
            
            if(reparsed == 8){
                cout << help;
            }
            
        }
    }
    else if(way == 2){
        response = "";
        while(parse(response) == 0||loopagain == true){
            cout << third << ask;
            getline(cin,response);
            reparsed = parse(response);
            
            if(reparsed == 8){
                cout << help;
            }
            
        }
    }

//return
return 0;
}