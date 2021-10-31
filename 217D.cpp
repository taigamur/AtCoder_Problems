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


int main(){

    int L,Q;
    cin >> L >> Q;
    vector<int> list;
    set<int> s;

    s.insert(0);
    s.insert(L);
    rep(i,0,Q){
        int c,x;
        cin >> c >> x;

        if(c == 1){
            s.insert(x);
        }else{
        
            auto itr = s.lower_bound(x);
            cout << *itr - *prev(itr) << endl;
        }
    }

}