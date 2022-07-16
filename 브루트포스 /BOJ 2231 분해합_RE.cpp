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

    
    cin >> n;
    for(int i=1;i<=n;i++){
        int num = i;
        int sum = i;
        
        while(num){
            sum += num % 10;
            num /= 10;
        }
        
        if(sum == n){
            cout << i << '\n';
            return 0;
        }
    }
    
    cout << "0" << '\n';
    // 아무 것도 안 되었을 경우 0을 출력
    
    
    return 0;

}
