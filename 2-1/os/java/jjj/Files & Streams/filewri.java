import java.io.*;

class filewri
{
public static void main(String args[]) throws Exception
{
  String source = "This is the time for lunch";
  char buf[] = new char[source.length()];
  source.getChars(0,source.length(),buf,0);
  FileWriter fo = new FileWriter("file1.txt");
  fo.write(buf);
  fo.close();

 FileReader f1 = new FileReader("file1.txt");
 BufferedReader br = new BufferedReader(f1);
 int a;
 while((a=br.read())!=-1)
 System.out.print((char)a);
 }
}


