#include <stdio.h>

int n;
int k;
int A[100000];
int i;

int p(int m){
    int s;
    s = 0;
    for(i = 0; i < n; i++){
        s = s + A[i]/m;  //ここのforで(A[i]/m)(切り捨て)の総和を計算
    }
    return s >= k;  //できた長さmの槍の本数がkを超えたかチェック
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  
  lb = 0;  //pの定義内に除算が含まれるが、lb=0は呼び出されず0除算は実際には実行されないのでおk
  ub = 1000000000/(k+(n-1)/n)+1;  //(プルリク後更に修正)(t-1)n<k<=tnの時長さ10^9/t(切り捨て)の槍が作れる
  while(ub-lb > 1){
      int m = (ub + lb) / 2;
      if(p(m)){
          lb = m;
      }
      else {
          ub = m;
      }
  }
  printf("%d\n", lb);


  return 0;
}
