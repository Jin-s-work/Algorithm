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


int gold[1001], silver[1001], bronze[1001];     // 숫자 잘못씀..
int ans = 0;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> k;
    
    for(int i=0;i<n;i++){
        int a;
        cin >> a;       // 여기서 먼저 선언을 해 주어야 a에 들어가겠다.
        cin >> gold[a] >> silver[a] >> bronze[a];
        
    }
    
    for(int i=1;i<=n;i++){
        if(gold[i] > gold[k])
            ans++;
        else if(gold[i] == gold[k]){
            if(silver[i] > silver[k])
                ans++;
            else if(silver[i] == silver[k]){
                if(bronze[i] > bronze[k])
                    ans++;
            }
        }
    }
    
    cout << ans + 1 << '\n';
    
    
    
    
    return 0;

}
