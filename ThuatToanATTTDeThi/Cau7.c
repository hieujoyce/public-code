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

void sangNguyenThuy(int sang[], int n) {
    for(int i = 2; i <= n; i++) {
        sang[i] = 1;
    }
    for(int i = 2; i * i <= n; i++) {
         if(sang[i] == 1) {
             for(int j = i + i; j <= n; j += i)
                 sang[j] = 0;
        }
    }
}

void inSoEmirp(int sang[], int n){
    printf("\nKQ: ");
    for(int i = 2; i < n; i++){
        int iDaoNguoc = daoNguocSo(i);
        if(sang[i] == 1 && isSNT(iDaoNguoc) == 1) printf("%d   ", i);
    }
}


int main(){
    int N;
    printf("Nhap N: ");
    scanf("%d", &N);
    int sang[N+1];
    sangNguyenThuy(sang, N);
    inSoEmirp(sang, N);
    getch();
    return 0;
}