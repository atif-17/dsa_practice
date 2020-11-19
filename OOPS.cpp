// OOPS
#include <iostream>
#include<cstring>
using namespace std;
// -------------- BLUE PRINT -------------------
class Car{
private:
	int price;
public:
    static int count;
	char *name;
	int model;
	int seats;
	const int tyres;

	// Default Constructor
	Car():tyres(4)
	{
		cout<<"In Default Constructor"<<endl;
		name=NULL;
		count++;
	}

	// Parameterzied constructor
	Car(char *n, int p, int s,int m):tyres(4),price(p),seats(s)
	{
	    cout<<"In parameterized constructor"<<endl;
	    name=new char[strlen(n)+1];
	    strcpy(name,n);
	    price=p;
	    seats=s;
	    model=m;
	    count++;
	}
	void SetPrice(int p)
	{
	    if(p>345678 || p<78)
            price=567889;
        else
            price=p;
	}
	int GetPrice()const
	{
	    return price;
	}
	void SetName(char *n)
	{
	    name=new char[strlen(n)+1];
	    strcpy(name,n);
	}
	void Print()const
	{
	    cout<<"Name: "<<name<<endl;
	    cout<<"Price: "<<price<<endl;
	    cout<<"Model: "<<model<<endl;
	}
	Car(Car &X) :tyres(4) //Copy constructor
	{
	    name=new char[strlen(X.name)+1]; //space allocate hia
	    strcpy(name,X.name);
	    price=X.price;
	    model=X.model;
	    count++;
	}
	void operator=(Car X)
	{
	    if(name!=NULL)
        {
            delete []name;
            name=NULL;
        }
	    name=new char[strlen(X.name)+1];
	    strcpy(name,X.name);
	    price=X.price;
	    model=X.model;
	}
	~Car()
	{
	    cout<<"In destructor"<<name<<endl;
	    count--;
	}
};
int Car::count;

int main()
{
    Car a;
    a.SetName("BMW");
	// a.price = 100;
	a.SetPrice(4234);
	a.model = 2000;
	a.seats = 5;
	Car b("Audi",43535554,2,2020);
	Car c=b;
	Car d(c);
	c.name[0]='L';
	//Operator overloading
	b=a;
	Car e;
	e=a;
	a.Print();
	b.Print();
	c.Print();
	d.Print();
	e.Print();
	Car *g=new Car;
	//assessing data members by deference operator
	(*g).name=new char[10];   //object in dynamic memory
	strcpy((*g).name,"F1");
	(*g).SetPrice(335);
	(*g).model=244;
	(*g).Print();

	cout<<"No of cars: "<<Car::count<<endl;

	delete g;
	g=NULL;

	cout<<"No of cars: "<<Car::count<<endl;
}
