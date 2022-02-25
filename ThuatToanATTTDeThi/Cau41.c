#include<stdio.h>
#include<conio.h>
#include<math.h>

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
    int a, k, n;
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap k: ");
    scanf("%d", &k);
    printf("Nhap n: ");
    scanf("%d", &n);
    int result = nhanBinhPhuongCoLap(a, k, n);
    if(isSNT(result) == 1){
        printf("KQ: a ^ k mod n = %d la SNT", result);
    } else {
        printf("KQ: a ^ k mod n = %d khong la SNT", result);
    }
    getch();
    return 0;
}
