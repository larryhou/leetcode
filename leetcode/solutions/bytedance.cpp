//
//  bytedance.cpp
//  leetcode
//
//  Created by larryhou on 2020/2/5.
//  Copyright © 2020 larryhou. All rights reserved.
//

#include "bytedance.h"
#include <iostream>
#include <vector>

void bytedance::resolve(int argc, const char * argv[])
{
    if (argc < 4) {return;}
    std::cout << (resolve(argv[1], argv[2], argv[3]) ? "True" : "False") << std::endl;
}

bool bytedance::resolve(std::string a, std::string b, std::string v)
{
    if (a.size() + b.size() != v.size()) {return false;}
    std::vector<char> concat(a.begin(), a.end());
    concat.insert(concat.end(), b.begin(), b.end());
    std::sort(concat.begin(), concat.end(), [](const char x, const char y)
         {
             return x < y;
         });
    std::vector<char> target(v.begin(), v.end());
    std::sort(target.begin(), target.end(), [](const char x, const char y)
         {
             return x < y;
         });
    auto t = target.begin();
    for (auto i = concat.begin(); i != concat.end(); i++)
    {
        if (*i != *t++) {return false;}
    }
    return true;
}
