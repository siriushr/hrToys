//
//  SelectionProblem.cpp
//  myPlayground
//
//  Created by 黄然 on 16/3/21.
//  Copyright © 2016年 黄然. All rights reserved.
//

#include <stdio.h>

void MyInsert(int b[], int k, int target) {
    for (int i = 0; i < k; i++) {
        if (b[i] > target) continue;
        for (int j = k-1; j > i; j--) {
            b[j] = b[j-1];
        }
        b[i] = target;
        break;
    }
}

int SelectionProblem(int* a, int n, int k) {
    int b[k];
    for (int i = 0; i < k; i++) //把前k个数存入数组b
        b[i] = a[i];
    
    //将数组b降序排序
    for (int i = 0; i < k; i++)
        for (int j = 1; j < k-i; j++)
            if (b[j] > b[j-1]) {
                int tmp = b[j];
                b[j] = b[j-1];
                b[j-1] = tmp;
            }
    
    //把剩下的n-k个数与b[k-1]比较，大于b[k-1]的进行插入，小于等于b[k-1]的忽略
    for (int i = k; i < n; i++) {
        if (a[i] > b[k-1]) {
            MyInsert(b, k, a[i]);
        }
    }
    return b[k-1];
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k); //输入n和k
    
    int *a = new int[n]; //输入数组
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int r;
    r = SelectionProblem(a, n, k);
    printf("%d\n", r);
    return 0;
}




