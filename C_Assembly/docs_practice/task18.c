#include <stdio.h>
// 18. Գրել ֆունկցիա, որը կկատարի բիթային գումարում։

void fullAder(int a, int b) {
    int cary = 0;
    int count = 0;
    int final = 0;
    
    while(count != sizeof(a) * 8) {
        int aDigit = a & 1;
        a >>= 1;
        int bDigit = b & 1;
        b >>= 1;

        int sum1 = aDigit ^ bDigit;
        int cary2 = aDigit & bDigit;

        int cary3 = sum1 & cary;
        int sum2 = cary ^ sum1;

        cary = cary2 | cary3;
        final |= sum2 << count;
        // final |= cary << (count + 1);
        count++;
    }
    printf("%d \n", final);
}

int main () {
    fullAder(-11, -15);
}