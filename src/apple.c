
#include <stdio.h>

int n;
int k;
int A[100000];
int i;

int p(int m){
    int s;
    s = 0;
    for(i = 0; i < n; i++){
        s = s + (A[i]+m-1)/m;  //ここのforで(A[i]/m)(切り上げ)の総和を計算
    }
    return s <= k;  //必要なm個入りのりんごバッグの個数がkを超えないかチェック
}

int main(){
    int lb, ub;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    lb = 1;
    ub = (1000000000+(k/n)-1)/(k/n);  //全員が10^9個(最大個数)のりんごを持っていても一人当たり少なくとも(k/n)(切り捨て)個のりんごバッグが配られる、かつりんごの余りを出さないためにも切り上げ処理が必要(例えばk=3n,7nなど)である
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
