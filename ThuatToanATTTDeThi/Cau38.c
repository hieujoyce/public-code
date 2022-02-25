#include<stdio.h>
#include<conio.h>
#include<math.h>

void xuLy(int a, int p){
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
    printf("\n%d ^ -1 mod %d = %d", a, p, x1);
}

int main(){
    int a, p;
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("\nNhap p: ");
    scanf("%d", &p);
    xuLy(a, p);
    getch();
    return 0;
}
