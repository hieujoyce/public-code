#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <time.h>
#include <stdlib.h>

int nhanBinhPhuongCoLap(int a, int k, int n){
    long long b = 1;
    if(k == 0) {
        return (int)b;
    }
    long long A = a;
    int t = k % 2;
    k = k / 2;
    if(t == 1){
        b = a;
    }
    for(int i = k; k > 0; k = k / 2){
        A = (A * A) % n;
        t = k % 2;
        if(t == 1){
            b = (A * b) % n;
        }
    }
    return (int)b;
}

int isSNT(int n){
    if(n < 2) return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int timk(int n){
    int smallerSNT, bigerSNT;
    for(int i = n - 1; ; i--){
        if(isSNT(i) == 1){
            smallerSNT = i;
            break;
        }
    }
    for(int i = n + 1; ; i++){
        if(isSNT(i) == 1){
            bigerSNT = i;
            break;
        }
    }
    int k = (n - smallerSNT > bigerSNT - n) ? bigerSNT : smallerSNT;
    return k;
}

int main(){
    int MSV, a, n = 123456;
    printf("Nhap MSV: ");
    scanf("%d", &MSV);
    printf("Nhap a: ");
    scanf("%d", &a);
    int k = timk(MSV);
    int result = nhanBinhPhuongCoLap(a, k, n);
    printf("\nKQ: %d ^ %d mod %d = %d", a, k, n, result);
    getch();
    return 0;
}