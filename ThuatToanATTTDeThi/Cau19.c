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
    int A, B, C, m, l, res;
    printf("Nhap A: ");
    scanf("%d", &A);
    printf("Nhap B: ");
    scanf("%d", &B);
    printf("Nhap C: ");
    scanf("%d", &C);
    printf("Nhap m: ");
    scanf("%d", &m);
    do{
        printf("Nhap l: ");
        scanf("%d", &l);
    }while(l <= m);
    printf("\nA * x ^ 2 + B * x + C = res");
    printf("\nKQ: Voi x = { ");
    for(int i = m; i <= l ; i++){
        res = A * (int)pow(i, 2) + B * i + C;
        if(isSNT(res) == 1){
            printf("%d, ", i);
        }
    }
    printf("} thi res la SNT");
    getch();
    return 0;
}
