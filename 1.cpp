#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include< conio.h >

#pragma warning( disable : 4996 )

struct birth {
	int year;
	int month;
	int day;
};
struct student
{
	long long num;
	char name[10];
	char sex[10];
	char Class[10];
	struct birth date;
	long long tel;
	float credit;
	struct student* next;
};
typedef struct student *Stu,stu;

//////////////////////////////
int meau();							//输出功能//                                     
void upfile(Stu head);					//新建并保存文件//								
void Back();							//返回主菜单choose()//								
void choose();							//调用各项菜单
void Delete(Stu head);					//删除 输入学号，调用查找函数，调用删除函数//
int Del(Stu h, int n);					//根据节点数删除某项数据//
void create(Stu head);					//读取文件//
void Print(Stu head);					//输出所有数据//
void SiPrint(Stu head,int n);			//输出单个数据//
void Add(Stu head);						//添加若干项学生信息//
int FindAll(Stu head,char name[20]);	//根据NAME或ID（char）查找，返回节点数或-1//
int FindID(Stu head,long long name);	//根据ID（long long）查找，返回节点数或-1//
void Search(Stu head);					//调用以上两个函数
void Change(Stu head);					//更改数据 需要调用查找函数，再调用更改函数
int alter(Stu head, int n);				//根据节点数，更改一条数据
//void IfReinput(Stu head,long long ID);	//查重
/// //////////////////////////
int main()
{
	//system("mode con cols=63 lines=40");
	system("color B5");
	//HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD buf = { 63,400 };
	//SetConsoleScreenBufferSize(con, buf);
	/*while (1)*/ {
		choose();
	}
	return 0;
}
int meau() {
	system("cls");
	printf("-------------------------------------------------------------\n\n");
	printf("------------------->>>学生信息管理系统<<<--------------------\n \n");
	printf("========================系统功能菜单=========================\n");
	printf("-------------------------------------------------------------\n"); printf("               ");
	printf("  +------------------------+\n"); printf("               ");
	printf("  | >>1.查看所有学生信息<< |\n"); printf("               ");
	printf("  +------------------------+\n"); printf("               ");
	printf("  | >>2.修改学生信息    << |\n"); printf("               ");
	printf("  +------------------------+\n"); printf("               ");
	printf("  | >>3.添加学生信息    << |\n"); printf("               ");
	printf("  +------------------------+\n"); printf("               ");
	printf("  | >>4.删除学生信息    << |\n"); printf("               ");
	printf("  +------------------------+\n"); printf("               ");
	printf("  | >>5.查找学生信息    << |\n"); printf("               ");
	printf("  +------------------------+\n"); printf("               ");
	printf("  | >>6.退出系统        << |\n"); printf("               ");
	printf("  +------------------------+\n"); printf("               ");
	printf("  | >>8.退出系统        << |\n"); printf("               ");
	printf("  +------------------------+\n");
	printf("--------------------------------------------------------------\n");
	int GetNum;
	printf("请输入功能对应编号：\n");
	scanf_s("%66d", &GetNum);
	return GetNum;
}
void choose()
{
	int GetNum=meau();
	Stu head = (Stu)malloc(sizeof(stu));
	if(head!=NULL)
	head->next = NULL;
	create(head);
	switch (GetNum)
	{
	case 1:	system("cls"); 
				Print(head); 
				Back(); 
			break;
	case 2:system("cls"); 
				Print(head); 
				Change(head); 
				upfile(head); 
				Back(); 
			break;
	case 3:system("cls"); 
				Add(head); 
				upfile(head); 
				Back(); 
			break;
	case 4:system("cls"); 
				Print(head); 
				Delete(head); 
				upfile(head); 
				Back(); 
			break;
	case 5:system("cls");
				Search(head); 
				Back(); 
			break;
	case 6:; break;
	case 7:; break;
	default: printf("请输入正确的数字！\n"); Sleep(1000); choose(); break;
	}
}
void Back() {
	int i;
	for (i = 0; i < 62; i++)
		printf("-");
	printf("\n按回车键返回");
	i=getche()+getchar();
	choose();
}

