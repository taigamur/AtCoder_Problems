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

struct UnionFind{
    vector<int> par,siz;

    //初期化
    UnionFind(int n) : par(n,-1),siz(n,1){}
    //根を求める
    int root(int x){
        if(par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }
    //x,yが同じグループかどうか
    bool issame(int x, int y){
        return root(x) == root(y);
    }
    //xを含むグループとyを含むグループを合併
    bool unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return false;
        //union by size (y側のサイズが小さくなるように)
        if(siz[x] < siz[y]) swap(x,y);
        //yをxの子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
    //xを含むグループのサイズ
    int size(int x){
        return siz[root(x)];
    }
};



int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    rep(i,0,N) cin >> A[i];

    UnionFind uf(200005);

    rep(i,0, N/2){
        int j = N - i - 1;
        if(A[i] != A[j]){
            uf.unite(A[i],A[j]);
        }
    }

    ll ans = 0;
    rep(i,0,200005){
        if(uf.root(i) == i ) ans += uf.size(i) - 1;
    }

    cout << ans << endl;

}