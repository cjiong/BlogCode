//  基础查找算法
//  BasicSearchAlgorithm.c
//  BlogCode
//
//  Created by 陈炯 on 2017/5/8.
//  Copyright © 2017年 Jiong. All rights reserved.
//

#include <stdio.h>

// OrderSearch

int orderSearch(int array[], int num, int count) {
    
    int index = -1;
    
    for (int i = 0; i < count; i++) {
        if (array[i] == num) {
            index = i;
            break;
        }
    }
    
    return index;
}

// BinarySearch

// 非递归版
int binarySearch(int array[], int num, int low, int high) {
    
    int index = -1;
    
    while (low <= high) {
        
        int middle = (low + high)/2;
        
        if (array[middle] == num) {
            return middle;
            
        } else if (array[middle] > num) {
            high = middle -1;
            
        } else {
            low = middle +1;
        }
    }
    
    return index;
}


// 递归版
int binarySearch1(int array[], int num, int low, int high) {
    
    int middle = (low + high)/2;
    
    if (array[middle] == num) {
        return middle;
        
    } else if (array[middle] > num) {
        return binarySearch1(array, num, low, middle - 1);
        
    } else {
        return binarySearch1(array, num, middle + 1, high);
    }
    
}


// InsertSearch
int insertSearch(int array[], int num, int low, int high) {
    
    int middle = low + (num - array[low])/(array[high] - array[low]) * (high - low);
    
    if (array[middle] == num) {
        return middle;
        
    } else if (array[middle] > num) {
        return binarySearch1(array, num, low, middle - 1);
        
    } else {
        return binarySearch1(array, num, middle + 1, high);
    }
    
}


















