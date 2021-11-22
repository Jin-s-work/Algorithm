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
    
    while(t--){
        
        int num = 0;
        cin >> num;
        int Max = -1000001;
        int Min = MAX;
        
        for(int i=0;i<num;i++){
            int a;
            cin >> a;
            if(Min > a)
                Min = a;
            if(Max < a)
                Max = a;
        }
        
        cout << Min << " " << Max << '\n';
        
    }
    
    
    return 0;

}


