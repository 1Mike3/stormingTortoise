#include <stdio.h>
#include <limits.h>
//XXXXXXXXXXXXXXXXX Smallest-elements-Pointer SAT_05_KUC XXXXXXXXXXXXXXXXXXXXXXX

void smallestElements (int arr[],short int elementNum, int *smallest, int *second);
unsigned short startSequence();



int main() {



    //input array from which the smallest elements will be determined
    int Array[99] = {};


//Pointer shenanigans
int * psmallestNum;         //creating pointer
int   smallestNum = 0;      //creating int var
psmallestNum = &smallestNum;//assigning int var addr to pointer
int * psecSmallestNum;
int   secSmallestNum = 0;
psecSmallestNum = &secSmallestNum; //MISTAKE &smallestnum was here, and somehow the second and first number were always the same, lol

//Main Block

           short int elementNumber = 0;//contains the number of valid elements in array
    //int sizeWhole = sizeof(Array);
   // int sizeo = sizeof (Array[0]);
   // printf("The size of the wohole array is: %d\n thezize of the first element is %d \n", sizeWhole , sizeo);

    short int progControl = 0;
    while(progControl != 2){
        progControl = startSequence();
        if(progControl == 1) {
           // coode to be executed
           // for loop for user input
            printf("Enter the desired Number of Elements: ");
            scanf("%i", &elementNumber);
            printf("\n");
            for(int i = 0;i < elementNumber; i++){
                printf("#%i: ", i);
                scanf("%i", &Array[i]);
                printf("\n");
            }


//main function call
            smallestElements(Array, elementNumber, psmallestNum, psecSmallestNum);
            printf("This is the smallest number:        %d \n", *psmallestNum);
            printf("This is the second smallest number: %d \n", *psecSmallestNum);


        }
    }


    return 0;
}







void smallestElements(int arr[],short int elementNum, int *smallest, int *second) {
    short int flag = 0;

    printf("the value of the third element in the function is %d \n\n", arr[2]);
//two loops to determine the smallest element
    for(short int j = 0, k = 0; j < elementNum; j++){
        for(short int i = 0; i < elementNum; i++){
            if (arr[j] <= arr[i])
                k++;

        }
        if(k == (elementNum -1)){
            *second = arr[j];
            flag = 1;
        }

        if(k == elementNum){  //was 10
            *smallest = arr[j];
        }
        k = 0;
    }
    if(flag == 0){
        *second = *smallest;
    }

}



//function which initiates the start sequence and lets the user input a control character
unsigned short startSequence() {
    //q = 113 and s = 115
    printf("Enter the control character here(s or q): ");
    char arr[10] = {'0','0','0','0','0','0','0','0','0','0'};
    char userInput = '0';
    for (int i = 0; i < 10; ++i) {

        arr[i] = getchar();


        if (arr[0] == '\n') {
            userInput = '0';
            break;
        }

        if (arr[i] == '\n') {
            userInput = arr[(i - 1)];
            break;
        }
    }

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



