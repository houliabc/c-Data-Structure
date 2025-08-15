#include <stdio.h>
#include <malloc.h>
#define Maxsize 100

//定义结点类型
//共享栈的基本操作需要增加一个形参，指出是对哪个栈进行操作
typedef int Elemtype;
typedef struct{
	Elemtype data[Maxsize];
	//top是左边下标从0开始的栈，top2是右边下标从Maxsize开始的栈
	int top,top2;
}SqStack;

void initlist(SqStack *&s,int n){
	s=(SqStack *)malloc(sizeof(SqStack));
	if (n==1)
		s->top=-1;
	else
		s->top2=Maxsize;
}
void destroylist(SqStack *&s){
	free(s);
}
bool Stackempty(SqStack *s,int n){
	if (n==1)
		return s->top==-1;
	else
		return s->top2==Maxsize;
}
//进栈
bool push(SqStack *&s,Elemtype e,int n){
	if(n==1){
		if(s->top > s->top2-1)
		//栈满
			return false;
		s->top++;
		s->data[s->top]=e;
		//上面两句等价于s->data[++s->top]=e;
	}
	else{
		if(s->top < s->top2-1)
		//栈满
			return false;
		s->top2--;
		s->data[s->top2]=e;
		//上面两句等价于s->data[--s->top2]=e;
	}
	return true;
}
//出栈
bool pop(SqStack *&s,Elemtype &e,int n){
	if (n==1){
		if(s->top==-1){ 
		//栈空
			return false;
		}
		e=s->data[s->top];
		s->top--;
		//等价于e=s->data[s->top--];
	}
	else{
		if(s->top2==Maxsize){ 
		//栈空
			return false;
		}
		e=s->data[s->top2];
		s->top2--;
		//等价于e=s->data[s->top2--];
	}
	return true;
}
bool gettop(SqStack *s,Elemtype &e,int n){
	if(n==1){
		if(s->top==-1)
			return false;
		e=s->data[s->top];
	}
	else{
		if(s->top==Maxsize)
			return false;
		e=s->data[s->top2];
	}
	return true;
}
void displist(SqStack *s,int n){
	if(n==1){
		s->top++;
		while(s->top!=-1)
			printf("%d,",s->data[s->top--]);
	}
	else{
		s->top2++;
		while(s->top2!=Maxsize)
			printf("%d,",s->data[s->top2++]);	
	}
}



int main(){
	int n;
	SqStack *s;
	printf("请输入要对1和2哪个栈进行操作：");
	scanf("%d",&n);
	if((n!=1) && (n!=2)){
		printf("输入错误,程序结束");
		exit(0);
		}
	initlist(s,n);
	for(int i=0;i<10;i++)
		push(s,i,n);
	for(int j=1;j<9;j+=3)
		pop(s,j,n);
	displist(s,n);
	return 0;
}
