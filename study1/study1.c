// Library Section

#include <stdio.h>               // for input and output
#include <stdlib.h>             //forgot for what we need ts
#include <string.h>            // strings
#include <unistd.h>           // For sleep(); seconds
#include <windows.h>         // For Sleep(); miliseconds or macro idk
#include <conio.h>          // To make terminal do stuff
#include <time.h>          // For Random Seed
//------------------------------------------------------------------/
// Asset Section

typedef struct{                //Player struct
                              //
    char name[16];           //Player name
    int score;              //Player score
    int xx;                //Player X coords
    int yy;               //Player Y coords
                         //
} Player;

typedef struct{               //Enemy struct
                             //
    int XX;                 //Enemy X coord
    int YY;                //Enemy Y coord
    int amount;           //Amount of enemies (1, 2 or 3)
    int difficulty;      //Chance of Enemy running away from Player
} Enemy;                //
//------------------------------------------------------------------/
// Global Variable Section

int x;                                       //X coordinate for drawMap()
int y;                                      //Y coordinate for drawMap()
int goal;                                  //Goal score integer
char hero = '@';                          //Our hero character
char villain = 'X';                      //Enemy
char action;                            //Input key (moving)
Player player;                         //Declaring player or sum, forgot what it does but it works
Enemy enemy;                          //Declaring enemy or sum, forgot what it does but it works
int chance;                          //Enemy difficulty chance
char phrase[16];                    //If map is generated to load
int twoEvil[] = {0, 0};            //If it's medium mode
int threeEvil[] = {0, 0, 0};      //If it's hard mode
////--------------------------------------------------------------------------------\\
// Text Section                                                                     //
                                                                                   //
//FUNCTION PROTOTYPES                                                             //
                                                                                 //
void drawMap();                                                                 // Draws map
void moving();                                                                 // pretty self explanatory
void updateMap();                                                             // Map update after action
void moveUp();                                                               // up
void moveDown();                                                            // down
void moveLeft();                                                           // left
void moveRight();                                                         // right
void spawnEnemy();                                                       // spawn Enemy
void easy();                                                            // launch easy mode
void medium();                                                         // launch medium mode
void hard();                                                          // launch hard mode
void checkPos();                                                     // check if enemies are ready to load
//__________________________________________________________________//
//MAIN FUNCTION---------------------------------------------------\\
int main(void){                                                   //Main
                                                                 //
    srand(time(NULL));                                          //seeding random number so it updates per-every change of clock
//                                                             //
    int randomX = (rand() % 19) + 1;                          // random number from 1 to 19
    int randomY = (rand() % 9) + 1;                          //random number from 1 to 9
    int randomXX = (rand() % 19) + 1;                       //random number from 1 to 19
    int randomYY = (rand() % 9) + 1;                       //random number from 1 to 9
                                                          //Prescise numbers to not touch borders
//                                                        \\
    player.xx = randomX;                                  //player coordinate X is random from 1 to 19
    player.yy = randomY;                                 //player coordinate Y is random from 1 to 9
                                                        //
    enemy.XX = randomXX;                               //enemy coordinate X is random from 1 to 19
    enemy.YY = randomYY;                              //enemy coordinate Y is random from 1 to 9
                                                     //coordinate can only be inside border

    
    printf("What is player name? \n");
    
    fgets(player.name, sizeof(player.name), stdin);     
    
    player.name[strcspn (player.name, "\n")] = '\0';                        // Getting rid of newline after input
    
    printf("What is the score goal? \n");  
     scanf("%d", &goal); 


    printf("\nGreat! Goodluck\n"); 
    printf("press F to quit game\n"); 
    Sleep(750);                                                              //wait 3/4 seconds or sum like that 
    system("cls");                                                          //clear screen
    drawMap();                                                             //draw map with character chosen randomly

    while (1){ 

        action = getch();                                              // get input
        moving();                                                     // move based on input
                                                                     //
        system("cls");                                              //clear screen to prepare it for new, freshly updated map
        updateMap(randomX, randomY);                               //draw updated map
        if(action == 'f'){ 
            break; 
        }//end of if statement
    }//end of while loop

    return 0; 
} //End of Main function


// FUNCTION
void moving(){                                                              //Function responsible for moving character

    switch (action) { 
        case 'w': 
            moveUp(); 
            break;    
        case 'a':     
            moveLeft();
            break;    
        case 's':     
            moveDown(); 
            break;     
        case 'd':     
            moveRight();
            break;  
    }//end of switch statement
}//End of function

//FUNCTION
void moveUp(){                                                                 // checks if path is free and moves player up  
                                                                              //
    if(player.yy > 1){                                                       // checks space
        player.yy--;                                                        // put player at Y with 1 less index than current
    }//End of for loop
}//End of function

