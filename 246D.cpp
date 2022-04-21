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


long long ans = 1000000000000000000;

ll N;

ll calc(ll a,ll b){
    return pow(a,3) + pow(a,2)*b + a*pow(b,2) + pow(b,3);
}

void f(ll a, ll b){

    ll sum;
    sum = calc(a,b-1);
    if(sum < ans && sum > N){
        ans = sum;
        f(a,b-1);
    }

    sum = calc(a+1,b-1);
    if(sum < ans && sum > N){
        ans = sum;
        f(a+1,b-1);
    }

    sum = calc(a-1,b-1);
    if(sum < ans && sum > N){
        ans = sum;
        f(a-1,b-1);
    }
}

int main(){
    cin >> N;

    ll key = 0;
    while(pow(key,3)*4 < N){
        key++;
    }

    f(key,key);

    cout << ans << endl;



}
