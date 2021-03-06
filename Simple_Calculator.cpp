/*************************************************************************
	> File Name: simple_calculator.cpp
	> Author:普鹏飞 
	> Mail:792570367@qq.com 
	> Created Time: 2014年11月15日 星期六 16时17分11秒
 ************************************************************************/

#include "functions.h"

using namespace std;

int main()
{
    operator_stack opr_for_check;
    string expression;
    bool show(false);
    int precision(6);

    init(&opr_for_check);
    
    cout<<"Key in an order or an expression to compute , press \"h\" for help !"<<endl;
    cout<<">>:";

    while(cin>>expression)
    {
        if (expression == "h")
	        print_help();
        else if(expression == "on")
        {
	        show = true;
	        cout<<"Open step by step , it's useful when parenthesis exists !"<<endl;
        }
        else if(expression == "off")
        {
	        show = false;
	        cout<<"Close step by step !"<<endl;
        }
        else if(expression == "p")
        {
	        cout<<"Setting precision...\n"<<"To quit please key in q !"<<endl;
	        string temp, num("0123456789");
	        string::size_type pos(0);
	        cout<<"set precision to:";
	        while(cin>>temp)
	        {
	            if (temp == "q")
                    break;
	            pos = temp.find_first_not_of(num);
	            if(pos != string::npos)
	            {
	                cout<<"Bad input,Only a positive integer will be accepted,Try again!"<<endl;
	                cout<<"set precision to:";
	                 continue;
	            }
	            else
	            {
	                precision = atoi(temp.c_str());
	                cout<<"Precision has been set to "<<precision<<" !"<<endl;
	                break;
	            }
	        }
        }
        else if(expression == "q")
        {
            destory(&opr_for_check);
    	    cout<<"Program Terminated!"<<endl;
	        break;
        }
        else if (!Is_Expression_Legal(&opr_for_check, expression))
        {
            destory(&opr_for_check);
	        cout<<">>:";
    	    continue;
        }
        else
        {
	        manage_plus_decrease(expression);
	        if(show == true)
	            cout<<"Steps: "<<endl;
	        cout<<"answer = "<<manage_calculate(expression, show, precision)<<endl;
        }
        cout<<">>:";
    }
    return 0;
}