void Print(Stu h)
{
	int i=0;
	Stu t = h;
	if (t->next != NULL) {
		printf("   +-----------+--------+----+--------------+------------+------+\n");
		printf("   |   学号    |  姓名  |性别|\t   生日\t    |    电话    | 学分 |\n");
		printf("   +-----------+--------+----+--------------+------------+------+\n");
		while (t->next != NULL)
		{
			t = t->next;
			printf("   |%-11lld|%-8s| %-3s|", t->num, t->name, t->sex);
			printf("%4d年%2d月%2d日|", t->date.year,t->date.month,t->date.day);
			printf("%11lld |%5.1f |\n", t->tel,t->credit);
			printf("   +-----------+--------+----+--------------+------------+------+\n");
			i++;
		}/*system("pause");*/
		printf("\n共%d条\n", i);
	}else {
		printf("暂未录入学生信息,请添加！\n");
		Back();
	}
}
void SiPrint(Stu h, int n) {
	Stu t = h;
	int i;
	if (NULL != t) {
		for (i = 0; i < n; i++) {
			if (t->next != NULL) {
				t = t->next;
			}
		}
		{
			printf("   +-----------+--------+----+--------------+------------+------+\n");
			printf("   |   学号    |  姓名  |性别|\t   生日\t    |    电话    | 学分 |\n");
			printf("   +-----------+--------+----+--------------+------------+------+\n");
			printf("   |%-11lld|%-8s| %-3s|", t->num, t->name, t->sex);
			printf("%4d年%2d月%2d日|", t->date.year, t->date.month, t->date.day);
			printf("%11lld |%5.1f |\n", t->tel, t->credit);
			printf("   +-----------+--------+----+--------------+------------+------+\n");
		}
	}
}
/*删除函数*/
int Del(Stu h, int n)
{
	Stu t = h, t1=NULL;
	int i;
	i = 0;
	while (i < n && t != NULL)
	{
		t1 = t;
		t = t->next;
		i++;
	}if (t != NULL&& t1 != NULL){
		t1->next = t->next;
		free(t);
		return 1;
	}else{
		return -1;
	}
}
void Delete(Stu h) {
	long long ID;
	int n;
	printf(">-请输入要删除的学生学号：\n");
	scanf_s("%lld", &ID);
	n = FindID(h, ID);
	if (n != -1) {
		printf(">>>您将要删除的学生信息如下：\n");
		SiPrint(h, n);
		char p=0;
	ju:printf(">->->是否删除？Y/N\n");
		p = getchar();
		scanf_s("%c", &p,1);
		if (p == 'N' || p == 'n') {
			printf(">->取消删除<-<\n");
				Sleep(1000);
			return;
		}
		else if (p == 'Y' || p == 'y') {
			if (Del(h, n)) {
				printf(">>>>删除成功<<<<\n");
				Print(h);
			}else printf(">>>>未录入该学生<<<<\n");
		}
		else
		{
			printf(">>>请输入正确的字符<<<\n");
			Sleep(1000);
			goto ju;
		}
	}
}
//////////////////////
void create(Stu head)
{
	Stu end, node;
	end = head;
	FILE* fp;
	fp = fopen("student.txt", "r+");
	if (fp == NULL)
	{
		fp = fopen("student.txt", "x");
		return;
	}
	char line[1024];
	int row = 0;
	while (fgets(line, sizeof(line), fp))
	{
		if (line[0] == '\n' || line[0] == '\r')
		{
			break;
		}
		else
		{
			row++;
		}
	}
	fclose(fp);
	int i;
	fp = fopen("student.txt", "r+");
	if (fp == NULL)
		return;
	if (fgetc(fp) != EOF)
	{
		rewind(fp);
		int mmm = 0;
		for (i = 0; !feof(fp) && i < row; i++)
		{
			node = (Stu)malloc(sizeof(stu));
			fscanf_s(fp, "%lld", &node->num);
			fscanf_s(fp, "%s", &node->name, 30);
			fscanf_s(fp, "%s", &node->sex, 5);
			fscanf_s(fp, "%d", &node->date.year);
			fscanf_s(fp, "%d", &node->date.month);
			fscanf_s(fp, "%d", &node->date.day);
			fscanf_s(fp, "%lld", &node->tel);
			fscanf_s(fp, "%f", &node->credit);
			end->next = node;
			end = node;
		}
		end->next = NULL;
	}
	fclose(fp);
}
void Add(Stu head)
{
	int i;
	int n;
	Stu t = head;
	Stu t1;
	while ( NULL != t->next )
	{
		t = t->next;
	}//t为尾部节点
	printf(">-请输入学生信息数量：");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)//每输入一个学生信息即构建一个节点存入
	{

		t1 = (Stu)malloc(sizeof(stu));
		if (t1 != NULL) {
			printf(">>>>学生学号:\n-->");
			scanf_s("%lld", &t1->num);
			printf(">>>>学生姓名:\n-->");
			scanf_s("%s", t1->name, 30);
			printf(">>>>性别:\n-->");
			scanf_s("%s", t1->sex, 5);
			printf(">>>>出生年:\n-->");
			scanf_s("%4d", &t1->date.year);
			printf(">>>>出生月:\n-->");
			scanf_s("%2d", &t1->date.month);
			printf(">>>>出生日:\n-->");
			scanf_s("%2d", &t1->date.day);
			printf(">>>>联系电话:\n-->");
			scanf_s("%lld", &t1->tel);
			printf(">>>>学分\n-->");
			scanf_s("%f", &t1->credit);
			t1->next = t->next;
			t->next = t1;
		}
		else {
			printf(">>>>内存不足<<<<");
		}
	}
}

