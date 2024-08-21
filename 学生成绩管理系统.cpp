//学生信息管理系统

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
////////////////////////////////////////////////////////////////类//////////////////////////////////////////////////////////////////
class Stu
{
 public:
   friend void Input(Stu stud[]) ;
   friend void Statistic(Stu stud[]);
   friend void Lookup(Stu stud[]) ;
   friend void Modify(Stu stud[]) ;
   friend void Delete(Stu stud[]) ;
   friend void Output(Stu stud[]) ;
   friend void Sort(Stu stud[]) ;
   friend void Insert(Stu stud[]) ;
   friend void Write(Stu stud[],int n);
   friend int Read(Stu stud[]);
 private:
   char class_0[20];
   int num;
   char name[8];
   float math;
   float c_program;
   float media;
   float english;
   float physical;
   float sport;
   float polity;
   float average;
   int order;
}stud[100];

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Write(Stu stud[],int n)
{
   fstream myFile;
   myFile.open("student.dat",ios::out|ios::binary);
   if(!myFile)
   {
     cout<<"student.dat can't open!"<<endl;
     abort();
   }
   int count=n;
   myFile<<count<<endl<<endl;
   for(int i=0;i<=count;i++)
   {
     myFile<<stud[i].class_0<<" "<<stud[i].num<<" "<<stud[i].name<<" "<<stud[i].math<<" "<<stud[i].c_program<<" "<<stud[i].media<<" "<<stud[i].english
     <<" "<<stud[i].physical<<" "<<stud[i].sport<<" "<<stud[i].polity<<" "<<stud[i].average<<endl;
   }
   myFile.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Read(Stu stud[])
{
   fstream myFile;
   myFile.open("student.dat",ios::in|ios::binary);
   if(!myFile)
   {
      cout<<"student.dat can't open!"<<endl;
      abort();
   }
   int count;
   myFile.seekg(0);
   myFile>>count;
   for(int i=0;i<=count;i++)
   {
      myFile>>stud[i].class_0>>stud[i].num>>stud[i].name>>stud[i].math>>stud[i].c_program>>stud[i].media>>stud[i].english>>stud[i].physical>>stud[i].sport>>stud[i].polity>>stud[i].average;
   }
   myFile.close();
   return count ;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Input(Stu stud[])
{
   system("cls");
   int i=0;
   int flag;
   char sign;
   cout<<endl<<"====>> 请输入学生成绩 <<===="<<endl;
   while(sign!='n'&&sign!='N')
   {
     cout<<" 班级:";
     cin>>stud[i].class_0;
     loop:
     cout<<" 学号:";
     cin>>stud[i].num;
     int c=0;
     while(c<i)
	 {
        c++;
        if(stud[i].num==stud[i-c].num)
		{
           cout<<" 你输入的学号已经存在!请重新输入。"<<endl;
           goto loop;
		}
	 }
     cout<<" 姓名: ";
     cin>>stud[i].name;
     do{
         flag=0;
         cout<<" 高等数学:";
         cin>>stud[i].math;
         if(stud[i].math>100 ||stud[i].math<1)
           cout<<"对不起,请输入1-100之间的数字!!\n";
         else      flag=1;
	 }while(flag==0);
     do{
         flag=0;
         cout<<" C++程序设计成绩:";
         cin>>stud[i].c_program;
         if(stud[i].c_program>100 ||stud[i].c_program<1)
           cout<<"对不起,请输入1-100之间的数字!!\n";
         else      flag=1;
	 }while(flag==0);
     do{
         flag=0;
         cout<<" 离散数学:";
         cin>>stud[i].media;
         if(stud[i].media>100 ||stud[i].media<1)
           cout<<"对不起,请输入1-100之间的数字!!\n";
         else      flag=1;
	 }while(flag==0);
     do{
         flag=0;
         cout<<" 大学英语成绩:";
         cin>>stud[i].english;
         if(stud[i].english>100 ||stud[i].english<1)
           cout<<"对不起,请输入1-100之间的数字!!\n";
         else      flag=1;
	 }while(flag==0);
     do{
         flag=0;
         cout<<" 大学物理成绩:";
         cin>>stud[i].physical;
         if(stud[i].physical>100 ||stud[i].physical<1)
           cout<<"对不起,请输入1-100之间的数字!!\n";
         else      flag=1;
	 }while(flag==0);
     do{
         flag=0;
         cout<<" 大学体育成绩:";
         cin>>stud[i].sport;
         if(stud[i].sport>100 ||stud[i].sport<1)
            cout<<"对不起,请输入1-100之间的数字!!\n";
         else      flag=1;
	 }while(flag==0);
     do{
         flag=0;
         cout<<" 思修:";
         cin>>stud[i].polity;
         if(stud[i].polity>100 ||stud[i].polity<1)
           cout<<"对不起,请输入1-100之间的数字!!\n";
         else      flag=1;
	 }while(flag==0);
     stud[i].average=(stud[i].math+stud[i].c_program+stud[i].media+stud[i].english+stud[i].physical+stud[i].sport+stud[i].polity)/7;
     cout<<" 平均分为:"<<stud[i].average<<endl;
     cout<<"====>提示:是否继续写入学生成绩?(Y/N)";
     cin>>sign;
     i++;
   }
   Write(stud,i);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Statistic(Stu stud[])
{
  system("cls");
  int n=Read(stud);
  cout<<endl<<"====>> 输出学生统计数据 <<===="<<endl;
  cout<<"班级"<<"\t"<<"学号"<<"\t"<<" 姓名"<<"\t"<<" 平均分"<<endl;
  for(int i=0;i<n;i++)
     cout<<stud[i].class_0<<"\t"<<stud[i].num<<"\t"<<stud[i].name<<"\t"<<stud[i].average<<endl;
  system("pause");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Lookup(Stu stud[])
{
  system("cls");
  int n=Read(stud);
  int s;
  int i=0;
  cout<<endl<<"====>> 查找学生成绩 <<===="<<endl;
  cout<<"请输入需要查找学生的学号:"<<endl;
  cin>>s;
  while((stud[i].num-s)!=0&&i<n) i++;
  if(i==n)
  {
    cout<<"=====>提示:对不起，无法找到该学生的信息!"<<endl;
  }
  else
  {
    cout<<"---------------------------"<<endl;
    cout<<"班级:"<<stud[i].class_0<<endl;
    cout<<"学号:"<<stud[i].num<<endl;
    cout<<"姓名:"<<stud[i].name<<endl;
    cout<<"高等数学:"<<stud[i].math<<endl;
    cout<<"C++程序设计:"<<stud[i].c_program<<endl;
    cout<<"离散数学:"<<stud[i].media<<endl;
    cout<<"大学英语:"<<stud[i].english<<endl;
    cout<<"大学物理:"<<stud[i].physical<<endl;
    cout<<"大学体育:"<<stud[i].sport<<endl;
    cout<<"思修:"<<stud[i].polity<<endl;
    cout<<"平均分:"<<stud[i].average<<endl;
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Modify(Stu stud[])
{
  system("cls");
  int n=Read(stud);
  int s;
  int i=0;
  cout<<endl<<"====>> 修改学生成绩 <<===="<<endl;
  cout<<"请输入需要修改成绩学生的学号:"<<endl;
  cin>>s;
  while((stud[i].num-s)!=0&&i<n) i++;
  if(i==n)
  {
    cout<<"=====>提示:对不起，无该学生的成绩……"<<endl;
  }
  else
  {
    cout<<"----------该学生的信息----------"<<endl;
    cout<<"班级"<<"\t"<<"学号"<<"\t"<<"姓名"<<"\t"<<"电子"<<"\t"<<"c++"<<"\t"<<" 多媒体"<<"\t"<<"英语"<<"\t"<<"数学"<<"\t"<<"体育"<<"\t"<<"政治"<<"\t"<<"平均分"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<stud[i].class_0<<"\t"<<stud[i].num<<"\t"<<stud[i].name<<"\t"<<stud[i].math<<"\t"<<stud[i].c_program<<"\t"<<stud[i].media<<"\t"<<stud[i].english<<"\t"<<stud[i].physical<<"\t"<<stud[i].sport<<"\t"<<stud[i].polity<<"\t"<<stud[i].average<<endl;
    cout<<"请重新输入该学生的信息"<<endl;
    cout<<"班级:"<<endl;
    cin>>stud[i].class_0;
    cout<<"学号:"<<endl;
    cin>>stud[i].num;
    cout<<"姓名:"<<endl;
    cin>>stud[i].name;
    cout<<"高等数学成绩:"<<endl;
    cin>>stud[i].math;
    cout<<"C++程序设计成绩:"<<endl;
    cin>>stud[i].c_program;
    cout<<"离散数学成绩:"<<endl;
    cin>>stud[i].media;
    cout<<"大学英语成绩:"<<endl;
    cin>>stud[i].english;
    cout<<"大学物理成绩:"<<endl;
    cin>>stud[i].physical;
    cout<<"大学体育成绩:"<<endl;
    cin>>stud[i].sport;
    cout<<"思修成绩:"<<endl;
    cin>>stud[i].polity;
    stud[i].average=(stud[i].math+stud[i].c_program+stud[i].media+stud[i].english+stud[i].physical+stud[i].sport+stud[i].polity)/7;
    cout<<"平均分为:"<<stud[i].average<<endl;
    char c;
    cout<<"是否保存数据?(y/n)"<<endl;
    cin>>c;
    if(c!='n'&&c!='N')
      Write(stud,n);
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Delete(Stu stud[])
{
  system("cls");
  int n=Read(stud);
  int s;
  int i=0,j;
  cout<<endl<<"====>> 删除学生成绩 <<===="<<endl;
  cout<<"请输入需要删除学生的学号:"<<endl;
  cin>>s;
  while((stud[i].num-s)!=0&&i<n) i++;
  if(i==n)
  {
    cout<<"====>提示:对不起，无法找到该学生……"<<endl;
  }
  else
  {
    for(j=i;j<n-1;j++)
	{
      strcpy(stud[j].class_0,stud[j+1].class_0);
      stud[j].num=stud[j+1].num;
      strcpy(stud[j].name,stud[j+1].name);
      stud[j].math=stud[j+1].math;
      stud[j].c_program=stud[j+1].c_program;
      stud[j].media=stud[j+1].media;
      stud[j].english=stud[j+1].english;
      stud[j].physical=stud[j+1].physical;
      stud[j].sport=stud[j+1].sport;
      stud[j].polity=stud[j+1].polity;
      stud[j].average=stud[j+1].average;
	}
    cout<<"====>提示:已成功删除!"<<endl;
  }
  Write(stud,n-1);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Insert(Stu stud[])
{
  system("cls");
  int n=Read(stud);
  char s;
  cout<<endl<<"====>> 增加学生成绩<<===="<<endl;
  while(s!='n'&&s!='N')
  {
    cout<<"班级:"<<endl;
    cin>>stud[n].class_0;
    cout<<"学号:";
    cin>>stud[n].num;
    cout<<"姓名:";
    cin>>stud[n].name;
    cout<<"高等数学成绩:";
    cin>>stud[n].math;
    cout<<"C++程序设计成绩:";
    cin>>stud[n].c_program;
    cout<<"离散数学成绩:";
    cin>>stud[n].media;
    cout<<"大学英语成绩:";
    cin>>stud[n].english;
    cout<<"大学物理成绩:";
    cin>>stud[n].physical;
    cout<<"大学体育成绩:";
    cin>>stud[n].sport;
    cout<<"思修成绩:";
    cin>>stud[n].polity;
    stud[n].average=(stud[n].math+stud[n].c_program+stud[n].media+stud[n].english+ stud[n].physical+stud[n].sport+stud[n].polity)/7;
    cout<<"平均分"<<stud[n].average;
    n++;
    cout<<"=====>提示:插入成功!"<<endl;
    cout<<"是否继续输入(y/n)"<<endl;
    cin>>s;
  }
    Write(stud,n);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Sort(Stu stud[])
{
  system("cls");
  int i,j,k;
  float s;
  char t[20];
  cout<<endl<<"====>> 降序排序成绩 <<===="<<endl;
  int n=Read(stud);
  for(i=0;i<n-1;i++)
  for(j=0;j<n-1-i;j++)
  if(stud[j].average<stud[j+1].average)
  {
    strcpy(t,stud[j+1].class_0);
    strcpy(stud[j+1].class_0,stud[j].class_0);
    strcpy(stud[j].class_0,t);
    k=stud[j+1].num;
    stud[j+1].num=stud[j].num;
    stud[j].num=k;
    strcpy(t,stud[j+1].name);
    strcpy(stud[j+1].name,stud[j].name);
    strcpy(stud[j].name,t);
    s=stud[j+1].math;
    stud[j+1].math=stud[j].math;
    stud[j].math=s;
    s=stud[j+1].c_program;
    stud[j+1].c_program=stud[j].c_program;
    stud[j].c_program=s;
    s=stud[j+1].media;
    stud[j+1].media=stud[j].media;
    stud[j].media=s;
    s=stud[j+1].english;
    stud[j+1].english=stud[j].english;
    stud[j].english=s;
    s=stud[j+1].physical;
    stud[j+1].physical=stud[j].physical; 
    stud[j].physical=s;
    s=stud[j+1].sport;
    stud[j+1].sport=stud[j].sport;
    stud[j].sport=s;
    s=stud[j+1].polity;
    stud[j+1].polity=stud[j].polity;
    stud[j].polity=s;
    s=stud[j+1].average;
    stud[j+1].average=stud[j].average;
    stud[j].average=s;
  }
  cout<<"----------------------------------------------------"<<endl;
  cout<<"班级"<<"\t"<<"学号"<<"\t"<<"姓名"<<"\t"<<"电子"<<"\t"<<"C++"<<"\t"<<"多媒体"<<"\t"<<"英语"<<"\t"<<"数学"<<"\t"<<"体育"<<"\t"<<"政治"<<"\t"<<"平均分"<<"\t"<<"名次"<<endl;
  cout<<"----------------------------------------------------"<<endl;
  for(i=0;i<n;i++)
  { stud[i].order=i+1;
    cout<<stud[i].class_0<<"\t"<<stud[i].num<<"\t"<<stud[i].name<<"\t"<<stud[i].math<<"\t"<<stud[i].c_program<<"\t"<<stud[i].media<<"\t "<<stud[i].english<<" \t"<< stud[i].physical<<"\t"<<stud[i].sport<<"\t "<<stud[i].polity<<"\t"<<stud[i].average<<"\t"<<stud[i].order<<endl;
  }
  Write(stud,n);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Output(Stu stud[])
{
  system("cls");
  int n=Read(stud);
  cout<<endl<<"====>> 显示全部学生成绩 <<===="<<endl;
  if(!stud)
    cout<<"没有记录";
  else
  {
    cout<<"----------------------------------------------------"<<endl;
    cout<<"班级"<<"\t"<<"学号"<<"\t"<<"姓名"<<"\t"<<"电子"<<"\t"<<"c++"<<"\t"<<"多媒体"<<"\t"<<"英语"<<"\t"<<"数学"<<"\t"<<"体育"<<"\t"<<"政治"<<"\t"<<"平均分"<<endl;
    cout<<"------------------------------------------------"<<endl;
    for(int i=0;i<n;i++)
	{
      cout<<stud[i].class_0<<"\t "<<stud[i].num<<"\t "<<stud[i].name<<"\t "<<stud[i].math<<" \t"<<stud[i].c_program<<"\t "<<stud[i].media<<"\t "<<stud[i].english<<"\t "<< stud[i].physical<<" \t"<<stud[i].sport<<"\t"<<stud[i].polity<<"\t"<<stud[i].average<<endl;
	}
    cout<<"--------------------------------------------------------"<<endl;
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu()
{
  char c;
  do
  {
    system("cls");
    cout<<" -------------<<欢迎您使用学生成绩管理系统>>------------\n"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"* 1、输入学生成绩 *"<<endl;
    cout<<"* 2、显示统计数据 *"<<endl;
    cout<<"* 3、查找学生成绩 *"<<endl;
    cout<<"* 4、修改学生成绩 *"<<endl;
    cout<<"* 5、删除学生成绩 *"<<endl;
    cout<<"* 6、插入学生成绩 *"<<endl;
    cout<<"* 7、按平均分降序排列 *"<<endl;
    cout<<"* 8、显示全部学生成绩 *"<<endl;
    cout<<"* 0、退出本系统 *"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"请你选择操作(0-8):"<<endl;
    c=getchar();
  }
  while(c<'0'||c>'8');
  return(c-'0');
}

///////////////////////////////////////////////////////////主函数/////////////////////////////////////////////////////////////////
int main()              
{
   system ("color e2");
   system ("title 学生成绩管理系统"); 
   for(;;)
   {
       switch(menu())
	   {
         case 1: Input(stud); break;
         case 2: Statistic(stud); break;
         case 3: Lookup(stud); cout<<"\t\t\t"; system("pause"); break;
         case 4: Modify(stud); cout<<"\t\t\t"; system("pause"); break;
         case 5: Delete(stud); cout<<"\t\t\t"; system("pause"); break;
         case 6: Insert(stud); cout<<"\t\t\t"; system("pause"); break;
         case 7: Sort(stud);   cout<<"\t\t\t"; system("pause"); break;
         case 8: Output(stud); cout<<"\t\t\t"; system("pause"); break;
         case 0:
            cout<<endl<<" ================================<<感谢您使用学生成绩管理系统>>===============================\n"<<endl;
            cout<<"\t\t\t";
            system("pause");
            exit(0);
	   }
   }
   return 0;
}