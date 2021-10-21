#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int inf = numeric_limits<int>::max();
ll INF = numeric_limits<ll>::max();
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)


/*
1021
*/
int main(){
    int N;
    cin >> N;

    vector<pair<int,int>> S;
    vector<pair<int,int>> T;

    rep(i,0,N){
        string s;
        cin >>s;
        rep(j,0,N){
            if(s[j] == '#'){
                S.push_back(make_pair(i,j));
            }
        }
    }

    rep(i,0,N){
        string t;
        cin >> t;
        rep(j,0,N){
            if(t[j] == '#'){
                T.push_back(make_pair(i,j));
            }
        }
    }

    if(S.size() != T.size()){
        cout << "No" << endl;
        return 0;
    }


    sort(T.begin(),T.end());

    rep(a,0,4){
        sort(S.begin(),S.end());
        int dif_x = S[0].first - T[0].first;
        int dif_y = S[0].second - T[0].second;
        int cnt = 1;
        rep(i,1,S.size()){
            if(S[i].first - dif_x == T[i].first && S[i].second - dif_y == T[i].second){
                cnt++;
            }else{
                break;
            }
        }
        if(cnt == S.size()){
            cout << "Yes" << endl;
            return 0;
        }

        rep(i,0,S.size()){
            int x = S[i].first;
            int y = S[i].second;
            S[i].first = -y;
            S[i].second = x;
        }

    }
    cout << "No" << endl;

}