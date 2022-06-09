
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
    ll N,a,b;
    cin >> N >> a >> b;
    ll p,q,r,s;
    cin >> p >> q >> r >> s;

    vector<vector<ll>> list(q - p + 1, vector<ll>( s - r + 1 ,0));

    ll x,y;
    x = max(p - a, r - b);
    y = min(q - a, s - b);

    for(ll i = x; i <= y; i++) list[a + i - p][b + i - r] = 1;

    x = max(p - a, b - s);
    y = min(q - a, b - r);
    for(ll i = x; i <= y; i++) list[a + i - p][b - i - r] = 1;

    for(ll i = 0; i < (q - p + 1); i++){
        for(ll j = 0; j < (s - r + 1 ); j++){

            if(list[i][j] == 1){
                cout << '#';
            }else{
                cout << '.';
            }
        }
        cout << endl;
    }


    return 0;
}