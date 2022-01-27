#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;
int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)


int main(){
    int H,W;
    cin >> H >> W;

    vector<vector<char>> map(H,vector<char>(W));
    vector<vector<int>> ans(H+1,vector<int>(W+1,0));
    rep(i,0,H){
        rep(j,0,W){
            cin >> map[i][j]; 
        }
    }

    
    for(int i = H-1; i >= 0; i--){
        for(int j = W-1; j >= 0; j--){
            if(map[i][j] == '.'){
                ans[i][j] = max(ans[i+1][j],ans[i][j+1]) + 1;
            }
            
        }
    }
    cout << ans[0][0] << endl;

}