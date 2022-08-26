#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_spaceship(char *space){
    int X = 0;
    int Y = 0;
    int count = 0;
    int my_len = strlen(space);                     // length of the parameter
    char *direction = "up";                         // for str OR char direction = 'up' for character
  
    char *memory = (char*)malloc(sizeof(char)* 500);
    
    while (count < my_len)
    {
        char ship = space[count]; // to avoid using the index of the parameter i.e space[c] in the first if statements as it gives a warning
        if (ship == 'L'){
            if (strcmp(direction, "right") == 0){
                direction = "up";
            }
            else if (strcmp(direction, "down") == 0){
                direction = "right";
            }
            else if (strcmp(direction, "up") == 0){
                direction = "left";
            }
            else{
                direction = "down";
            }
        };

        if (ship == 'R'){
            if (strcmp(direction, "down") == 0){
                direction = "left";
            }
            else if (strcmp(direction, "left") == 0){
                direction = "up";
            }
            else if (strcmp(direction, "up") == 0){
                direction = "right";
            }
            else{
                direction = "down";
            }
        };

        if (ship == 'A')        {
            if (strcmp(direction, "up") == 0){
                Y = Y - 1;
            }
            else if (strcmp(direction, "down") == 0){
                Y = Y + 1;
            }
            else if (strcmp(direction, "left") == 0){
                X = X - 1;
            }
            else{
                X = X + 1;
            }
        }
        count++;
    }
    sprintf(memory, "{x: %d, y: %d, direction: '%s'}", X, Y, direction); // concatenate properly
    return memory;
}