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

    
    cin >> n >> k;
    
    int ans = 0;
    for(int h=0;h<=n;h++){
        for(int m=0;m<60;m++){
            for(int s=0;s<60;s++){
                if(h % 10 == k || h / 10 == k || m % 10 == k || m / 10 == k || s % 10 == k || s / 10 == k)
                    ans++;
            }
        }
    }
    // 처음에는 바보 같이 내가 그냥 셋었는데 분류가 브루트포스기도 하고, for문을 통해서 찾으면 된다.
    
    cout << ans;
    
    return 0;

}
