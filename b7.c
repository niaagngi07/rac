#include <stdio.h>
#define db double

db a[100][100];

void nhap(db a[][100], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf ("%lf", &a[i][j]);
        }
    }
}

void xuat(db a[][100], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf ("%g ", a[i][j]);
        } printf ("\n");
    }
}

void doixung(db a[][100], int n){
    db tmp=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (a[i][j]!=a[j][i]) tmp++;
        }
    } if (tmp!=0) printf ("Ma tran khong doi xung");
    else printf ("Ma tran doi xung");
}

int main(){
    int n; 
    scanf ("%d", &n);
    nhap(a,n);
    xuat(a,n);
    doixung(a,n);
}