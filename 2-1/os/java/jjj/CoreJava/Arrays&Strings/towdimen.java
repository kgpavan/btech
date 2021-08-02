import java.lang.*;

class towdimen{
public static void main(String args[]) {

  int towd[][] = new int[4][];
  
  int i,j,k=1;

  towd[0] = new int[1];
  towd[1] = new int[2];
  towd[2] = new int[3];
  towd[3] = new int[4];

  for(i=0;i<4;i++)
  for(j=0;j<towd[i].length;j++)
     {
     towd[i][j] = k;
      k++;
      }
for(i=0;i<4;i++) {
for(j=0;j<towd[i].length;j++)
System.out.print(towd[i][j] + "    ");
System.out.println();
  }
 }
 }