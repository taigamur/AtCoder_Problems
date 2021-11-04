#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

/* 1102 AC */

int main(){

    ll N,Q;
    cin >> N >> Q;

    vector<ll> front(N+1,-1);
    vector<ll> back(N+1,-1);

    rep(i,0,Q){
        ll q;
        cin >> q;

        if(q == 1){
            ll x,y;
            cin >> x >> y;
            back[x] = y;
            front[y] = x;
        }else if(q == 2){
            ll x,y;
            cin >> x >> y;
            back[x] = -1;
            front[y] = -1;
        }else{
            ll x;
            cin >> x;
            while(front[x] != -1){
                x = front[x];
            }
            vector<ll> ans;
            while(x != -1){
                ans.push_back(x);
                x = back[x];
            }

            cout << ans.size() << " ";
            
            rep(j,0,ans.size()-1){
                cout << ans[j] << " ";
            } 
            cout << ans[ans.size()-1] << endl;

        }
    }



}