import java.io.ObjectOutputStream;
import java.net.Socket;
import java.io.PrintWriter;
import java.io.IOException;

public class PortTest {


    private String host;
    private int port;

    public PortTest(String host, int port) {
        this.host=host;
        this.port=port;
    }

    public void Test() {
        try { 
            Socket socket = new Socket(this.host,this.port);
            PrintWriter out = new PrintWriter(socket.getOutputStream(),true);
            out.println("");
            System.out.println("OK");
        } catch (Exception e) { System.out.println(e.getMessage()); }
    }

    public static void main(String[] args) {
        try {
            PortTest t = new PortTest(args[0],Integer.parseInt(args[1]));
            t.Test();
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
