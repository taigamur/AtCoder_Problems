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

// 順列の全探索　難しかった

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> x(n,vector<int>(n,0));
    vector<vector<int>> y(n,vector<int>(n,0));

    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        x[a][b] = x[b][a] = 1;
    }

    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        y[a][b] = y[b][a] = 1;
    }

    vector<int> p(n);
    rep(i,0,n) p[i] = i;

    do{
        bool ans = true;
        rep(i,0,n){
            rep(j,0,n){
                if(x[i][j] != y[p[i]][p[j]]){
                    ans = false;
                }
            }
        }
        if(ans){
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(p.begin(),p.end()));

    cout << "No" << endl;
}