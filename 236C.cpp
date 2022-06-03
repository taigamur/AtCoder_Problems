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
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<string> list;
    rep(i,0,n){
        string s;
        cin >> s;
        list.push_back(s);
    }

    vector<string> list2;
    rep(i,0,m){
        string s;
        cin >> s;
        list2.push_back(s);
    }


    int j = 0;
    rep(i,0,n){
        if(list[i] == list2[j]){
            cout << "Yes" << endl;
            j++;
        }else{
            cout << "No" << endl;
        } 
    }


}