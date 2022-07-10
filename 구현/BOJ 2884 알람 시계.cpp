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

    
    int h,m;
    cin >> h >> m;
    
    int hour, min;
    
    if(h == 0 && m < 45){
        hour = h + 23;
        min = m + 60 - 45;
    }
    else if(m < 45){
        hour = h - 1;
        min = m + 60 - 45;
    }
    else{
        hour = h;
        min = m - 45;
    }
    
    
    cout << hour << " " << min;
    
    
    return 0;

}




