/*************************************************************************
	> File Name: simple_calculator.cpp
	> Author:普鹏飞 
	> Mail:792570367@qq.com 
	> Created Time: 2014年11月15日 星期六 16时17分11秒
 ************************************************************************/
#include "functions.h"

using namespace std;

void print_help()
{
  cout<<"-----------------help---------------------"<<endl;
  cout<<"*Key in h to show this help;"<<endl;
  cout<<"*Key in on to show every step; "<<endl;
  cout<<"*Key in off to close step by step compute;"<<endl;
  cout<<"*Key in p to set precision(Default value : 6);"<<endl;
  cout<<"*Key in q to terminate this program;"<<endl;
  cout<<"*Important tips: "<<endl;
  cout<<"	\"++...\" , \"--...\" and \"+-+-...\" are supported !";
  cout<<"This program will not take numbers begin with the  charactor \".\", it only supports operator \"+ - * /\", accepts parenthesis \" ( )\".Expressions with syntax error also will be refused . Highest precision is equal to size double .Maybe you will come across these circumstance later ,so,just be careful !"<<endl;
  cout<<"Any questions , Mail:792570367@qq.com , Thanks !"<<endl;
  cout<<"-----------------exit---------------------"<<endl;
}

bool is_empty(p_num_stack top)
{
    return (top->next == NULL) ? true : false;
}

bool is_empty(p_opr_stack top)
{
    return (top->next == NULL) ? true : false;
}

bool get_top(p_num_stack top, double *num)
{
    if (!is_empty(top))
    {
        *num = top->next->integer;
        return true;
    }
    return false;
}

bool get_top(p_opr_stack top, char *opr)
{
    if (!is_empty(top))
    {
        *opr = top->next->opr;
        return true;
    }
    *opr = 'e';
    return false;
}

bool push(p_num_stack top, double num)
{
    p_num_stack temp = new number_stack;
    if (temp == NULL)
    return false;
    temp->integer = num;
    temp->next = top->next;
    top->next = temp;
    return true;
}

bool push(p_opr_stack top, char opr)
{
    p_opr_stack temp = new operator_stack;
    if (temp == NULL)
    return false;
    temp->opr = opr;
    temp->next = top->next;
    top->next = temp;
    return true;
}

bool pop(p_num_stack top, double *num)
{
    if (top->next == NULL)
    return false;
    p_num_stack temp = top->next;
    top->next = temp->next;
    *num = temp->integer;
    delete temp;
    return true;
}

bool pop(p_opr_stack top, char *opr)
{
    if (top->next == NULL)
    {
        *opr = 'e';
        return false;
    }
    p_opr_stack temp = top->next;
    top->next = temp->next;
    *opr = temp->opr;
    delete temp;
    return true;
}

bool init(p_num_stack top)
{
    top->next = NULL;
    return true;
}

bool init(p_opr_stack top)
{
    top->next = NULL;
    return true;
}

bool destory(p_num_stack top)
{
    if (top->next == NULL)
    return true;
    p_num_stack temp;
    while(top->next != NULL)
    {
        temp = top->next;
        top->next = temp->next;
        delete temp;
    }
    return true;
}

bool destory(p_opr_stack top)
{
    if (top->next == NULL)
    return true;
    p_opr_stack temp;
    while(top->next != NULL)
    {
        temp = top->next;
        top->next = temp->next;
        delete temp;
    }
    return true;
}

bool is_opr(char opr)
{
    return ((opr == '+') || (opr == '-') || (opr == '*') || (opr == '/') || (opr == '(') || (opr == ')'))? true : false;
}

bool is_num(char c)
{
    return (((c > 47) && (c < 58)) || (c == 46)) ? true : false;
}

bool double_to_str(string &str, double d_number = 0, int PRECISION = 6)
{
    int decpt, sign;
    str = fcvt(d_number, PRECISION, &decpt, &sign);
    if (d_number != 0)
    {
        str.insert(decpt, 1, '.');
        if(sign == 1)
            str.insert(0, 1, '-');
    }
    return true;
}

