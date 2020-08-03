//
//  유클리드호제법.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/20.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

// 재귀 O
int greaterCommonDivisor(int a,int b){
    if(b == 0){
        return a;
    }else {
        return greaterCommonDivisor(b, a % b);
    }
}
// 재귀 X
int greaterCommonDivisor2(int a,int b){
    while(b == 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// LCM

int main(void){
    int a,b;
    cin >> a >> b;
    
    int g = greaterCommonDivisor(a,b);
    cout << g << '\n';
    int l = g * (a / g) * ( b / g);
    // LCM least Common Multiple
    cout << l;
    
    return 0;
}
