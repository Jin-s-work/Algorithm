
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
    
    deque<int>dq;
    cin >> n;
    
    while(n--){
        
        string s;
        cin >> s;
        

        if(s == "push_front"){
            cin >> m;
            dq.push_front(m);
        }
        else if(s == "push_back"){
            cin >> m;
            dq.push_back(m);
        }
        else if(s == "front"){
            if(!dq.empty())
                cout << dq.front() << '\n';
            else
                cout << "-1" << '\n';
        }
        else if(s == "back"){
            if(!dq.empty())
                cout << dq.back() << '\n';
            else
                cout << "-1" << '\n';
        }
        else if(s == "pop_front"){
            if(dq.empty())
                cout << "-1" << '\n';
            else{
                int num = dq.front();
                dq.pop_front();
                cout << num << '\n';
            }
        }
        else if(s == "pop_back"){
            if(dq.empty())
                cout << "-1" << '\n';
            else{
                int num = dq.back();
                dq.pop_back();
                cout << num << '\n';
            }
        }
        else if(s == "size")
            cout << dq.size() << '\n';
        
        else if(s == "empty"){
            if(dq.empty()){
                cout << "1" << '\n';
            }
            else
                cout << "0" << '\n';
        }
        
        
    }
    
    
    
    
    return 0;

}


// 스택과 큐와 같은 디큐의 활용법
