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
    std::cout << "[1]" << (resolve_1(argv[1], argv[2], argv[3]) ? "True" : "False") << std::endl;
    std::cout << "[2]" << (resolve_2(argv[1], argv[2], argv[3]) ? "True" : "False") << std::endl;
}

// 理解1：a/b字符串顺序无关，通过自由排列可以组成c字符串
bool bytedance::resolve_1(std::string a, std::string b, std::string v)
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

// 理解2：a/b字符串顺序不能改变，只能交错插入组成c字符串
bool bytedance::resolve_2(std::string a, std::string b, std::string v)
{
    if (a.size() + b.size() != v.size()) {return false;}
    auto x = a.begin();
    auto y = b.begin();
    
    auto cursor = v.begin();
    while (cursor != v.end())
    {
        if (*x != *cursor)
        {
            if (*y != *cursor) {return false;}
            ++y;
        }
        else
        {
            ++x;
        }
        ++cursor;
    }
    
    return true;
}
