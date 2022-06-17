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

    int N,M;
    cin >> N >> M;
    
    vector<vector<int>> d(N+1, vector<int>(N+1,inf/2));

    rep(i,0,M){
        int from, to, cost;
        cin >> from >> to >> cost;
        d[from][to] = cost;
    }

    ll ans = 0;
    
    for(int k = 1; k <= N; k++){ //経由する頂点

        for(int i = 1; i <= N; i++){ //始点
            for(int j = 1; j <= N; j++){ //終点
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);               
            }
        }
        // kまで経由できる時の重みの計算
        rep(i,1,N+1){
            rep(j,1,N+1){
                if( i != j && d[i][j] < inf/2) ans += d[i][j];
            }
        }

    }

    cout << ans << endl;
}

