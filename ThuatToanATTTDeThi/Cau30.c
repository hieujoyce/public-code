#include<stdio.h>
#include<conio.h>
#include<math.h>

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

int kiemTraSoCamichael(int n){
    for(int a = 1; a <= n - 1; a++){
        if(gcd(a, n) == 1){
            int r = nhanBinhPhuongCoLap(a, n-1, n);
            if(r != 1){
                return 0;
            }
        }
    }
    return 1;
}

void sangNguyenThuy(int sang[], int n) {
    sang[0] = 0;
    sang[1] = 0;
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

int main(){
    int N;
    printf("Nhap N: ");
    scanf("%d", &N);
    int sang[N];
    sangNguyenThuy(sang, N);
    int sum = 0;
    for(int i = 2; i < N; i++){
        if(sang[i] == 0 && kiemTraSoCamichael(i) == 1){
                sum += i;
        }
    }
    printf("\nKQ: Tong cac so Camichael nho hon %d la: %d\n", N, sum);
    getch();
    return 0;
}
