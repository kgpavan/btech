import java.io.*;
//super class here
class  Student {
protected int sno;
protected String sname;
protected String sm1,sm2,sm3;
protected int m1,m2,m3;

public void input() {
  System.out.println("Enter the student details");

   try{
  
  System.out.println("Enter Student Number");
  DataInputStream dis = new DataInputStream(System.in);
  sno = Integer.parseInt(dis.readLine());
  
  System.out.println("Enter the Student Name");
  DataInputStream dis1 = new DataInputStream(System.in);
  sname= dis1.readLine();

  System.out.println("Enter the marks1");
  DataInputStream dis2= new DataInputStream(System.in);
  m1= Integer.parseInt(dis2.readLine());
 
 System.out.println("Enter the marks2");
  DataInputStream dis3= new DataInputStream(System.in);
 m2= Integer.parseInt(dis3.readLine());

  System.out.println("Enter the marks3");
//  sm3=dis.readLine();
  DataInputStream dis4= new DataInputStream(System.in);
  m3= Integer.parseInt(dis4.readLine());
  }
  catch(Exception e)
  {
   System.out.println("Error in input");
   }
  } //end of function
  } // end of class

//sub class defined here
  class StudRes extends  Student  {
  protected int tot;
  protected float avg;
 protected char grade;

 public void cal() {
 tot = m1+m2+m3; 
  avg=tot/3.0f;
    if(m1<35 || m2<35 || m3<35)
	      grade='F';
	else
	    grade='P';
	}
	public void show() {
	System.out.println("The Student no is" +sno);
	System.out.println("The Student name is" +sname);
	System.out.println("The total marks are" + tot);
	System.out.println("The average is" + avg);
	System.out.println("The grade is" + grade);
} // end of function
} //end of class

class SingleInherit2 {
 public static void main(String args[]) {
  StudRes sr = new StudRes();
  sr.input();
  sr.cal();
  sr.show();
  }
  }