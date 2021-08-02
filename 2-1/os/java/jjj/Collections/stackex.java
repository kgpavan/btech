public class stackex
{
int stck[] = new int[10];
int tos ;
stackex()
{
 tos = -1;
}
void push(int item)
{
 if(tos == 9)
  System.out.println("Stack is full");
  else
  stck[++tos] = item;
}

int pop()
{
  if(tos <0)
  {
    System.out.println("Stack underflow");
    return(-1);
  }
  else
  return stck[tos--];
 }
 void display()
 {
   for(int i=0;i<=tos;i++)
     System.out.print("  " + stck[i] + "   ");
 }

public static void main(String args[])
{
stackex s = new stackex();
for(int i = 0; i<10; i++) s.push(i);
s.display();
System.out.println("\n");
for(int i = 0 ;i<10; i++)
System.out.print("  " + s.pop() + "  ");
}
}
