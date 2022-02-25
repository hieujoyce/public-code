#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int isSNT(int n){
    if(n < 2) return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int main(){
    int N;
    printf("Nhap N: ");
    scanf("%d", &N);
    int a[N];
    srand((int)time(0));//Khoi tao bo sinh so ngau nhien
    for(int i = 0; i < N; i++){
        a[i] = rand();
    }
    printf("Mang sinh ngau nhien:\n");
    for(int i = 0; i < N; i++){
        if(i == 0) printf("[%d, ", a[i]);
        else if(i == N - 1) printf("%d]", a[i]);
        else printf("%d, ", a[i]);
    }
    int check = 0;
    printf("\nKQ: ");
    for(int i = 0; i < N; i++){
        if(isSNT(a[i]) == 1){
            printf("%d, ", a[i]);
            check++;
        }
    }
    if(check == 0) printf("Khong co SNT nao trong mang");
    else printf("la SNT trong mang");
    getch();
    return 0;
}
