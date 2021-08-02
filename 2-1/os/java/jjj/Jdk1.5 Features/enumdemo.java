enum java {
servlets,jsp,beans,ejb,struts
  }

class enumdemo {
public static void main(String args[]) {
 java j;

   j =java.ejb;

System.out.println("Value of enum is" + j);
System.out.println();

  j= java.jsp;

if(j==java.jsp)
System.out.println("J contains jsp");
   
  switch(j) {
     case servlets:
     System.out.println("Servlets are web applications");
     break;
     case jsp:
     System.out.println("Jsp is simple");
     break;
     case ejb:
     System.out.println("Used for business logic");
     break;
     case beans:
     System.out.println("resuable component");
     break;
     case struts:
     System.out.println("MVC 2 arch");
     break;
        }
    }
} 