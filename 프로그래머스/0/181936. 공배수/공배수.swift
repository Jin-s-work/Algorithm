import Foundation

func solution(_ number:Int, _ n:Int, _ m:Int) -> Int {
    
    if number % n == 0 && number % m == 0{
        return 1
    }
    else{
        return 0
    }
    
    return 0
}