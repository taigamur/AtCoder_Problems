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

ll N,key;
vector<vector<ll>> list;

ll ans = 0;
void dfs(ll pos, ll calc){
    if(pos == N){
        if(calc == key){
            ans++;
        }
        return;
    }

    for(ll a : list[pos]){
        if(calc*a <= key){
            dfs(pos+1, calc*a);
        }
    }


}


int main(){
    cin >> N >> key;
    list.resize(N);

    rep(i,0,N){
        ll L;
        cin >> L;
        list[i].resize(L);

        rep(j,0,L){
            cin >> list[i][j];
        }
    }

    dfs(0,1);

    cout << ans << endl;


    



}