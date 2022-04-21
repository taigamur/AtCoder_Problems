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
    vector<vector<int>> list(n+1);

    rep(i,1,n+1){
        int t;
        cin >> t;
        list[t].push_back(i);
    }

    int q;
    cin >> q;
    rep(i,0,q){
        int l,r,x;
        cin >> l >> r >> x;
        int l2 = lower_bound(list[x].begin(), list[x].end(), l) - list[x].begin();
        int r2 = lower_bound(list[x].begin(), list[x].end(), r+1) - list[x].begin();
        cout << r2 - l2 << endl;
    }
}