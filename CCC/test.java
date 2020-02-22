package CCC;
import java.io.*;
class test{
    public static void main(String[] args)throws IOException{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String name;
        name = reader.readLine();
        while(!name.equals("stop")){
            System.out.println("??");
            name = reader.readLine();
        }

    }

}
