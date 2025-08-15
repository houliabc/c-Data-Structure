#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#define Maxsize 100

//定义结点类型
typedef char Elemtype;
typedef struct linknode{
	Elemtype data;
	struct linknode *next;
}LinkStNode;

void initlist(LinkStNode *&s){
	s=(LinkStNode *)malloc(sizeof(LinkStNode));
	s->next=NULL;
}
void destroylist(LinkStNode *&s){
	linknode *p=s->next,*q=s;
	//销毁链表并不需要使头指针一直指向删除后的剩下的结点
	while(p!=NULL){  //p为NULL时，q为尾节点
		free(q);
		q=p;  //指向删除节点的下一个节点
		p=p->next;
	}
	free(q);  //一个个释放节点
}
bool Stackempty(LinkStNode *s){
	return (s->next==NULL);
}
//因为链栈不会满，所以不用判定是否满了，所以用void
void push(LinkStNode *&s,Elemtype e){
	LinkStNode *p=(LinkStNode *)malloc(sizeof(linknode));
	p->data=e;
	p->next=s->next;
	s->next=p;
}
bool pop(LinkStNode *&s,Elemtype &e){
	if(s->next==NULL)
		return false;
	linknode *p=s->next;
	e=p->data;
	s->next=p->next;
	free(p);
	return true;
}
bool gettop(LinkStNode *&s,Elemtype &e){
	if(s->next==NULL)
		return false;
	e=s->next->data;
	return true;
}

void displist(LinkStNode *s){
	linknode *p=s->next;
	while(p!=NULL){
		printf("%d,",p->data);
		p=p->next;
	}
}

//设计一个算法用来检查圆括号是否配对
bool match(Elemtype str[]){
	int i=0;Elemtype e;
	LinkStNode *s;  //定义顺序栈指针
	initlist(s);
	if(str[i]=='\0'){
		return false;
	}
	
	while(str[i]!='\0'){
		if(str[i]=='('){
			push(s,'(');
		}
		else if(str[i]==')'){
			if(gettop(s,e)!=0){
				pop(s,e);
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

//设计一个算法用来检查所有括号是否配对
bool match2(Elemtype str[]){
	int i=0;Elemtype e;
	LinkStNode *s;  //定义顺序栈指针
	initlist(s);
	if(str[i]=='\0')
		return false;
	while(str[i]!='\0'){
		if((str[i]=='(' || str[i]=='[') || str[i]=='{')
			push(s,str[i]);
		else if((str[i]==')' || str[i]==']') || str[i]=='}'){
			gettop(s,e);
			if((e=='(' && str[i]==')') || (e=='[' && str[i]==']') || (e=='{' && str[i]=='}'))
				pop(s,e);
			else
				return false;
		}
		i++;
	}
	if(Stackempty(s)==1)
		return true;
	else
		//printf("\n测试3\n");
		return false;
}

int main(){
	char str[]="(3+2)*2=10",str2[]="char[5]=(1+1)=2={2})";
	LinkStNode *s;
	initlist(s); 
	for(int i=1;i<=10;i++){
		push(s,i);
	}
	displist(s);
	
	//1表示匹配，0表示不匹配
	printf("\n圆括号匹配吗：%d",match(str));
	printf("\n所有扩号匹配吗：%d",match2(str2));
	return 0;
}
