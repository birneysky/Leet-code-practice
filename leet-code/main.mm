//
//  main.m
//  leet-code
//
//  Created by zhangguang on 16/3/4.
//  Copyright © 2016年 com.github. All rights reserved.
//

#import <Foundation/Foundation.h>

#include "ArraySolution.hpp"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        int array[] = {1,  1,  1,  2,  3, 3,  4,  5  };
        int count = sizeof(array) / sizeof(int);
        vector<int>* num = new vector<int>(array,array + count);
        
        ArraySolution asolution;
        
        long result = 0;
        
//        result = asolution.removeDuplicates1(*num);
//        result = asolution.removeDuplicates2(*num);
//        result = asolution.removeDuplicates3(*num);
        result = asolution.removeDuplicates4(*num);
        NSLog(@"result = %ld",result);
        delete num;
    }
    return 0;
}
