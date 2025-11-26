/*
Bài thực hành sáng nay 25/11/2025
Các em thực các bài sau:
Bài 1. Viêt chương trình có sử dụng hàm thực các công việc sau
1.	Nhập 2 ma trận thực  A và B  gồm  cấp mxn 
2.	Xuất 2 ma trận đó ra màn hình
3.	Thực hiện nhân 2 nhân 2 ma trận  A và B trong điều kiện số cột của ma trận A bằng số hàng của ma trận B
4.	Chuyển vị ma  trận tích của A và B
5.	Đưa phần tử lớn nhất của từng hàng của ma trận A lên đường chéo chính khi ma trận A là 1 ma trận vuông. Tính tổng các phần tử của lớn nhất của từng hàng trên đường chéo chính sau đó đổi sang cơ số bất kỳ ( cơ số nhập từ bàn phím : Cơ số từ 2 đến 16)
6.	Đưa phần tử bé nhất của của từng cột của ma trận B lên đường chéo phụ khi ma trận B là 1 ma trận vuông
7.	Tìm hạng của ma trận B
*/
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

void nhanmatrix(db a[][100], db b[][100], db c[][100], int m, int n, int g, int h){
    if (n==g){
        for (int i=0; i<m; i++){
            for (int j=0; j< h; j++){
                c[i][j]=0;
                for (int k=0; k<g; k++){
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    } else printf ("Khong the nhan 2 ma tran A va B\n");
}

void chuyenvi(db a[][100], int m, int h){
    for (int i=0; i<h; i++){
        for (int j=0; j<m; j++){
            printf ("%g ", a[j][i]);
        } printf ("\n");
    }
}

void swap(db *a, db *b){
    db tmp = *a;
    *a = *b;
    *b = tmp;
}

void doicoso(double a){
    int coso;
    int pre;
    printf ("Nhap co so:\n");
    scanf ("%d",&coso);
    if (coso<2 || coso>16) {
            printf("Co so duoc chon phai nam trong khoang [2;16]\n");
            return;
    }
    printf("So dau thap phan duoc lam tron sau dau '.':\n");
    scanf("%d",&pre);
    char s[]="0123456789ABCDF";
    int gt_am = 0;
    if (a<0){
        gt_am = 1;
        a = -a;
    }
    long long phannguyen = (long long) a;
    double thapphan = a - phannguyen ;
    // doiphannguyen
    int len=0;
    char nguyen[100];
    if (phannguyen==0){
        nguyen[len++] = '0';
    }
    else{
        while (phannguyen>0){
            int du = phannguyen % coso;
            nguyen[len++] = s[du];
            phannguyen /= coso;
        }
    }
    printf("Gia tri cua tong theo co so %d la: \n",coso);
    if (gt_am) printf("-");
    for (int i=len-1; i>=0; i--){
        printf ("%c",nguyen[i]);
    }
    if (pre>0){
        printf (".");
        // doiphanthapphan
        int tmp=0;
        for(int i=0; i<pre; i++){
            thapphan *= coso;
            tmp= (int) thapphan ;
            printf ("%c", s[tmp]);
            thapphan -= tmp;
        }
    }
    printf("\n");

}

void max(db a[][100], int m, int n){
    if (m==n){
        printf ("Ma tran A sau khi dua cac phan tu lon nhat ve duong cheo chinh:\n");
        db sum=0;
        for (int i=0; i<m; i++){
            db max = a[i][0];
            int max_vl=0;
            for (int j=1; j<m; j++){
                if (a[i][j]>max){
                    max = a[i][j];
                    max_vl=j;
                }
            } if (max_vl != i){
                swap (&a[i][max_vl], &a[i][i]);
            } sum += max;
        }
        xuat(a,m,n);
        printf ("Tong cac phan tu lon nhat tren duong cheo chinh la:\n%g\n", sum);
        doicoso(sum);
    } else printf ("Khong the lam duoc do khong phai ma tran vuong\n");
}

void min(db b[][100], int m, int n){
    if (m==n){
        printf ("Ma tran B sau khi chuyen cac phan tu be nhat len duong cheo phu:\n");
        for (int j=0; j<m; j++){
            int min_vl = 0;
            db min=b[0][j];
            for (int i=1; i<m; i++){
                if (b[i][j]<min){
                    min=b[j][i];
                    min_vl=i;
                }
            } if (min_vl != m-1-j){
                swap (&b[min_vl][j], &b[m-1-j][j]);
            }
        } xuat(b,m,n);
    } else printf ("Khong the lam duoc do B khong phai ma tran vuong\n");
}

int rank(db b[][100], int m, int n){
	int i,j,k,r,cnt=0;
	for (i=0;i<m;++i){
	    k=-1;
	    for (j=i;j<m;++j){
	        if (b[j][i]!=0){
	            k=j;
	            break;
	        }
	    }
	    if (k==-1) continue;
	    if (k!=i){
	        for (j=0;j<n;++j){
	            swap(&b[i][j],&b[k][j]);
	        }
	    }
	    for (r=i+1;r<m;++r){
	        db x=-b[r][i]/b[i][i];
	        int c;
	        for (c=0;c<n;++c){
	            b[r][c]+=x*b[i][c];
	        }
	    }
	}
	for (i=0;i<m;++i){
	    for (j=0;j<n;++j){
	        if (b[i][j]!=0){
	            ++cnt;
	            break;
	        }
	    }
	}
	return cnt;
}

int main(){
    int m, n, g, h;
    printf ("Nhap kich thuoc ma tran A:\n");
        scanf ("%d %d", &m, &n);
    printf ("Nhap ma tran A:");
        nhap(a,m,n);
    printf ("Nhap kich thuoc ma tran B:\n");
        scanf ("%d %d", &g, &h);
    printf ("Nhap ma tran B:");
        nhap(b,g,h);
    printf ("Ma tran A la:\n");
        xuat(a,m,n);
    printf ("Ma tran B la:\n");
        xuat(b,g,h);
        nhanmatrix(a,b,c,m,n,g,h);
    printf ("Ma tran tich A va B la:\n");
        xuat(c,m,h);
    printf ("Ma tran chuyen vi cua ma tran tich la:\n");
        chuyenvi(c,m,h);
        max(a,m,n);
        min(b,g,h);
    int r=rank(b,m,n);
    printf ("Ma tran B sau khi dua ve dang ma tran tam giac\n");
        xuat(b,g,h);
    printf ("Hang cua ma tran B la:\n%d", r);
}
