import Foundation

func solution(_ n:Int) -> Int {
    
    func find(number : Int) -> Bool{
        var cnt = 0
        for i in 1...number{
            if number % i == 0{
                cnt += 1
            }
        }
        if cnt >= 3{
            return true
        }
        else{
            return false
        }
    }
    
    // var arr : [Int] = []
    var ans = 0
    for i in 1...n{
        if find(number : i){
            ans += 1
            // arr.append(i)
        }
    }
    
    
    return ans
}