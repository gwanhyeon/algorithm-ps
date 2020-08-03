//
//  나머지10430.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/20.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    int a,b,c;
    cin >> a >> b >> c;
    
    cout << (a + b) % c << '\n';
    cout << ((a % c) + (b % c)) % c << '\n';;
    cout << (a * b) % c << '\n';
    cout << ((a % c) * (b % c)) % c;
    
    return 0;
}
