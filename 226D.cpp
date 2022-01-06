#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <cassert>
#include <numeric>
using namespace std;

typedef long long ll;
int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> point(N);
    rep(i,0,N){
        pair<int,int> p;
        cin >> p.first;
        cin >> p.second;
        point[i] = p;
    }

    map<pair<int,int>,bool> list;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i != j){
                int x = point[i].first - point[j].first;
                int y = point[i].second - point[j].second;

                int z;
                pair<int,int> p2;
                if(x == 0){
                    p2.first = 0;
                    p2.second = y / abs(y);
                    list[p2] = true;
                }else if(y == 0){
                    p2.first = x / abs(x);
                    p2.second = 0;
                    list[p2] = true;
                }else{
                    z = gcd(abs(x),abs(y));
                    p2.first = x / z;
                    p2.second = y / z;
                    list[p2] = true;
                }
          

            }
        }
    }
    cout << list.size() << endl;



}