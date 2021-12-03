

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer;
    
    int size = nums.size();
    // unique erase로 되려나
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    int change = nums.size();
    if(size/2 >= change)
        answer = change;
    else
        answer = size/2;
    
    
    return answer;
}

// 머야 이게 맞네..













