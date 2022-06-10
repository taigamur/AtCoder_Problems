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
    int H,W,N;
    cin >> H >> W >> N;

    vector<pair<int,int>> Y;
    vector<pair<int,int>> X;



    rep(i,0,N){
        int A,B;
        cin >> A >> B;

        pair<int,int> a;
        pair<int,int> b;

        a.first = A;
        a.second = i+1;

        b.first = B;
        b.second = i+1;

        Y.push_back(a);
        X.push_back(b);
    }

    sort(Y.begin(), Y.end());
    sort(X.begin(), X.end());

    vector<pair<int,int>> ans(N+1);

    int a = Y[0].first;
    ans[Y[0].second].first = 1;
    int y = 1;
    rep(i,1,N){
        if(Y[i].first == a){
            ans[Y[i].second].first = y;
        }else{
            y++;
            ans[Y[i].second].first = y;
            a = Y[i].first;
        }
    }


    int b = X[0].first;
    ans[X[0].second].second = 1;
    int x = 1;
    rep(i,1,N){
        if(X[i].first == b){
            ans[X[i].second].second = x;
        }else{
            x++;
            ans[X[i].second].second = x;
            b = X[i].first;
        }
    }

    rep(i,1,N+1){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

}