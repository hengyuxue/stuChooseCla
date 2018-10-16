#ifndef _MYSTRUCT_H_
#define _MYSTRUCT_H_
typedef struct course
{
	int cno;
	char cname[10];
	char cquality[10];
	int period;
	int credit;
	int hadperson;
	int maxsum;

}COUR;
typedef struct courselist
{
	COUR cou;
	struct courselist *next;
}Clist;
typedef struct student
{
	int sno;
	char name[10];
	int count;//选择的课程数
	int chosed_class[5];
    int credit;
}STUD;
typedef struct LNode
{
	STUD stu;
	struct LNode *next;
}LinkNode;
#endif
