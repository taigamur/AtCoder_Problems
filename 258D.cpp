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

int main(){
    ll N,X;
    cin >> N >> X;

    vector<pair<ll,ll>> P;
    rep(i,0,N){
        pair<ll,ll> p;
        cin >> p.first >> p.second;
        P.push_back(p);
    }

    ll ans = INF;
    ll sum = 0;
    rep(i,0,N){
        sum += P[i].first + P[i].second;
        ll t = sum;
        if(X - (i + 1) > 0){
            t += P[i].second * (X - (i + 1) );
        }
        
        if(t < ans) ans = t;
    }

    cout << ans << endl;


}