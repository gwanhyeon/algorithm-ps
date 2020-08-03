//
//  부분수열의합1182(bitmask).cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/30.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int arr[21];

int main(void){
    int n,m;
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int ans = 0;
    for(int i=1; i<(1<<n); i++){
        int sum = 0;
        for(int k=0; k<n; k++){
            if(i & (1<<k)){
                sum += arr[k];
            }
        }
        
        if(m == sum){
            ans += 1;
        }
    }
    
    cout << ans << '\n';
    
    
    return 0;
}
