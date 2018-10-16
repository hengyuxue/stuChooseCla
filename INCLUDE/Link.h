#ifndef _LINK_H_
#define _LINK_H_
#include<malloc.h>
#include"mystruct.h"

//向链表里新增学生
void addstu(LinkNode *lstu,STUD a);
//初始化学生信息
void initstuInf(STUD *stu);
//从文件中读取数据？？？？？？？？？
void getinffromFile(LinkNode *lstu);
//从键盘读取数据
void getinffromkeyb(LinkNode *lstu);
//向学生结构体（链表节点）中添加数据
void addstuInf(STUD *stu,int sno,char name[],int course[],int count,int credit);
//打印学生信息（指定学生）
void printstuInf(STUD stu);
//打印链表中已有学生信息
void printstu(LinkNode *lstu);
//根据姓名查找学生
int findstu_name(LinkNode *lstu,char name[]);
//根据学号查找学生
int findstu_sno(LinkNode *lstu,int sno);
//修改学生信息￥￥￥￥￥￥￥￥￥￥
void changestuInf(LinkNode *lstu,Clist *lcou);
//删除学生
int delstu(LinkNode *lstu,Clist *lcou);
//将信息写回到文件》》》》》》》》》
void writeintoFile(LinkNode *lstu);
//释放
void freeList(LinkNode *lstu);
#endif

