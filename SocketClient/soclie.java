import java.io.*;
import java.applet.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.*;

public class soclie extends Applet implements ActionListener{

    Socket socket = null;
    
    PrintStream os;
    BufferedReader in;
    
    TextField field;
    
    String s;
    String test = "";
    String inet = "192.168.0.10";
    
    
    //init(): Hier findet die gesamte einmal Initialisierung des Applet statt
    public void init(){
        
        field = new TextField("Hallo Test");
        field.setColumns( 20 );
        add( field );
        field.addActionListener(this);
        
        try{
            socket = new Socket( getCodeBase().getHost() , 7);
             }
        catch(UnknownHostException e){
             // TODO Auto-generated catch block
             e.printStackTrace();
             } 
        catch(IOException e){
             // TODO Auto-generated catch block
             e.printStackTrace();
             }
        
        
        
        }
    

    // Alles was das Applet ausführen soll
    public void start(){
        
        try{
            os = new PrintStream( socket.getOutputStream() );
            in = new BufferedReader(new InputStreamReader( socket.getInputStream()) );
            
            //os.println(field.getText());
            //s = in.readLine();
            } 
        catch(IOException e){
            // TODO Auto-generated catch block
            e.printStackTrace();
            }
        }
    
    // Wenn das Applet z.B. verkleinert oder nicht genutzt wird
    public void stop(){}
    
    
    // Wenn das Applet geschlossen wird
    public void destroy(){
        try{
           socket.close();
            }
        catch(IOException e){
            // TODO Auto-generated catch block
            e.printStackTrace();
            }
        }

    
    public void actionPerformed(ActionEvent arg0){

        // Eingabe Strom zum Echo Server schicken
        os.println(field.getText());
        try {
            test = in.readLine();
            } 
        catch(IOException e){
            // TODO Auto-generated catch block
            e.printStackTrace();
            }
        
        System.out.println(test);
        //test = field.getText();
        repaint();
        }
    
    public void paint(Graphics g){
        g.drawString( test, 10, 60 );
        }
}
