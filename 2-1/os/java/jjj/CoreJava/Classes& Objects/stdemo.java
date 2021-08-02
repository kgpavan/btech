import java.util.*;
class stdemo
{
static String in = "Title=Mca and Msc computer science;"+
"institute=SSIL Nellore"  +
"College = Narayana" ;
public static void main(String args[])
{
StringTokenizer st = new StringTokenizer(in,"=;");
while(st.hasMoreTokens())
{
 String key = st.nextToken();
 String val = st.nextToken();
 System.out.println(key  + "\t\t" + val);
}
}
}
