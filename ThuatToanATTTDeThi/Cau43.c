#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int isSNT(int n){
    if(n < 2) return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int nhanBinhPhuongCoLap(int a, int k, int n){
    long long b = 1;
    if(k == 0) {
        return (int)b;
    } else if(k == 1){
        return a % n;
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

int main(){
    int p, n;
    srand((int) time(0));
    do{
        p = 1 + rand() % (100 + 1 - 1);
    } while (isSNT(p) != 1);
    printf("Nhap n: ");
    scanf("%d", &n);
    while(n <= 0 || n >= 1000){
        printf("Hay nhap lai n: ");
        scanf("%d", &n);
    }
    printf("\np = %d ", p);
    printf("\nq = %d ", n);
    printf("\nKQ: ");
    for(int a = 1; a < 1000; a++){
        if(isSNT(nhanBinhPhuongCoLap(a, p, n)) == 1 ) printf("%d,  ", a);
    }
    getch();
    return 0;
}
