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

typedef struct{ //Player struct

    char name[16];//Player name
    int score;//Player score
    int xx; //Player X coords
    int yy; //Player Y coords

} Player;
//------------------------------------------------------------------/
// Global Variable Section
int x; //X coordinate for drawMap()
int y; //Y coordinate for drawMap()
int goal; //Goal score integer
char hero = '@'; //Our hero character
char villain = 'X'; //Enemy
char action; //Input key (moving)
Player player; //Declaring player or sum, forgot what it does but it works

////------------------------------------------------------------------/
// Text Section

//FUNCTION PROTOTYPES - functions explained below!
void drawMap(int randomX, int randomY); // Draws map
//void spawnPlayer(int randomX, int randomY); // Spawns Player
void moving();  // pretty self explanatory
void updateMap(int randomX, int randomY); // Map update after action
void moveUp(); // up
void moveDown(); // down
void moveLeft(); // left
void moveRight(); // right

//MAIN FUNCTION
int main(){ //Main

    srand(time(NULL)); //seeding random number so it updates per-every change of clock

    int randomX = (rand() % 19) + 1; // random number from 1 to 19
    int randomY = (rand() % 9) + 1; //random number from 1 to 9
    //such weird numbers are necessary for character to not spawn outside box

    player.xx = randomX; // player coordinate X is random from 1 to 19
    player.yy = randomY; // player coordinate Y is random from 1 to 9
                         // so they won't touch borders

    //Asks user to enter Name
    printf("What is player name? \n");
    //User inputs name
     fgets(player.name, sizeof(player.name), stdin);
    //Getting rid of new line after input
     player.name[strcspn (player.name, "\n")] = '\0';
    
    //Asks user to enter Score Goal
    printf("What is the score goal? \n");
    //check the input  
     scanf("%d\n", &goal); 

     
    printf("Great! Goodluck\n"); //stupid message for decoration
    printf("press F to quit game\n"); //additional info
    Sleep(500); //wait 0.2 seconds or sum like that 
    system("cls"); //clear screen
    drawMap(randomX, randomY); //draw map with character chosen randomly

    while (1){ //while game runs

        action = getch();     // get input
        moving();             // move based on input
                                  
        system("cls"); //clear screen to prepare it for new, freshly updated map
        updateMap(randomX, randomY); //draw updated map
        if(action == 'f'){ //if f is pressed
            break; //break loop
        }//end of if statement
    }//end of while loop

    return 0; // You'll never guess..
} //End of Main function


// FUNCTION
void moving(){ //Function responsible for moving character

    switch (action) { // action variable, which is updated after every click is 
        case 'w':     //if W is pressed                    // getting new value
            moveUp(); //execute moveUp funtion
            break;    //break loop
        case 'a':     //if A is pressed
            moveLeft();//execute moveLeft function
            break;     //break loop
        case 's':     //if S is pressed
            moveDown();//execute moveDown function 
            break;     //break loop
        case 'd':     //if D is pressed
            moveRight();//execute moveRight function
            break;  //break loop
    }//end of switch statement
}//End of function

//FUNCTION
void moveUp(){ // checks if path is free and moves player up 

    if(player.yy - 1 != 0){ // checks
        player.yy--;        // put player at Y with 1 less index than current
    }//End of for loop
}//End of function

//FUNCTION
void moveDown(){  // checks if path is free and moves player down

    if(player.yy + 1 != 10){ // checks
        player.yy++;         // put player at Y with 1 more index than current
    }//End of for loop
}//End of function

//FUNCTION
void moveLeft(){ // checks if path is free and moves player left

    if(player.xx - 1 != 0){ // checks
        player.xx--;        // put player at X with 1 less index than current
    }//End of for loop
}//End of function

//FUNCTION
void moveRight(){ // checks if path is free and moves player right
 
    if(player.xx + 1 != 20){ // checks
        player.xx++;         // put player at X with 1 more index than current
    }//End of for loop
}//End of function

//FUNCTION
void drawMap(int randomX, int randomY){ // Function that draws map

    for(int y = 0; y <= 10; y++){ // incrementing y
        for(int x = 0; x <= 20; x++){ // incrementing x
            if(y == 0 || y == 10){ //if y is the corner
                printf("#"); // draw border
                fflush(stdout); //Show output immediately to not buffer #
                Sleep(5); // Wait 0.025 seconds
                if(x == 20){ // but if its the right corner
                  printf("\n"); //then make a new line
                }//End of nested if statement

            }else if(x == player.xx && y == player.yy){ //if it's at pos of hero
                printf("%c", hero);       //prints our character
            }else if(x == 0){ //if the X is upper right corner
                printf("#"); // make border
                fflush(stdout); // Show output immediately to not buffer #
                Sleep(5);     // Wait 0.025 seconds

            }else if(x == 20){ //if the X is upper left corner
                printf("#\n"); // make border
                fflush(stdout); //Show output immediately to not buffer #
                Sleep(5); // Wait 0.025 seconds

            }else{              //if it's rest of place
                    printf(" "); //Just leave it empty
            } // End of for loop inside nested loop
        } // End of nested loop
    } // End of For loop
} // End of function

//FUNCTION
void updateMap(int randomX, int randomY){ // new map drawing
    for(int y = 0; y <= 10; y++){ // incrementing y
        for(int x = 0; x <= 20; x++){ // incrementing x
            if(y == 0 || y == 10){ //if y is the corner
                printf("#"); // draw border
                fflush(stdout); //Show output immediately to not buffer #
                if(x == 20){ // but if its the right corner
                  printf("\n"); //then make a new line
                }//End of nested if statement

            }else if(x == player.xx && y == player.yy){ // if it's at the pos of hero
                printf("%c", hero); //prints our character
            }else if(x == 0){ //if the X is upper right corner
                printf("#"); // make border
                fflush(stdout); // Show output immediately to not buffer #

            }else if(x == 20){ //if the X is upper left corner
                printf("#\n"); // make border
                fflush(stdout); //Show output immediately to not buffer #
            }else{              //if it's rest of place
                    printf(" "); //Just leave it empty
            } // End of for loop inside nested loop
        } // End of nested loop
    } // End of For loop

}//End of function

//-------------------------------------------------------------------/
// Comment Section

// I decided to rewrite whole code cuz it looked like bunch of garbage 
// and made my head spin.