void calculate(double *answer, double tmp2, double tmp1, char opr)
{
    if(opr == 'e')
        return;
    switch(opr)
    {
        case '+':
            (*answer) = tmp1 + tmp2;
        break;
        case '-':
            (*answer) = tmp1 - tmp2;
        break;
        case '*':
            (*answer) = tmp1 * tmp2;
        break;
        case '/':
            (*answer) = (tmp2 * 1.0) / tmp1;
        break;
        default:break;
    }
}

int find_index(const string &expression)
{
    int index(-1);
    char c;
    operator_stack tmp;
    init(&tmp);
    while(++index < expression.size())
    {
        if(expression[index] == '(')
           push(&tmp, '(');
        else if(expression[index] == ')')
        {
            pop(&tmp, &c);
            if(is_empty(&tmp))
                return index;
        }
    }
    return index;
}

int find_first(const string &expression)
{
        int index(0);
        while(++index < expression.size())
        {
            if(expression[index] == ')')
                return index;
        }
        return index;
 }
 
 bool has_illegal_char(string expression)
{
    int i(0);
    char temp;
    while(i < expression.size())
    {
        temp = expression[i++];
        if((temp < 40) || (temp > 57) || (temp == 44))
        {
            cout<<"Illegal charactor :"<<"\""<<temp<<"\""<<endl;
            return true;
        }
    }
    return false;
}
 
 bool Is_Expression_Legal(p_opr_stack s, string expression)
{
    if(has_illegal_char(expression))
    return false;

    if(expression[0] == '*')
    {
        cout<<"Syntax Error: Begin with charactor \"*\" !"<<endl;
        return false;
    }
    else if(expression[0] == '/')
    {
        cout<<"Syntax Error: Begin with charactor \"/\" !"<<endl;
        return false;
    }
    else if(expression[expression.size() - 1] == '/')
    {
        cout<<"Syntax Error: End  with charactor \"/\" !"<<endl;
        return false;
    }
    else if(expression[expression.size() - 1] == '*')
    {
        cout<<"Syntax Error: End  with charactor \"*\" !"<<endl;
        return false;
    }
    else if(expression[expression.size() - 1] == '+')
    {
        cout<<"Syntax Error: End  with charactor \"+\" !"<<endl;
        return false;
    }
    else if(expression[expression.size() - 1] == '-')
    {
        cout<<"Syntax Error: End  with charactor \"-\" !"<<endl;
        return false;
    }
    
    string::size_type pos = 0;
    
    if((pos = expression.find("*)")) != string::npos)
    {
        cout<<"Syntax Error: Bad use \"*)\""<<endl;
        return false;
    }
    else if((pos = expression.find("/)")) != string::npos)
    {
        cout<<"Syntax Error: Bad use \"/)\""<<endl;
        return false;
    }
    else if((pos = expression.find("+)")) != string::npos)
    {
        cout<<"Syntax Error: Bad use \"+)\""<<endl;
        return false;
    }
    else if((pos = expression.find("-)")) != string::npos)
    {
        cout<<"Syntax Error: Bad use \"-)\""<<endl;
        return false;
    }
    else if((pos = expression.find("()")) != string::npos)
    {
        cout<<"Syntax Error: Bad use \"()\""<<endl;
        return false;
    }
    else if((pos = expression.find("+*")) != string::npos)
    {
        cout<<"Syntax Error: Bad use \"+*\""<<endl;
        return false;
    }
    else if((pos = expression.find("+/")) != string::npos)
    {
        cout<<"Syntax Error: Bad use \"+/\""<<endl;
        return false;
    }
    else if((pos = expression.find("-*")) != string::npos)
    {
        cout<<"Syntax Error: Bad use \"-*\""<<endl;
        return false;
    }
    else if((pos = expression.find("-/")) != string::npos)
    {
        cout<<"Syntax Error: Bad use \"-/\""<<endl;
        return false;
    }
    else if((pos = expression.find("//")) != string::npos)
    {
        cout<<"Syntax Error: Bad use \"//\""<<endl;
        return false;
    }
    else if((pos = expression.find("*/")) != string::npos)
    {
        cout<<"Syntax Error: Bad use \"*/\""<<endl;
        return false;
    }
    else if((pos = expression.find("**")) != string::npos)
    {
        cout<<"Syntax Error: Bad use \"**\""<<endl;
        return false;
    }
    else if((pos = expression.find("/*")) != string::npos)
    {
        cout<<"Syntax Error: Bad use \"/*\""<<endl;
        return false;
    }

    int i = 0;
    char c;

    while(++i != expression.size())
    {
        if((expression[i] == '(') && !is_opr(expression[i - 1]))
        {
            cout<<"Syntax Error: Bad use \""<<expression[i - 1]<<expression[i]<<"\" ! Try to insert an operator(+ - * /) !"<<endl;
            return false;
        }
        else if((expression[i] == ')') && ((i + 1) < expression.size()) && !is_opr(expression[i + 1]))
        {
            cout<<"Syntax Error: Bad use \""<<expression[i]<<expression[i + 1]<<"\" ! Try to insert an operator(+ - * /) !"<<endl;
            return false;
        }
        else if((expression[i] == '.') && (!is_num(expression[i - 1]) || (expression[i - 1] == '.') || !is_num(expression[i + 1]) || (expression[i + 1] == '.')))
        {
            cout<<"Syntax Error: Bad use \""<<expression[i - 1]<<expression[i]<<expression[i + 1]<<"\" ! Try to complete the number !"<<endl;
            return false;
        }
    }

    i = 0;
    while(i != expression.size())
    {
	if (expression[i] == '{' || expression[i] == '[' || expression[i] == '(')
	{
		push(s, expression[i]);
	}
	if (expression[i] == '}' || expression[i] == ']' || expression[i] == ')')
	{
		pop(s, &c);
		switch(expression[i])
		{
		case '}':
			if (c != '{')
			{
				cout<<"Illegal, error }\n";
				return false;
			}
			break;
		case ']':
			if (c != '[')
			{
				cout<<"Illegal, error ]\n";
				return false;
			}
			break;
		case ')':
			if (c != '(')
			{
				cout<<"Syntax error,Unecessary \") !\"\n";
				return false;
			}
			break;
		}
	}
	i++;
	}
	if (is_empty(s))
	{
		//cout<<"Legal\n";
		return true;
	}
    else
    {
        int r(0);
        p_opr_stack s_t = s;
        while(s->next != NULL)
        {
            r++;
            s = s->next;
        }
        cout << "Error: lack of " << r << " \")\" !" << endl;
        destory(s_t);
        return false;
    }
}

