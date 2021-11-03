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

// 1103 AC

int main(){
    int N;
    cin >> N;

    vector<ll> S(N);

    vector<ll> ans(N);

    rep(i,0,N){
        cin >> S[i];
    }
    rep(i,0,N){
        cin >> ans[i];
    }

    rep(i,1,N){
        ans[i] = min(ans[i-1]+S[i-1],ans[i]);
    }
    ans[0] = min(ans[N-1]+S[N-1],ans[0]);

    rep(i,1,N){
        ans[i] = min(ans[i-1]+S[i-1],ans[i]);
    }


    rep(i,0,N){
        cout << ans[i] << endl;
    }
}