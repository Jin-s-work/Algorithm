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
    
    cin >> t;
    
    while(t--){
        
        string st;
        cin >> st;
        
        int ans = 0;
        int move = st.length() - 1;
        
        for(int i=0;i<st.length();i++){
            if(st[i] == 'A'){
                int idx = i;
                while(idx < st.length() && st[idx] == 'A')
                    idx += 1;
                // idx가 길이보다 짧고, st의 인덱스가 A일 경우
                // 하나씩 더해준다.
                
                int left;
                if(i == 0)
                    left = 0;
                else
                    left = i-1;
                // i가 0이면 왼쪽이 0이고, 아닐 경우는 i에서 하나 빼서 말해준다.
                
                int right = st.length() - idx;
                move = min(move, left + right + min(left, right));
            }
        }
        
        ans += move;
        for(auto k : st)
            ans += min(k - 'A', 'Z' - k + 1);
        
        cout << ans << '\n';
    }
    
    return 0;
    
}

// 프로그래머스 레벨 2 조이스틱과 같아, 다시 풀었다.
