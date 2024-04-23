import Foundation

func solution(_ myString:String) -> [Int] {
    
    var ans : [Int] = []
    var num = 0
    for k in myString{
        if k == "x"{
            ans.append(num)
            num = 0
        }
        else {
            num += 1
        }
    }
    ans.append(num)
    
    return ans
}