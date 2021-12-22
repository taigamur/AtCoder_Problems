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

//累積和を使う問題

int main(){

    string s;
    cin >> s;
    ll k;
    cin >> k;

    ll n = s.size();

    vector<ll> cnt(n+1); // 累積和
    rep(i,0,n){
        if(s[i] == '.'){
            cnt[i+1] = cnt[i] + 1;
        }else{
            cnt[i+1] = cnt[i];
        }
    }

    ll ans = 0;
    ll r = 0;
    rep(i,0,n){
        while(r < n && cnt[r+1] - cnt[i] <= k){
            r++;
        }
        ans = max(ans,r-i);
    }
    cout << ans << endl;

}