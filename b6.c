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

void max(db a[][100], int n){
    db max = a[0][0];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (a[i][j] > max) max = a[i][j];
        }
    } printf ("%g", max);
}

int main(){
    int n;
    printf ("Nhap gia tri n cua ma tran vuong kich thuoc nxn:\n");
    scanf ("%d", &n);
    printf ("Nhap ma tran:\n");
    nhap(a,n);
    printf ("Ma tran vua nhap la:\n");
    xuat(a,n);
    printf ("Phan tu lon nhat cua ma tran la:\n");
    max(a,n);
}