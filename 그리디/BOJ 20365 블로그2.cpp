
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
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
    
    cin >> n;
    
    string st;
    cin >> st;
    
    int ans = 1;
    int rednum = 0;
    int bluenum = 0;
    
    bool blue = false;
    bool red = false;
    for(int i=0;i<n;i++){
        
        
        if(st[i] == 'B'){
            if(blue)
                bluenum--;
            
            bluenum++;
            red = false;
            blue = true;
        }
        if(st[i] == 'R'){
            if(red)
                rednum--;
            
            rednum++;
            red = true;
            blue = false;
        }
        
        // 각각 한번 더 red나 blue가 나올 경우 빼주었다가 더해서 중복일때는 늘지 않게 하고
        // 각각의 수를 구한다.
        
    }
    
    if(rednum >= bluenum)
        ans += bluenum;
    else
        ans += rednum;
    // ans인 1에다가 더 작은 숫자를 더해주면 ans
    
    cout << ans;
    
    
    
    
    return 0;
}

// 신기한 방법이 많다.. 구현은 내가 함
// 중복된 것들을 모두 제거해주고, 하나로 만든 다음
// 많은 것을 기준으로 하나 더하고, 나머지 개수를 구해주면 된다.


