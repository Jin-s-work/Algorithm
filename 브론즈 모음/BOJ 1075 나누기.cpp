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


int func(){
    int start = (n / 100) * 100;
    
    int ans;
    for(int i=start;i<start+100;i++){
        if(i % m == 0){
            ans = i % 100;
            break;
        }       // 나누어질 경우에 바로 나온다.
    }
    
    return ans;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    int num = func();
    
    if(num >= 0 && num < 10){
        cout << "0";
    }
    
    cout << num << '\n';
    
    
    
    return 0;

}
