#ifndef _COURSE_H_
#define _COURSE_H_
#include<malloc.h>
#include<string.h>
#include"mystruct.h"
//向课程链表里新增课程
void addcou(Clist *lcou,COUR cou);
//初始化课程信息
void initcouInf(COUR *cou);
//从文件中读取数据
void getcoufromFile(Clist *lcou);
//从键盘读取数据
void getcoufromkeyb(Clist *lcou);
//打印课程信息(指定课程)
void printcouInf(COUR cou);
//打印链表中所有课程信息
void printcou(Clist *lcou);
//按课程编号查找课程信息
int findCou(Clist *lcou,int cno);
//修改课程￥￥￥￥￥￥￥
void changecouInf(Clist *lcou,LinkNode *lstu);
//删除课程
int delcou(Clist *lcou,LinkNode *lstu);
//将信息写回到文件
void writebackFile(Clist *lcou);
//释放
void freeCList(Clist *lcou);
#endif
