#include <stdio.h>


//delete first
//delete last
//delete position

//union
//intersection
//difference

int main() {
   
    unsigned char mask = 1 << (sizeof(char) * 8-1);
    unsigned char A = 255;
   
    printf("Original Binary Value of A: \n");
    for(int i=0;mask>0; mask >>=1, i++){
        printf("%u ",((A&mask) != 0)? 1:0);
    }
   
    printf("\n");
    unsigned char mask1 = 1 << (sizeof(char) * 8-1);
    printf("Changing LSB to 0:\n");
    unsigned char delLSB = A & (~1);
    for(int i=0; mask1>0; mask1 >>=1, i++){
        printf("%u ",((delLSB&mask1) != 0)? 1:0);
    }
    
    printf("\n");
    unsigned char mask2 = 1 << (sizeof(char) * 8-1);
    printf("Changing MSB to 0:\n");
    unsigned char delMSB = A & (~(1 << 7));
    for(int i=0; mask2>0; mask2 >>=1, i++){
        printf("%u ",((delMSB&mask2) != 0)? 1:0);
    }
    
    printf("\n");
    unsigned char mask3 = 1 << (sizeof(char) * 8-1);
    printf("Changing 0 in the middle:\n");
    unsigned char delMid = A & (~(1 << 4)) ;
    for(int i=0; mask3>0; mask3 >>=1, i++){
        printf("%u ",((delMid&mask3) != 0)? 1:0);
    }
    
    
    printf("\n\n");
    unsigned char B = 11;
    
    unsigned char mask4 = 1 << (sizeof(char) * 8-1);
    printf("Original Binary Value of B: \n");
    for(int i=0;mask4>0; mask4 >>=1, i++){
        printf("%u ",((B&mask4) != 0)? 1:0);
    }
    printf("\n");
    
    unsigned char mask5 = 1 << (sizeof(char) * 8-1);
    printf("A|B:\n");
    unsigned char bitUnion = A | B ;
    for(int i=0; mask5>0; mask5 >>=1, i++){
        printf("%u ",((bitUnion&mask5) != 0)? 1:0);
    }
    
    printf("\n");
    unsigned char mask6 = 1 << (sizeof(char) * 8-1);
    printf("A&B:\n");
    unsigned char bitInter = A & B ;
    for(int i=0; mask6>0; mask6 >>=1, i++){
        printf("%u ",((bitInter&mask6) != 0)? 1:0);
    }
    
    printf("\n");
    unsigned char mask7 = 1 << (sizeof(char) * 8-1);
    printf("A&(~B):\n");
    unsigned char bitDiffB = A & (~B);
    for(int i=0; mask7>0; mask7 >>=1, i++){
        printf("%u ",((bitDiffB&mask7) != 0)? 1:0);
    }
    
    printf("\n");
    unsigned char mask8 = 1 << (sizeof(char) * 8-1);
    printf("(~A)&B:\n");
    unsigned char bitDiffA = (~A) & B;
    for(int i=0; mask8>0; mask8 >>=1, i++){
        printf("%u ",((bitDiffA&mask8) != 0)? 1:0);
    }
    
    printf("\n");
    unsigned char mask9 = 1 << (sizeof(char) * 8-1);
    printf("A^B:\n");
    unsigned char bitDiff = A^B;
    for(int i=0; mask9>0; mask9 >>=1, i++){
        printf("%u ",((bitDiff&mask9) != 0)? 1:0);
    }
    
    return 0;
}
