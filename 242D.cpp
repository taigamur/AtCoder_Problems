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


string S;

char g(char s, ll add){
    int t = ((s - 'A') + add) % 3;
    return 'A' + t;
}

char f (ll t, ll k){
    if(t == 0) return S[k];
    if(k == 0) return g(S[0],t);
    return  g(f(t-1, k/2), k%2+1);
}

int main(){
    cin >> S;
    ll q;
    cin >> q;

    rep(i,0,q){
        ll t,k;
        cin >> t >> k;
        k--;
        ll sum = 0;
        ll tmp;

        cout << f(t, k) << endl;
    }

}