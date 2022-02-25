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
static const int MAX = 100005;
#define SIZE 10005
struct Node{
    int right, left, parent;
};
struct Node node[SIZE];

vector<vector<int>> G(MAX, vector<int>());
vector<int> value(MAX);
vector<int> used(MAX); 
int N;
vector<vector<int>> list(MAX, vector<int>());

void dfs(int u){
    used[u] = 1;

    for(auto v : G[u]){
        if(used[v] == 0){
            dfs(v);
        }
    }

    if(G[u].size() == 0){
        list[u].push_back(value[u]);
    }else{
        vector<int> tmp;
        tmp.push_back(value[u]);
        for(auto v : G[u]){
            if(used[v] == 1){
                rep(i,0,list[v].size()){
                    tmp.push_back(list[v][i]);
                }
            }

        }
        sort(tmp.begin(),tmp.end(), greater<int>());
        int M;
        if(tmp.size() < 20) M = tmp.size();
        else M = 20;

        rep(i,0,M){
            list[u].push_back(tmp[i]);
        }
    }   
    return;
}

void dfs_init(){
    rep(i,0,N+1){
        used[i] = 0;
    }
    return;
}


int main(){
    int Q;
    cin >> N >> Q;
    rep(i,1,N+1) cin >> value[i];
    int a,b;
    rep(i,0,N-1){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs_init();
    dfs(1);

    rep(i,0,Q){
        int v,k;
        cin >> v >> k;
        cout << list[v][k-1] << endl;
    }

}