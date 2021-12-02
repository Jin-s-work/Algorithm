

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool sosu(int num){
    for(int i=2;i<=sqrt(num);i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    int n = nums.size();
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(sosu(nums[i] + nums[j] + nums[k]))
                    answer++;
            }
        }
    }
    

    return answer;
}

// 무난한 소수문제













