#include<iostream>
#include<cstring>
using namespace std;

class Student
{
private:
    int roll;
public:
    char *name;
    char *branch;
    int year;
    static int count;

    Student()
    {
        cout<<"In default constructor"<<endl;
        name=NULL;
        branch=NULL;
        roll=0;
        year=0;
        count++;
    }
    Student(char *n,char *b,int rn,int y):roll(rn),year(y)
    {
        cout<<"In parameterized constructor"<<endl;
        name=new char[strlen(n)+1];
        strcpy(name,n);
        branch=new char[strlen(b)+1];
        strcpy(branch,b);
//        roll=rn;
//        year=y;
        count++;
    }
    Student(Student &X)
    {
        cout<<"In copy constructor"<<endl;
        name=new char[strlen(X.name)+1];
        strcpy(name,X.name);
        branch=new char[strlen(X.branch)+1];
        strcpy(branch,X.branch);
        roll=X.roll;
        year=X.year;
        count++;
    }
    void operator=(Student X)
    {
        if(name!=NULL)
        {
            delete []name;
            name=NULL;
        }
        name=new char[strlen(X.name)+1];
        strcpy(name,X.name);
        if(branch!=NULL)
        {
            delete []branch;
            branch=NULL;
        }
        branch=new char[strlen(X.branch)+1];
        strcpy(branch,X.branch);
        roll=X.roll;
        year=X.year;
    }
    void operator+=(Student X)
    {
        if(name==NULL)
        {
            name=new char[0];
            name="";
        }
        else if(branch==NULL)
        {
            branch=new char[0];
            branch="";
        }
        char *temp=name;
        name=new char[strlen(temp)+strlen(X.name)+1];
        strcpy(name,temp);
        strcpy(name+strlen(temp),X.name);

        char *temp1=branch;
        branch=new char[strlen(temp1)+strlen(X.branch)+1];
        strcpy(branch,temp1);
        strcpy(branch+strlen(temp1),X.branch);

        roll=roll+X.roll;
        year=year+X.year;
    }
    void SetRoll(int rn)
    {
        roll=rn;
    }
    void Setname(char *n)
    {
        name = new char[strlen(n)+1];
        strcpy(name,n);
    }
    void Setbranch(char *b)
    {
        branch = new char[strlen(b)+1];
        strcpy(branch,b);
    }
    void print()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Branch: "<<branch<<endl;
        cout<<"Roll: "<<roll<<endl;
        cout<<"Year: "<<year<<endl;
    }
    ~Student()
    {
        cout<<"Inside destructor "<<name<<endl;
        count--;
    }
};
int Student::count;

int main()
{
    Student s1;
    s1.Setname("Atif");
    s1.Setbranch("PHE");
    s1.SetRoll(42);  //setter
    s1.year=3;

    Student s2("Tanmay","MnC",17,2);
    Student s3=s1;

    Student *s4=new Student;
    (*s4).Setname("Naman");
    (*s4).Setbranch("ECE");
    (*s4).SetRoll(51);
    (*s4).year=3;

    Student s5;
    s5=(*s4);

    s1.print();
    s2.print();
    s3.print();
    s3+=s2;
    s3.print();
    (*s4).print();
    s5.print();
    cout<<"No of students: "<<Student::count<<endl;
    delete s4;
    s4=NULL;
    cout<<"No of students: "<<Student::count<<endl;
}
