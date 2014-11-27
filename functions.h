/*************************************************************************
	> File Name: functions.h
	> Author:普鹏飞 
	> Mail:792570367@qq.com 
	> Created Time: 2014年11月18日 星期二 21时46分56秒
 ************************************************************************/
#include "struct.h"
#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

void print_help();
bool is_empty(p_num_stack top);
bool is_empty(p_opr_stack top);
bool is_empty(p_opr_stack top);
bool get_top(p_num_stack top, double *num);
bool get_top(p_opr_stack top, char *opr);
bool push(p_num_stack top, double num);
bool push(p_opr_stack top, char opr);
bool pop(p_num_stack top, double *num);
bool pop(p_opr_stack top, char *opr);
bool init(p_num_stack top);
bool init(p_opr_stack top);
bool destory(p_num_stack top);
bool destory(p_opr_stack top);
bool is_opr(char opr);
bool double_to_str(string &str, double d_number, int PRECISION);
void calculate(double *answer, double tmp1, double tmp2, char opr);
int find_index(const string &expression);
int find_first(const string &expression);
int find_first(const string &expression, int begin, char c = '(');
bool is_num(char c);
double calculator(p_num_stack num_top, p_opr_stack opr_top, string &expression);//前提：表达式无误
bool has_illegal_char(string expression);
bool Is_Expression_Legal(p_opr_stack s, string expression);
bool manage_plus_decrease(string &expression);
double manage_calculate(string &expression, bool show , int  precision);
double merge_for_ic(double num1, double num2);
double manage_pow(string &expression);
#endif
