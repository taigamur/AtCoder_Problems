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


int main(){

    vector<pair<int,int>> list;

    int H,W,N;
    cin >> H;
    cin >> W;
    cin >> N;
    rep(i,0,N){
        int a,b;
        cin >> a >> b;
        pair<int,int> p;
        p.first = a;
        p.second = b;
        list.push_back(p);
    }
    sort(list.begin(),list.end());

    list
    for(i,0,N-1){
        
    }

}