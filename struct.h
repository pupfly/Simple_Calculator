/*************************************************************************
	> File Name: struct.h
	> Author:普鹏飞 
	> Mail:792570367@qq.com 
	> Created Time: 2014年11月18日 星期二 21时46分06秒
 ************************************************************************/

#ifndef _STRUCT_H
#define _STRUCT_H
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

typedef struct number_stack
{
    double integer;
    number_stack *next;
}number_stack, *p_num_stack;

typedef struct operator_stack
{
    char opr;
    operator_stack *next;
}operator_stack, *p_opr_stack;
#endif
