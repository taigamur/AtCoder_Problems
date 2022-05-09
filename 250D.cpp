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
static const int MAX = 1000005;
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

vector<long long> plist;
ll N;


bool IsPrime(ll n){
    if(n < 2) return false;
    else if(n == 2) return true;
    else if(n % 2 == 0) return false;

    for(int i = 3; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

ll get_q(ll p){
    ll ng = -1;
    ll ok = plist.size();
    while(ok - ng > 1){
        ll mid = (ng + ok) / 2;
        ll q = plist[mid];
        if(q * q * q <= N / p){
            ng = mid;
        }else{
            ok = mid;
        }
    }
    return ng;
}


int main(){
    cin >> N;

    rep(i,0,MAX){
        if(IsPrime(i)) plist.push_back(i);
    }

    ll p,q;
    ll q_i;
    ll ans = 0;
    rep(i,0,plist.size()){
        p = plist[i];
        q_i = get_q(p);

        if(i < q_i) ans += q_i - i;
    }

    cout << ans << endl;



}