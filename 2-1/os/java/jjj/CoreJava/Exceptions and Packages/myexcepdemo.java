class myexception extends Exception{
int detail;
myexception(int a){
detail=a;
}
}

class myexcepdemo{

static void compute(int a) throws myexception {
System.out.println("Called compute" + a);

if(a>10)
throw new myexception(a);

System.out.println("normal exit");
  }

public static void main(String args[]){
try{
     compute(1);
     compute(2);
     compute(12);
    }
catch(myexception e){
System.out.println("Caught Exception");
}
}
}