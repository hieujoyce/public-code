#include <stdio.h>
#include <conio.h>
#include <math.h>

int tongSoUoc(int n){
    int total = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            total += i;
        }
    }
    return total;
}


int main(){
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    int check[3*n];
    for(int i = 1; i < 3 * n; i++){
        check[i] = 0;
    }
    for(int i = n - 1; i >= 1; i--){
        int res = tongSoUoc(i) - i;
        if(check[res]){
            printf("\nKQ: Do la 2 so %d va %d", i, check[res]);
            break;
        }
        check[res] = i;
    }
    getch();
    return 0;
}