bool manage_plus_decrease(string &expression)
{
    int back(0), front(0), i(0);
    while(i < expression.size())
    {
        if(expression[i] == '+')
        {
            back = i, front = i;
            while(expression[++front] == '+');
            front--;
            if(front != back)
            {
                expression.erase(back, front - back);
            }
            if((i + 1) == expression.size())
                return false;
            else if((expression[i + 1] == '-') || ((i > 0) && ((expression[i - 1] == '-') || (expression[i - 1] == '*') || (expression[i - 1] == '/'))))
                expression.erase(back,1);
        }
        i++;
    }
    
    i = 0;
    
    while(i < expression.size())
    {
        if(expression[i] == '-')
        {
            back = i, front = i;
            while(expression[++front] == '-');
            front--;
            if(front != back)
            {
                if((front - back) % 2 == 0)
                    expression.erase(back, front - back);
                else
                {
                    expression.erase(back,front - back + 1);
                    expression.insert(back,1,'+');
                }
            }
            if((i + 1) == expression.size())
                return false;
        }
        i++;
    }
    
    i = 0;
    
    while(i < expression.size())
    {
        if(expression[i] == '+')
        {
            back = i, front = i;
            while(expression[++front] == '+');
            front--;
            if(front != back)
            {
                expression.erase(back, front - back);
            }
            if((i + 1) == expression.size())
                return false;
            else if((expression[i + 1] == '-') || ((i > 0) && ((expression[i - 1] == '-') || (expression[i - 1] == '*') || (expression[i - 1] == '/'))))
                expression.erase(back,1);
        }
        i++;
    }
    return true;
}
 
