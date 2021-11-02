#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

// 1102 難しい

int main(){

    //筒の色はvector<queue>, 一番上の色はvector<vector> で管理する

    int N,M;
    cin >> N >> M;

    vector<queue<int>> list(M);
    vector<vector<int>> color(N); // N種類
    
    rep(i,0,M){
        int k;
        cin >> k;
        rep(j,0,k){
            int l;
            cin >> l;
            list[i].push(l-1);
        }
        color[list[i].front()].push_back(i);
    }

    queue<int> que; // 排出された色のポール番号
    rep(i,0,N){
        if(color[i].size() == 2){
            que.push(i);
        }
    }

    while(!que.empty()){
        int t = que.front();
        que.pop();

        for(auto p : color[t]){
            list[p].pop();
            if(!list[p].empty()){
                color[list[p].front()].push_back(p);
                if(color[list[p].front()].size() == 2){
                    que.push(list[p].front());
                }
            }
        }
    }

    rep(i,0,M){
        if(list[i].size() != 0){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

}