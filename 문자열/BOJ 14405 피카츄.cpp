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
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h, w;



int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    string st;
    cin >> st;
    bool check = true;
    string ans = "YES";
    
    
    for(int i=0;i<st.length();){
        if(st[i] == 'p' && st[i+1] == 'i'){
            i += 2;
        }
        else if(st[i] == 'k' && st[i+1] == 'a'){
            i += 2;
        }
        else if(st[i] == 'c' && st[i+1] == 'h' && st[i+2] == 'u'){
            i += 3;
        }
        else{
            check = false;
            break;
        }
        
        
        
    }
    
    if(check)
        cout << "YES";
    else
        cout << "NO";
    
    
    return 0;
    
}
