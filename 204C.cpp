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
        int A,B;
        cin >> A >> B;
        G[A].push_back(B);
    }
 
    ll ans = 0;
 
    rep(i,1,N+1){
        vector<bool> used(N+1, false);
        queue<int> q;
        q.push(i);
        used[i] = true;
 
        ll sum = 1;
        while(!q.empty()){
            int v = q.front();
            q.pop();
 
            for(int next_v : G[v]){
                if(used[next_v]) continue;
                q.push(next_v);
                used[next_v] = true;
                sum++;
            }
        }
        ans += sum;
    }
 
    cout << ans << endl;
 
}