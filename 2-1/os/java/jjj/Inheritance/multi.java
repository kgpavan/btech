class student {
int rollnumber;
void getnumber(int n){
rollnumber=n;
}
void putnumber(){
System.out.println("The Roll number is" + rollnumber);
   }
}
class test extends student{

float part1,part2;

void getmarks(float m1,float m2) {
part1=m1;
part2=m2;
}
void putmarks(){
System.out.println("the marks obtained is" + part1+" "+ part2);
   }
}

interface sports {
float sportswt=6.0f;
void putwt();
}

class results extends test implements sports{
float total;
public void putwt(){
System.out.println("The sports marks is" + sportswt);
}
void display(){
total= part1+part2+sportswt;
putnumber();
putmarks();
putwt();
System.out.println("Total Score is" + total);
}
}
class multi{
public static void main(String args[]) {

results stud = new results();
stud.getnumber(1234);
stud.getmarks(27.5F,33.0F);
stud.display();
     }
}