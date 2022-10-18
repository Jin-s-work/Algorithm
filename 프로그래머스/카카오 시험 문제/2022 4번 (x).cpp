#include <string>
#include <vector>
#include <iostream>

using namespace std;

int bin(int num){
    int ans = 0;
    for(int i=1;num>0;i*=10){
        int tmp = num % 2;
        ans += tmp * i;
        num /= 2;
    }

    return ans;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

// 이진 범위 14개 안
    for(int i=0;i<numbers.size();i++){

        int num = bin(numbers[i]);
        string str = to_string(num);

        int str_size = str.length();

        if(str_size == 1){
            if(num == 1)
                answer.push_back(0);
            else
                answer.push_back(1);
        }
        else if(str_size == 2){
            if(str[0] == '1')
                answer.push_back(1);
            else
                answer.push_back(0);
        }
        else if(str_size == 3){
            if(str[1] == '1')
                answer.push_back(1);
            else
                answer.push_back(0);
        }
        else if(str_size == 4){
            if(str[0] == '1' && str[1] == '1')
                answer.push_back(1);
            else
                answer.push_back(0);
        }
        else if(str_size == 5){
            if(str[1] == '1' && str[2] == '1')
                answer.push_back(1);
            else
                answer.push_back(0);
        }
        else if(str_size == 6){
            if(str[2] == '1' && str[3] == '1')
                answer.push_back(1);
            else
                answer.push_back(0);
        }
        else if(str_size == 7){
            if(str[1] == '1' && str[3] == '1' && str[5] == '1')
                answer.push_back(1);
            else
                answer.push_back(0);
        }
        else if(str_size == 8){
            if(str[2] == '1' && str[4] == '1' && str[6] == '1')
                answer.push_back(1);
            else
                answer.push_back(0);
        }
        else if(str_size == 9){
            if(str[1] == '1' && str[3] == '1' && str[5] == '1' && str[7] == '1')
                answer.push_back(1);
            else
                answer.push_back(0);
        }
        else if(str_size == 10){
            if(str[2] == '1' && str[4] == '1' && str[6] == '1' && str[8] == '1')
                answer.push_back(1);
            else
                answer.push_back(0);
        }
        else if(str_size == 11){
            if(str[1] == '1' && str[3] == '1' && str[5] == '1' && str[7] == '1' && str[9] == '1')
                answer.push_back(1);
            else
                answer.push_back(0);
        }
        

        // else{
        //     bool check = false;
        //     for(int j=0;j<str.size()-2;j+=2){
        //         int one = str[j] - '0';
        //         int three = str[j+2] - '0';
        //         if((one + three) >= 1 && str[j+1] == '0'){
        //             answer.push_back(0);
        //             check = true;
        //             break;
        //         }
        //     }
        //     if(!check)
        //         answer.push_back(1);
        // }

    }

    
    return answer;
}
