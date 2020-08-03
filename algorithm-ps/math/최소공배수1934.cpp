//
//  최소공배수1934.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/20.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int gcd(int a,int b){
    if(b == 0){
        return a;
    }else {
        return gcd(b, a % b);
    }
}
int main(void){
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        int g = gcd(a,b);
        int l = g * (a / g) * (b / g);
        cout << l << '\n';
    }
    

    
    return 0;
}
