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


int main(){
    string X;
    cin >> X;

    int s = 0;
    int c = 0;
    
    rep(i,0,X.size()){
        s += X[i] - '0';
    }

    string res;
    int i = X.size() - 1;
    while(1){
        c += s;
        res.push_back('0' + ( c % 10)); // ある桁の値を決定
        c = c / 10; // 桁上がりの値
        if(i >= 0){
            s -= (X[i] - '0'); // 次の桁の和のための調整
        }

        if(i <= 0 && c == 0){
            break; //全ての桁を参照, 繰り上がりなし で終了
        }

        i--;
    }

    reverse(res.begin(), res.end());
    cout << res << endl;
}