
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
    
    
    cin >> n >> k;
    
    queue<int>q;
    
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    
    
    int m = 0;
    int num = 0;
    
    cout << "<";
    
    while(!q.empty()){
        m = q.front();
        q.pop();
        // q의 제일 앞을 m으로 해놓고 pop해줌
        num++;
        // 횟수 더하기
        
        if(num == k){       // 그러면서 num이 k가 될 때 즉, 순서가 되었을 때 m을 출력해준다.
            if(!q.size())       // q가 끝나면 >로 끝내줌
                cout << m << ">" << '\n';
            else                // 아닐경우 ,로 진행해줌
                cout << m << ", ";
            
            num = 0;
            // 그러면 num을 다시 0으로 해주고 다시 해줌
        }
        
        else
            q.push(m);
        // 아닐 경우 다시 m을 push 해주고 지나감
        
    }
    
    
    
    return 0;

}

