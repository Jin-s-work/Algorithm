

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    
    sort(numbers.begin(), numbers.end());
    
    for(int i=0;i<numbers.size();i++){
        for(int j=i+1;j<numbers.size();j++){
            int sum = 0;
            sum = numbers[i] + numbers[j];
            answer.push_back(sum);
        }
    }
    
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    // v.erase(unique(begin, end), end)
    // 를 활용한다면 중복된 것들을 지울 수가 있다.
    // 하지만 우선 정렬을 하고 사용하여야 한다.
    
    
    return answer;
}













