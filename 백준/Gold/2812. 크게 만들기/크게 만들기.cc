
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>


using ll = long long;
using namespace std;
int l,m;
int n,t,k;
int h,w;

vector<char>v;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    for(int i=0;i<s.length();i++){
        while(k!=0 && !v.empty() && v.back() < s[i]){
            v.pop_back();    // 넣으면서 들어간 값이 있었던 값보다 작으면 있던 값을 v에서 꺼낸다.
            k--;            // 이런 식으로 k를 줄인다.
        }
        v.push_back(s[i]);      // 그러고 이러한 s[i]를 v에 넣는다.
    }
    // 예를 들어 19일때, 1을 먼저 v에 넣고, 9가 더 큰 경우 1을 빼주고 9를 넣어준다.
    
    while(k--){         // k가 남아있으면
        v.pop_back();       // 그대로 출력
    }
    
    for(int i=0;i<v.size();i++){
        cout << v[i];
    }
    cout << '\n';
    
    
    return 0;
}


