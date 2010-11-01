/*Read a postfix string from the keyboard and convert 
it into an expression tree. Then,

    i) Write a function to "evaluate" the tree
    ii) Write a function to print the tree in inorder
    iii) Write a function to generate assembly code from the tree
*/
#include<stdio.h>
#include<stdlib.h>
struct node *a[20];
int top=-1;
struct node{
	char data;
	struct node *left;
	struct node *right;
};
struct node*new(char data)
{
	struct node *h;

	h=malloc(sizeof(struct node));
	h->data=data;
	h->left=0;
	h->right=0;
	return h;
}
void push(struct node *h)
{
        a[++top]=h;
}

struct node *pop()
{
        return a[top--];
}

void make_tree(char ch)
{
	struct node *h;
	
	h=new(ch);
	h->left=pop();
	h->right=pop();
	push(h);
}
int compute(char d,int l,int r)
{
	switch(d){
        	case '+':return l+r;
                         break;
                case '-':return l-r;
                         break;
                case '*':return l*r;
                         break;
                case '/':return l/r;
                         break;
                }

}
int evaluate(struct node *h)
{
	int r,l;

	if(h==0) return 0;
	l=evaluate(h->left);
	r=evaluate(h->right);
	if(isdigit(h->data))
		return (h->data-'0');
	else
        	return compute(h->data,l,r);

}
print_op(char d)
{
	printf("pop A\npop B\n");
	switch(d){
                case '+':printf("add A,B\n");
                         break;
                case '-':printf("sub A,B\n");
                         break;
                case '*':printf("mul A,B\n");
                         break;
                case '/':printf("div A,B\n");
			break;
                }
	printf("push A\n");
}
void assembly(struct node *h)
{
        if(h==0) return;
        assembly(h->left);
	assembly(h->right);
        if(isdigit(h->data))
                printf("push %d\n",h->data-'0');
        else
		print_op(h->data);
}

main()
{
	char exp[20];
        int i=0;

        scanf("%s",exp);
	while(exp[i]!='\0'){
	if(isdigit(exp[i]))
                        push(new(exp[i]));
                else
                        make_tree(exp[i]);

        i++;
        }
	printf("%d\n",evaluate(a[top]));
	assembly(a[top]);
}
