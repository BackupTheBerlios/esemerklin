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
import javax.swing.JOptionPane;


/**
 *
 * @author mohamed
 */
public class SocketConnect {
    
    
    private static String inet;  
    private static int port = 7;
    private Socket socket = null;
    

    
        
    /** Creates a new instance of socketConnect */
    public SocketConnect(String inet){
        this.inet = inet;
        try {
            socket = new Socket(inet ,port); 
        } catch (UnknownHostException ex) {
            JOptionPane.showMessageDialog(null,"Verbindung zum Socket Server konnte nicht hergestellt werden");
            ex.printStackTrace();
            System.out.println("Keine Host gefunden");
        } catch (IOException ex) {
            JOptionPane.showMessageDialog(null,"Verbindung zum Socket Server konnte nicht hergestellt werden");
            ex.printStackTrace();
        }
    }
    
    public Socket getSocket(){
        return socket;
    }
    public void sendStream(){}
    
    
    public String setInet(){
        return inet;
    }
    
    public int getPort(){
        return port;
    }

    
    
    
}
