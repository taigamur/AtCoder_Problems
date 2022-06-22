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

    int N;
    cin >> N;

    vi A(N);
    rep(i,0,N) cin >> A[i];
    vi B(N);
    rep(i,0,N) cin >> B[i];
    vi C(N);
    rep(i,0,N) cin >> C[i];

    vi D(100005,0);
    rep(i,0,N){
        D[B[C[i]-1]]++;
    }

    ll ans = 0;
    rep(i,0,N){
        ans += D[A[i]];
    }

    cout << ans << endl;

}