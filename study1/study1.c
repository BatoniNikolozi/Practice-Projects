// Library Section

#include <stdio.h> // for input and output
#include <stdlib.h> //forgot for what we need ts
#include <string.h> // strings
#include <unistd.h> // For sleep(); seconds
#include <windows.h> // For Sleep(); miliseconds or macro idk
#include <conio.h>   // To make terminal do stuff
#include <time.h>    // For Random Seed 
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
int goal; //Goal score integer
char hero = '@';
char villain = 'X';
char action;
////------------------------------------------------------------------/
// Text Section

//FUNCTION PROTOTYPES - functions explained below!
void drawMap(int randomX, int randomY); 
void spawnEnemy(int randomX, int randomY);
void spawnPlayer(int randomX, int randomY);
void spawnCoin();
void healthStatus();
void spawnStuff();
void moving(int randomX, int randomY);

//MAIN FUNCTION
int main(){ //Main
    //Local Variables
    srand(time(NULL)); // seeding
                       
    int randomX = (rand() % 19) + 1;  // Random X position
    int randomY = (rand() % 9) + 1;   // Random Y position

    Player player;

    //Asks user to enter Name
    printf("What is player name? \n");
    //User inputs name
    fgets(player.name, sizeof(player.name), stdin);
    //Getting rid of new line after input
    player.name[strcspn (player.name, "\n")] = '\0';
    
    //Asks user to enter Score Goal
    printf("What is the score goal? \n");
    scanf("%d", &goal);
    
    printf("\n"); //new line 
    printf("Great! Goodluck\n"); //stupid message for decoration
    Sleep(100);
    system("cls");

    moving(randomX, randomY);

do{
    system("cls");
    drawMap(randomX, randomY); // Draw a map, what a suprise right
}while(action = getch());

    return 0; // You'll never guess..
} //End of Main function



//FUNCTION
//void scorecounter(int currentScore, int goalScore){ // Counts score

//} // End of function

// FUNCTION
void moving(int randomX, int randomY){
    Coords coords;

    if (action == 'w'){
        coords.yy--;
    }else if(action == 'a'){
        coords.yy++;
    }else if(action == 's'){
        coords.xx++;
    }else if(action == 'd'){
        coords.xx--;
    }
}

//FUNCTION
void drawMap(int randomX, int randomY){ // Function that draws map. since X and Y are global variables, we don't need to include parametres.

    Coords coords;

    for(int y = 0; y <= 10; y++){ // incrementing y
        for(int x = 0; x <= 20; x++){ // incrementing x
            if(y == 0 || y == 10){ //if y is the corner
                printf("#"); // printf border
                fflush(stdout); //Show output immediately to not buffer #
                Sleep(10); // Wait 0.05 seconds
                if(x == 20){ // but if its the right corner
                  printf("\n"); //then make a new line
                }

            }else if(x == 0){ //if the X is upper right corner
                printf("#"); // make border
                fflush(stdout); // Show output immediately to not buffer #
                Sleep(10);     // Wait 0.05 seconds

            }else if(x == 20){ //if the X is upper left corner
                printf("#\n"); // make border
                fflush(stdout); //Show output immediately to not buffer #
                Sleep(10); // Wait 0.05 seconds

            }else{              //if it's rest of place
                //spawnPlayer(randomX, randomY);
                //if(x == randomX && y == randomY){
                  //  printf("%c", hero);
                //}else{
                    printf(" ");
                //}  // leave it empty.
            } // End of for loop inside nested loop
        } // End of nested loop
    } // End of For loop
} // End of function


//FUNCTION
void spawnEnemy(int randomX, int randomY){ // Spawns Enemy on Map
} // End of function


//FUNCTION
void spawnPlayer(int randomX, int randomY){ // Spawns Player on Map  
    Coords coords;
    coords.xx = randomX;
    coords.yy = randomY;

    


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


// This is second time i worked on this a little. added jus a few improvements. 

// I will surely work on this way more but right now it's lowk drilling my brains so i will quit
