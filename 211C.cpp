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

class Edge{
    public: 
    int t, w;
    Edge();
    Edge(int t, int w): t(t), w(w){};
};
// vector<Edge> G[MAX];



int main(){
    string S;
    cin >> S;

    S = "*" + S;

    vector<vector<int>> dp(S.size()+2,vector<int>(10,0));

    string T = "*chokudai";
    ll U = 1000000007;
    
    rep(j,1,9){
        rep(i,1,S.size()+1){
            if(j == 1){
                if(S[i] == T[j]) dp[i][j] = dp[i-1][j] + 1;
                else dp[i][j] = dp[i-1][j];
            }else{
                if(S[i] == T[j]) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % U ;
                else dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[S.size()][8] << endl;

    // rep(j,1,9){
    //     rep(i,1,S.size()+1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    

}