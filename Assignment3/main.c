/*
 * sum_square_num_Kuc.c
 *
 *  Created on: Oct 5, 2022
 *      Author: osboxes
 */

#include <stdio.h>

//definition of char evaluation
int charProcessing(char userInput);

int main (void){
    //Martikelnummmer ...33

    printf("Square Number Adder:\nSelect one value from one to nine\nPress q to abort\n\n");

    while (1){
//get char from user input
        char input = getchar();
        getchar();

        //check if user selected quit
        if(input == 113){
            printf("You selected Stop");
            return 0;
        }

        //call Function and Print value
        int charFunctOut = charProcessing(input);
        if (charFunctOut > 0){ //print if valid function return
            printf("Selected Number:  %c \n", input);
            printf("Calculated Value: %i \n\n", charFunctOut);
        }
    }
    return 0;
}

// evaluates the user input and prints the calculated int value if input correct and -1 if input incorrect
int charProcessing(char userInput){

    int correspondingNumber = userInput -48;
    int numberAndOne = 0;
    int calculatedNumber = 0;
    //calculating the second number
    if(correspondingNumber == 9){
        numberAndOne = 1;
    }
    else{
        numberAndOne = correspondingNumber + 1;
    }

    //invalid input
    if (correspondingNumber < 1 || correspondingNumber > 9){
        printf("Incorrect input, please enter ONE Number between 1 and 10 \n"
               "press q to stop the program\n");
        return -1;
    }
    else{
        //valid input
        calculatedNumber = (correspondingNumber * correspondingNumber) + (numberAndOne * numberAndOne);
        return calculatedNumber;
    }
    printf("Something is Wrong -2");
    return -2;
}

