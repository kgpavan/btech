import java.util.*;

class watch1 implements Observer{
public void update(Observable obj, Object arg)  //observer function
{
System.out.println("count is " + ((Integer)arg).intValue());
}
}

class watch2 implements Observer {
public void update(Observable obj, Object arg)
{
System.out.println("count from second is " + ((Integer)arg).intValue());
}
}
class beginwatch extends Observable
{
 void counter(int period)
 {
   for(;period>=0;period--)
   {
   setChanged();  //ready for signal
   notifyObservers(new Integer(period));   //sending signal
   try
   {
     Thread.sleep(100);
   } catch(InterruptedException e)
     {
       System.out.println("sleep interruped");
     }
  } //for
 } // counter
}
class testobserver{
public static void main(String args[])
{
beginwatch observed = new beginwatch();
watch1  ob1 = new watch1();
watch2  ob2 = new watch2();
observed.addObserver(ob1);   //register observer1
observed.addObserver(ob2);   // register observer2
observed.counter(5);
}
}

