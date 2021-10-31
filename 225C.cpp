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

    int N,M;
    cin >> N >> M;

    vector<vector<int>> list(N,vector<int>(M));

    rep(i,0,N){
        rep(j,0,M){
            cin >> list[i][j];
        }
    }

    int n,m;
    n = (list[0][0]-1) / 7 + 1;
    m = (list[0][0]-1) % 7 + 1;

    rep(i,0,N){
        rep(j,0,M){
            if( (i+n-1) * 7 + (j+m) == list[i][j] && (j+m) < 8){
                continue;
            }else{
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;


}