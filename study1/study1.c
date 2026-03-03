// Library Section

#include <stdio.h> // for input and output
#include <stdlib.h> //forgot for what we need ts
#include <string.h> // strings
#include <unistd.h> // For sleep(); seconds
#include <windows.h> // For Sleep(); miliseconds or macro idk
#include <conio.h>   // To make terminal do stuff

//------------------------------------------------------------------/
// Asset Section

typedef struct{ //Score struct

    int currentScore; // Current Score
    int goalScore;    // Goal Score
    
}   Score;

typedef struct { //Coordinates struct

    int xx; //Player X coordinate
    int yy; //Player Y coordinate

} Coords;


typedef struct{
    char name[16]; // Player name
    int losses; // Amount of Loses
    int wins; // Amount of Wins

}   Player;

//------------------------------------------------------------------/
// Global Variable Section
int x; //X coordinate for drawMap()
int y; //Y coordinate for drawMap()
int randomX = (rand() % 19) + 1 // Random X position
int randomY = (rand() % 9) + 1 // Random Y position

//------------------------------------------------------------------/
// Text Section

//FUNCTION PROTOTYPES - functions explained below!
void drawMap(); 
void spawnEnemy();
void spawnPlayer();
void spawnCoin();
void healthStatus();
void spawnStuff();


//MAIN FUNCTION
int main(){ //Main

    //Asks user to enter Score Goal
    printf("What is the score goal? \n");
    int goal;
    scanf("%d", &goal);
    
    printf("\n"); //new line 
    printf("Great! Goodluck\n"); //stupid message for decoration

    drawMap(); // Draw a map, what a suprise right
    
    return 0; // You'll never guess..
} //End of Main function



//FUNCTION
void scorecounter(int currentScore, int goalScore){ // Counts score

} // End of function

//FUNCTION
void drawMap(){ // Function that draws map. since X and Y are global
                // variables, we don't need to include parametres.
    for(int y = 0; y <= 10; y++){ // incrementing y
        for(int x = 0; x <= 20; x++){ // incrementing x
            if(y == 0 || y == 10){ //if y is the corner
                printf("#"); // printf border
                fflush(stdout); //Show output immediately to not buffer #
                Sleep(100); // Wait 0.1 seconds
                if(x == 20){ // but if its the right corner
                  printf("\n"); //then make a new line
                }

            }else if(x == 0){ //if the X is upper right corner
                printf("#"); // make border
                fflush(stdout); // Show output immediately to not buffer #
                Sleep(100);     // Wait 0.1 seconds

            }else if(x == 20){ //if the X is upper left corner
                printf("#\n"); // make border
                fflush(stdout); //Show output immediately to not buffer #
                Sleep(100); // Wait 0.1 seconds

            }else{              //if it's rest of place
                printf(" ");    // leave it empty.
            } // End of for loop inside nested loop
        } // End of nested loop
    } // End of For loop

} // End of function


//FUNCTION
void spawnEnemy(){ // Spawns Enemy on Map
} // End of function


//FUNCTION
void spawnPlayer(){ // Spawns Player on Map
} // End of function

//FUNCTION
void spawnCoin(){  // Randomly Spawns Coin
} // End of function

//FUNCTION
void healthStatus(){ // Displays Health percentage and updates every frame
} // End of function

//FUNCTION
void spawnStuff(){ // Function that randomly spawns some cool usables
} // End of function

//-------------------------------------------------------------------/
// Comment Section


// This is a small game so i could practice different libraries + some of the C features.

// Code will be Uploaded on Github 

// I'm cooking this at 6:15AM
