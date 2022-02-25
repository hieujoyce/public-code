#include<stdio.h>
#include<conio.h>
#include<math.h>

void sangNguyenThuy(int sang[], int n) {
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

void inSNT(int sang[], int min, int max){
    printf("\nKQ: ");
    for(int i = min; i < max; i++) {
        if(sang[i] == 1)
            printf("%d   ", i);
    }
}

//Nhập n từ 2 đến 5 thôi nếu cô hỏi thì bảo n >= 6 thì bộ nhớ không cung cấp được

int main(){
    int n;
    printf("Nhap n (So chu so cua SNT can tim): ");
    scanf("%d", &n);
    int min = n < 2 ? 2 : (int)pow(10, n - 1);
    int max = (int)pow(10, n);
    int sang[max];
    sangNguyenThuy(sang, max);
    inSNT(sang, min, max);
    getch();
    return 0;
}
