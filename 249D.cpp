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
static const int MAX = 200005;

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

    vector<int> A(MAX,0);
    int M = 0;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        A[t]++;
        M = max(M,t);
    }

    ll ans = 0;
    for(int i = 1; i <= M; i++){
        for(int j = 1; i*j <= M; j++){
            ans += (long long) A[i] * A[j] * A[i*j];
        }
    }
    cout << ans << endl;

}