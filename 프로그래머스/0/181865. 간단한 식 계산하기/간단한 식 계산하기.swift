import Foundation

func solution(_ binomial:String) -> Int {
    
    let op = binomial.split(separator : " ")
    
    let a = Int(op[0])!
    let b = String(op[1])
    let c = Int(op[2])!
    
    if b == "+"{
        return a + c
    }
    else if b == "-"{
        return a - c
    }
    else if b == "*"{
        return a * c
    }
    
    return 0
}