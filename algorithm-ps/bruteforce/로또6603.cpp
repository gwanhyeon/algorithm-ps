//
//  로또6603.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/27.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    
    
    while(true){
        
        int n=0;
        cin >> n;
        vector<int> arr(n);
        vector<int> check;
        

        if(n == 0){
            break;
        }
        
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        for(int i=0; i<n-6; i++){
            check.push_back(0);
        }
        for(int i=0; i<6; i++){
            check.push_back(1);
        }
        sort(arr.begin(), arr.end());
        vector<vector<int>> v;
        do {
            vector<int> curr;
            for(int i=0; i<n; i++){
                if(check[i] == 1){
                    curr.push_back(arr[i]);
                }
            }
            v.push_back(curr);
        }while(next_permutation(check.begin(), check.end()));
        
        sort(v.begin(), v.end());
        
        for(auto &a : v){
            for(int i=0; i<a.size(); i++){
                cout << a[i] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
      
    }
    return 0;
}
