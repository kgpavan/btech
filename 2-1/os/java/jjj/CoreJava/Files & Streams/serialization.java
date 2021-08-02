import java.io.*;
public class serialization
{
  public static void main(String args[])
  {
    try
     {
        myclass ob1 = new myclass(1,"first");
        System.out.println("object 1  " + ob1);
        FileOutputStream fos = new FileOutputStream("serial.txt");
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        oos.writeObject(ob1);
        oos.flush();
        oos.close();
    }
    catch(Exception e)
    {
      System.out.println("exception");
    }

    try
    {
     myclass ob2;
     FileInputStream fis = new FileInputStream("serial.txt");
     ObjectInputStream ois = new ObjectInputStream(fis);
     ob2 = (myclass) ois.readObject();
     ois.close();
     System.out.println("from the file the value is" + ob2);
     }
     catch(Exception e) {  }
    }
  }
  class myclass implements Serializable
  {
    String s;
    int i;
    public myclass(int i, String s)
    {
     this.i = i;
     this.s = s;
    }
    public String toString()
    {
     return " s= " + s +" i = "  + i;
    }
  }
