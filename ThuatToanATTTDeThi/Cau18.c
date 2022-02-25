#include<stdio.h>
#include<conio.h>
#include<math.h>

void chuyenMaTran(int a, int n[], int t, int w){
    for(int i = t-1; i>=0; i--) {
        n[i] = a / (int)pow(2, i * w);
        a = a % (int)pow(2, i * w);
    }
}

int cong(int a[], int b[], int c[], int t, int w) {
    int e = 0;
    for(int i = 0; i < t; i++){
        int tmp = a[i] + b[i] + e;
        c[i] = tmp % (int)pow(2, w);
        if(tmp >= 0 && tmp < (int)pow(2, w)){
            e = 0;
        } else {
            e = 1;
        }
    }
    return e;
}

void hienThi(int c[], int t, int e){
    printf("\nKet qua la: ");
    printf("(%d, (", e);
    for(int i = t - 1; i>= 0; i--){
        if(i != 0) {
            printf("%d, ", c[i]);
        } else {
            printf("%d)", c[i]);
        }
    }
}

int main(){
    int a,b,p,w,m,t;
    printf("Nhap p: ");
    scanf("%d", &p);
    printf("Nhap w: ");
    scanf("%d", &w);
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);
    m = round(log2(p));
    t = ceil((float)m/w);
    int A[t], B[t], C[t];
    chuyenMaTran(a, A, t, w);
    chuyenMaTran(b, B, t, w);
    int e = cong(A, B, C, t, w);
    hienThi(C, t, e);

    getch();
    return 0;
}