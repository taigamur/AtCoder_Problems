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
    int n;
    cin >> n;

    int N = 200005;

    vll a_sum(N,0);
    vll a(n);
    rep(i,0,n){
        int t;
        cin >> t;
        a_sum[t]++;
        a[i] = t;
    }

    vll list(N,0);
    rep(i,1,N){
        list[i] = list[i-1] + a_sum[i];
    }

    ll ans = 0;
    rep(i,0,n){
        ans += list[a[i]-1] * (n - list[a[i]]);
    }

    cout << ans << endl;



}