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

struct edge{
    int to, index;
    ll cost;
};
// struct Node node[SIZE];

int main(){
    
    int N,M;
    cin >> N >> M;

    int A,B;
    ll C;
    vector<vector<edge>> G(N+1);
    rep(i,1,M+1){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        edge e;
        e.to = b;
        e.cost = c;
        e.index = i;
        G[a].push_back(e);
        e.to = a;
        G[b].push_back(e);
    }

    priority_queue<double, vector<double>. greater<double>> q;
    q.push(0);

    vi ans;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(edge e : G[v]){
            if(visit[e.to]) continue;
            q.push(e.to);
        }
    }


    
}