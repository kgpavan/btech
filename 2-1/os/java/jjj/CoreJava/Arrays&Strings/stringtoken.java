import java.util.*;

class stringtoken{
public static void main(String args[]) {
String sample = "This is the string;it should get divide into tokens;a=b+c;";
StringTokenizer st = new StringTokenizer(sample,";+=");
String s1 = " ";

while(st.hasMoreTokens()) {
String s = st.nextToken();
System.out.println(s);
}
System.out.println(s1);
}
}