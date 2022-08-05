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

// control i처
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


int a, b;
bool check[10001];

void BFS(){
    queue<pair<int, string>>q;
    q.push({a, ""});
    check[a] = true;
    
    while(!q.empty()){
        int now = q.front().first;
        string str = q.front().second;
        q.pop();
        // 처음에 숫자를 다음에는 문자열을 넣어준다.
        
        if(now == b){
            cout << str << '\n';
            return;
        }
        // now가 b와 같아지면 문자열을 출력하고 한줄 넘어간다.
        
        int D, S, L, R;
        
        // D
        D = (now * 2) % 10000;
        if(!check[D]){
            check[D] = true;
            q.push({D, str + "D"});
        }
        // now를 두배로 하지만 9999보다 크면 10000으로 나눈 나머지여야 하기에
        // 만약 이 숫자에 안들어와있으면 check를 바꾸고 D를 넣어준다.
        
        // S
        if(now < 1)
            S = 9999;
        else
            S = now - 1;
        // 1보다 작을 경우 즉 0일 경우에는 9999로 저장되고, 아닐 경우에는 그냥 1을 뺌
        
        if(!check[S]){
            check[S] = true;
            q.push({S, str + "S"});
        }
        
        
        // L
        L = (now % 1000) * 10 + (now / 1000);
        if(!check[L]){
            check[L] = true;
            q.push({L, str + "L"});
        }
        // 왼쪽으로 shift인데 네자리 수 이므로 위와 같이 한다.
        
        // R
        R = now / 10 + (now % 10) * 1000;
        if(!check[R]){
            check[R] = true;
            q.push({R, str + "R"});
        }
        
    }
    
}



int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> t;
    while(t--){
        cin >> a >> b;
        memset(check, false, sizeof(check));
        BFS();
    }
    
    
    
    return 0;
    
}

