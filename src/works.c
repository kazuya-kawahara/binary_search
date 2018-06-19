#include <stdio.h>

int n;
int k;
int A[100000];
int i;

int p(int m){
    int j;
    int sum;
    i = 1;
    j = 0;
    while(i < n){
        sum = 0;
        i = i - 1;
        while(sum <= m){
            while(A[i] > 0){
                sum = sum + A[i];
                i = i + 1;
            }
        }
        j = j + 1;
    }
    return j <= k;
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
