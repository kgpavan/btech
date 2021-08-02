import java.util.Date;

class sortedemployee{
 Date doa;
 String name;

sortedemployee(String newname, Date newdoa){
  name = newname;
  doa = new Date();
  doa = newdoa;
 }
void display(){
System.out.println("Name :" +name+"\nDate of Appointment:"+doa.getDate() + "/"+ doa.getMonth() + "/"+ doa.getYear());
 }

public static void main(String args[]){

 sortedemployee e[];
 int k;
 e = new sortedemployee[5];

e[0] = new sortedemployee("Deepa Mehta", new Date(98,3,22));
e[1] = new sortedemployee("Ravi Kiran", new Date(98,4,23));
e[2] = new sortedemployee("Akila", new Date(99,5,26));
e[3] = new sortedemployee("Rajan", new Date(98,3,26));
e[4] = new sortedemployee("Venu", new Date(96,8,26));


   for(int i=0;i<4;i++){
        for(int j=i+1; j<5;j++){
  if(e[i].doa.after(e[j].doa)){

    Date tempdoa;
    String tempname;

     tempdoa= e[i].doa;
     e[i].doa = e[j].doa;
     e[j].doa = tempdoa;

    tempname = e[i].name;
    e[i].name = e[j].name;
    e[j].name = tempname;
   }
         }
       }
      for(k=0;k<5;k++){
      e[k].display();
       }
     }
   } 