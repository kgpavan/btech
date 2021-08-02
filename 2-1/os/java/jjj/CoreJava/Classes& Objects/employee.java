class employee
{
String name;
int no;
int seniority;

void setemployee(String a1, int a2, int a3)
{
  name = a1;
  no = a2;
  seniority = a3;
}
employee()
{
System.out.println(" ");
}
void display()
{
System.out.println(name + "       " + no + "       " + seniority);
}
public static void main(String args[])
{
  employee e[] = new employee[5];
  String str[] = {"first","second","third","fourth","fifth"};
  int i=1,j=1;
  try
  {
  for(i=0;i<5;i++)
  {
    e[i]=new employee();
    e[i].setemployee(str[i],i, i);
  }

 for(i=0;i<5;i++)
   e[i].display();



  for(i=0;i<4;i++)
  {
    for(j=0;j<4-i;j++)
    {
       employee  temp = new employee() ;
       if (e[j].seniority < e[j+1].seniority)
       {
         temp = e[j];
         e[j] = e[j+1];
        e[j+1] = temp;
       }
    }
 }
 System.out.println("the result is");
 for(i=0;i<5;i++)
   e[i].display();
 }
 catch(Exception e1) { System.out.println("asdfasdfasdf");}
 }
}



