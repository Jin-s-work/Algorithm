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
    
    int arr[31] = {0};
    
    for(int i=0;i<28;i++){
        int a;
        cin >> a;
        arr[a]++;
    }
    
    for(int i=1;i<=30;i++){
        if(arr[i] == 0)
            cout << i << '\n';
    }
    
    
    return 0;

}

