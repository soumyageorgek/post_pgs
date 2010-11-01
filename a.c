//Read a postfix string from the keyboard and evaluate it using a stack.
#include <stdio.h>
#include <ctype.h>
int a[20];
int top=-1;

void push(int x)
{
	a[++top]=x;
}

int pop()
{
	return a[top--];
}

void evaluate(char ch)
{
	int n1,n2;

	n1=pop();
        n2=pop();
	switch(ch){
	case '+':push(n1+n2);
		 break;
	case '-':push(n1-n2);
		 break;
	case '*':push(n1*n2);
		 break;
	case '/':push(n1/n2);
		 break;
	}
}
main()
{
	char exp[20];
	int i=0;

	scanf("%s",exp);
	while(exp[i]!='\0'){
		if(isdigit(exp[i]))
			push(exp[i]-'0');
		else{
			evaluate(exp[i]);
		}
	i++;
	}
	printf("Value of expression is %d\n",a[top]);
}
