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
int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

#define SIZE 10005
struct Node{
    int right, left, parent;
};
struct Node node[SIZE];

vector<int> G[200005];
int L[200005], R[200005];
int leaf[200005];

int id = 0;

void dfs(int v, int p){ //p: parent
    if(v != 1 && G[v].size() == 1){
        leaf[v] = ++id;
        return;
    }
    for(auto u : G[v]){
        if(u != p) dfs(u,v);
    }
}

void dfs2(int v, int p){
    if(leaf[v]){
        L[v] = R[v] = leaf[v];
        return;
    }
    L[v] = inf;
    R[v] = -inf;
    for(auto u : G[v]){
        if(u == p) continue;
        dfs2(u,v);
        L[v] = min(L[v], L[u]);
        R[v] = max(R[v], R[u]);
    }
}

int main(){
    int n;
    cin >> n;
    int u,v;
    rep(i,0,n-1){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    

    dfs(1, -1);
    dfs2(1,-1);

    for(int i = 1; i <= n; i++) cout << L[i] << " " << R[i] << endl;

}