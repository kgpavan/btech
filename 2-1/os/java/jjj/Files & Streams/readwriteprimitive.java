
    import java.io.*;

    class readwriteprimitive
    {
      public static void main(String args[]) throws IOException
      {
        File primitive = new File("prim.dat");
        FileOutputStream fos = new FileOutputStream(primitive);
        DataOutputStream dos = new DataOutputStream(fos);

        //write the primitive data to prim.dat
        dos.writeInt(1999);
        dos.writeDouble(375.85);
        dos.writeBoolean(false);
        dos.writeChar('X');
        dos.close();
        dos.close();

        //read the data from the prim.dat
        FileInputStream fis = new FileInputStream (primitive);
        DataInputStream dis = new DataInputStream(fis);
        System.out.println(dis.readInt());
        System.out.println(dis.readDouble());
        System.out.println(dis.readBoolean());
        System.out.println(dis.readChar());

         dis.close();
         fis.close();
         }
      }


