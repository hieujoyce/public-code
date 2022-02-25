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
    int p, q;
    srand((int) time(0));
    do{
        p = 1 + rand() % (1000 + 1 - 1);
    } while (isSNT(p) != 1);
    do{
        q = 1 + rand() % (1000 + 1 - 1);
    } while (isSNT(q) != 1);
    printf("\np = %d ", p);
    printf("\nq = %d ", q);
    printf("\nKQ: ");
    for(int a = 1; a < 100; a++){
        if(isSNT(nhanBinhPhuongCoLap(a, p, q)) == 1 ) printf("%d,  ", a);
    }
    getch();
    return 0;
}