#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)


int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> v(n);
    rep(i,0,n){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(),v.end());
    int ans = 0;
    rep(i,0,n){
        rep(j,0,n){
            if(v[i].first < v[j].first && v[i].second < v[j].second){
                if(binary_search(v.begin(),v.end(),make_pair(v[i].first,v[j].second)) && 
                binary_search(v.begin(),v.end(),make_pair(v[j].first,v[i].second))) ans++;
            }
            
        }
    }
    cout << ans << endl;

    

}