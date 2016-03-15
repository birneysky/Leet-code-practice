//
//  main.m
//  leet-code
//
//  Created by zhangguang on 16/3/4.
//  Copyright © 2016年 com.github. All rights reserved.
//

#import <Foundation/Foundation.h>

#include "ArraySolution.hpp"
#include "ArraySolution1.hpp"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        for (int i = 0 ; i < argc; i++) {
            NSLog(@"arg%d = %s",i,argv[i]);
        }
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
        
        ArraySolution1 searchSolution;
        int searchArray[] = {0,  1,  2,  3,  4, 5,  6,  7  };
        int searchCount = sizeof(searchArray) / sizeof(int);
        vector<int>* searchNums = new vector<int>(searchArray,searchArray + searchCount);

        searchSolution.search(*searchNums, 2);
        
        int searchArray1[] = {7,  6,  5,  4,  3, 2,  1,  0  };
        int searchCount1 = sizeof(searchArray) / sizeof(int);
        vector<int>* searchNums1 = new vector<int>(searchArray1,searchArray1 + searchCount1);
        searchSolution.search(*searchNums1, 2);
        
        delete num;
    }
    return 0;
}
