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

void chan(db a[], int n){
    for (int i=0; i<n; i++){
        if (a[i] == (int) a[i]){
            int vl= a[i];
            if (vl %2==0) printf ("%d", vl);
        }
    }
}

int main(){
    int n;
    scanf ("%d", &n);
    nhap(a,n);
    xuat(a,n);
    chan(a,n);
}