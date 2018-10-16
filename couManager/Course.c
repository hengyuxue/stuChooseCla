#include<stdio.h>
#include"Course.h"
//向课程链表里新增课程
void addcou(Clist *lcou,COUR cou)
{
  Clist *p;
  Clist *s;
  s=(Clist*)malloc(sizeof(Clist));
  s->cou=cou;
  p=lcou;
  while(p->next!=NULL)
  {
	p=p->next;
  }
  p->next=s;
  s->next=NULL;
}
//初始化课程信息
void initcouInf(COUR *cou)
{
	cou=(COUR *)malloc(sizeof(COUR));
}
//从文件中读取数据
void getcoufromFile(Clist *lcou)
{
	FILE *fp;
	char filepath[20];
	COUR cou;
	int cno;
	char cname[10];
	char cquality[10];
	int period;
	int credit;
	int hadperson;
	int maxsum;
	initcouInf(&cou);
	printf("输入要读入的文件路径:\n");
	scanf("%s",filepath);
	if((fp=fopen(filepath,"rt"))==NULL)
	{
		printf("找不到%s文件\n",filepath);
        return ;
	}
	while(!feof(fp))
	{
		fscanf(fp,"%d %s %s %d %d %d %d ",&cno,cname,cquality,&period,&credit,&hadperson,&maxsum);
		cou.cno=cno;
		strcpy(cou.cname,cname);
		strcpy(cou.cquality,cquality);
		cou.period=period;
		cou.credit=credit;
		cou.hadperson=hadperson;
		cou.maxsum=maxsum;
		addcou(lcou,cou);
	}
	fclose(fp);
}
//从键盘读取数据
void getcoufromkeyb(Clist *lcou)
{
	int i;
	int n;
	int cno;
	char cname[10];
	char cquality[10];
	int period;
    int credit;
	int hadperson;
	int maxsum;
	COUR cou;
	initcouInf(&cou);
	printf("请输入课程个数：\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("输入课程信息\n");
		printf("课程号、课程名、课程性质、授课学时、学分、已选人数、人数上限\n");
		scanf("%d %s %s %d %d %d %d",&cno,cname,cquality,&period,&credit,&hadperson,&maxsum);
		cou.cno=cno;
		strcpy(cou.cname,cname);
		strcpy(cou.cquality,cquality);
		cou.period=period;
		cou.credit=credit;
		cou.hadperson=hadperson;
		cou.maxsum=maxsum;
		
		addcou(lcou,cou);	
	}
}
//打印课程信息(指定课程)
void printcouInf(COUR cou)
{
	printf("%d %s %s %d %d %d %d\n",cou.cno,cou.cname,cou.cquality,cou.period,cou.credit,cou.hadperson,cou.maxsum);
}
//打印链表中所有课程信息
void printcou(Clist *lcou)
{
	if(lcou->next==NULL)
	{
		printf("此链表为空\n");
		return ;
	}
	while(lcou->next)
	{
		lcou=lcou->next;
		printf("%d %s %s %d %d %d %d\n",lcou->cou.cno,lcou->cou.cname,lcou->cou.cquality,lcou->cou.period,lcou->cou.credit,lcou->cou.hadperson,lcou->cou.maxsum);
	}
}
//按课程编号查找课程信息
int findCou(Clist *lcou,int cno)
{
	if(lcou->next==NULL)
	{
	    printf("当前链表为空\n");
		return 0;
	}
	while(lcou->next!=NULL)
	{
		lcou=lcou->next;
		if(lcou->cou.cno==cno)
		{
			printf("找到了！\n");
			printcouInf(lcou->cou);
			return 1;
		}
	}
	if(lcou->next==NULL)
	{
		printf("没有这个学生\n");
	
	}
	return 0;
}
//修改课程￥￥￥￥￥￥￥
void changecouInf(Clist *lcou,LinkNode *lstu)
{
	int cno;
	int choice;
	char cquality[10];
	int period;
	int credit;
	int oldcredit;
	int maxsum;
	int count;
	int i;
	printf("请选择要修改的课程\n");
	scanf("%d",&cno);
	while(lcou->next!=NULL)
	{
		lcou=lcou->next;
		if(lcou->cou.cno==cno)//找到要修改的课程
		{
			printf("请选择服务：\n");
			printf("1:修改课程性质\n");
			printf("2:修改授课学时\n");
			printf("3:修改学分\n");
			printf("4:修改课程人数上限\n");
			scanf("%d",&choice);
			if(choice==1)
			{
				printf("请输入修改后的课程性质\n");
				scanf("%s",cquality);
				strcpy(lcou->cou.cquality,cquality);
				printf("修改成功\n");
			}
			else if(choice==2)
			{
				printf("请输入修改后的授课学时\n");
				scanf("%d",&period);
				lcou->cou.period=period;
				printf("修改成功\n");
			}
			else if(choice==3)
			{
				printf("请输入修改后的学分\n");
				scanf("%d",&credit);
				oldcredit=lcou->cou.credit;
				while(lstu->next!=NULL)
				{
					lstu=lstu->next;
					count=lstu->stu.count;
					for(i=0;i<count;i++)
					{
						if(lstu->stu.chosed_class[i]==cno)
						{
							lcou->cou.credit=credit;
							lstu->stu.credit-=oldcredit;
							lstu->stu.credit+=credit;
							printf("修改成功\n");
						}
						
					}

				}
			}
			else if(choice==4)
			{
				printf("请输入修改后的课程人数上限\n");
				scanf("%d",&maxsum);
				lcou->cou.maxsum=maxsum;
				printf("修改成功\n");
			}

		}
	}
}
//删除课程
int delcou(Clist *lcou,LinkNode *lstu)
{
	Clist *p,*q;
	int del_cno;
	int count;
	int credit;
	int a;
	int flag=0;
	int i;
	p=lcou;
	q=lcou->next;
	printf("输入要删除的课程编号：\n");
	scanf("%d",&del_cno);
	if(lcou->next==NULL)
	{
	    printf("课程链表为空\n");
		return 0;
	}
	while(q->next!=NULL)
	{
		if(q->cou.cno==del_cno)//q为要删除的链表节点
		{
			credit=q->cou.credit;
			p->next=q->next;//删除q节点
			while(lstu->next!=NULL)
			{
				lstu=lstu->next;
				count=lstu->stu.count;
				for(i=0;i<count;i++)
				{
					if(lstu->stu.chosed_class[i]==del_cno)//该学生选了这门课
					{
						lstu->stu.chosed_class[i]=lstu->stu.chosed_class[i+1];
						a=i;
						flag=1;
					}
					if(i>a)
					{
						lstu->stu.chosed_class[i]=lstu->stu.chosed_class[i+1];
					}
					
				}
				if(flag==1)
				{
					lstu->stu.count-=1;
					lstu->stu.credit-=credit;
					printf("删除成功！\n");
                }
			}
			if(flag==0)
			{
				printf("没有人选该门课程\n");
			}
		}
		p=p->next;
		q=q->next;
	}
	if(q->next==NULL)
	{
		if(q->cou.cno==del_cno)
		{	
			credit=q->cou.credit;
			p->next=NULL;
			while(lstu->next!=NULL)
			{
				lstu=lstu->next;
				count=lstu->stu.count;
				for(i=0;i<count;i++)
				{
					if(lstu->stu.chosed_class[i]==del_cno)
					{
						lstu->stu.chosed_class[i]=lstu->stu.chosed_class[i+1];
						a=i;
						flag=1;
					}
					if(i>a)
					{
						lstu->stu.chosed_class[i]=lstu->stu.chosed_class[i+1];
					}
					
				}
				if(flag==1)
				{
					lstu->stu.count-=1;
					lstu->stu.credit-=credit;
					printf("删除成功！\n");
                }
				if(flag==0)
				{
					printf("没有人选该门课程\n");
				}
			}
			if(flag==0)
			{
				printf("没有人选该门课程\n");
			}
			
		}
		else
		{
			printf("链表中没有该课程\n");
		}
	
	}

	return 0;
}
//将信息写回到文件
void writebackFile(Clist *lcou)
{
	FILE *fp;
	char filepath[20];
	printf("输入课程信息要保存的文件路径:\n");
	scanf("%s",filepath);
	if((fp=fopen(filepath,"w"))==NULL) 
    {
        printf("\n保存失败!");
		return ;
    }
	while(lcou->next!=NULL)
	{
		lcou=lcou->next;
		fprintf(fp,"%d %s %s %d %d %d %d\n",lcou->cou.cno,lcou->cou.cname,lcou->cou.cquality,lcou->cou.period,lcou->cou.credit,lcou->cou.hadperson,lcou->cou.maxsum);
	}
	fclose(fp);
	printf("课程信息已保存在%s中!\n",filepath);
}
//释放
void freeCList(Clist *lcou)
{
	Clist *p;
	while(lcou!=NULL)
	{
		p=lcou;
		lcou=lcou->next;
		free(p);
		p=NULL;
	}
}
