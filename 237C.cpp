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

bool judge(string s){
    for(int i = 0; i < s.size()/2; i++){
        if(s[i] == s[s.size()-i-1]){

        }else{
            return false;
        }
    }
    return true;
}

int main(){
    string S;
    cin >> S;
    
    if(judge(S)){
        cout << "Yes" << endl;
        return 0;
    }else{

        ll l = S.size();
        int y = 0;
        while(1){
            if(S[l-1] == 'a'){
                l--;
                y++;
            }else{
                break;
            }
        }

        int x;
        while(1){
            if(S[x] == 'a'){
                x++;
            }else{
                break;
            }
        }

        if(y-x >= 0){
            string T = S.substr(0,S.size()-(y-x));
            if(judge(T)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else{
            cout << "No" << endl;
        }




    }


    

}