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
typedef unsigned long long ull;
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

int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> C;
    vector<pair<int,int>> D;

    rep(i,1,10){
        pair<int,int> p;
        cin >> p.first;
        p.second = i;
        C.push_back(p);
        p.second =p.first;
        p.first = i;
        D.push_back(p);
    }

    sort(C.begin(),C.end());

    ll S = N / C[0].first; //桁数

    ll sum = C[0].first * S;
    vi ans;

    rep(i,0,S){
        for(int j = D.size()-1; j >= 0; j--){
            if(sum + (D[j].second - C[0].first) <= N ){
                ans.push_back(D[j].first);
                sum += (D[j].second - C[0].first);
                break;
            }
        }
    }

    rep(i,0,ans.size()){
        cout << ans[i];
    }

    cout << endl;


}