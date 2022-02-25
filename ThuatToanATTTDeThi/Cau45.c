#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include <time.h>


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

int isSNTbyMillerRabin(int n){
    int r = n - 1, s = 0, t = 5;
    int a[t];
    for(int i = 0; i < t; i++){
        a[i] = 2 + rand() % (n - 2 + 1 - 2);
    }
    while(r % 2 == 0){
        s++;
        r = r / 2;
    }
    for(int i = 1; i <= t; i++){
        int y = nhanBinhPhuongCoLap(a[i-1], r, n);
        if(y != 1 && y != (n-1)){
            int j = 1;
            while(j <= s-1 && y != (n-1) ){
                y = (y * y) % n;
                if(y == 1){
                    return 0;
                }
                j += 1;
            }
            if(y != (n-1) ){
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    //Nhap n toi da 7 thoi :((
    srand((int) time(0));
    int n;
    printf("Nhap do dai cua mang A: ");
    scanf("%d", &n);
    int A[n];
    int MAX = 100, MIN = 3;
    for(int i = 0; i < n; i++) {
        int r = MIN + rand() % (MAX + 1 - MIN);
        while(isSNTbyMillerRabin(r) != 1) {
            r = MIN + rand() % (MAX + 1 - MIN);
        }
        A[i] = r;
    }
    printf("\nKQ: Mang A la: \n[ ");
    for(int i = 0; i < n; i++){
        if(i != n - 1) printf("%d,  ", A[i]);
        else printf("%d]", A[i]);
    }
    int minRange = abs(A[0] - A[1]), x = 0, y = 1;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(abs(A[i] - A[j]) < minRange) {
                minRange = abs(A[i] - A[j]);
                x = i;
                y = j;
            }
        }
    }
    printf("\nKhoang cach nho nhat la A[%d] va A[%d] la |%d - %d| = %d", x, y, A[x], A[y], minRange);
    getch();
    return 0;
}
