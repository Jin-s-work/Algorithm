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

    
    string arr[6];
    for(int i=0;i<5;i++){
        cin >> arr[i];
        
    }
    
    string st;
    for(int i=0;i<15;i++){
        for(int j=0;j<5;j++){
            if(i < arr[j].size())
            cout << arr[j][i];
        }
    }
    
    
    
    return 0;

}

