#include <stdio.h>
#define db double

db a[1000001];

void nhap(db a[], int n){
    for (int i=0; i<n; i++){
        scanf ("%lf", &a[i]);
    }
}

void xuat(db a[], int n){
    for (int i=0; i<n; i++){
        printf ("%g ", a[i]);
    }  printf ("\n");
}

void am(db a[], int n){
    for (int i=0; i<n; i++){
        if (a[i]<0){
            printf ("%d ", i);
        }
    }
}

int main(){
    int n;
    scanf ("%d", &n);
    nhap(a,n);
    xuat(a,n);
    am(a,n);
}