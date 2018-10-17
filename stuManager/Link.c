#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include"Link.h"

void addstu(LinkNode *lstu,STUD a)//向链表里新增学生
{
  LinkNode *p;
  LinkNode *s;
  s=(LinkNode*)malloc(sizeof(LinkNode));
  s->stu=a;
  p=lstu;
  while(p->next!=NULL)
  {
	p=p->next;
  }
  p->next=s;
  s->next=NULL;

}
//初始化学生信息
void initstuInf(STUD *stu)
{
	stu=(STUD *)malloc(sizeof(STUD));
}
//从文件中读取数据
void getinffromFile(LinkNode *lstu)
{
	FILE *fp;
	char filepath[20];
	STUD stu;
	int sno;
	char name[15];
	int course[5];
	int count;
	int credit;
	int i,j;
	char str[50];
	initstuInf(&stu);
	printf("输入要读入的文件路径:\n");
	scanf("%s",filepath);
	if((fp=fopen(filepath,"rt"))==NULL)
	{
		printf("找不到%s文件\n",filepath);
        return ;
	}
	while(!feof(fp))
	{
		fscanf(fp,"%d %s",&sno,name);
		stu.sno=sno;
		strcpy(stu.name,name);
		fscanf(fp,"%d",&count);
		stu.count=count;
		for(i=0;i<count;i++)
		{
			fscanf(fp,"%d",&course[i]);
		}
		for(j=0;j<i;j++)
			stu.chosed_class[j]=course[j];
		fscanf(fp,"%d ",&credit);
		stu.credit=credit;
		addstu(lstu,stu);
	}
	fclose(fp);
	sprintf(str,"read student inf from File: %s\n",filepath);
	system("date >> ../log.log");
	system("echo $str >> ../log.log");			
}

//从键盘读取数据
void getinffromkeyb(LinkNode *lstu)
{
	int i,j;
	int n;
	int snum;
	char sname[10];
	int scredit;
    int course[5];
	int count;
	STUD stu;
	char str[50];
	initstuInf(&stu);
	printf("请输入学生个数：\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("输入学生信息\n");
		printf("请输入该学生的学号和姓名\n");
		scanf("%d %s",&snum,sname);
		printf("请输入该学生选课的门数：\n");
		scanf("%d",&count);
		printf("请输入选择课程的编号\n");
		for(j=0;j<count;j++)
		{
			scanf("%d",&course[j]);
		}
		printf("请输入总学分\n");
		scanf("%d",&scredit);
		addstuInf(&stu,snum,sname,course,count,scredit);
		addstu(lstu,stu);	
	}
	sprintf(str,"read student inf from Screen: \n");
	system("date >> ../log.log");
	system("echo $str >> ../log.log");

}

