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
#include <sstream>

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


    cin >> t;
    
    while(t--){
        
        string st;
        cin >> st;
        
        stack<char>s;
        bool check = true;
        
        for(int i=0;i<st.length();i++){
            if(st[i] == '('){
                s.push(st[i]);
                // (일 경우에는 그것을 그냥 스택에 push
            }
            else if(st[i] == ')'){
                if(!s.empty() && s.top() == '('){
                    s.pop();
                    // )일 경우 비어있지 않고 top이 (로 끝나는 경우 그것을 pop
                }
                else{
                    check = false;
                    break;
                    // 스택에 쌓인 것 중 ( 가 없는데 )가 들어왔거나 비어있으면 false로 하고 break
                }
            }
            
            
                
        }
        
        if(s.empty() && check)
            cout << "YES" << '\n';
        // 여기서 stack도 비어있어야 한다. 남아있는채로 끝나면 아직 짝이 없는 (가 남아잇는 것
        else
            cout << "NO" << '\n';
        
        
    }
    
    
    return 0;

}

