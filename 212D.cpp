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
    ll Q;
    cin >> Q;

    multiset<ll> st;

    ll sum = 0;
    rep(i,0,Q){
        int P;
        ll X;
        cin >> P;

        if(P == 1){
            cin >> X;
            st.insert(X-sum);
        }else if(P == 2){
            cin >> X;
            sum += X;
        }else{
            ll ans = *st.begin();
            st.erase(st.begin());
            cout << ans + sum << endl;
        }
    }

}