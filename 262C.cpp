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

    vi a(N);
    rep(i,0,N) cin >> a[i];

    ll ans = 0;
    ll same = 0;
    rep(i,0,N){
        if(a[i] == i+1){
            same++;
        }else if(a[a[i]-1] == i+1 && a[i] > i + 1){
            ans++;
        }
    }

    if(same > 1){
        ll sum = 0;
        same--;
        for(;same > 0; same--){
            sum += same;
        }
        ans += sum;
    }

    cout << ans << endl;
}