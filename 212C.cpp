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

    vll A(N);
    vll B(M);

    rep(i,0,N) cin >> A[i];
    rep(i,0,M) cin >> B[i];

    ll ans = INF;

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    rep(i,0,N){
        auto t = lower_bound(B.begin(),B.end(),A[i]);
        if(t == B.end()){
            t--;
            ans = min(ans, abs(A[i]-*t));
        }else if(t == B.begin()){
            ans = min(ans, abs(A[i]-*t));
        }else{
            ans = min(ans, abs(A[i]-*t));
            t--;
            ans = min(ans, abs(A[i]-*t));
        }
    }

    cout << ans << endl;

}