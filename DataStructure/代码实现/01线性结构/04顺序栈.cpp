#include <stdio.h>
#include <malloc.h>
#define Maxsize 100

//定义结点类型。可以直接用数组加个下表来表示，不用定义结构体
typedef int Elemtype;
typedef struct{
	Elemtype data[Maxsize];
	int top;
}SqStack;

void initlist(SqStack *&s){
	s=(SqStack *)malloc(sizeof(SqStack));
	//因为传入的是指针型s所以要用->的方式访问
	s->top=-1;
}
void destroylist(SqStack *&s){
//对于用顺序存储实现的即用数组实现的结构释放空间都是直接释放整个，不用逐一释放
	free(s);
}
bool Stackempty(SqStack *s){
	return (s->top==-1);
}
//进栈
bool push(SqStack *&s,Elemtype e){
	if(s->top==Maxsize-1)
	//栈满
		return false;
	//入栈操作：先加后放
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
	//出栈顺序：先出后减
	e=s->data[s->top];
	s->top--;
	//等价于e=s->data[s->top--];
	return true;
}
bool gettop(SqStack *s,Elemtype &e){
	//栈空则取不出
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	return true;
}
void displist(SqStack *s){
	while(s->top!=-1){
		printf("%d,",s->data[s->top--]);
	}
}

//用顺序栈判断字符串是否为对称串
bool symmetry(char str[]){
	Elemtype e; //用来接收退栈的值来与字符串第一位开始比较
	//什么时候需要自己定义结构指针？
	//当题目没给你结构体指针时你需要自行定义并初始化结构
	//或者是你需要自行把数据插进去时，就可以采用
	
	SqStack *s;  //定义顺序栈指针
	initlist(s);
	for(int i=0;str[i]!='\0';i++){
		//先遍历一次字符串，将全部插入栈中
		push(s,str[i]);
	}
	for(int i=0;str[i]!='\0';i++){
		pop(s,e);
		//printf("\n%c,%c。",str[i],e); //测试用
		if(str[i]!=e){
			//题目没要求销毁栈，但是判断已经完成，该栈无用了，故可以销毁掉
			destroylist(s);  
			return false;
		}
	}
	destroylist(s);
	return true;
}

//设计一个算法用来检查圆括号是否配对
bool check(char str[]){
	int i=0;Elemtype e;
	SqStack *s;  //定义顺序栈指针
	initlist(s);
	if(str[i]=='\0'){
		return false;
	}
	
	while(str[i]!='\0'){
		if(str[i]=='(')
			push(s,'(');
		else if(str[i]==')'){
			gettop(s,e);
			if(e=='('){
				pop(s,e);
				e='\0';  //用完e临时变量后清空
			}
			else
				return false;
		}
		i++;
	}
	if(Stackempty(s)==1)
		return true;
	else
		return false;
}


int main(){
	char a[]="abcddcba",b[]="((5+4)*3)";
	SqStack *s;
	initlist(s);
	for(int i=0;i<=10;i++)
		push(s,i);
	for(int j=1;j<9;j+=3)
		pop(s,j);
	displist(s);
	printf("\n对称串：%d\n",symmetry(a));
	printf("括号匹配：%d\n",check(b));
	return 0;
}
