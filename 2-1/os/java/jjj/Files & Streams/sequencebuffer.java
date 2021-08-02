
      import java.io.*;

      class sequencebuffer
      {
         public static void main(String args[]) throws IOException
         {
              //declares file stream
              FileInputStream file1 = null;
              FileInputStream file2 = null;

              //declare file three to store combined files
              SequenceInputStream file3 = null;

              file1 = new FileInputStream("text1.dat");
              file2 = new FileInputStream("text2.dat");

              //concatenate file1 and file2 into file3
              file3 = new SequenceInputStream(file1,file2);

              //create buffered input and output streams

  BufferedInputStream inbuffer = new BufferedInputStream(file3);
  BufferedOutputStream outbuffer = new BufferedOutputStream(System.out);

  //read and write till the end of buffers
  int ch;
  while((ch = inbuffer.read()) != -1)
  {
     outbuffer.write((char)ch);
  }
  inbuffer.close();
  outbuffer.close();
  file1.close();
  file2.close();
  }
}


            
