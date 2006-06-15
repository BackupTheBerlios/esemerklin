/*
 * socketConnect.java
 *
 * Created on 15. Juni 2006, 16:36
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package protoyp.gui;
import java.awt.TextField;
import java.net.*;
import java.io.*;

/**
 *
 * @author mohamed
 */
public class SocketConnect {
    
    private static String inet = "169.254.9.81";
    private static int port = 7;
    private Socket socket = null;
    

    
        
    /** Creates a new instance of socketConnect */
    public SocketConnect(){        
    }
    
    /*
     * Liest Information aus dem Einkommenden Stream
     * @return Den
     */ 
    public PrintStream getStream(TextField field){
        
        return outStream;
        
    }
    
    public void setStream(){}
    
    
    public String getInet(){
        return inet;
    }
    
        
    public void initSocket(){
             try {
                socket = new Socket( inet , port);
            } catch (UnknownHostException ex) {
                ex.printStackTrace();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        
  
    }
    
    
}
