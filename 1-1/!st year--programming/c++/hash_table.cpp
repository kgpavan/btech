#include<iostream>
using namespace std;
class student
{
	string name;
	int roll;
};
class hashtable
{
	private:
		int tablesize;
		student a[size];
	public:
		student(int roll,char name)
		{
			roll=roll;
			name=name;
		}
}
int hash(student s)
{
	int value=0;
	for(i=0;s.name[i]!='\0';i++)
	{
		value=value+s.name[i]*i;
	}
	value=value*19;

