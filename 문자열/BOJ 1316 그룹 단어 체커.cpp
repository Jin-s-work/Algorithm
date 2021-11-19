
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
    int ans = 0;
    
    while(t--){
        
        string st;
        cin >> st;
        bool check = true;
        
        for(int i=0;i<st.length();i++){
            for(int j=0;j<i;j++){
                if(st[i] != st[i-1] && st[i] == st[j]){
                    check = false;
                    break;
                    // i를 처음부터끝까지 탐색하면서
                    // j는 i보다 작게 설정하여 하나라도 다른 문자를 넘어 같다면 false를 만들고 끝냄
                }
                    
            }
        }
        if(check)
            ans++;
        
    }
    
    cout << ans;
    
    return 0;

}

// 생각해서 풀던 것과 저번에 푼 것이 거의 같았으나, for문으로 범위를 제한시켜주는 부분에 있어서 참조하여 풀었다.

