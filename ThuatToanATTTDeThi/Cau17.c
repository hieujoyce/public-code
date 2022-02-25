#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int isSNT(int n){
    if(n < 2) return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int main(){
    int A, B, C, x, res;
    printf("Nhap A: ");
    scanf("%d", &A);
    printf("Nhap B: ");
    scanf("%d", &B);
    printf("Nhap C: ");
    scanf("%d", &C);
    for(int i = 1; ; i++){
        res = A * (int)pow(i, 2) + B * i + C;
        if(isSNT(res) == 1){
            x = i;
            break;
        }
    }
    printf("\nA * x ^ 2 + B * x + C = %d", res);
    printf("\nKQ: Voi x = %d thi %d la SNT", x, res);
    getch();
    return 0;
}
