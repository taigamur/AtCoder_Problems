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

class Edge{
    public: 
    int t, w;
    Edge();
    Edge(int t, int w): t(t), w(w){};
};
// vector<Edge> G[MAX];

int N,M;

vector<vector<int>> G(200005);


ll dis = 0;
ll ans = 0;
ll T = 1000000007;

int main(){

    
    cin >> N >> M;

    
    rep(i,0,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<ll> cnt(N+1, 0);
    vector<ll> dist(N+1, INF);
    vector<bool> visit(N+1,false);

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    cnt[1] = 1;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        
        for(int next_v : G[v]){
            if(visit[next_v] == false){
                q.push(next_v);
                visit[next_v] = true;
                cnt[next_v] = cnt[v];
                dist[next_v] = dist[v] + 1;
            }else{
                if(dist[next_v] == dist[v] + 1){
                    cnt[next_v] += cnt[v];
                    cnt[next_v] %= T;
                }
            }
        }
    }

    cout << cnt[N] % T << endl;
}