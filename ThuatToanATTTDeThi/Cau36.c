#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
int lastOccurrence(char p[], char kitu){
    for(int i = strlen(p)-1; i >= 0; i--) {
        if(kitu == p[i]) return i;
    }
    return -1;
}

int min(int a, int b){
    return(a < b ? a : b);
}

void xuLy(char t[], char p[]){
    int i = strlen(p)-1, j = strlen(p)-1, check = 0, sopheptinh = 0, solanlap = 1;
    while(i < strlen(t)){
        int checkp = 0;
        while(checkp != strlen(p)){
            if(t[i] == p[j]){
                i--;
                j--;
                checkp++;
                sopheptinh++;
            }else{
                i = i + strlen(p) - min(j, 1 + lastOccurrence(p, t[i]));
                j = strlen(p) - 1;
                solanlap++;
                sopheptinh++;
                break;
            }
        }
        if(checkp == strlen(p)){
            check++;
            printf("\nKQ: Vi tri %d", i + 1);
            break;
        }
    }
    if(check == 0){
        printf("\nKQ: Khong co chuoi can tim");
    } else {
        printf("\nSo phep tinh la: %d", sopheptinh);
        printf("\nSo lan lap la: %d", solanlap);
    }
}

int main(){
    char t[5000],p[100];
    printf("Nhap doan van ban T: ");
    fflush(stdin);
    gets(t);
    printf("Nhap chuoi P can tim: ");
    fflush(stdin);
    gets(p);
    fflush(stdin);
    xuLy(t, p);
    getch();
    return 0;
}
