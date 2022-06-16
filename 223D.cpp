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
typedef vector<int> vi;
typedef vector<long long> vll;


typedef long long ll;
int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

// 0120 トポロジカルソート　わからなかった。

vector<vector<int>> G(200005);
vi indegree(200005);

int V,E;

vi ans;

void topological_sort(){
    priority_queue<int, vector<int>, greater<int>> que;

    for(int i = 1; i <= V; i++){
        if(indegree[i] == 0) que.push(i);
    }

    while(!que.empty()){
        int v = que.top();
        que.pop();

        for(int i = 0; i < G[v].size(); i++){
            int u =  G[v][i];
            indegree[u] -= 1;
            if(indegree[u] == 0) que.push(u);
        }
        ans.push_back(v);
    }
}

int main(){

    cin >> V >> E;

    rep(i,0,E){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        indegree[b] += 1;
    }

    topological_sort();

    if(ans.size() != V){
        cout << -1 << endl;
    }else{
        rep(i,0,V) cout << ans[i] << " ";
        cout << endl;
    }
}