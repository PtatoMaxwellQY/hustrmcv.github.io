//
//  main.c
//  考勤机  改
//
//  Created by qinyue on 2017/11/27.
//  Copyright © 2017年 、. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct members
{
    
    
    int num;
    char group[20];
    char grade[20];
    char major[20];
    char stu_num[20];
    char name[20];
    char tel[20];
    char qq[20];
    
    
    int sign;
    
    struct members * next;    //链表成员
    
    
    
};




struct members mem[100];    //定义100个成员空间

void input(int);

void search();


void print_all();
void print_pec(int);
void print_group();
void print_grade();
void print_major();


void search_num();
void search_nam();
void search_tel();
void search_qq();



void file_print();
void file_read();
void file_add(int );


void delet();
void sign();



FILE * fp;



int main()
{
    int cho;
    int num=0;
    
    if ((fp=fopen("/Users/qinyue/Desktop/vision","a") )==NULL)

    {fp=fopen("/Users/qinyue/Desktop/vision","w"); }

    else fp=NULL;

    
    
    while (1)
        
    {
        
        printf("choose what you need to do\n");
        printf("input members  ----1\n");
        printf("search         ----2\n");
        printf("view all       ----3\n");
        printf("log in         ----4\n");
        printf("delet          ----5\n");
        printf("end programm   ----6\n");
        
        
        
        scanf("%d",&cho);
        if (cho>=0&&cho<=10)
        switch (cho)
        {
            case 1:file_read();
                while (mem[num].num==0)
                {
                    if (mem[num].num==0)
                    {
                        input(num);
                        num++;
                        break;
                    }
                    else num++;
                }
                break;
                
                
            case 2:search();
                break;
            case 3:
                print_all();
                break;
                
            case 4:
                sign();
                break;
                
            case 5:
                
                delet();break;
            case 6:
                goto end;
            default:
                break;
        }
        
    }
    
    
end:
    printf("programm ends succssfully\n");
    return 0;
    
    
    
    
}









void input(int i)
{
    
    mem[i].num=i+1;
    
    mem[i].sign=0;
    
    mem[i].next=&mem[i+1];
    
    
    
    
    
    printf("please input\n");
    printf("group         :");
    scanf("%s",mem[i].group);
    
    
    printf("major         :");
    scanf("%s",mem[i].major);
    
    
    printf("student name  :");
    scanf("%s",mem[i].name);
    
    
    printf("student number:");
    scanf("%s",mem[i].stu_num);
    
    
    printf("telephone     :");
    scanf("%s",mem[i].tel);
    
    
    printf("QQ            :");
    scanf("%s",mem[i].qq);
    
    
    
    printf("grade         :");
    scanf("%s",mem[i].grade);
    
    
    file_print();
}









/*
 search函数家族
 */


void search()
{
    file_read();
    
    
    
    printf("which path would you like ?\n");
    printf("search by student number ----1\n");
    printf("search by name           ----2\n");
    printf("search by telephone      ----3\n");
    printf("search by QQ             ----4\n");
    printf("search by group          ----5\n");
    printf("search by major          ----6\n");
    printf("search by grade          ----7\n");
    printf("drop ou the search engine----8\n");
    printf("don' input a letter,or the programm will be in a dead circus!!\n ");
    int opt;
    
    if (scanf("%d",&opt)==1)
    {switch (opt) {
            
        case 1:search_num();break;
        case 2:search_nam();break;
        case 3:search_tel();break;
        case 4:search_qq();break;
        case 5:print_group();break;
        case 6:break;
        case 7:print_grade();break;
        case 8:printf("search engine drop out\n");
            break;
        default:printf("wrong number,please input again\n");
            search();
            break;
            
    }
    }
}









void search_num()        //学号搜索
{
    fp=fopen("/Users/qinyue/Desktop/vision", "r");
    
    
    
    char temp[20]={0};
    char flag=0;
    printf("input the student number you want to search\n");
    scanf("%s",temp);
    for (int i=0; i<100; i++)
    {
        if (strcmp(temp, mem[i].stu_num)==0)
        {
            print_pec(i);
            flag++;
        }
        
    }
    if (flag==0)
    {
        printf("sorry,student not found\n");
    }
    
}










void search_nam()        //名字搜索
{
    char temp[20]={0};
    char flag=0;
    printf("input the student name you want to search\n");
    scanf("%s",temp);
    for (int i=0; i<100; i++)
    {
        if (strcmp(temp, mem[i].name)==0)
        {
            print_pec(i);
            flag++;
        }
        
    }
    if (flag==0)
    {
        printf("sorry,student not found\n");
    }
    
}


void search_tel()        //电话搜索
{
    char temp[20]={0};
    char flag=0;
    printf("input the student telephone you want to search\n");
    scanf("%s",temp);
    for (int i=0; i<100; i++)
    {
        if (strcmp(temp, mem[i].tel)==0)
        {
            print_pec(i);
            flag++;
        }
        
    }
    if (flag==0)
    {
        printf("sorry,student not found\n");
    }
    
}


void search_qq()          //qq搜索
{
    
    char temp[20]={0};
    char flag=0;
    printf("input the student QQ you want to search\n");
    scanf("%s",temp);
    for (int i=0; i<100; i++)
    {
        if (strcmp(temp, mem[i].qq)==0)
        {
            print_pec(i);
            flag++;
        }
        
    }
    if (flag==0)
    {
        printf("sorry,student not found\n");
    }
}



