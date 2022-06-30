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
    int N,M;
    cin >> N >> M;
    vector<vector<int>> G(N+1);
    rep(i,0,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int Q;
    cin >> Q;

    vi dist(N+1,0);
    vi used(N+1,0);
    
    rep(i,0,Q){
        int x,k;
        cin >> x >> k;

        queue<int> q;
        q.push(x);
    
        used[x] = 1;
        vi ans;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            ans.push_back(v);
            if(dist[v] == k) continue;
            for(auto next_v : G[v]){
                if(used[next_v]) continue;
                if(dist[v] + 1 <= k ){
                    q.push(next_v);
                    used[next_v] = 1;
                    dist[next_v] = dist[v] + 1;
                }
            }
        }
        ll sum = 0;
        rep(j,0,ans.size()){
            used[ans[j]] = 0;
            dist[ans[j]] = 0;
            sum += ans[j];
        }
        cout << sum << endl;

    }
}