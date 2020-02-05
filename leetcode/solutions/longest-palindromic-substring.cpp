//
//  longest-palindromic-substring.cpp
//  leetcode
//
//  Created by larryhou on 2020/2/4.
//  Copyright © 2020 larryhou. All rights reserved.
//

#include "longest-palindromic-substring.h"

#include <vector>
#include <iostream>

void longest_palindromic_substring::resolve(const char *v)
{
    std::vector<std::pair<const char *, const char *>> candidates;
    decltype(candidates)::value_type solution = std::make_pair(nullptr, nullptr);
    
    auto iter = v;
    auto num = 0;
    while (*iter != '\0')
    {
        auto s = candidates.rbegin();
        while (s != candidates.rend())
        {
            if (*(s->first - 1) != *(s->second + 1))
            {
                if (!solution.first || s->second - s->first > solution.second - solution.first)
                {
                    memcpy(&solution, &*s, sizeof(solution));
                }
                candidates.erase(s.base() - 1);
            }
            else
            {
                s->first--;
                s->second++;
            }
            ++s;
        }
        
        ++num;
        if (num >= 2)
        {
            auto b1 = iter - 1;
            if (*iter == *b1)
            {
                candidates.emplace_back(std::make_pair(b1, iter));
            }
            
            if (num >= 3)
            {
                auto b2 = b1 - 1;
                if (*iter == *b2)
                {
                    candidates.emplace_back(std::make_pair(b2, iter));
                }
            }
        }
        
        ++iter;
    }
    
    if (candidates.size() > 0)
    {
        for (auto s = candidates.begin(); s != candidates.end(); s++)
        {
            if (!solution.first || s->second - s->first > solution.second - solution.first)
            {
                memcpy(&solution, &*s, sizeof(solution));
            }
        }
    }
    
    if (solution.first)
    {
        iter = solution.first;
        std::cout << '+' << iter - v << " #" << solution.second - solution.first + 1 << ' ';
        while (iter <= solution.second)
        {
            std::cout << *iter++;
        }
        std::cout << std::endl;
    }
    else
    {
        printf("err\n");
    }
}
