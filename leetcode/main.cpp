//
//  main.cpp
//  leetcode
//
//  Created by larryhou on 2020/2/4.
//  Copyright © 2020 larryhou. All rights reserved.
//

#include <iostream>
#include "solutions/longest-palindromic-substring.h"
#include "solutions/zigzag-conversion.h"
#include "solutions/bytedance.h"

void resolve(const char *v)
{
//    longest_palindromic_substring::resolve(v);
//    zigzag_conversion::resolve(v);
}

int main(int argc, const char * argv[])
{
    if (argc > 1)
    {
        for (auto i = 1; i < argc; i++)
        {
            printf("# %s\n", argv[i]);
            resolve(argv[i]);
        }
    }
    else
    {
        std::string pipe;
        while (std::getline(std::cin, pipe))
        {
            resolve(pipe.c_str());
        }
    }
    
    bytedance::resolve(argc, argv);
    
    return 0;
}