void upfile(Stu head)
{
	Stu p;
	FILE* fp;
	fp = fopen("student.txt", "w");
	p = head->next;
	while (p != NULL)
	{
		fprintf(fp, "%-11lld    %-10s   %-5s", p->num, p->name, p->sex);
		fprintf(fp, "%4d   %2d   %2d   ",p->date.year,p->date.month,p->date.day);
		fprintf(fp, "%11lld %5.1f\n", p->tel,p->credit);
		p = p->next;
	}
	fclose(fp);
}

int alter(Stu head, int n)
{
	Stu t;
	int i;
	t = head;
	i = 0;
	while (i < n && t != NULL)
	{
		t = t->next;
		i++;
	}
	if (t != NULL)
	{
			printf("学生学号:\n-->");
			scanf_s("%lld", &t->num);
			printf("学生姓名:\n-->");
			scanf_s("%s", t->name, 30);
			printf("性别:\n-->");
			scanf_s("%s", t->sex, 5);
			printf("出生年:\n-->");
			scanf_s("%d", &t->date.year);
			printf("出生月:\n-->");
			scanf_s("%d", &t->date.month);
			printf("出生日:\n-->");
			scanf_s("%d", &t->date.day);
			printf("联系电话:\n-->");
			scanf_s("%lld", &t->tel);
			printf(">>>>学分\n-->");
			scanf_s("%f", &t->credit);
			return 1;
	}
	else
	{
		return -1;
	}
}
void Change(Stu head) {
	long long id;
	char p;
	printf("请输入要更改的学生学号：\n>-->>");//搜索一下，搜索函数返回n,再把n传给alter
	scanf_s("%lld", &id);
	int n = FindID(head, id);
	if (n == -1) {
		printf("\n>>>未录入该学生<<<\n");
		return;
	}
	else
	{


	re:printf("\n>>>请确认要更改以下学生信息(Y/N?)\n>>->");
		SiPrint(head, n);
		p = getchar();
		scanf_s("%c", &p, 1);
		if (p == 'N' || p == 'n') {
			printf(">->取消更改<-<\n");
			Sleep(1000);
			return;
		}
		else if (p == 'Y' || p == 'y') {
			if (alter(head, n)) {
				SiPrint(head, n);
			}
			else printf(">>>>未录入该学生<<<<\n");
		}
		else
		{
			printf(">>>请输入正确的字符<<<\n");
			Sleep(1000);
			goto re;
		}
	}
}
void Search(Stu head) {
	char p[20];
	int n;
	printf("请输入姓名或学号:\n");
	scanf_s("%s", p,20);
	n = FindAll(head, p);
	if (n!=-1) {
		SiPrint(head, n);
	}else printf(">>>>未录入该学生<<<<\n");
}
int FindAll(Stu head, char name[20]) {
	Stu t = head;
	char id[30];
	int i = -1;
	if (NULL != t) {
		t = t->next;
		sprintf_s(id, "%lld", t->num);
		while (strcmp(t->name, name) && strcmp(id, name)) {
			i++;
			sprintf_s(id, "%lld", t->num);
			t = t->next;
			if (NULL == t)
			{
				return -1;
			}
		}return i + 2;
	}return -1;
}

int FindID(Stu head, long long ID) {
	int i = -1;
	Stu t = head->next;
	if (NULL != t) {
		while (ID != t->num) {
			i++;
			if (t->next == NULL)
				return -1;
			else
			t = t->next;
		}
		return i + 2;
	}return -1;
}

