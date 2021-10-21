#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;
int inf = numeric_limits<int>::max()-1;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

/*
dp[i][j][k]: 状態ijkに到達するまでの最小値
*/

int main(){
    int N;
    cin >> N;
    int X,Y;
    cin >> X >> Y;
    vector<int> A(301);
    vector<int> B(301);
    vector<vector<vector<int>>> dp(301,vector<vector<int>>(301,vector<int>(301)));
    
    rep(i,1,N+1){
        cin >> A[i] >> B[i];
    }



    rep(i,0,N+1){
        rep(x,0,301){
            rep(y,0,301){
                dp[i][x][y] = inf;
            }
        }
    }
    dp[0][0][0] = 0;

    rep(i,0,N+1) dp[i][0][0] = 0;

    rep(i,1,N+1){
        rep(x,0,X+1){
            rep(y,0,Y+1){
                dp[i][min(x+A[i],X)][min(y+B[i],Y)] = 
                    min(dp[i][min(x+A[i],X)][min(y+B[i],Y)],dp[i-1][x][y]+1);

                dp[i][x][y] = min(dp[i][x][y],dp[i-1][x][y]);
                
            }
        }
    }

    int ans = dp[N][X][Y];

    if(ans < inf){
        cout << ans << endl;;
    }else{
        cout << "-1" << endl;
    }

}