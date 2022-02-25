#include <stdio.h>
#include <conio.h>
#include <math.h>

int isSNT(int n){
    if(n < 2) return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int daoNguocSo(int n){
    int res = 0, tmp;
    while(n > 0){
        tmp = n % 10;
        res = res * 10 + tmp;
        n = n / 10;
    }
    return res;
}

int main(){
    printf("KQ: ");
    for(int i = 5; i < 10; i++){
        if(isSNT(daoNguocSo(i*i*i)) == 1) printf("%d   ", i*i*i);
    }
    getch();
    return 0;
}