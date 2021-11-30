

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int Min = 999999;
    int idx = 0;
    if(arr.size() == 1){
        answer.push_back(-1);
        return answer;
    }
    else{
        for(int i=0;i<arr.size();i++){
            if(Min > arr[i]){
                Min = arr[i];
                idx = i;
            }
        }
        
    }
    
    for(int i=0;i<arr.size();i++){
        if(i == idx)
            continue;
        answer.push_back(arr[i]);
    }
    
    return answer;
}


// 밑은 min_element를 구해서 erase해버리는 간편한 방법..

//
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> arr) {
//    vector<int> answer;
//
//   if(arr.size() == 1)          // 여기서 하나를 지우면 없어지므로 -1을 그냥 냄
//    {
//        answer.push_back(-1);
//        return answer;
//    }
//
//    arr.erase(min_element(arr.begin(), arr.end()));
//    // 전체중 가장 작은 element를 지운다.
//    answer = arr;
//    // 이러한 arr들을 answer에 넣는다.
//
//    return answer;
//}










