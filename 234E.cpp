#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;
int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)


set<ll> gen_tosasu(){
    set<ll> res;
    for(int i = 0; i <= 9; i++){
        for(int j = -9; j <= 8; j++){
            string s;
            int l = i;
            for(int k = 0; k < 18; k++){
                s.push_back(l+'0');
                res.insert(stoll(s));
                l += j;
                if(!(0<=l && l <= 9)){break;}
            }
        }
    }
    return res;
}

int main(){
    //

    ll x;
    cin >> x;
    set<ll> st = gen_tosasu();
    cout << *st.lower_bound(x) << endl;
    return 0;

}