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

ll ans = 0;
int N;
vector<vector<ll>> point(20,vector<ll>(20,0));

void dfs(vector<pair<ll,ll>> pairs, vector<bool> list ){

    if(pairs.size() == N){
        ll sum = 0;
        for(int i = 0; i < N; i++){
            sum = sum ^ point[pairs[i].first][pairs[i].second];
        }

        ans = max(ans, sum);

    }else{

        ll x = 0;
        for(int i = 1; i <= 2*N; i++){
            if(list[i] == false){
                x = i;
                list[i] = true;
                break;
            }
        }

        for(int i = 1; i <= 2*N; i++){
            if(list[i] == false){

                list[i] = true;
                pair<ll, ll> p;
                p.first = x;
                p.second = i;
                pairs.push_back(p);
                dfs(pairs, list);

                pairs.pop_back();
                list[i] = false;

            }
        }

        return;

    }
    

}

int main(){

    cin >> N;

    rep(i,1,2*N){
        rep(j,i+1,2*N+1){
            cin >> point[i][j];
        }
    }

    vector<bool> list(20, false);
    vector<pair<ll,ll>> pairs;
    
    dfs(pairs, list);
    cout << ans << endl;

}