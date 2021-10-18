
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
int h;

bool arr[1000001];
void prime(){
    for(int i=2;i*i<=1000000;i++){
        if(arr[i] == false)         // false이어야 한다 왜냐면 false일때 바꾸어야 하니까
            for(int j=i*i;j<=1000000;j+=i){
                arr[j] = true;      // 소수가 아니면 true
            }
    }


}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    prime();

    while(1){
        
    
        cin >> n;
        
        if(n == 0)
            break;
        
        for(int i=3;i<=n;i++){
            int gold = n - i;
            if(!arr[gold] && !arr[i]){      // i도 소수인것을 알아야 하는 데 빠뜨린듯
                cout << n << " = " << i << " + " << gold << '\n';
                break;
            }
            
        }
        
        
    }
    
    
    
    return 0;
}