//FUNCTION
void moveDown(){                                                          // checks if path is free and moves player down
                                                                         //
    if(player.yy < 9){                                                  // checks space
        player.yy++;                                                   // put player at Y with 1 more index than current
    }//End of for loop
}//End of function

//FUNCTION
void moveLeft(){                                                   // checks if path is free and moves player left
                                                                  //
    if(player.xx > 1){                                           // checks space
        player.xx--;                                            // put player at X with 1 less index than current
    }//End of for loop
}//End of function

//FUNCTION
void moveRight(){                                           // checks if path is free and moves player right
                                                           //
    if(player.xx < 19){                                   // checks space
        player.xx++;                                     // put player at X with 1 more index than current
    }//End of for loop
}//End of function


//FUNCTION
void drawMap(){                                                                          // Function that draws map
                                                                                        //
    for(int y = 0; y <= 10; y++)                                                       //
    {                                                                                 // incrementing y
        for(int x = 0; x <= 20; x++)                                                 //
        {                                                                           // incrementing x
            if(y == 0 || y == 10)                                                  //
            {                                                                     //if y is the corner
                printf("#");                                                     // draw border
                fflush(stdout);                                                 //Show output immediately to not buffer '#'
                Sleep(5);                                                      // Wait 0.025 seconds
                if(x == 20){                                                  // but if its the right corner
                    printf("\n");                                            //then make a new line
                }//End of nested if statement

            }else if(x == player.xx && y == player.yy){                   //if it's at pos of hero
                printf("%c", hero);                                      //
            }else if(x == 0){                                           //if the X is upper right corner
                printf("#"); 
                fflush(stdout); 
                Sleep(5);     

            }else if(x == 20){                                       //if the X is upper left corner
                printf("#\n");                                      //
                fflush(stdout);                                    //
                Sleep(5);                                         //
                                                                 //
            }else{                                              //if it's rest of place
                    printf(" "); 
            } // End of for loop inside nested loop
        } // End of nested loop
    } // End of For loop
} // End of function


//FUNCTION
void updateMap(){                                                           // new map drawing
    for(int y = 0; y <= 10; y++){                                          // incrementing y
        for(int x = 0; x <= 20; x++){                                     // incrementing x
            if(y == 0 || y == 10)                                        // if y is the corner
            {   
                printf("#"); 
                fflush(stdout);                                          //Show output immediately to not buffer '#'
                if(x == 20){                                            // but if its the right corner
                  printf("\n"); 
                }//End of nested if statement

            }
            else if(x == player.xx && y == player.yy)                        // if it's at the pos of hero
            {                                                               //
                printf("%c", hero);                                        //prints our character
            }                                                             //
            else if(x == 0)                                              //if the X is upper right corner
            { 
                printf("#"); 
                fflush(stdout); 

            }
            else if(x == 20){                                           //if the X is upper left corner
                printf("#\n"); 
                fflush(stdout); 
            
            }
            else                                                         //if it's middle
            {             
                printf(" "); 1
            }// End of for loop inside nested loop
        } // End of nested loop
    } // End of For loop

}//End of function



//FUNCTION
char checkPos()
{
    if (chance =< 6)
    {
        if(enemy.XX != player.xx && enemy.YY != player.YY)
        {
            return phrase[] = "Available";
        }
    }
    else if (chance > 6 && chance =< 9)
    {
        
    }
}



//FUNCTION
/*
void spawnEnemy(){
    int chance = (rand() % 10) + 1; //Generates number between 1 and 10. determines difficulty
    
    //Launches mode based on difficulty
    if(chance <= 6)                 // 60% chance of easy difficulty
    {
        enemy.difficulty = 1;       // easy difficulty
        if(enemy.XX != player.xx && enemy.YY != player.yy)
        {
            easy();
        }
    }
    else if (chance > 6 && chance =< 9) // 30% chance of medium difficulty
    {   
        enemy.difficulty = 2;       // medium difficulty
        if(enemy.XX != player.xx && enemy.YY != player.yy){
            medium();
        }
    }
    else                            // 10% chance of hard difficulty
    {
        enemy.difficulty = 3;       // hard difficulty
        if(enemy.XX != player.xx && enemy.YY != player.yy){
            hard();             
        }
    }
    

}*/


//FUNCTION
void easy()
{
    //Amount of enemies
    enemy.amount = 1;
    for (int i = 1; i =< 3; i++)
    {
        printf("%c", villain);
    }
}

//FUNCTION
void medium()
{
    //Amount of enemies
    enemy.amount = 2;
    for (int i = 1; i =< 4; i++){
        printf("%c", villain);
    }
}

//FUNCTION
void hard()
{
    //Amount of enemies
    enemy.amount = 3;
    for (int i = 1; i =< 5; i++){
        printf("%c", villain);
    }
}

//-------------------------------------------------------------------/
// Comment Section

// I decided to rewrite whole code cuz it looked like bunch of garbage 
// and made my head spin.
