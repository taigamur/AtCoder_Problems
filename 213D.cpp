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

vector<int> ans;
vector<vector<int>> mp(200005);
vector<bool> visit(200005, false);

void dfs(int s){

    ans.push_back(s);
    visit[s] = true;

    rep(i,0,mp[s].size()){
        int t;
        t = mp[s][i];
        if(visit[t] == false){
            dfs(t);
            ans.push_back(s);
        }

    }
}

int main(){

    int N;
    cin >> N;

    
    rep(i,0,N-1){
        int A,B;
        cin >> A >> B;
        mp[A].push_back(B);
        mp[B].push_back(A);
    }

    rep(i,1,N+1){
        sort(mp[i].begin(), mp[i].end());
    }


    visit[1] = true;
    dfs(1);

    rep(i,0,ans.size()){
        cout << ans[i] << " ";
    }
    cout << endl;

}