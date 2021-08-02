import java.io.*;
class wordcount
{
public static int lines = 0;
public static int chars = 0;
public static void ws(InputStream f) throws IOException{
int c = 0;
String whitespace = "\t\n\r";
while((c=f.read()) != -1)
{
 chars++;
 if(c=='\n')
 lines++;
}
System.out.println("The numbe of lines" + lines);
System.out.println("The number of chars " + chars);
}
public static void main(String args[])
{
 FileInputStream f;
 try
 {
 f = new FileInputStream("abc.txt");
 ws(f);
 }
 catch(IOException e)
 {
 System.out.println("error");
 }
System.out.println("end of program");
}
}
 