//向学生结构体（链表节点）中添加数据
void addstuInf(STUD *stu,int sno,char name[],int course[],int count,int credit)
{
	int i=0;
	stu->sno=sno;
	strcpy(stu->name,name);
	stu->count=count;
	for(i=0;i<count;i++)
	{
		stu->chosed_class[i]=course[i];
	}
	stu->credit=credit;
}
//打印学生信息（指定学生）
void printstuInf(STUD stu)
{
	int i=0;
	printf("%d %s ",stu.sno,stu.name);
	while(i<stu.count)
	{
		printf("%d ",stu.chosed_class[i]);
		i++;
	}
	printf("%d\n",stu.credit);

}
//打印链表中已有学生信息
void printstu(LinkNode *lstu)
{
	int i;
	if(lstu->next==NULL)
	{
		printf("kongde\n");
		return ;
	}
	while(lstu->next)
	{
		i=0;
		lstu=lstu->next;
		printf("%d %s ",lstu->stu.sno,lstu->stu.name);
		while(i<lstu->stu.count)
		{
			printf("%d ",lstu->stu.chosed_class[i]);
			i++;
		}
		printf("%d\n",lstu->stu.credit);
	}
}
//根据姓名查找学生
int findstu_name(LinkNode *lstu,char name[])
{
	char str[50];
	if(lstu->next==NULL)
	{
	    printf("当前链表为空\n");
		return 0;
	}
	while(lstu->next!=NULL)
	{
		lstu=lstu->next;
		if(strcmp(lstu->stu.name,name)==0)
		{
			printf("找到了！\n");
			printstuInf(lstu->stu);
			sprintf(str," find student inf by name %s \n",name);
	                system("date >> ../log.log");
	       		system("echo $str >> ../log.log");
			return 1;
		}
	}
	if(lstu->next==NULL)
	{
		printf("没有这个学生\n");
		sprintf(str," can't find student inf by name %s \n",name);
	        system("date >> ../log.log");
	      	system("echo $str >> ../log.log");
	}
	
	return 0;
}
//根据学号查找学生
int findstu_sno(LinkNode *lstu,int sno)
{
	if(lstu->next==NULL)
	{
	    printf("当前链表为空\n");
		return 0;
	}
	while(lstu->next!=NULL)
	{
		lstu=lstu->next;
		if(lstu->stu.sno==sno)
		{
			printf("找到了！\n");
			printstuInf(lstu->stu);
			sprintf(str," find student inf by stuNum %d \n",sno);
	                system("date >> ../log.log");
	       		system("echo $str >> ../log.log");
			return 1;
		}
	}
	if(lstu->next==NULL)
	{
		printf("没有这个学生\n");
		sprintf(str," find student inf by stuNum %d \n",sno);
	        system("date >> ../log.log");
	       	system("echo $str >> ../log.log");
	
	}
	return 0;
}
//修改学生信息
void changestuInf(LinkNode *lstu,Clist *lcou)
{
	int ch;
	int cno;
	int count;
	int sno;
	int credit;
	int i;
	int flag=0;
	char stu[50];
	int a;//课程位置标志
	printf("请输入你想修改的学生编号：\n");
	scanf("%d",&sno);
	printf("请选择服务：\n");
	printf("1:新增学习课程\n");
	printf("2:删除已选课程\n");
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("请输入你想添加的课程编号:\n");
		scanf("%d",&cno);
		if(lstu->next==NULL)
		{
			printf("学生链表为空\n");
			
		}
		while(lstu->next!=NULL)
		{
			lstu=lstu->next;
			if(lstu->stu.sno==sno)//找到了这名学生
			{
				printf("找到了该学生\n");
				if(lcou->next==NULL)
				{
					printf("课程链表为空\n");
				}
				
				while(lcou->next!=NULL)
				{
					lcou=lcou->next;
					if(lcou->cou.cno==cno)//找到了要添加的这门课程
					{
						count=lstu->stu.count;
						count++;
						lstu->stu.count+=1;
						lstu->stu.chosed_class[count-1]=cno;
						credit=lcou->cou.credit;
						lstu->stu.credit+=credit;
						flag=1;
						printf("添加成功\n");

					}
				}
						sprintf(str," change student %s inf : add a course \n",lstu->stu.name);
	        				system("date >> ../log.log");
	       					system("echo $str >> ../log.log");
				if(flag==0)
				{
					printf("课程链表没有要该课程\n");
				}
			
			}
		}
	}
	else if(ch==2)
	{
		printf("请输入你想删除的课程编号:\n");
		scanf("%d",&cno);
		if(lstu->next==NULL)
		{
			printf("学生链表为空\n");
		}
		while(lstu->next!=NULL)
		{
			lstu=lstu->next;
			if(lstu->stu.sno==sno)//找到了这名学生
			{
				if(lcou->next==NULL)
				{
					printf("课程链表为空\n");
				}
				while(lcou->next!=NULL)
				{
					lcou=lcou->next;
					if(lcou->cou.cno==cno)//找到了要添加的这门课程
					{
						credit=lcou->cou.credit;
						flag=1;

					}
				}
				if(flag==1)
				{
					count=lstu->stu.count;
					for(i=0;i<count;i++)
					{
						if(lstu->stu.chosed_class[i]==cno)
						{
							lstu->stu.chosed_class[i]=lstu->stu.chosed_class[i+1];
							a=i;
						}
						if(i>a)
						{
							lstu->stu.chosed_class[i]=lstu->stu.chosed_class[i+1];
						}
					}
					lstu->stu.count-=1;
					lstu->stu.credit-=credit;
					
				}
				sprintf(str," change student %s inf : delete a course \n",lstu->stu.name);
	        		system("date >> ../log.log");
	       			system("echo $str >> ../log.log");
				if(flag==0)
				{
					printf("课程链表中没有该课程\n");
				}


			
			}
		}
	}
	else
	{
		printf("错误输入\n");
	}

}
//删除学生
int delstu(LinkNode *lstu,Clist *lcou)//删除成功返回1
{
	LinkNode *p,*q;
	int del_sno;
	int cno;
	int count;
	int i;
	char str[50];
	p=lstu;
	q=lstu->next;
	printf("输入要删除的学生学号：\n");
	scanf("%d",&del_sno);
	if(lstu->next==NULL)
	{
	    printf("当前链表为空\n");
		return 0;
	}
	while(q->next!=NULL)
	{
		if(q->stu.sno==del_sno)//此时q为要删除的学生的那个链表节点
		{
			count=q->stu.count;
			for(i=0;i<count;i++)
			{
				cno=q->stu.chosed_class[i];
				while(lcou->next!=NULL)
				{
					lcou=lcou->next;
					if(lcou->cou.cno==cno)//找到了要修改的课程
					{

						lcou->cou.hadperson--;
						break;
					}
				}
			}
			p->next=q->next;
			printf("删除成功\n");
			sprintf(str," delete student %s  \n",q->stu.name);
	        	system("date >> ../log.log");
	       		system("echo $str >> ../log.log");
			return 1;
		}
		p=p->next;
		q=q->next;
	}
    if(q->next==NULL)
	{
		if(q->stu.sno==del_sno)
		{
			printf("222\n");
			count=q->stu.count;
			for(i=0;i<count;i++)
			{
				cno=q->stu.chosed_class[i];
				while(lcou->next!=NULL)
				{
					lcou=lcou->next;
					if(lcou->cou.cno==cno)//找到了要添加的这门课程
					{
						lcou->cou.hadperson-=1;
						break;
					}
				}
			}
			p->next=NULL;	
			printf("删除成功！\n");
			sprintf(str," delete student %s  \n",q->stu.name);
	        	system("date >> ../log.log");
	       		system("echo $str >> ../log.log");
			return 1;
		}
		else
		{
			printf("链表中没有该学生\n");
		}
	
	}

	return 0;
}
//将信息写回到文件
void writeintoFile(LinkNode *lstu)
{
	FILE *fp;
	int i;
	int count;
	char filepath[20];
	char str[50];
	printf("输入学生信息要保存的文件路径:\n");
	scanf("%s",filepath);
	if((fp=fopen(filepath,"w"))==NULL) 
   	{
       		printf("\n保存失败!");
		return ;
    	}
	while(lstu->next!=NULL)
	{
		lstu=lstu->next;
		fprintf(fp,"%d %s ",lstu->stu.sno,lstu->stu.name);
		count=lstu->stu.count;
		fprintf(fp,"%d ",lstu->stu.count);
		for(i=0;i<count;i++)
		{
			fprintf(fp,"%d ",lstu->stu.chosed_class[i]);
		}
		fprintf(fp,"%d \n",lstu->stu.credit);
	}
	fclose(fp);
	printf("学生信息已保存在%s中!\n",filepath);
	sprintf(str," save  all student info into file %s \n",filepath);
	system("date >> ../log.log");
   	system("echo $str >> ../log.log");

}
void freeList(LinkNode *lstu)
{
	LinkNode *p;
	while(lstu!=NULL)
	{
		p=lstu;
		lstu=lstu->next;
		free(p);
		p=NULL;
	}
}
