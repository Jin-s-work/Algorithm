
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

vector<int>v;

void decimal(int num){
    while(num){
        v.push_back(num % 2);
        num /= 2;
    }
    
    
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    
    while(t--){
        cin >> n;
        
        decimal(n);
        
        for(int i=0;i<v.size();i++){
            if(v[i] == 1)
                cout << i << " ";
        }
        
        v.clear();
        
    }
    
    
    
    
    
    
    return 0;
}
