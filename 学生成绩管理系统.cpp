//ѧ����Ϣ����ϵͳ

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
////////////////////////////////////////////////////////////////��//////////////////////////////////////////////////////////////////
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
   cout<<endl<<"====>> ������ѧ���ɼ� <<===="<<endl;
   while(sign!='n'&&sign!='N')
   {
     cout<<" �༶:";
     cin>>stud[i].class_0;
     loop:
     cout<<" ѧ��:";
     cin>>stud[i].num;
     int c=0;
     while(c<i)
	 {
        c++;
        if(stud[i].num==stud[i-c].num)
		{
           cout<<" �������ѧ���Ѿ�����!���������롣"<<endl;
           goto loop;
		}
	 }
     cout<<" ����: ";
     cin>>stud[i].name;
     do{
         flag=0;
         cout<<" �ߵ���ѧ:";
         cin>>stud[i].math;
         if(stud[i].math>100 ||stud[i].math<1)
           cout<<"�Բ���,������1-100֮�������!!\n";
         else      flag=1;
	 }while(flag==0);
     do{
         flag=0;
         cout<<" C++������Ƴɼ�:";
         cin>>stud[i].c_program;
         if(stud[i].c_program>100 ||stud[i].c_program<1)
           cout<<"�Բ���,������1-100֮�������!!\n";
         else      flag=1;
	 }while(flag==0);
     do{
         flag=0;
         cout<<" ��ɢ��ѧ:";
         cin>>stud[i].media;
         if(stud[i].media>100 ||stud[i].media<1)
           cout<<"�Բ���,������1-100֮�������!!\n";
         else      flag=1;
	 }while(flag==0);
     do{
         flag=0;
         cout<<" ��ѧӢ��ɼ�:";
         cin>>stud[i].english;
         if(stud[i].english>100 ||stud[i].english<1)
           cout<<"�Բ���,������1-100֮�������!!\n";
         else      flag=1;
	 }while(flag==0);
     do{
         flag=0;
         cout<<" ��ѧ����ɼ�:";
         cin>>stud[i].physical;
         if(stud[i].physical>100 ||stud[i].physical<1)
           cout<<"�Բ���,������1-100֮�������!!\n";
         else      flag=1;
	 }while(flag==0);
     do{
         flag=0;
         cout<<" ��ѧ�����ɼ�:";
         cin>>stud[i].sport;
         if(stud[i].sport>100 ||stud[i].sport<1)
            cout<<"�Բ���,������1-100֮�������!!\n";
         else      flag=1;
	 }while(flag==0);
     do{
         flag=0;
         cout<<" ˼��:";
         cin>>stud[i].polity;
         if(stud[i].polity>100 ||stud[i].polity<1)
           cout<<"�Բ���,������1-100֮�������!!\n";
         else      flag=1;
	 }while(flag==0);
     stud[i].average=(stud[i].math+stud[i].c_program+stud[i].media+stud[i].english+stud[i].physical+stud[i].sport+stud[i].polity)/7;
     cout<<" ƽ����Ϊ:"<<stud[i].average<<endl;
     cout<<"====>��ʾ:�Ƿ����д��ѧ���ɼ�?(Y/N)";
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
  cout<<endl<<"====>> ���ѧ��ͳ������ <<===="<<endl;
  cout<<"�༶"<<"\t"<<"ѧ��"<<"\t"<<" ����"<<"\t"<<" ƽ����"<<endl;
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
  cout<<endl<<"====>> ����ѧ���ɼ� <<===="<<endl;
  cout<<"��������Ҫ����ѧ����ѧ��:"<<endl;
  cin>>s;
  while((stud[i].num-s)!=0&&i<n) i++;
  if(i==n)
  {
    cout<<"=====>��ʾ:�Բ����޷��ҵ���ѧ������Ϣ!"<<endl;
  }
  else
  {
    cout<<"---------------------------"<<endl;
    cout<<"�༶:"<<stud[i].class_0<<endl;
    cout<<"ѧ��:"<<stud[i].num<<endl;
    cout<<"����:"<<stud[i].name<<endl;
    cout<<"�ߵ���ѧ:"<<stud[i].math<<endl;
    cout<<"C++�������:"<<stud[i].c_program<<endl;
    cout<<"��ɢ��ѧ:"<<stud[i].media<<endl;
    cout<<"��ѧӢ��:"<<stud[i].english<<endl;
    cout<<"��ѧ����:"<<stud[i].physical<<endl;
    cout<<"��ѧ����:"<<stud[i].sport<<endl;
    cout<<"˼��:"<<stud[i].polity<<endl;
    cout<<"ƽ����:"<<stud[i].average<<endl;
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Modify(Stu stud[])
{
  system("cls");
  int n=Read(stud);
  int s;
  int i=0;
  cout<<endl<<"====>> �޸�ѧ���ɼ� <<===="<<endl;
  cout<<"��������Ҫ�޸ĳɼ�ѧ����ѧ��:"<<endl;
  cin>>s;
  while((stud[i].num-s)!=0&&i<n) i++;
  if(i==n)
  {
    cout<<"=====>��ʾ:�Բ����޸�ѧ���ĳɼ�����"<<endl;
  }
  else
  {
    cout<<"----------��ѧ������Ϣ----------"<<endl;
    cout<<"�༶"<<"\t"<<"ѧ��"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"c++"<<"\t"<<" ��ý��"<<"\t"<<"Ӣ��"<<"\t"<<"��ѧ"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"ƽ����"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<stud[i].class_0<<"\t"<<stud[i].num<<"\t"<<stud[i].name<<"\t"<<stud[i].math<<"\t"<<stud[i].c_program<<"\t"<<stud[i].media<<"\t"<<stud[i].english<<"\t"<<stud[i].physical<<"\t"<<stud[i].sport<<"\t"<<stud[i].polity<<"\t"<<stud[i].average<<endl;
    cout<<"�����������ѧ������Ϣ"<<endl;
    cout<<"�༶:"<<endl;
    cin>>stud[i].class_0;
    cout<<"ѧ��:"<<endl;
    cin>>stud[i].num;
    cout<<"����:"<<endl;
    cin>>stud[i].name;
    cout<<"�ߵ���ѧ�ɼ�:"<<endl;
    cin>>stud[i].math;
    cout<<"C++������Ƴɼ�:"<<endl;
    cin>>stud[i].c_program;
    cout<<"��ɢ��ѧ�ɼ�:"<<endl;
    cin>>stud[i].media;
    cout<<"��ѧӢ��ɼ�:"<<endl;
    cin>>stud[i].english;
    cout<<"��ѧ����ɼ�:"<<endl;
    cin>>stud[i].physical;
    cout<<"��ѧ�����ɼ�:"<<endl;
    cin>>stud[i].sport;
    cout<<"˼�޳ɼ�:"<<endl;
    cin>>stud[i].polity;
    stud[i].average=(stud[i].math+stud[i].c_program+stud[i].media+stud[i].english+stud[i].physical+stud[i].sport+stud[i].polity)/7;
    cout<<"ƽ����Ϊ:"<<stud[i].average<<endl;
    char c;
    cout<<"�Ƿ񱣴�����?(y/n)"<<endl;
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
  cout<<endl<<"====>> ɾ��ѧ���ɼ� <<===="<<endl;
  cout<<"��������Ҫɾ��ѧ����ѧ��:"<<endl;
  cin>>s;
  while((stud[i].num-s)!=0&&i<n) i++;
  if(i==n)
  {
    cout<<"====>��ʾ:�Բ����޷��ҵ���ѧ������"<<endl;
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
    cout<<"====>��ʾ:�ѳɹ�ɾ��!"<<endl;
  }
  Write(stud,n-1);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Insert(Stu stud[])
{
  system("cls");
  int n=Read(stud);
  char s;
  cout<<endl<<"====>> ����ѧ���ɼ�<<===="<<endl;
  while(s!='n'&&s!='N')
  {
    cout<<"�༶:"<<endl;
    cin>>stud[n].class_0;
    cout<<"ѧ��:";
    cin>>stud[n].num;
    cout<<"����:";
    cin>>stud[n].name;
    cout<<"�ߵ���ѧ�ɼ�:";
    cin>>stud[n].math;
    cout<<"C++������Ƴɼ�:";
    cin>>stud[n].c_program;
    cout<<"��ɢ��ѧ�ɼ�:";
    cin>>stud[n].media;
    cout<<"��ѧӢ��ɼ�:";
    cin>>stud[n].english;
    cout<<"��ѧ����ɼ�:";
    cin>>stud[n].physical;
    cout<<"��ѧ�����ɼ�:";
    cin>>stud[n].sport;
    cout<<"˼�޳ɼ�:";
    cin>>stud[n].polity;
    stud[n].average=(stud[n].math+stud[n].c_program+stud[n].media+stud[n].english+ stud[n].physical+stud[n].sport+stud[n].polity)/7;
    cout<<"ƽ����"<<stud[n].average;
    n++;
    cout<<"=====>��ʾ:����ɹ�!"<<endl;
    cout<<"�Ƿ��������(y/n)"<<endl;
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
  cout<<endl<<"====>> ��������ɼ� <<===="<<endl;
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
  cout<<"�༶"<<"\t"<<"ѧ��"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"C++"<<"\t"<<"��ý��"<<"\t"<<"Ӣ��"<<"\t"<<"��ѧ"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"ƽ����"<<"\t"<<"����"<<endl;
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
  cout<<endl<<"====>> ��ʾȫ��ѧ���ɼ� <<===="<<endl;
  if(!stud)
    cout<<"û�м�¼";
  else
  {
    cout<<"----------------------------------------------------"<<endl;
    cout<<"�༶"<<"\t"<<"ѧ��"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"c++"<<"\t"<<"��ý��"<<"\t"<<"Ӣ��"<<"\t"<<"��ѧ"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"ƽ����"<<endl;
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
    cout<<" -------------<<��ӭ��ʹ��ѧ���ɼ�����ϵͳ>>------------\n"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"* 1������ѧ���ɼ� *"<<endl;
    cout<<"* 2����ʾͳ������ *"<<endl;
    cout<<"* 3������ѧ���ɼ� *"<<endl;
    cout<<"* 4���޸�ѧ���ɼ� *"<<endl;
    cout<<"* 5��ɾ��ѧ���ɼ� *"<<endl;
    cout<<"* 6������ѧ���ɼ� *"<<endl;
    cout<<"* 7����ƽ���ֽ������� *"<<endl;
    cout<<"* 8����ʾȫ��ѧ���ɼ� *"<<endl;
    cout<<"* 0���˳���ϵͳ *"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"����ѡ�����(0-8):"<<endl;
    c=getchar();
  }
  while(c<'0'||c>'8');
  return(c-'0');
}

///////////////////////////////////////////////////////////������/////////////////////////////////////////////////////////////////
int main()              
{
   system ("color e2");
   system ("title ѧ���ɼ�����ϵͳ"); 
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
            cout<<endl<<" ================================<<��л��ʹ��ѧ���ɼ�����ϵͳ>>===============================\n"<<endl;
            cout<<"\t\t\t";
            system("pause");
            exit(0);
	   }
   }
   return 0;
}