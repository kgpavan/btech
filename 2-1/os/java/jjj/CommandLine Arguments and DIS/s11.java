import java.io.DataInputStream;
class box
{
  int length,width,height,volume;
 void  compute_vol()
  {
  DataInputStream in = new DataInputStream(System.in);
  try
  {
  length = Integer.parseInt(in.readLine());
  width = Integer.parseInt(in.readLine());
  height = Integer.parseInt(in.readLine());
  volume = length * width * height;
  System.out.println("The volume is " + volume);
  
  }
  catch(Exception e) {  }
 }
}
class s11
{
  public static void main(String args[])
  {

     box b2 = new box();
      b2.compute_vol();
  }
}
