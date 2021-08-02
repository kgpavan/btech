import java.util.*;
class datedemo
{
public static void main(String args[])
{
Date date = new Date();
System.out.println(date);
long msec = date.getTime();
long mdate = date.getDay();
System.out.println(mdate);


Date d1 = new Date(99,4,10);
System.out.println(d1);
System.out.println(date.before(d1));
}
}
