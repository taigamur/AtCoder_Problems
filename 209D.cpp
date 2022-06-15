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



int main(){
    int N,Q;
    cin >> N >> Q;

    vector<vector<int>> G(N+1);
    rep(i,0,N-1){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<int> q;
    q.push(1);

    vector<bool> visit(N+1,false);
    visit[1] = true;

    vector<int> dist(N+1);
    dist[1] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int next_v : G[v]){
            if(visit[next_v]) continue;
            q.push(next_v);
            visit[next_v] = true;
            dist[next_v] = dist[v] + 1;
        }
    }

    rep(i,0,Q){
        int c,d;
        cin >> c >> d;
        if(dist[c] % 2 == dist[d] % 2){
            cout << "Town" << endl;
        }else{
            cout << "Road" << endl;
        }
    }

}