#include <stdio.h>
#include <conio.h>

void sangNguyenThuy(int sang[], int n){
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

int demSoNgTo(int sang[], int n){
    int count = 0;
    for(int i = 2; i < n; i++){
        if(sang[i] == 1) count++;
    }
    return count;
}

int main(){
    int A, B;
    printf("Nhap A: ");
    scanf("%d", &A);
    do{
        printf("Nhap B: ");
        scanf("%d", &B);
    }while(B <= A);
    int sang[B+1];
    sangNguyenThuy(sang, B);
    printf("\nKQ: ");
    for(int i = A; i <= B; i++){
        if(sang[demSoNgTo(sang, i)] == 1) printf("%d,  ", i);
    }
    getch();
    return 0;
}
