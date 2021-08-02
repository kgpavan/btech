import java.io.*;
class matrix
{
  public static void main(String args[])
  {
    DataInputStream in = new DataInputStream(System.in);
    int i=2,j,m,n;
    int p[][] = {{1,2,3},{3,4,6}};
    int m1[][]  = { {i*1,i*2,i*3,i*4},{i*5,i*6,i*7}};
    int q[][];
    int r[][] = new int[5][];
 try
    {
       q = new int[5][5];
       r[0] = new int[5];
       r[1] = new int[4];

       m = Integer.parseInt(in.readLine());
      n = Integer.parseInt(in.readLine());
      m1 = new int[m][n];
      for(i=0;i<m;i++)
      {
        for(j=0;j<n;j++)
        {
          m1[i][j] = Integer.parseInt(in.readLine());
        }
     }

     for(i=0;i<m;i++)
      {
        for(j=0;j<n;j++)
       System.out.print(m1[i][j] + "       " );
       System.out.println();
       
     }
   }catch(IOException e)  {   }

 }

}

