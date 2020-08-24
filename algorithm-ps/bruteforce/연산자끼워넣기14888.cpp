//
//  연산자끼워넣기14888.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/28.
//  Copyright © 2020 kgh. All rights reserved.
//

/*
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void){
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    vector<int> check;  // 체크 벡터로 next_permutation

    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    for(int i=0; i<4; i++){
        int cnt;
        cin >> cnt;
        for(int j=0; j<cnt; j++){
            check.push_back(i+1);
        }
    }
    
    vector<int> res;
    sort(check.begin(), check.end());
    do {
        
        int ans = 0;
        ans = v[0];
        
        for(int i=1; i<v.size(); i++){
            for(int j=i-1; j<check.size(); j++){
                if(check[j] == 1){
                    ans = ans + v[i];
                    break;
                }else if(check[j] == 2){
                    ans = ans - v[i];
                    break;
                }else if(check[j] == 3){
                    ans = ans * v[i];
                    break;
                }else if(check[j] == 4){
                    if(ans < 0){
                        ans = -ans;
                        ans = ans/v[i];
                        ans = -ans;
                    }else {
                        ans = ans/v[i];
                    }
                    break;
                }
            }
        }
        res.push_back(ans);
    } while (next_permutation(check.begin(), check.end()));
    
    int min = *min_element(res.begin(), res.end());
    int max = *max_element(res.begin(), res.end());
    cout << max << '\n' <<  min << '\n';
    return 0;
}

*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> check;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int plus, minus, multi, div;
    
    cin >> plus >> minus >> multi >> div;
    
    for(int i=0; i<plus; i++){
        check.push_back(1);
    }
    for(int i=0; i<minus; i++){
        check.push_back(2);
    }
    for(int i=0; i<multi; i++){
        check.push_back(3);
    }
    for(int i=0; i<div; i++){
        check.push_back(4);
    }
    
    vector<int> res;
    do {
        int sum = v[0];
        
        for(int i=1; i<n; i++){
            if(check[i-1] == 1){
                sum += v[i];
            }else if(check[i-1] == 2){
                sum -= v[i];
            }else if(check[i-1] == 3){
                sum *= v[i];
            }else if(check[i-1] == 4){
                if(sum < 0){
                    sum = -sum;
                    sum = (sum / v[i]);
                    sum = -sum;
                }else {
                    sum = sum / v[i];
                }
            }
        }
        res.push_back(sum);
    } while (next_permutation(check.begin(), check.end()));

    int max = *max_element(res.begin(), res.end());
    int min = *min_element(res.begin(), res.end());
    
    cout << max << '\n' << min << '\n';
    return 0;
}
    





















