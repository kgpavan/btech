class towdimen1{
public static void main(String args[]){
  int towd[][][][] = new int[5][5][5][5];
  int i,j,k = 1,l,m,n,p,q,r,s,t;
  for(t=0;t<4;t++)
  for(s=0;s<4;s++)
  for(r=0;r<4;r++)
  for(q=0;q<4;q++)
   for(j=0;j<5;j++)     {
     towd[t][s][r][q]= k;
      k++;
      }
  for(t=0;t<4;t++)
  for(s=0;s<4;s++)
  for(r=0;r<4;r++)
   for(q=0;q<4;q++)
     {
     System.out.println(towd[t][s][r][q]);
      }
 }
 }