interface intstack
{
 void push(int item);
 void pop();
}

class stack implements intstack{
private int s1[];
private int tos;
stack(int size)
{
  s1 = new int[size];
  tos = -1;
}
public void push(int item)
{
  if(tos == s1.length -1)
    System.out.println("stack is overflow");
    else
    s1[++tos] = item;
  
}
public int pop()
{
  if(tos<0)
  {
   System.out.println("stack is underflow");
   return(0);
  }
  else
    return(s1[tos--]);
}
}
class stacktest{
  public static void main(String args[])
  {
    stack  p = new stack(10);
    for(int i= 0;i<9;i++) p.push(i);
    for(int i= 0;i<9;i++)
    System.out.println(p.pop());
  }
}
