#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <functional>
#include <map>
#include <unordered_map>
#include <set>

// control i
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;





int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int>v;
    for(int i=0;i<5;i++){
        string st;
        cin >> st;
        
        bool check = false;

        for(int j=0;j<st.length()-2;j++){
            if(st[j] == 'F' && st[j+1] == 'B' && st[j+2] == 'I'){
                check = true;
                break;
            }
                
        }
        
        if(check)
            v.push_back(i+1);
        
    }
    
    if(v.empty()){
        cout << "HE GOT AWAY!" << '\n';
        return 0;
    }
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << '\n';
    
    
    return 0;

}
