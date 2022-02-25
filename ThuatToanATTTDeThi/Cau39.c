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

int gcd(int a, int b){
    int A = a, B = b;
    while(B > 0){
        int R = A % B;
        A = B;
        B = R;
    }
    return A;
}

void xuLy(int a[], int n){
    int check = 0;
    printf("\nKQ:\n");
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(isSNT(gcd(a[i], a[j])) == 1){
                printf("(%d, %d)\n", a[i], a[j]);
                check = 1;
            }
        }
    }
    if(check == 0) printf("Khong co cap nao thoa man");
}

int main(){
    int n;
    printf("Nhap do dai cua mang a: ");
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
        while(a[i] < 0){
            printf("Xin hay nhap lai a[%d]: ", i);
            scanf("%d", &a[i]);
        }
    }
    xuLy(a, n);
    getch();
    return 0;
}
