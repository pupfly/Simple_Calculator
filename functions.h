/*************************************************************************
	> File Name: functions.h
	> Author:普鹏飞 
	> Mail:792570367@qq.com 
	> Created Time: 2014年11月18日 星期二 21时46分56秒
 ************************************************************************/
#include "struct.h"
#include <math.h>
#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

void print_help();//打印帮助信息函数
bool is_empty(p_num_stack top);//判断栈是否为空
bool is_empty(p_opr_stack top);//判断栈是否为空
bool get_top(p_num_stack top, double *num);//获取栈顶元素
bool get_top(p_opr_stack top, char *opr);//获取栈顶元素
bool push(p_num_stack top, double num);//压栈
bool push(p_opr_stack top, char opr);//压栈
bool pop(p_num_stack top, double *num);//出栈
bool pop(p_opr_stack top, char *opr);//出栈
bool init(p_num_stack top);//栈初始化
bool init(p_opr_stack top);//栈初始化
bool destory(p_num_stack top);//销毁栈
bool destory(p_opr_stack top);//销毁栈
bool is_opr(char opr);//判断是否是操作符
bool double_to_str(string &str, double d_number, int PRECISION);//将double数字转换为string
void calculate(double *answer, double tmp1, double tmp2, char opr);//一次计算
bool is_num(char c);//判断是否是数字
double calculator(p_num_stack num_top, p_opr_stack opr_top, string &expression);//前提：表达式无误，无括号
bool has_illegal_char(string expression);//判断是否含有非法字符
bool Is_Expression_Legal(p_opr_stack s, string expression);//判断表达式是否合法
bool manage_plus_decrease(string &expression);//处理粘连的加减号
double manage_calculate(string &expression, bool show , int  precision);//处理含有括号的表达式
double merge_for_ic(double num1, double num2);//自定义的“电阻的并”运算
bool add_priority_for_pow(string &expression);//处理幂运算
#endif
