 import java.io.*;

class linenumber
{
public static void main(String args[]) throws Exception
{
  String source = "This is the time for lunch \n This is a cat";
  char buf[] = new char[source.length()];
  source.getChars(0,source.length(),buf,0);
  FileWriter fo = new FileWriter("file1.txt");
  fo.write(buf);
  fo.close();

 FileReader f1 = new FileReader("file1.txt");
LineNumberReader br = new LineNumberReader(f1);

try
{
  System.out.println(br.readLine());
  System.out.println("The line number is" + br.getLineNumber());
  System.out.println(br.readLine());
  br.setLineNumber(2);
  System.out.println(br.readLine());
  System.out.println("The line number is" + br.getLineNumber());

}
catch(Exception e) {}

 }
}


