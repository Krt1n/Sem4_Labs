import java.io.*;

public class fileusingbyte {
    public static void main(String[] args){
        FileInputStream fis = null;
        FileOutputStream fos = null;

        try{
            fis = new FileInputStream("D:\\\\240911550\\\\Lab5\\\\Sample.txt");
            fos = new FileOutputStream("D:\\\\240911550\\\\Lab5\\\\Destination.txt");

            int data;

            while((data = fis.read())!=-1){
                fos.write(data);
            }
            System.out.println("File Copied Successfully");
        } catch (IOException e) {
            System.out.println("File Error: "+e.getMessage());
        } finally{
            try{
                if(fis!=null){
                    fis.close();
                }
                if(fos!=null){
                    fos.close();
                }
            } catch(IOException e){
                    System.out.println("Error closing file");
            }
        }
    }
}
