#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <time.h>
#include <stdlib.h>

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

int gcd(int a, int b){
    int A = a, B = b;
    while(B > 0){
        int R = A % B;
        A = B;
        B = R;
    }
    return A;
}

int nghicdao(int a, int p){
    int u = a, v = p, x1 = 1, x2 = 0, q, r, x;
    while(u != 1) {
        q = v / u;
        r = v - q * u;
        x = x2 - q * x1;
        //
        v = u;
        u = r;
        x2 = x1;
        x1 = x;
    }
    if(x1 < 0) {
        x1 = x1 + p;
    }
    return x1;
}

int main(){
    int p, q, n, phin, e, d, SBD, c, m;
    printf("Nhap SBD: ");
    scanf("%d", &SBD);
    srand((int) time(0));
    do{
        p = 100 + rand() % (500 + 1 - 100);
    } while (isSNT(p) == 0);
    do{
        q = 100 + rand() % (500 + 1 - 100);
    } while (isSNT(q) == 0);
    printf("\np = %d", p);
    printf("\nq = %d", q);
    n = p * q;
    phin = (p - 1)*(q - 1);
    printf("\nn = p * q = %d", n);
    printf("\nphin = (p - 1)*(q - 1) = %d", phin);
    for(int i = 3; i < phin; i++){
        if(gcd(i, phin) == 1){
            e = i;
            break;
        }
    }
    printf("\ne = %d", e);
    d = nghicdao(e, phin);
    printf("\nd = %d", d);
    m = SBD + 123;
    printf("\nBan ma:\nm = 123 + %d = %d",SBD , m);
    c = nhanBinhPhuongCoLap(m, e, n);
    printf("\nc = %d", c);
    printf("\nGiai ma:");
    m = nhanBinhPhuongCoLap(c, d, n);
    printf("\nm = %d", m);
    getch();
    return 0;
}