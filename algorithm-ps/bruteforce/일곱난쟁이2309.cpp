//
//  일곱난쟁이2309.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/21.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int a[9];
int main(void){
    
    int sum = 0;
    int n = 9;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a,a+n);
     
    // 9개중 7개 뽑기
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(sum -a[i] - a[j] == 100){
                for(int k=0; k<n; k++){
                    if(i == k || j == k){
                        continue;
                    }
                    cout << a[k] << '\n';
                    return 0;
                }
            }
        }
    }
    
    
    return 0;
}
