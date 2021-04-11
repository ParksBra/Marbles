// Libraries I copy and paste even if I don't need them
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


// Define a max
#define MAX 1024

// Global init for marble bag and size
int marbleBag[MAX] = {1, 2, 4, 7};
int marbleBagSize = 4;


// Add x marbles with y amount
void addMarble(int marbleSize, int marbleAmt){
    for(int i = 0; i < marbleAmt; i++){
        marbleBag[marbleBagSize] = marbleSize;
        marbleBagSize++;

    }
    printf("%i marble(s) added!\n\n", marbleAmt);
}

// Remove x marble from the array
void removeMarble(int marbleLoc){
    if (marbleLoc <= marbleBagSize){
        int tempMarble = marbleBag[marbleLoc];
        for(int i = marbleLoc - 1; i <= marbleBagSize; i++){
            marbleBag[i] = marbleBag[i + 1];
        }
        marbleBagSize--;
        printf("A marble with the value %i has been removed.\n\n", tempMarble);
    }
    else{
        printf("Please select a valid marble to remove.");
    }
}


// Provide UI
int main(){
    while (true){
        int choice = 0;
        printf("Marbles: ");
        for (int i = 0; i < marbleBagSize; i++){
            if (i == marbleBagSize - 1){
                printf("%i.", marbleBag[i]);
            }
            else{
                printf("%i, ", marbleBag[i]);
            }
            
        }
        printf("\n1: Add a marble\n2: Remove a marble\n3: Quit\n");
        printf("Please enter a command: ");
        scanf("%i", &choice);
        if (choice == 1){
            int tempMarbleSize, tempMarbleAmt;
            printf("Please enter a value for the marble(s): ");
            scanf("%i", &tempMarbleSize);
            printf("Please enter how many marbles to add: ");
            scanf("%i", &tempMarbleAmt);

            addMarble(tempMarbleSize, tempMarbleAmt);

        }
        else if (choice == 2){
            int tempRemoveLoc;
            while (true){
                printf("Please enter the location you'd like to remove (First being 1): ");
                scanf("%i", &tempRemoveLoc);
                if (tempRemoveLoc >= 1 && tempRemoveLoc <= marbleBagSize){
                    removeMarble(tempRemoveLoc);
                    break;
                }  
            }
        }
        else if (choice == 3){
            printf("Goodbye!");
            exit(0);
        }
        else{
            printf("Please select a valid command.\n\n");
        }
    }
    return 0;
}


// Program wouldn't run unless I did this?

// Just "main();" wouldn't work.
int _ = main();
