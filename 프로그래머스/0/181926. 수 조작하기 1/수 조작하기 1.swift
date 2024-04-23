import Foundation

func solution(_ n:Int, _ control:String) -> Int {
    
    var num = n
    for k in control{
        if k == "w"{
            num += 1
        }
        else if k == "s"{
            num -= 1
        }
        else if k == "d"{
            num += 10
        }
        else if k == "a"{
            num -= 10
        }
    }
    
    return num
}