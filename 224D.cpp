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

// 幅優先探索　map

// 0115 難しかった


int main(){

    map<vector<ll>,ll> mp;
    vector<ll> G[10];
    queue<vector<ll>> Q;

    ll M;
    cin >> M;
    rep(i,0,M){
        ll u,v;
        cin >> u >> v;
        --u;
        --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<ll> start(9);
    bool used[9]{};
    rep(i,0,8){
        ll s;
        cin >> s;
        --s;
        start[s] = i;
        used[s] = true;
    }

    ll blank = -1;
    rep(i,0,9){
        if(used[i] == false) blank = i;
    }
    start[blank] = 8;

    Q.push(start);
    mp[start] = 0;

    vector<ll> goal(9);
    rep(i,0,9) goal[i] = i;

    ll turn = -1;
    while(!Q.empty()){
        ll siz = Q.size();
        ++turn;

        rep(i,0,siz){
            auto V = Q.front();
            Q.pop();

            // 終了条件
            if(V == goal){
                cout << turn << endl;
                return 0;
            }

            ll blank;
            rep(i,0,9){
                if(V[i] == 8) blank = i;
            }

            for(auto u : G[blank]){
                swap(V[blank],V[u]);
                if(mp.count(V) == false){
                    mp[V] = turn + 1;
                    Q.push(V);
                }
                swap(V[blank],V[u]); //復元
            }
        }
    }
    cout << -1 << endl;

}