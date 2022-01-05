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
            int gcd = 1;
            if(i != j){
                int x = point[i].first - point[j].first;
                int y = point[i].second - point[j].second;

                int z;
                pair<int,int> p2;
                if(x == 0){
                    z = y;
                    p2.first = 0;
                    p2.second = y / abs(y);
                    list[p2] = true;
                }else if(y == 0){
                    z = x;
                    p2.first = x / abs(x);
                    p2.second = 0;
                    list[p2] = true;
                }else{
                    z = min(abs(x),abs(y));
                    for(int k = 1; k*k < z; k++){
                        if(x % k == 0 && y % k == 0){
                            gcd = k;
                        }
                    }
                    if(x % z == 0 && y % z == 0){
                        gcd = z;
                    }
                    p2.first = x / gcd;
                    p2.second = y / gcd;
                    list[p2] = true;
                }
                // cout << "ans: " << p2.first << " " << p2.second << endl;
                

            }
        }
    }
    cout << list.size() << endl;



}