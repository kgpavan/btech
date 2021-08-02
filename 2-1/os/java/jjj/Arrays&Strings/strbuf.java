
class strbuf {
public static void main(String args[]){

String f = "software";
String s1 = "solutions   " + f + "ltd" + Integer.toString(524001);
System.out.println(s1);

//the equilant using string buffer

StringBuffer sb = new StringBuffer("nellore");
sb.append(f);
sb.append("india");
System.out.println(sb);

}
}






