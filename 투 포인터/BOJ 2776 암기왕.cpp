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





int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> t;
    
    while(t--){
        
        cin >> n;
        
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        
        cin >> m;
        vector<int>w(m);
        
        for(int i=0;i<m;i++){
            cin >> w[i];
        }
        for(int i=0;i<m;i++){
            int left = 0;
            int right = n-1;
            
            while(1){
                if(left > right){
                    cout << 0 << '\n';
                    break;
                }
                int mid = (left + right) / 2;
                if(v[mid] == w[i]){
                    cout << 1 << '\n';
                    break;
                }
                
                if(v[mid] > w[i]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
        }
        
        
    }
    
    
    
    return 0;

}
