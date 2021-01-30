#include <math.h>

int lcMult(int numOne, int numTwo){

    int max = (numOne > numTwo) ? numOne : numTwo;

    while (1) {
        if (max % numOne == 0 && max % numTwo == 0) {
            break;
        }
        ++max;
    }
    return max;
}

float absolute(float numOne){
    
    if (numOne < 0){
        return numOne * -1;
    }else{
        return numOne;
    }
}

int root(int number){

    if(number < 0){
        return number = sqrt(absolute(number));
    } else {
        return sqrt(number);
    }

}
