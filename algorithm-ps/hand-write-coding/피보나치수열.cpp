//
//  피보나치수열.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/11.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int arr[101];
int fibonachi(int n){
    
    if(n <= 2){
        return 1;
    }
    return fibonachi(n-2) + fibonachi(n-1);
}

int main(void){
    
    int n = 5;

    for(int i=1; i<=n; i++){
        cout << fibonachi(i) << '\n';
        
    }
    
    return 0;
}
