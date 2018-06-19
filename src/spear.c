#include <stdio.h>

int n;
int k;
int A[100000];
int i;

int p(int m){
    int s;
    s = 0;
    for(i = 0; i < n; i++){
        s = s + A[i]/m;
    }
    return s >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  
  lb = 0;
  ub = 1000000000/(k/n);
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
