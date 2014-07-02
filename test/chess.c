#include <stdio.h>

typedef unsigned long int board;

board createPositionMask(char position[2]){
    int column = (position[0] - 97) + 1;
    int row = position[1] - '0'; 
    board newPosition = 0 | 0x01;
    return newPosition << ((column*row)-1);
}

board createMoveMask(char from[2], char to[2]){
    board fromPositionMask = createPositionMask(from);
    board toPositionMask = createPositionMask(to);
    return fromPositionMask | toPositionMask;
}

board move(board *b, char from[2], char to[2]){
    board moveMask = createMoveMask(from, to);
    return *b ^ moveMask;
}

void printbits(board num){
    int i;
    for(i= (sizeof(unsigned long int)*8)-1;i>= 0; i--){
        char c = (num &(1LL<<i))? '1' : '0';
        putchar(c);
    }
    printf("\n");
}

void printboard(board *b){
    int i, j;
    int m = 0;
    char squares[64];
    for(i = (sizeof(unsigned long int)*8)-1;i>= 0; i--){
        m++;
        char c = (*b &(1LL<<i))? '1' : '.';
        squares[i] = c;
    }

    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            putchar(squares[(j*8)+i]); 
            putchar(' ');
        }
        printf("\n");
    }
}

void initialize_pawns(board *b){
    int i;
    long int bit = 1;
    for(i = 0; i < 255;i+=8){
        *b |= (bit<<(i+1));
    }
}

void initialize_whitepawns(board *b){
    int i;
    long int bit = 1;
    for(i = 0; i < 255;i+=8){
        *b |= (bit<<(i+6));
    }
}

int main(){
    board black_pawns = 0;
    board white_pawns = 0;
    initialize_pawns(&black_pawns);
    initialize_whitepawns(&white_pawns);
    board result = black_pawns | white_pawns;
    result = move(&result, "h2", "h3");
    printboard(&result);
}
