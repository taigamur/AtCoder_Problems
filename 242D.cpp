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

string S;
void f(int t, int k){
    if(t == 0){
        cout << S[k] << endl;
    }else{
        if(k == 0){
            char c = 'A' + (S[0]-'A'+t)%3 ;
            cout << c << endl; 
        }else{
            f(t-1, k/2);
            char c =  hu8778887
        }
    }    
}

int main(){
    int Q;
    cin >> S >> Q;

    rep(i,0,Q){
        int t,k;
        cin >> t >> k;
        f(t,k-1);
    }

}