// Decompiled by DJ v2.8.8.54 Copyright 2000 Atanas Neshkov  Date: 2/12/2007 7:31:06 PM
// Home Page : http://members.fortunecity.com/neshkov/dj.html  - Check often for new version!
// Decompiler options: packimports(3) 
// Source File Name:   StringArray.java

import java.io.PrintStream;

class StringArray
{

    StringArray()
    {
    }

    public static void main(String args[])
    {
        String args1[] = new String[5];
        args1[0] = "String 0";
        args1[1] = "String 1";
        args1[2] = "String 2";
        args1[4] = "String 4";
        System.out.println(args1.length);
        System.out.println(args1[0]);
        System.out.println(args1[1]);
        System.out.println(args1[2]);
        System.out.println(args1[3]);
        System.out.println(args1[4]);
    }
}
