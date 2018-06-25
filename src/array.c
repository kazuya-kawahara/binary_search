#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = -1 ;　　//(プルリク後修正)ubとして0を呼び出す場合があるのでlb=0は不適切
  ub = n ;
  while( ub-lb > 1 ) {
      int m = ( lb + ub ) / 2 ;
      if (A[m]>=k) {  //pは省略、ここで条件を記した
          ub = m ;
      }
      else {
          lb = m ;
      }
  }
    printf( "%d\n" , ub ) ;
  return 0;
}