double calculator(p_num_stack num_top, p_opr_stack opr_top, string &expression)//前提：表达式无误
{
    int index_front(0), index_back(0);
    char t_opr;

    string::size_type m_d;
    bool has_not_plus_dec(false);

    int back(-1), front(-1);
    double answer(0), temp1(0), temp2(0);
    int has_L(0), has_R(0);
    char operate;
    bool is_end(false);
    
    if(((m_d = expression.find("*")) != string::npos) || ((m_d = expression.find("/")) != string::npos))
        has_not_plus_dec = true;

    number_stack number_stack_final;
    operator_stack operator_stack_final;

    init(&number_stack_final);
    init(&operator_stack_final);

    manage_plus_decrease(expression);
    
    while(front != expression.size())
    {
        back = front + 1;
        while((++front != expression.size()) && (!is_opr(expression[front])));
        if(front == expression.size())
            is_end = true;
        string temp_str = expression.substr(back, (front - back));
        if((expression[front] != '(') && (expression[front - 1] != ')'))
        {
            if((front > 0) && (expression[front] == '-') && (is_num(expression[front + 1])) && ((expression[front - 1] == '*') || (expression[front - 1] == '/')))
            {
                while((++front != expression.size()) && (!is_opr(expression[front])));
                temp_str = expression.substr(back, (front - back));
                push(num_top, strtod(temp_str.c_str(),NULL));
                if(front == expression.size())
                    is_end = true;
            }
            else if((front == 0) && (expression[front] == '-'))
	        {
		        while((++front != expression.size()) && (!is_opr(expression[front])));
                temp_str = expression.substr(back, (front - back));
                push(num_top, strtod(temp_str.c_str(),NULL));
                if(front == expression.size())
                    is_end = true;
	        }
            else
                push(num_top, strtod(temp_str.c_str(),NULL));
        }
        if((expression[front] == '+') || (expression[front] == '-'))
        {
            get_top(opr_top, &operate);
            if(operate == '+' || operate == '-')
            {
                if(!has_not_plus_dec)
                {
                    pop(num_top, &temp2);
                    pop(num_top, &temp1);
                    pop(opr_top, &operate);
                    calculate(&answer, temp2, temp1, operate);
                    push(num_top, answer);
                    push(opr_top, expression[front]);
                    continue;
                }
                push(opr_top, expression[front]);
                continue;
            }
            else if(is_empty(opr_top) || expression[front + 1] == '(')
            {
                push(opr_top, expression[front]);
                continue;
            }
            else if((operate == '*') || (operate == '/'))
            {
                pop(num_top, &temp1);
                pop(num_top, &temp2);
                pop(opr_top, &operate);
                calculate(&answer, temp2, temp1, operate);
                push(num_top, answer);
                push(opr_top, expression[front]);
                continue;
            }
        }
        if((expression[front] == '*') || (expression[front] == '/'))
        {
            get_top(opr_top, &operate);
            if((operate == '*') || (operate == '/'))
            {
                pop(num_top, &temp1);
                pop(num_top, &temp2);
                pop(opr_top, &operate);
                calculate(&answer, temp2, temp1, operate);
                push(num_top, answer);
                push(opr_top, expression[front]);
                continue;            
            }
            else if((is_empty(opr_top)) || (operate == '+') || (operate == '-') || (expression[front + 1] == '('))
            {
                push(opr_top, expression[front]);
                continue; 
            }
        }
        else if(is_end || expression[front] == ')')
        {
            if(is_empty(opr_top))
            {
                pop(num_top, &answer);
                destory(num_top);
                destory(opr_top);
                return answer;
            }
            get_top(opr_top,&operate);
            if((operate == '*') || (operate == '/'))
            {
                pop(num_top, &temp1);
                pop(num_top, &temp2);
                pop(opr_top, &operate);
                calculate(&answer, temp2, temp1, operate);
                push(num_top, answer); 
            }
            while(!is_empty(num_top))
            {
                pop(num_top, &temp1);
                push(&number_stack_final, temp1);
            }
            while(!is_empty(opr_top))
            {
                pop(opr_top, &operate);
                push(&operator_stack_final, operate);
            }
            destory(num_top);
            destory(opr_top);
             while((!is_empty(&number_stack_final)) && (!is_empty(&operator_stack_final)))
            {
                pop(&number_stack_final, &temp1);
                pop(&number_stack_final, &temp2);
                pop(&operator_stack_final, &operate);
    //            if(operate == '-')
      //              calculate(&answer, temp1, temp2, operate);
        //        else
                    calculate(&answer, temp2, temp1, operate);
                push(&number_stack_final, answer);
            }
            destory(&number_stack_final);
            destory(&operator_stack_final);
            return answer;
        }
    }
   if(is_empty(opr_top))
    {
        pop(num_top, &answer);
        destory(num_top);
        destory(opr_top);
        return answer;
    }
    get_top(opr_top,&operate);
    if((operate == '*') || (operate == '/'))
    {
        pop(num_top, &temp1);
        pop(num_top, &temp2);
        pop(opr_top, &operate);
        calculate(&answer, temp2, temp1, operate);
        push(num_top, answer); 
    }
    while(!is_empty(num_top))
    {
        pop(num_top, &temp1);
        push(&number_stack_final, temp1);
    }
    while(!is_empty(opr_top))
    {
        pop(opr_top, &operate);
        push(&operator_stack_final, operate);
    }
    destory(num_top);
    destory(opr_top);
    while((!is_empty(&number_stack_final)) && (!is_empty(&operator_stack_final)))
    {
        pop(&number_stack_final, &temp1);
        pop(&number_stack_final, &temp2);
        pop(&operator_stack_final, &operate);
       // if(operate == '-')
         //   calculate(&answer, temp1, temp2, operate);
        //else
            calculate(&answer, temp2, temp1, operate);
        push(&number_stack_final, answer);
    }
    destory(&number_stack_final);
    destory(&operator_stack_final);
    return answer;
}

double manage_calculate(string &expression, bool show, int  precision)
{
    number_stack virtual_bracket;
    number_stack numbers;
    operator_stack operators;

    int front(0), steps(0);
    double back(0);
    string substring, temp, temp_show;

    init(&virtual_bracket);
    init(&numbers);
    init(&operators);
    while(front < expression.size())
    {
        manage_plus_decrease(expression);
        destory(&numbers);
        destory(&operators);
        if(expression[front] == '(')
           push(&virtual_bracket,(double) front);
        else if(expression[front] == ')')
        {
	    steps++;
            pop(&virtual_bracket, &back);
            substring = expression.substr(back + 1, front - back - 1);
	    temp_show = substring;
	  
            expression.erase(back, front - back + 1);
            double_to_str(temp, calculator(&numbers, &operators, substring), precision);
            expression.insert((int)back, temp);
	    if (show == true)
	    {
	      cout<<"<Step "<<steps<<" >:"<<temp_show<<"="<<temp<<endl;
	      cout<<"expression changed to:"<<expression<<endl;
	    }
            front = back - 1;
        }
        front++;
    }
    destory(&numbers);
    destory(&operators);
    manage_plus_decrease(expression);
    return calculator(&numbers, &operators, expression);
}
