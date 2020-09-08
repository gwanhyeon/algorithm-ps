//
//  next_permutation.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/25.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

bool next_permutation_func(int *a, int n){
    int i = n-1;
    while(i > 0 && a[i-1] >= a[i]){
        i -= 1;
    }
    
    if(i <= 0){
        return false;
    }
    
    int j = n-1;
    
    // 가장 큰 j를 찾는다.
    while(a[j] <= a[i-1]){
        j -= 1;
    }
    swap(a[i-1], a[j]);
    j = n-1;
    
    
    // i < j 큰 부분 모두 swap
    while(i < j){
        swap(a[i], a[j]);
        i += 1;
        j -= 1;
    }
    return true;
    
}
int main(void){
    
    
    return 0;
}
