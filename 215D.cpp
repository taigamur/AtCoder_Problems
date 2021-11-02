#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

// 1102 解けていない

int main(){

    int N,M;
    cin >> N >> M;
    set<int> list;
    rep(i,0,N){
        int t;
        cin >> t;
        int u = 0;
        for(int j = 2; j*j <= t; j++){
            if(t % j == 0){
                list.insert(j);
                u++;
            }
        }
        if(u == 0){
            list.insert(t);
        }
    }

    vector<int> ans;
    int u = 0;
    for(int i = 1; i*i <= M; i++){

        int cnt = 0;
        for(auto t : list){
            if(i % t != 0){
                cnt++;
            }
        }

        if(cnt == list.size()){
            ans.push_back(i);
        }

    }


    sort(ans.begin(),ans.end());

    cout << ans.size() << " ";
    rep(i,0,ans.size()-1){
        cout << ans[i] << " ";
    }
    cout << ans[ans.size()-1] << endl;



}