#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
    int i, j, sum;
    i = 0;
    j = 0;
    while((A[i] <= m)&&(i < n)){
        sum = 0;
        while((sum + A[i] <= m)&&(i < n)){
            sum = sum + A[i];
            i = i + 1;
        }　　//ここのwhileで仕事量の和がmを超えないように順にグループ分けする
        j = j + 1;　　//グループの数をカウントする
    }
    if(A[i] > m){
        j = k + 1;
    }
    return j <= k;　　//グループの数が人数を超えていないかチェック
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
    
  lb = n/k;
  ub = 1000000000;
  while(ub-lb > 1){
      int m = (ub + lb) / 2;
      if(p(m)){
          ub = m;
      }
      else {
          lb = m;
      }
  }
  printf("%d\n", ub);

  return 0;
}
