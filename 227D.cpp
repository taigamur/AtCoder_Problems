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
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i,0,n) cin >> v[i];
    ll right = INF/k;
    ll left = 0;
    ll ans = 0;
    while(right - left > 1){
        ll mid = left + (right - left) / 2;
        ll sum = 0;
        rep(i,0,n) sum += min(v[i],mid);
        if(sum >= k*mid) left = mid; //kをinfにしているだけだと溢れる
        else right = mid;
    }
    cout << left << endl;
}