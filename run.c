#include<stdio.h>
#include"Link.h"
#include"Course.h"
int main()
{
	int choice;
	int flag;
	LinkNode *lstu;
	lstu=(LinkNode*)malloc(sizeof(LinkNode));
	lstu->next=NULL;
	Clist *lcou;
	lcou=(Clist *)malloc(sizeof(Clist));
	lcou->next=NULL;
	flag=1;
	while(flag==1)
	{
		printf("请问是否需要使用本系统，1：是、2：否\n");
		scanf("%d",&flag);
		if(flag==2)
		{
			printf("再见！\n");
			break;
		}
    printf("hello,welcome to use the sysytem!\n");
    printf("请选择您要使用的模块\n");
    printf("1: 学生信息模块\n");
	printf("2:课程信息模块\n");
    scanf("%d",&choice);
	if(choice==1)//学生信息模块
	{
		printf("您选择的是学生信息模块\n");
		printf("请选择如下服务：\n");
		printf("1：查看学生信息\n");
		printf("2：新增学生信息\n");
		printf("3：修改学生信息\n");
		printf("4：删除学生信息\n");
		
		scanf("%d",&choice);
		switch(choice)
		{
		  case 1:
			{
			  printf("您选择的是学生信息模块\n");
              printf("请选择如下服务：\n");
		      printf("1：查看当前所有学生信息\n");
		      printf("2：按姓名查看学生信息\n");
		      printf("3：按学号查看学生信息\n");
		      scanf("%d",&choice);
			  if(choice==1)
			  {
				printstu(lstu);
			  }
		  	  if(choice==2)
			  {
				char find_name[10];
				printf("输入你要查找的学生的姓名：\n");
				scanf("%s",find_name);
				findstu_name(lstu,find_name);
			  }
		  	  if(choice==3)
			  {
				int find_sno;
				printf("输入你要查找的学生的学号：\n");
				scanf("%d",&find_sno);
				findstu_sno(lstu,find_sno);
			  }
			 
			 break;
	
			}
		case 2:
			{
				printf("您选择的是新增学生信息模块\n");
				printf("请选择如下服务：\n");
				printf("1：从键盘读入数据\n");
			    printf("2：从文件读入数据\n");
				scanf("%d",&choice);
				if(choice==1)
				{
					getinffromkeyb(lstu);
				}
				else if(choice==2)
				{
					getinffromFile(lstu);
				}
				else
				{
					printf("输入错误！\n");
				}
				
				break;

			}
		case 3:
			{
				printf("您选择的是修改学生信息模块\n");
				changestuInf(lstu,lcou);
				break;
			
			}
		case 4:
			{
				printf("您选择的是删除学生信息模块\n");
				delstu(lstu,lcou);
				break;
			}
		default:
			printf("请正确输入\n");
			break;	
		}

	}
	else if(choice==2)
	{
		printf("您选择的是课程信息模块\n");
		printf("请选择如下服务：\n");
		printf("1：查看课程信息\n");
		printf("2：新增课程信息\n");
		printf("3：修改课程信息\n");
		printf("4：删除课程信息\n");
		scanf("%d",&choice);
		switch(choice)
		{
		  case 1:
			{
		  	    printf("您选择的是课程信息模块\n");
                printf("请选择如下服务：\n");
				printf("1：查看当前所有课程信息\n");
				printf("2：按课程编号查看课程信息\n");
				scanf("%d",&choice);
				if(choice==1)
				{
					printcou(lcou);
				}
				if(choice==2)
				{
					int cno;
					printf("输入你要查找的课程的编号：\n");
					scanf("%d",&cno);
					findCou(lcou,cno);
				}
			
				break;
	
			}
		case 2:
			{
				printf("您选择的是新增课程信息模块\n");
				printf("请选择如下服务：\n");
				printf("1：从键盘读入数据\n");
			    printf("2：从文件读入数据\n");
				scanf("%d",&choice);
				if(choice==1)
				{
					getcoufromkeyb(lcou);
				}
				else if(choice==2)
				{
					getcoufromFile(lcou);
				}
				else
				{
					printf("输入错误！\n");
				}
				
				break;

			}
		case 3:
			{
				printf("您选择的是修改学生信息模块\n");
				changecouInf(lcou,lstu);
				break;
			
			}
		case 4:
			{
				printf("您选择的是删除学生信息模块\n");
				delcou(lcou,lstu);
				break;
			}
		default:
			printf("请正确输入\n");
			break;
		}




	}
	else
	{
		printf("错误输入，请输入1或2\n");
	}
	}
	writeintoFile(lstu);
	writebackFile(lcou);
	freeList(lstu);
	freeCList(lcou);
	return 0;

}
