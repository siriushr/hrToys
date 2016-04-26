//
//  PrintDigit.cpp
//  myPlayground
//
//  Created by 黄然 on 16/3/21.
//  Copyright © 2016年 黄然. All rights reserved.
//

#include <stdio.h>

void PrintOut(int i) {
    printf("%d", i);
}

int PrintDigit(int i) {
    if (0 <= i && i <= 9) {
        PrintOut(i);
        return 1;
    }
    if (-9 <= i && i < 0) {
        PrintOut(i);
        return -1;
    }
    int r = PrintDigit(i/10);
    if (r == -1) {
        PrintOut(-i%10);
    } else {
        PrintOut(i%10);
    }
    return r;
}

int main() {
    int i;
    scanf("%d", &i);
    PrintDigit(i);
    printf("\n");
    return 0;
}