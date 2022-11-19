#include <stdio.h>

// Kuc Michal
// Martikelnummer 52201833
//Assignment 4: Palindrome

//Function declaration
unsigned short startSequence();
void wordFunction();



int main() {
    printf("\n\nPalindrome creator:\n");
    printf("press \"s\" to start or \"q\" to quit the program.\n"
                  "Enter a Word, press enter and watch the magic happen :)\n\n");

    unsigned short progControl = 0; //programm steering which executes or exits the programm depending on the user input
    // 1 is execute, 2 is abort
    while(progControl != 2){
        progControl = startSequence();
        if(progControl == 1) {
            wordFunction();
        }
    }

   return 0;
}


/*This function in the core function of the Program which reads
the user imput, checks for correctness, fuses it together into a array of chars
,flips the array to create a palindrome and finally outputs the result using the printf function */
//the largest accepted input is 45 characters (the largest word according to google :) )
void wordFunction(){
    char rawUserArray[47] = {}; //array which contains the raw user input
    char palindrome[47] = {};
    unsigned short inputCounter = 0; // contains the number of entered characters including Enter
    //TODO Uprade to Input controll, entered undefined character
    //For loop which reads the user input
    printf("Enter your word:      ");
    for (int i = 0; i < 45; ++i) {
        rawUserArray[i] = getchar();
        inputCounter++;
       if (rawUserArray[i] == '\n') {
           break;
       }
    }

    //from here the mirroring of the user input start
    //
    unsigned short j = (inputCounter -2); // counter for the palindrome creation, -2 so enter doesnt get flipped
    for(unsigned short i = 0;i <= (inputCounter -2) && i < 46; i++, j--) {
       palindrome[i] = rawUserArray[j];
        //printf("\nThis is i: %i\n", i);
        //printf("this is value i: %c\n", palindrome[i]);
        //printf("This is j: %i\n", j);
        //printf("this is value j: %c\n", rawUserArray[j]);
    }
    printf("\n\nThis is your Word:       %s", rawUserArray);
    printf("This is your palindrome: %s\n\n", palindrome);

}

//function which initiates the start sequence and lets the user input a control character
unsigned short startSequence() {
   //q = 113 and s = 115
    printf("Enter the control character here(s or q): ");
    //TODO make the function immune to more than one input
    char userInput = getchar();
    getchar(); // to catch the enter input
    while((int)userInput != 113){// loop will only be executed if the user input is incorrect
        if((int)userInput != 115){
            //hello
        }
        else{
            break;
        } //till here: check in input either 113 or 115, if not stay in loop

        printf("You entered an incorrect character, try again!\n\n");
        printf("Enter the control character here(s or q): ");
        userInput = getchar();
        getchar(); // to catch the enter input
    }
    if(userInput == 113){
        return 2;
    }
   else if (userInput == 115) {
        return 1;
    }

}