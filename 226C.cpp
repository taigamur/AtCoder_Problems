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

    ll ans = 0;
    int n,x;
    cin >> n;

    vector<bool> used(n,false);

    ll t[n];
    int k[n];
    vector<int> e[n];

    rep(i,0,n){
        cin >> t[i];
        cin >> k[i];
        rep(j,0,k[i]){
            cin >> x;
            e[i].push_back(x-1);
        }
    }

    used[n-1] = true;
    for(int i = n-1; i >= 0; i--){
        if(used[i]){
            ans += t[i];
            rep(j,0,k[i]){
                used[e[i][j]] = true;
            }
        }
    }
    cout << ans << endl;

}