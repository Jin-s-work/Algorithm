
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
    
    
    queue<int>q;
    cin >> n;
    
    while(n--){
        
        string s;
        cin >> s;
        

        if(s == "push"){
            cin >> m;
            q.push(m);
        }
        else if(s == "front"){
            if(!q.empty())
                cout << q.front() << '\n';
            else
                cout << "-1" << '\n';
        }
        else if(s == "pop"){
            if(q.empty())
                cout << "-1" << '\n';
            else{
                int num = q.front();
                q.pop();
                cout << num << '\n';
            }
        }
        else if(s == "size")
            cout << q.size() << '\n';
        
        else if(s == "empty"){
            if(q.empty()){
                cout << "1" << '\n';
            }
            else
                cout << "0" << '\n';
        }
        else if(s == "back"){
            if(!q.empty())
                cout << q.back() << '\n';
            else
                cout << "-1" << '\n';
        }
        
    }
    
    
    return 0;

}

// 전에 푼 스택이랑 거의 같음
