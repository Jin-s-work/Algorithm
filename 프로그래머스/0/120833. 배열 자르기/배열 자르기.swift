import Foundation

func solution(_ numbers:[Int], _ num1:Int, _ num2:Int) -> [Int] {
    
    var ans : [Int] = []
    for (i, num) in numbers.enumerated(){
        if num1 <= i && i <= num2{
            ans.append(num)
        }
    }
    
    return ans
}