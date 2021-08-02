class employee {
    int empno;
    float empsal;

   employee(int e,float f) {
      empno=e;
      empsal=f;
     }
 void display() {
 System.out.println("The employee number is" + empno);
 System.out.println("The employee salary is" + empsal);
  }
}

class empdetails {
public static void main(String args[]) {

employee e = new employee(10,5000);
e.display();
}
}

    