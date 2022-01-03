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
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
ll n,m,k;
int l,r,t;
int h;


vector<ll>v;
stack<ll>s;
vector<string>str;
#define MAXIMUM 1000000000

ll NUM(ll a){
    s.push(a);
    return 0;
}

ll POP(){
    if(s.empty())
        return 1;
    s.pop();
    
    return 0;
}

ll INV(){
    if(s.empty())
        return 1;
    // 없으면 1
    ll tp = s.top();
    s.pop();
    s.push(-tp);
    // top을 저장해놓고, 빼준다음에 부호 바꾸어서 넣어준다.
    
    return 0;
}

ll DUP(){
    if(s.empty())
        return 1;
    ll tp = s.top();
    s.push(tp);
    
    return 0;
}

ll SWP(){
    if(s.size() < 2)
        return 1;
    ll tp = s.top();
    s.pop();
    ll tp2 = s.top();
    s.pop();
    s.push(tp);
    s.push(tp2);
    
    return 0;
}

ll ADD(){
    if(s.size() < 2)
        return 1;
    ll tp = s.top();
    s.pop();
    ll tp2 = s.top();
    s.pop();
    s.push(tp + tp2);
    
    return 0;
}

ll SUB(){
    if(s.size() < 2)
        return 1;
    ll tp = s.top();
    s.pop();
    ll tp2 = s.top();
    s.pop();
    s.push(tp2 - tp);
    
    return 0;
}

ll MUL(){
    if(s.size() < 2)
        return 1;
    ll tp = s.top();
    s.pop();
    ll tp2 = s.top();
    s.pop();
    s.push(tp2 * tp);
    
    return 0;
}

ll DIV(){
    if(s.size() < 2)
        return 1;
    ll tp = s.top();
    s.pop();
    ll tp2 = s.top();
    s.pop();
    
    if(!tp)
        return 1;
    
    ll res = llabs(tp2) / llabs(tp);
    // llabs는 ll의 절대값
    if(tp * tp2 < 0)
        res *= -1;
    
    s.push(res);
    
    return 0;
}

ll MOD(){
    if(s.size() < 2)
        return 1;
    ll tp = s.top();
    s.pop();
    ll tp2 = s.top();
    s.pop();
    
    if(!tp)
        return 1;
    
    ll res = llabs(tp2) % llabs(tp);
    // llabs는 ll의 절대값
    if(tp2 < 0)
        res *= -1;
    
    s.push(res);
    
    return 0;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll num = 0;
    
    while(1){
        
        v.clear();
        str.clear();
        
        ll tmp = 0;
        
        while(1){
            string st;
            cin >> st;
            
            if(st == "NUM"){
                cin >> num;
                v.push_back(num);
            }
            
            if(st == "END")
                break;
            
            if(st == "QUIT")
                return 0;
            
            str.push_back(st);
            // string 기록하는 벡터에 넣어다 둠
        }
        
        cin >> t;
        
        while(t--){
            
            k = 0;
            cin >> n;
            
            s.push(n);
            
            for(int i=0;i<str.size();i++){
                if(str[i] == "NUM"){
                    tmp = NUM(v[k++]);
                    // v[k]를 넣어주고 k는 증가시킴
                }
                else if(str[i] == "POP")
                    tmp = POP();
                else if(str[i] == "INV")
                    tmp = INV();
                else if(str[i] == "DUP")
                    tmp = DUP();
                else if(str[i] == "SWP")
                    tmp = SWP();
                else if(str[i] == "SUB")
                    tmp = SUB();
                else if(str[i] == "ADD")
                    tmp = ADD();
                else if(str[i] == "MUL")
                    tmp = MUL();
                else if(str[i] == "DIV")
                    tmp = DIV();
                else if(str[i] == "MOD")
                    tmp = MOD();
                
                if(!s.empty() && (llabs(s.top()) > MAXIMUM))
                    tmp = 1;
                
                if(tmp)
                    break;
                
            }
            
            if(tmp || s.size() != 1)
                cout << "ERROR" << '\n';
            else
                cout << s.top() << '\n';
            
            while(!s.empty())
                s.pop();
            
        }
        
        cout << '\n';
    }

    return 0;

}
