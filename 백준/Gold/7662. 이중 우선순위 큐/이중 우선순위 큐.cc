#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
#include <deque>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,r;
int l,k,t;
int h,w;


bool check[1000001];


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> t;
    
    while(t--){
        
        priority_queue<pair<int, int>> Max;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Min;

        cin >> n;
        
        for(int i=0;i<n;i++){
            
            char st;
            int num;
            cin >> st >> num;
            
            if(st == 'I'){
                Max.push({num, i});
                Min.push({num, i});
                check[i] = true;
            }
            else{
                if(num == 1){
                    while(!Max.empty() && !check[Max.top().second])
                        Max.pop();
                    if(!Max.empty()){
                        check[Max.top().second] = false;
                        Max.pop();
                    }
                }
                else{
                    while(!Min.empty() && !check[Min.top().second])
                        Min.pop();
                    if(!Min.empty()){
                        check[Min.top().second] = false;
                        Min.pop();
                    }
                }
            }
            
        }
        
        
        while(!Max.empty() && !check[Max.top().second])
            Max.pop();
        while(!Min.empty() && !check[Min.top().second])
            Min.pop();
        
        if(Min.empty() && Max.empty())
            cout << "EMPTY\n";
        else
            cout << Max.top().first << " " << Min.top().first << '\n';
        
        
    }
    
    
    
    return 0;
}