/*
 print函数家族
 */

void print_all()          //输出全部----数组法
{
    
    file_read();
    printf(" rank");
    printf("             (group)");
    printf("             (grade)");
    printf("             (major)");
    printf("    (student number)");
    printf("              (name)");
    printf("         (telephone)");
    printf("                (qq)");
    printf(" sign");
    printf("\n");
    for (int i=0; i<100; i++)
    {
        
            print_pec(i);
       
        
    }
    
}



void print_pec(int i)          //输出特定成员----数组法
{
    
    
    printf("%20s",mem[i].group);
    printf("%20s",mem[i].grade);
    printf("%20s",mem[i].major);
    printf("%20s",mem[i].stu_num);
    printf("%20s",mem[i].name);
    printf("%20s",mem[i].tel);
    printf("%20s",mem[i].qq);
    printf("%5d",mem[i].sign);
    
    
    
}


void print_group()         //输出一组成员
{
    
    char temp[20]={0};
    char flag=0;
    printf("input the group you want to print\n");
    scanf("%s",temp);
    for (int i=0; i<100; i++)
    {
        if (strcmp(temp, mem[i].group)==0)
        {
            print_pec(i);
            flag++;
        }
        
    }
    if (flag==0)
    {
        printf("sorry,group not found\n");
    }
    
}



void print_grade()        //输出一个年级的同学
{
    char temp[20]={0};
    char flag=0;
    printf("input the grade you want to print\n");
    scanf("%s",temp);
    for (int i=0; i<100; i++)
    {
        if (strcmp(temp, mem[i].grade)==0)
        {
            print_pec(i);
            flag++;
        }
        
    }
    if (flag==0)
    {
        printf("sorry,no this grade\n");
    }
    
}


void print_major()
{
    
    char temp[20]={0};
    char flag=0;
    printf("input the major you want to print\n");
    scanf("%s",temp);
    for (int i=0; i<100; i++)
    {
        if (strcmp(temp, mem[i].major)==0)
        {
            print_pec(i);
            flag++;
        }
        
    }
    if (flag==0)
    {
        printf("sorry,no this major\n");
    }
    
}


/*
 file处理函数
 
 */


void file_print()          //想文件写入数据
{
    fp=fopen("/Users/qinyue/Desktop/vision", "w");
    for (int i=0; i<100;i++)
    {
        
        if (mem[i].num!=0)
            
        {
            fprintf(fp, "%5d",mem[i].num);
            fprintf(fp, "%20s",mem[i].group);
            fprintf(fp, "%20s",mem[i].grade);
            fprintf(fp, "%20s",mem[i].major);
            fprintf(fp, "%20s",mem[i].stu_num);
            fprintf(fp, "%20s",mem[i].name);
            fprintf(fp, "%20s",mem[i].tel);
            fprintf(fp, "%20s",mem[i].qq);
            fprintf(fp,"%5d",mem[i].sign);
            fprintf(fp, "\n");
            
        }
    }
    
    fp=NULL;
}


void file_read()           //从文件读出数据
{
    fp=fopen("/Users/qinyue/Desktop/vision", "r");
    
    
    if (fp==NULL)
    {
        printf("sorry,no file\n");
    }
    else
    
    for (int i=0; i<100; i++)
    {
        
        fscanf(fp, "%d",&mem[i].num);
         fscanf(fp, "%s",mem[i].group);
         fscanf(fp, "%s",mem[i].grade);
         fscanf(fp, "%s",mem[i].major);
         fscanf(fp, "%s",mem[i].stu_num);
         fscanf(fp, "%s",mem[i].name);
         fscanf(fp, "%s",mem[i].tel);
         fscanf(fp, "%s",mem[i].qq);
         fscanf(fp, "%d",&mem[i].sign);
        
        
    }
    
    fp=NULL;
    
}


void file_add(int i)
{
    
    fp=fopen("/Users/qinyue/Desktop/vision", "a");
    
    
    fprintf(fp, "%5d",mem[i].num);
    fprintf(fp, "%20s",mem[i].group);
    fprintf(fp, "%20s",mem[i].grade);
    fprintf(fp, "%20s",mem[i].major);
    fprintf(fp, "%20s",mem[i].stu_num);
    fprintf(fp, "%20s",mem[i].name);
    fprintf(fp, "%20s",mem[i].tel);
    fprintf(fp, "%20s",mem[i].qq);
    fprintf(fp,"%5d",mem[i].sign);
    fprintf(fp, "\n");
    
    
    fp=NULL;
    
    
}


/*
 删除成员
 */
void delet()
{
    
    
    printf("choos the student number you want to delet\n");
    char temp[20];
    int pos;
    int flag=0;
    scanf("%s",temp);
    for (int i=0; i<100; i++)
    {
        if (strcmp(temp, mem[i].stu_num)==0)
        {
            pos=i;
            flag++;
        }
    }
    
    if (flag==1)
    {
        for (int i=flag; i<100; i++)
        {
            mem[i]=mem[i+1];
        }
    }
    
    else printf("student not found \n");
    file_print();
    
    
}



void sign()
{
    printf("please input your student number\n");
    char temp[20];
    int pos;
    int flag=0;
    for (int i=0; i<100; i++)
    {
        if (strcmp(temp, mem[i].stu_num)==0)
        {
            flag++;
            pos=i;
        }
    }
    
    
    if (flag==1)
    {
        mem[flag].sign++;
    }
    
    else printf("sorry,student not found\n");
}
