#include <stdio.h>

int translateMove(char position[2]){
    int column = (position[0] - 97) + 1;
    int row = position[1] - '0'; 

    return (column * row);
}

int main(){
    printf("%s = %d \n", "a1", translateMove("a1"));
    printf("%s = %d \n", "h8", translateMove("h8"));
    return 0;
}
