#include <stdio.h>
#define db double

db a[100][100];
db b[100][100];
db c[100][100];

void nhap(db a[][100], int m, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            scanf ("%lf", &a[i][j]);
        }
    }
}
void xuat(db a[][100], int m, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            printf ("%g ", a[i][j]);
        } printf ("\n");
    }
}

void nhanmatran(db a[][100], db b[][100], db c[][100], int m, int g, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            c[i][j] = 0;
            for (int k=0; k<g; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(){
    int m, n, g, h;
    printf ("Nhap vao kich thuoc ma tran a:\n");
    scanf("%d %d", &m, &g);
    printf ("Nhap vao kich thuoc ma tran b:\n");
    scanf ("%d %d", &h, &n);
    if (g==h){
        printf ("Nhap ma tran a:\n");
        nhap(a,m,g);
        printf ("Nhap ma tran b:\n");
        nhap(b,h,n);
        nhanmatran(a,b,c,m,g,n);
        printf ("Gia tri sau khi nhan ma tran a voi ma tran b:\n");
        xuat(c,m,n);
    } else printf ("So hang cua ma tran a khong bang voi so hang cua ma tran b");
}
