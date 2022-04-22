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

ll calc(ll a, ll  b){
    return a * a * a + a * a * b + a * b * b + b * b * b;
}

int main(){
    ll N;
    cin >> N;

    ll ans = INF;
    for(ll a = 0; a <= 1000000; a++){
        ll left = -1;
        ll right = 1000000;
        while(left + 1 != right){
            ll mid  = (left + right) / 2;
            if(N <= calc(a,mid)) right = mid;
            else left = mid;
        }
        ans = min(ans, calc(a,right));
    }
    cout << ans << endl;

}