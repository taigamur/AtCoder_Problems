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

class Edge{
    public: 
    int t, w;
    Edge();
    Edge(int t, int w): t(t), w(w){};
};
// vector<Edge> G[MAX];



int main(){
    int N;
    cin >> N;
    multiset<ll> st;
    rep(i,0,N){
        int t;
        cin >> t;
        ll x;
        cin >> x;
        if(t == 1){
            st.insert(x);
        }else if(t == 2){
            int k;
            cin >> k;
            auto itr = st.upper_bound(x);

            rep(i,0,k){
                if(itr == st.begin()){
                    itr = st.end();
                    break;
                }
                itr--;
            }

            if(itr == st.end()){
                cout << -1 << endl;
            }else{
                cout << *itr << endl;
            }

        }else{
            int k;
            cin >> k;
            auto itr = st.lower_bound(x);

            rep(i,0,k-1){
                if(itr == st.end()){
                    break;
                }
                itr++;
            }
            if(itr == st.end()){
                cout << -1 << endl;
            }else{
                cout << *itr << endl;
            }
        
        }
    }

}