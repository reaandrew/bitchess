#include <stdio.h>

typedef unsigned long int board;

board createPositionMask(char position[2]){
    int fileIndex = (position[0] - 97);
    int rankIndex = position[1] - '0'; 
    int squareIndex = 8*rankIndex + fileIndex;
    board newPosition = 1 << squareIndex;
    return newPosition;
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

void printzeebits(board num){
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

    for(i = 63; i >= 0; i-=8){
        for(j = 7; j >= 0; j--){
            putchar(squares[i-j]);
            //printf("%d",i-j);
            putchar(' ');
        }
        printf("\n");
    }
    printf("\n");
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
    /*
       board white_pawns = 0;
       initialize_pawns(&black_pawns);
       initialize_whitepawns(&white_pawns);
       board result = black_pawns | white_pawns;
       result = move(&result, "a2","a3");
       */
    board result = black_pawns | 0x0101010101010101;
    printboard(&result);
    result = black_pawns | 0x00000000000000FF;
    printboard(&result);
    result = black_pawns | 0xFF00000000000000;
    printboard(&result);
    result = black_pawns | 0x8040201008040201;
    printboard(&result);
    result = black_pawns | 0x55AA55AA55AA55AA;
    printboard(&result);
}
