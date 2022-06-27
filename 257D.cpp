#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <math.h>
#include <iomanip>
#include <limits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
static const int MAX = 100005;
#define SIZE 10005

struct Node{
    int right, left, parent;
};
// struct Node node[SIZE];

int main(){
    ll N;
    cin >> N;
    pair<ll,ll> p;
    vector<pair<ll,ll>> map(N);
    vector<ll> P(N);
    rep(i,0,N){
        cin >> p.first >> p.second;
        map[i] = p;
        ll t;
        cin >> t;
        P[i] = t;
    }

    ll ng = 0;
    ll ok = 4000000005;

    while(ok - ng > 1){
        ll mid = (ng + ok) / 2;
        bool tf = false;
        rep(k,0,N){
            vector<vector<ll>> G(N);
            rep(i,0,N){
                rep(j,0,N){
                    if(i == j) continue;
                    if( (ll) P[i]*mid >= abs(map[i].first - map[j].first) + abs(map[i].second - map[j].second)){
                        G[i].push_back(j);
                    }
                }
            }
            vector<bool> visit(N,false);
            visit[k] = true;
            queue<ll> q;
            q.push(k);
            while(!q.empty()){
                ll v = q.front();
                q.pop();
                for(ll next_v : G[v]){
                    if(visit[next_v]) continue;
                    q.push(next_v);
                    visit[next_v] = true;
                }
            }
            ll sum = 0;
            rep(i,0,N){
                if(visit[i]) sum++;
            }
            if(sum == N) tf = true;
        }
        if(tf) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;

}