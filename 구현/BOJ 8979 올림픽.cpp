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
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;



int gold[1001], silver[1001], bronze[1001];
int ans = 0;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> k;
    
    for(int i=0;i<n;i++){
        int idx;
        cin >> idx;
        cin >> gold[idx] >> silver[idx] >> bronze[idx];
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
    
    
    cout << ans + 1;
    
    
    return 0;

}
