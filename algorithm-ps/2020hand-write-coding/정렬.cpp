//
//  정렬.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/13.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
int arr[10] = {4,2,6,1,5};

void swap(int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
// 선택 정렬
void insertion_sort(int size){
    int index = 0;
    for(int i=0; i<size-1; i++){
        index = i;
        
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[index]){
                index = j;
            }
        }
        swap(arr[i],arr[index]);
    }
    
}

// 삽입 정렬
void selection_sort(int size){
    int key = 0;
    int j =0;
    for(int i=1; i<size; i++){
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];      //복사
            j--;
        }
        arr[j+1] = key;
    }
}

// 버블 정렬
void bubble_sort(int size){
    for(int i=size-1; i>0; i--){
        for(int j=0; j<i; i++){
            if(arr[j] < arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(void){
    bubble_sort(5);
    selection_sort(5);
    insertion_sort(5);
    
    
    return 0;
}
