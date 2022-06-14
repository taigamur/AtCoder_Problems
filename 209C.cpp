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

    int N;
    cin >> N;

    vll C(N);
    rep(i,0,N) cin >> C[i];

    sort(C.begin(),C.end());

    ll ans = 1;

    rep(i,0,N){
        if(C[i]-i <= 0){
            cout << 0 << endl;
            return 0;
        }
        ans = (ans * (C[i] - i)) % 1000000007;
    }

    cout << ans << endl;

}