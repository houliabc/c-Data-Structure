#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100

typedef char Elemtype;
//算数表达式转化为后缀表达式的类型
typedef struct{
	Elemtype data[Maxsize];
	int top;
}SqStack;
void initlist(SqStack *&s){
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
void destroylist(SqStack *&s){
	free(s);
}
bool Stackempty(SqStack *s){
	return (s->top==-1);
}
//进栈
bool push(SqStack *&s,Elemtype e){
	if(s->top>Maxsize-1)
	//栈满
		return false;
	s->top++;
	s->data[s->top]=e;
	//上面两句等价于s->data[++s->top]=e;
	return true;
}
//出栈
bool pop(SqStack *&s,Elemtype &e){
	if(s->top==-1){ 
	//栈空
		return false;
	}
	e=s->data[s->top];
	s->top--;
	//等价于e=s->data[s->top--];
	return true;
}
bool gettop(SqStack *s,Elemtype &e){
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	return true;
}


//算数表达式转化为后缀表达式的类型
typedef struct{
	Elemtype data[Maxsize];
	int top;
}SqStack1;
void initlist1(SqStack1 *&s){
	s=(SqStack1 *)malloc(sizeof(SqStack1));
	s->top=-1;
}
void destroylist1(SqStack1 *&s){
	free(s);
}
bool Stackempty1(SqStack1 *s){
	return (s->top==-1);
}
//进栈
bool push1(SqStack1 *&s,double e){
	if(s->top>Maxsize-1)
	//栈满
		return false;
	s->top++;
	s->data[s->top]=e;
	//上面两句等价于s->data[++s->top]=e;
	return true;
}
//出栈
bool pop1(SqStack1 *&s,double &e){
	if(s->top==-1){ 
	//栈空
		return false;
	}
	e=s->data[s->top];
	s->top--;
	//等价于e=s->data[s->top--];
	return true;
}
bool gettop1(SqStack1 *s,Elemtype &e){
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	return true;	
}

void trans(char *exp,char postexp[]){
	char e;
	SqStack * Optr;
	initlist(Optr);
	int i=0;
	while(*exp!='\0')
	{
		switch(*exp)
		{
			case '(':
				push(Optr,'(');
				exp++;  //字符串加1表示下一个字符的地址，即下一个字符
				break;
			case ')':
				pop(Optr,e);
				while(e!='(')
				{
					postexp[i++]=e;
					pop(Optr,e);
				}
				exp++;
				break;
			case '+':
			case '-':
				while(!Stackempty(Optr))
				{
					gettop(Optr,e);
					if(e!='(')
					{
						postexp[i++]=e;
						pop(Optr,e);
					}
					else
						break;
				}
				push(Optr,*exp);
				exp++;
				break;
			case '*':
			case '/':
				while(!Stackempty(Optr))
				{
					gettop(Optr,e);
					if(e=='*'||e=='/')
					{
						postexp[i++]=e;
						pop(Optr,e);
					}
					else
						break;
				}
				push(Optr,*exp);
				exp++; 
				break;
			default:
				while(*exp>='0'&&*exp<='9')
				{
					postexp[i++]=*exp;
					exp++;
				}
				postexp[i++]='#';
		}
	}
	while(!Stackempty(Optr))
	{
		pop(Optr,e);
		postexp[i++]=e;
	}
	postexp[i]='\0';
	destroylist(Optr);
}

double compvalue(char * postexp)
{
	double d,a,b,c,e;
	SqStack1 * Opnd;
	initlist1(Opnd);
	while(*postexp!='/0')
	{
		switch(*postexp)
		{
			case '+':
				pop1(Opnd,a);
				pop1(Opnd,b);
				c=b+a;
				push1(Opnd,c);
				break;
			case '-':
				pop1(Opnd,a);
				pop1(Opnd,b);
				c=b-a;
				push(Opnd,c);
				break;
			case '*':
				pop1(Opnd,a);
				pop1(Opnd,b);
				c=b*a;
				push1(Opnd,c);
				break;
			case '/':
				pop1(Opnd,a);
				pop1(Opnd,b);
				if(a!=0)
				{
					c=b/a;
					push1(Opnd,c);
					break;
				}
				else
				{
					printf("\n\t除零出错!\n");
					exit(0);
				}
				break;
		}
		default:
			{
			d=0;
			while(*postexp>='0'&& *postexp<='9')
			{
				d=10*d+*postexp-'0';
				postexp++;
			}
			push1(Opnd,d);
			break;
			}
		postexp++;
	}
	gettop1(Opnd,e);
	DestroyStack1(Opnd);
	return e;
}
int main
{
	char exp[]="(56-20)/(4+2)";
	char postexp[MaxSize];
	trans(exp,postexp);
	printf("中缀表达式:%s\n",exp);
	printf("后缀表达式:%s\n",postexp);
	printf("表达式的值:%g\n",compvalue(postexp));
}
