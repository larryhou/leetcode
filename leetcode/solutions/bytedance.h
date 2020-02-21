//
//  bytedance.h
//  leetcode
//
//  Created by larryhou on 2020/2/5.
//  Copyright © 2020 larryhou. All rights reserved.
//

/**
 给定三个字符串a, b, c, 判断c是否可以通过字符串a, b的子串按顺序交错组成.
 例如:
 a: "btdne" b: "yeac" c: "bytedance"
 返回: True
 a: "bytece" b: "dan" c: "bytedance"
 返回: True
 a: "bytec" b: "dan" c: "bytedance"
 返回: False
 a: "byte" b: "danced" c: "bytedance"
 返回: False
 */

#ifndef bytedance_h
#define bytedance_h

#include <stdio.h>
#include <string>
namespace bytedance {
void resolve(int argc, const char * argv[]);
bool resolve_1(std::string a, std::string b, std::string v);
bool resolve_2(std::string a, std::string b, std::string v);
}

#endif /* bytedance_h */
