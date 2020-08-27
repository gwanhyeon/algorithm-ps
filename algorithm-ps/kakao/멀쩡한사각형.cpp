//
//  멀쩡한사각형.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/27.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int gcd(int w,int h){
    
    if(h == 0){
        return w;
    }
    
    return gcd(h, w % h);
}
int main(void){
    long long w = 8;
    int h = 12;
    
    int gcd_num = gcd(w,h);
    long long sqaure_area = (long long)w * (long long)h;
    
    long long answer = sqaure_area - ((long long)w + (long long)h - gcd_num);
    cout << answer;
   
    return 0;
}
