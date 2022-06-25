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

    vector<vector<int>> list(205);

    vi A(N);
    rep(i,0,N){
        int a;
        cin >> a;
        a = a % 200;
        A[i] = a;
        list[a].push_back(i);
    }

    ll ans = 0;
    rep(i,0,N){
        int t = lower_bound(list[A[i]].begin(), list[A[i]].end(), i ) - list[A[i]].begin();
        ans += list[A[i]].size() - t - 1;
    }
    cout << ans << endl;


}