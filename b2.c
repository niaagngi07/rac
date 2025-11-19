#include <stdio.h>
#include <string.h>

char a[1001];
int main(){
    scanf ("%s", a);
    int n = strlen(a);
    int num=0;
    for (int i=0; i<=(n/2); i++){
        if (a[i]!=a[n-i-1]) num+=i;
    }
    if (num!=0) printf ("no");
    else printf ("yes");
}