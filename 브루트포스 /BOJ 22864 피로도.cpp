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

    
    int a, b, c;
    
    cin >> a >> b >> c >> m;
    
    int tired = 0;
    int work = 0;
    for(int i=0;i<24;i++){
        
        if(tired + a <= m){
            tired += a;
            work++;
            // 일한 시간을 세줌
        }
        else{
            tired -= c;
            if(tired < 0)       // 0 밑으로 오면은 0으로 치환
                tired = 0;
        }
        
        
    }
    
    cout << b * work;
    // 일한 시간을 찾아서 그냥 곱해주면 된다.
    
    
    return 0;

}
