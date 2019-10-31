//: Playground - noun: a place where people can play

import UIKit

enum TrafficLight{
    case Green;
    case Orange;
    case Red;
}
let light = TrafficLight.Orange
print(light)





enum enumstring :String{
    case king = "vive le roi"
    case queen = "vive la reine"
}
var tmp0 = enumstring.king
print(tmp0)
print(tmp0.rawValue)
tmp0.rawValue






enum enumnumber :Int{
    case value1 = 42
    case value2 = 0
}
var tmp1 = enumnumber.value1
print(tmp1)
print(tmp1.hashValue)
tmp1.hashValue







enum Optional <T>{
    case Nil;
    case firstValue;
    case OptValue(T)
}

var tmp3 = Optional<Int>.Nil
// ERROR has no member 'hashvalu' -> tmp3.hashValue
print(tmp3)

var intOpt = Optional.OptValue("vive les poissons")

switch intOpt{
case .Nil:
    print("the value is Nil")
case .firstValue:
    print("the value is the first value")
case .OptValue(let n):
    print("the value is \(n)")
}
