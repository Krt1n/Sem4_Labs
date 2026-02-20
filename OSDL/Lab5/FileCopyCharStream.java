package Lab5;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class FileCopyCharStream {
    public static void main(String[] args) {
        try {
            FileReader fr = new FileReader("D:\\240911550\\Lab5\\Sample.txt");
            FileWriter fw = new FileWriter("D:\\240911550\\Lab5\\Destination1.txt");

            int ch;

            while ((ch = fr.read()) != -1) {
                fw.write(ch);
            }

            fr.close();
            fw.close();

            System.out.println("Text file copied successfully.");

        } catch (IOException e) {
            System.out.println("File error: " + e.getMessage());
        }
    }  
}
