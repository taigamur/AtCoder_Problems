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

    ll N,K;
    cin >> N >> K;
    vector<pair<ll,ll>> A(N);
    pair<ll,ll> p;
    rep(i,0,N){
        cin >> p.first >> p.second;
        A[i] = p;
    }
    sort(A.begin(), A.end());

    ll prev = 0;
    ll now = 0;
    rep(i,0,N){
        if(K + prev < A[i].first ){
                if(prev + K < pow(10,100)) cout << prev + K << endl;
                else cout << pow(10,100) - 1 << endl;
            return 0;
        }
        K += A[i].second - (A[i].first - prev );
        prev = A[i].first;
    }
    if(prev + K < pow(10,100)) cout << prev + K << endl;
    else cout << pow(10,100) - 1 << endl;


}