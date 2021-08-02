import java.io.DataInputStream;
class array
{

public static void main(String args[])
{
DataInputStream in = new DataInputStream(System.in);
int a[][] = { {1,2,3,4,5},{1,1,1,1,1}};

int row,col,i,j;
try
{

/*System.out.println("Enter the number of rows");
row =Integer.parseInt(in.readLine());
System.out.println("Enter the number of cols");
col =Integer.parseInt(in.readLine());

a = new int[row][col]; 
for(i=0;i<2;i++)
{
 for(j=0;j<5;j++)
  a[i][j] =Integer.parseInt(in.readLine());
}             */

for(i=0;i<2;i++)
{
 for(j=0;j<5;j++)
 System.out.print(a[i][j] + "    ");
 System.out.println();
}
 }
 catch(Exception e) {  System.out.println("err"); }
 }
 }
