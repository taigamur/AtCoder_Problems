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

#define SIZE  100005

vector<int> pfact(int x){
    vector<int> res;
    for(int i = 2; i*i <= x; i++){
        while(x%i == 0){
            x/=i;
            res.push_back(i);
        }
    }
    if(x!=1){res.push_back(x);}
    return res;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<bool> fl(SIZE,true);
    rep(i,0,n){
        int a;
        cin >> a;
        vector<int> v=pfact(a);
        rep(i,0,v.size()){
            if(fl[v[i]]){
                for(int j=v[i]; j < SIZE; j+=v[i]){
                    fl[j] = false;
                }
            }

        }
    }

    vector<int> res;
    for(int i=1; i<=m;i++){
        if(fl[i]){
            res.push_back(i);
        }
    }

    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }

}