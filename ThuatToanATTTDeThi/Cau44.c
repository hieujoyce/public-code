#include<stdio.h>
#include<conio.h>
#include<math.h>

int nghichdao(int a, int p){
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
    int n, p = 2147483647;
    printf("Nhap do dai cua mang a: ");
    scanf("%d", &n);
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
        while(a[i] <= 0 || a[i] >= p){
            printf("Nhap lai a[%d] lon hon 0 va nho hon p: ", i);
            scanf("%d", &a[i]);
        }
    }
    for(int i = 0; i < n; i++){
        b[i] = nghichdao(a[i], p);
    }
    printf("\nKQ: Mang b nghich dao tuong ung mang a la: \n[ ");
    for(int i = 0; i < n; i++){
        if(i != n - 1) printf("%d,  ", b[i]);
        else printf("%d]", b[i]);
    }
    getch();
    return 0;
}
