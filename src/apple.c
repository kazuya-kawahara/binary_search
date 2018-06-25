
#include <stdio.h>

int n;
int k;
int A[100000];
//(プルリク後修正)iをpとmainそれぞれの局所変数へ移動、pとmainでiに共通の意味はなく大域変数にする意味もない

int p(int m){
    int s, i;
    s = 0;
    for(i = 0; i < n; i++){
        s = s + (A[i]+m-1)/m;  //ここのforで(A[i]/m)(切り上げ)の総和を計算
    }
    return s <= k;  //必要なm個入りのりんごバッグの個数がkを超えないかチェック
}

int main(){
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    lb = 0; //(プルリク後修正)ubとして1を呼び出す場合があるのでlb=1は不適切
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
