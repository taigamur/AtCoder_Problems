#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <math.h>
#include <iomanip>
#include <limits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
static const int MAX = 100005;
#define SIZE 10005

struct Node{
    int right, left, parent;
};
// struct Node node[SIZE];



int main(){
    ll A,B,K;
    cin >> A >> B >> K;
    
    vector<vector<ll>> dp(A+1,vector<ll>(B+1,0)); //dp[i][j] : Aがi個, Bがj個のときの文字列の総数
    
    dp[0][0] = 1;
    // 先にコストのテーブルを作成する
    for(int i = 0; i <= A; i++){
        for(int j = 0; j <= B; j++){
            if(i > 0) dp[i][j] += dp[i-1][j];
            if(j > 0) dp[i][j] += dp[i][j-1];
        }
    }

    vi ans; // a = 0, b = 1;
    ll M = A + B;
    for(int i = 0; i < M; i++){
        if(A == 0){
            ans.push_back(1);
        }else if(B == 0){
            ans.push_back(0);
        }else{
            if( K <= dp[A-1][B] ){
                ans.push_back(0);
                A--;
            }else{
                ans.push_back(1);
                K -= dp[A-1][B];
                B--;
            }
        }
    }

    rep(i,0,M){
        if(ans[i] == 0) cout << "a";
        else cout << "b";
    }
    cout << endl;

}