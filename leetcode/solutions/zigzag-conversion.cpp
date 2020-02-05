 //
//  zigzag-conversion.cpp
//  leetcode
//
//  Created by larryhou on 2020/2/5.
//  Copyright © 2020 larryhou. All rights reserved.
//

#include "zigzag-conversion.h"
#include <vector>
#include <iostream>

void zigzag_conversion::resolve(const char *v)
{
    const int ROW_COUNT = 8;
    std::vector<std::vector<char>> matrix(ROW_COUNT);
    auto cursor = v;
    auto iter = matrix.begin();
    auto line = true;
    auto column = 0;
    while (*cursor != '\0')
    {
        if (!line)
        {
            iter->push_back(ROW_COUNT - (iter - matrix.begin()) - 1 == column? *cursor++ : 0);
        }
        else
        {
            iter->push_back(*cursor++);
        }
        
        if (++iter == matrix.end())
        {
            iter = matrix.begin();
            if (column + 1 == ROW_COUNT - 1)
            {
                column = 0; line = true;
            }
            else
            {
                line = false;
                ++column;
            }
        }
    }
    
    for (auto r = matrix.begin(); r != matrix.end(); r++)
    {
        for (auto c = r->begin(); c != r->end(); c++)
        {
            std::cout << (*c ? *c : ' ') << ' ' << std::flush;
        }
        std::cout << std::endl;
    }
}
