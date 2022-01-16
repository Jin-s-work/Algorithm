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
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;

int gcd(int a, int b){
    
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bool arr[1001] = {0};
    
    cin >> n >> k;
    
    int num = 0;
    for(int i=2;i<=n;i++){
        if(arr[i] == false){
            arr[i] = true;
            num++;
            
            if(num == k){
                cout << i;
                return 0;
            }
            
            for(int j=i+i;j<=n;j+=i){
                if(arr[j] == false){        // 여기서도 소수가 아님을 체크해야 됏엇다..
                arr[j] = true;
                num++;
                if(num == k){
                    cout << j;
                    return 0;
                }
            }
            }
        }
        
    }
    
    
    
    
    

    return 0;

}












//
//
//
//
//cin >> n >> k;
//
//priority_queue<int>pq;
//vector<int>v;
//
//for(int i=0;i<n;i++){
//    int a;
//    cin >> a;
//    v.push_back(a);
//}
