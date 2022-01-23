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
    ll N;
    ll K;
    cin >> N >> K;

    vector<ll> a(N);
    vector<ll> s(N+1);

    rep(i,0,N){
        cin >> a[i];
    }

    rep(i,0,N){
        s[i+1] = s[i] + a[i];
    }

    map<ll,ll> mp;
    ll ans = 0;
    rep(i,1,N+1){
        mp[s[i-1]]++;
        ans += mp[s[i]-K];
    }

    cout << ans << endl;
}