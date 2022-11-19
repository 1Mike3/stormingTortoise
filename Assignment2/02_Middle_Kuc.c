
#include <stdio.h>

int main(void){
    //Martikelnummer 52201833


    int firstNumber = 47, secondNumber = 92, thirdNumber = 33; // 47, 92, 33
    int minValue = 0;
    int modValue = 0;
    int referenceNumber = 0;


    if (firstNumber < secondNumber && firstNumber < thirdNumber ){
        minValue = firstNumber;
    }
    if ( secondNumber <   firstNumber && secondNumber < thirdNumber){
        minValue = secondNumber;
    }
    if (thirdNumber < firstNumber && thirdNumber < secondNumber){
        minValue = thirdNumber;
    }
    /*
    //Protection against two lower numbers result
    if ((firstNumber == secondNumber || firstNumber == thirdNumber || thirdNumber == secondNumber)&& minValue == 0){
        printf("One or more numbers are the same! \n No definitive Result!");
        return 1;
    }
     */
    //printing the initial Values
    printf(" First Number:  %d \n Second Number: %d \n Third Number:  %d \n", firstNumber,secondNumber,thirdNumber);
//creating a reference Number for the switch-case function
    if(firstNumber == minValue && secondNumber != minValue && thirdNumber != minValue){
        referenceNumber = 1;
    }
    else if (secondNumber == minValue && firstNumber != minValue && thirdNumber != minValue){
        referenceNumber = 2;
    }
    else if(thirdNumber == minValue && firstNumber != minValue && secondNumber != minValue){
        referenceNumber = 3;
    }
    else {
        referenceNumber = 4;
    }
    // printing the highest value
    switch (referenceNumber){
        case 1 : printf("The first number is the lowest number"
                        " with a value of: %d \n", firstNumber); break;

        case 2: printf("The second number is the lowest number"
                       " with a value of: %d \n", secondNumber); break;

        case 3: printf("The third number is the lowest number"
                       " with a value of: %d \n", thirdNumber); break;

        case 4: printf("Two or more of the numbers are identical, the lowest number is"
                       ": %d \n", thirdNumber); break;

        default: printf("well,well,well... seems you made a mistake :( #1");
    }

    modValue = minValue % 3;
    printf("Mod value largest number: %d \n", modValue);

    return 0;
}
