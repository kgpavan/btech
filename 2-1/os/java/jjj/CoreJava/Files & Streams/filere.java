import java.io.*;

class filere
{
public static void main(String args[]) throws Exception
{
FileReader fr = new FileReader("samp.txt");

BufferedReader br = new BufferedReader(fr);
String s;
while((s=br.readLine())!= null)
System.out.println(s);
fr.close();
}
}
