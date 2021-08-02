import java.lang.*;

class comline{
public static void main(String v[]) {
  int sum=0;
  int invalid=0;

for(int i=0;i<v.length;i++){
try{
sum+=Integer.parseInt(v[i]);
 }
catch(Exception e){
invalid++;
    }
   }
System.out.println("Total number of arguments" + v.length);
System.out.println("Sum is" + sum);
System.out.println("Invalid integers are" + invalid);
}
}