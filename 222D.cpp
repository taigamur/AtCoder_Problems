#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;
int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)


int main(){
    int N;
    cin >> N;

    vector<int> A(N),B(N);
    rep(i,0,N) cin >> A[i];
    rep(i,0,N) cin >> B[i];

    int MAX = 3000;

    vector<vector<int>> dp(N+1,vector<int>(3001,0));
    dp[0][0] = 1;
    rep(i,0,N+1){
        //累積和に変更している
        rep(j,0,MAX){
            dp[i][j+1] += dp[i][j];
            dp[i][j+1] = dp[i][j+1] % 998244353;
        }
        if(i!=N){
            // A,Bの範囲内のみ入れていく
            for(int j = A[i]; j <=B[i]; j++){
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] = dp[i+1][j] % 998244353;
            }
        }
    }

    cout << dp[N][MAX] << endl;



}