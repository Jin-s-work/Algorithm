
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
    
    stack<int>st;
    // 안에다 넣으면 계속 갱신되는디...
    cin >> n;
    
    while(n--){
        
        string s;
        cin >> s;
        

        if(s == "push"){
            cin >> m;
            st.push(m);
        }
        else if(s == "top"){
            if(!st.empty())
                cout << st.top() << '\n';
            else
                cout << "-1" << '\n';
        }
        else if(s == "pop"){
            if(st.empty())
                cout << "-1" << '\n';
            else{
                int num = st.top();
                st.pop();
                cout << num << '\n';
            }
            }
        else if(s == "size")
            cout << st.size() << '\n';
        else if(s == "empty"){
            if(st.empty()){
                cout << "1" << '\n';
            }
            else
                cout << "0" << '\n';
        }
        
        
    }
    
    
    
    
    return 0;

}

