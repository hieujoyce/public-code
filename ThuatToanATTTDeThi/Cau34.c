#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

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
    int t = 5;
    int a[t];
    for(int i = 0; i < t; i++){
        a[i] = 2 + rand() % (n - 2 + 1 - 2);
    }
    for(int i = 0; i < t; i++){
        int r = nhanBinhPhuongCoLap(a[i], n-1, n);
        if(r != 1){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n, t=5;
    printf("Nhap n: ");
    scanf("%d", &n);
    if(isSNT(n) == 1){
        printf("\nKQ:-> Nguyen to");
    } else {
        printf("\nKQ:-> Hop so");
    }
    getch();
    return 0;
}
