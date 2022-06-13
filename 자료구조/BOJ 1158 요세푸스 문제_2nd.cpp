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


    cin >> n >> k;
    
    queue<int>q;
    
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    
    int idx = 0;
    int a = 0;
    cout << "<";
    while(!q.empty()){
        a = q.front();
        q.pop();
        idx++;
        
        if(idx == k){
            if(q.empty())
                cout << a << ">" << '\n';
            else
                cout << a << ", ";
            
            idx = 0;
            // q라서 뺐다가 다시 넣어주면 뒤로 가기에 idx를 0부터 하면 원형 큐랑 같이 됨
        }
        else{
            q.push(a);
            
        }
        
        
        
        
    }
    
    // 1 2 3 4 5 6 7
    //     d     d
    //   d
    
    
    return 0;

}

