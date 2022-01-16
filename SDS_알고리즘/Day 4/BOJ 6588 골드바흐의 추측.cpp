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

bool arr[1000001];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    for(int i=2;i*i<=1000000;i++){
        if(arr[i] == false){        // i가 소수일때 (false이면 소수)
            for(int j=i*i;j<=1000000;j+=i){
                arr[j] = true;      // j가 i*i부터 시작해서 i씩 더할 경우에
            }                       // arr[j]는 소수가 아니므로 true로 한다.
        }
        
        
    }
    
    
    while(1){
        
        cin >> n;
        
        if(!n)
            break;
        
        bool check = false;
        for(int i=3;i<n;i++){
            int num = n - i;
            
            if(arr[num] == false && arr[i] == false){
                cout << n << " = " << i << " + " << num << '\n';
                check = true;
                break;
            }
            
        }
        
        if(!check)
            cout << "Goldbach's conjecture is wrong." << '\n';
        
        
        
    }
    
    
    
    
    

    return 0;

}

// 에라토스테네스의 체
// 투 포인터














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
