//
//  로또6603.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/27.
//  Copyright © 2020 kgh. All rights reserved.
//

/*
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
 */

// 8/19일 복습 next_permutation
/*
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int main(void){
    while(true){
        int n;
        cin >> n;
        vector<int> v(n);
        vector<bool> check;
        
        if(n == 0){
            break;
        }
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        for(int i=0; i<n-6; i++){
            check.push_back(false);
        }
        for(int i=0; i<6; i++){
            check.push_back(true);
        }
        vector<vector<int>> res;
        sort(v.begin(), v.end());
        do {
            vector<int> curr;
            for(int i=0; i<n; i++){
                if(check[i] == true){
                    curr.push_back(v[i]);
                }
            }
            res.push_back(curr);
            
        } while (next_permutation(check.begin(), check.end()));
        
        sort(res.begin(), res.end());
        for(auto &a : res){
            for(int i=0; i<a.size(); i++){
                cout << a[i] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
}
*/
// recursive 백트래킹 8.20
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
using namespace std;
int n;
int check[13];
vector<int> res;
void dfs(int idx, int cnt, vector<int> v){
    // basement
    if(cnt == 6){
        for(int i=0; i<res.size(); i++){
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=idx; i<v.size(); i++){
        if(check[i] == true){
            continue;
        }
        check[i] = true;
        res.push_back(v[i]);
        dfs(i, cnt+1, v);
        check[i] = false;
        res.pop_back();
    }
    
}

int main(void){
    /*
    7 1 2 3 4 5 6 7
    8 1 2 3 5 8 13 21 34
    0
    */
    
    
    while(true){
        n = 0;
        cin >> n;
        vector<int> v(n);
        if(n == 0){
            break;
        }
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        dfs(0,0,v);
        cout << '\n';
        v.clear();
        memset(check,0,sizeof(check));
    }
    
    return 0;
}



