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


    cin >> n;
    
    stack<int>s;
    
    while(n--){
        string st;
        cin >> st;
        // num을 안받는 경우도 있는데 바보 같이 뒤에도 받아버림
        
        if(st == "push"){
            int num;
            cin >> num;
            s.push(num);
        }
        else if(st == "pop"){
            if(s.empty()){
                cout << "-1" << '\n';
                continue;
            }
            
            int tp = s.top();
            s.pop();
            
            cout << tp << '\n';
        }
        else if(st == "size"){
            cout << s.size() << '\n';
        }
        else if(st == "empty"){
            if(s.empty())
                cout << "1" << '\n';
            else
                cout << "0" << '\n';
        }
        else if(st == "top"){
            if(!s.empty())
                cout << s.top() << '\n';
            else
                cout << "-1" << '\n';
        }
    }
    
    
    
    return 0;

}
