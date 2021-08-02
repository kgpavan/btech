import java.util.*;
class iftest{
 public static void main(String args[]){
 int month=4;
 String season;

 if(month==12 || month==1 || month==2){
 season="Spring";
 }
 else if(month==3 || month==4 || month==5){
 season = "Summer";
 }
 else if(month==6 || month== 7 || month==8){
 season= "autum";
 }
 else if(month==9 || month==10 || month== 11){
  season="winter";
 }
 else
 {
  season= "Invalid month";
 }
System.out.println("April is" + season);
 }
}