//  基础排序算法
//  BasicSortAlgorithm.c
//  BlogCode
//
//  Created by 陈炯 on 2017/5/4.
//  Copyright © 2017年 Jiong. All rights reserved.
//

#include <stdio.h>

// Bubble Sort
void bubbleSort(int array[], int count) {
    
    for (int i = 0; i < count; i++) {
        for (int j = 1; j < count - i; j++) {
            
            if (array[j] < array[j - 1]) {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
}

// Insert Sort
void insertSort(int array[], int count) {
    
    int i, j, k;
    
    for (i = 1; i < count; i++) {
        // 在array[0, i-1]给array[i]上找到合适的位置
        for (j = i - 1; j >= 0; j--) {
            if (array[j] < array[i]) {
                break;
            }
        }
        
        if (j != i - 1) {
            
            int temp = array[i];
            // 将比array[i]大的数据全部后移
            for (k = i - 1; k > j; k--) {
                array[k + 1] = array[k];
            }
            array[k +1] = temp;
        }
    }
}

// Select Sort
void selectSort(int array[], int count) {
    
    for (int i = 0; i < count; i++) {
        
        // 找出最小元素的位置
        int index = i;
        for (int j = i + 1; j < count; j++) {
            
            if (array[j] < array[index]) {
                index = j;
            }
        }
        
        int temp = array[index];
        array[index] = array[i];
        array[i] = temp;
    }
}

// Quick Sort
// 详细版
int quickSortPartition(int array[], int low, int high) {
    
    int i = low, j = high;
    
    // 将第一个元素作为哨兵
    int sentry = array[i];
    
    while (i < j) {
        
        // 从右往左找第一个小于哨兵的元素
        while (i < j && array[j] >= sentry) {
            j--;
        }
        
        if (i < j) {
            array[i] = array[j];
            i++;
        }
        
        // 从左往右找第一个大于哨兵的元素
        while (i < j && array[j] <= sentry) {
            i++;
        }
        
        if(i < j) {
            array[j] = array[i];
            j--;
        }
    }
    
    // 把哨兵放在 i == j 处
    array[i] = sentry;
    
    // 返回哨兵的位置
    return i;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        
        // 分界点
        int partition = quickSortPartition(array, low, high);
        // 递归实现
        quickSort(array, low, partition - 1);
        quickSort(array, partition + 1, high);
    }
}

// 简洁版
void quickSort1(int array[], int low, int high) {
    
    int i, j, temp;
    i = low;
    j = high;
    temp = array[low];
    
    if (low > high) {
        return;
    }
    
    while (i != j) {
        
        // 从右往左找第一个小于哨兵的元素
        while (i < j && array[j] >= temp)
            j--;
        
        if (j > i)
            array[i++] = array[j];
        
        // 从左往右找第一个大于哨兵的元素
        while (i < j && array[i] <= temp)
            i++;
        
        if (j > i)
            array[j--] = array[i];
    }
    
    array[i] = temp;
    quickSort1(array, low, i - 1);
    quickSort1(array, i + 1, high);
}


// Shell Sort
void shellSort(int array[], int count) {
    
    for (int dk = count / 2; dk > 0; dk = dk / 2) { // 增量
        
        // 直接插入排序
        for (int i = 0; i < dk; i++) {
            
            for (int j = i + dk; j < count; j += dk) {
                
                if (array[j] < array[j - dk]) {
                    
                    int temp = array[j];
                    int k = j - dk;
                    
                    while (k >= 0 && array[k] > temp) {
                        
                        array[k +dk] = array[k];
                        k -= dk;
                    }
                    
                    // 每组最前的一个元素为最小的元素
                    array[k + dk] = temp;
                    
                }
            }
        }
    }
}


// Merga Sort
void merge(int array[], int temp[], int low, int middle, int high) {
    
    int i = low, m = middle, j = middle + 1, n = high;
    int k = 0;
    
    // 那个小就把哪个先放入temp中
    while (i <= m && j <= n) {
        
        if (array[i] < array[j]) {
            temp[k++] = array[i];
        } else {
            temp[k++] = array[j];
        }
    }
    
    while (i <= m) {
        temp[k++] = array[i++];
    }
    while (j <= n) {
        temp[k++] = array[j++];
    }
    
    // 将temp的元素复制到array
    for (int i = 0; i < k; k++) {
        array[low + i] = temp[i];
    }
    
}

void mergeSort(int array[], int temp[], int low, int high) {
    
    if (low > high ) {
        return;
    }
    
    int middle = (low + high) / 2;
    mergeSort(array, temp, low, middle); // 递归左边
    mergeSort(array, temp, middle +1, high); // 递归右边
    merge(array, temp, low, middle, high); // 合并
}


// Heap Sort
void adjustMinHeap(int array[], int i, int count) {
    
    int j, temp;
    
    temp = array[i];
    j = i * 2 +1;
    while (j < count) {
        // 找出较小的子节点
        if (j + 1 < count && array[j +1] < array[j])
            j++;
        
        // 若较小节点比父节点大，直接返回；否则调整节点
        if (array[j] >= temp)
            break;
        
        array[i] = array[j]; // 将较小节点设置为父节点
        i = j;
        j = i * 2 +1;
    }
    
    array[i] = temp;
}

void heapSort(int array[], int count) {
    
    // 构造小顶堆
    for (int i = (count - 1) / 2; i >= 0; i--) {
        adjustMinHeap(array, i, count);
    }
    
    for (int i = count - 1; i >= 1; i--) {
        
        // 交换根节点和最末节点
        int temp = array[i];
        array[i] = array[0];
        array[0] =temp;
        
        // 再次构造小顶堆
        adjustMinHeap(array, 0, i);
    }
}












