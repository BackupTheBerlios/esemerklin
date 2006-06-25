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
 * Diese Klasse ist f&uuml;r die Socketverbindung zust&auml;ndig
 * @author mohamed
 */
public class SocketConnect {
    
    
    private static String inet;  
    private static int port = 7;
    private Socket socket = null;
    

    
        
    /**
     * Konstruktor der Klasse SocketConnection.
     * Erstellt eine neuen Instanz der Klasse
     * SocketConnection.
     * @param inet Die IP Adresse des SocketServers
     */
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
    
    /**
     *Gibt den Socketdeskriptor als R&Uuml;ckgabewert zur&Uuml;ck
     *@author mohamed
     *@return Socketdeskriptor vom Typ {@link Socket}
     */
    public Socket getSocket(){
        return socket;
    }
    
    /**
     *Gibt die IP Adresse des Socketservers zur&Uuml;ck
     *@author mohamed
     *@return IP als {@link String} 
     */
    public String setInet(){
        return inet;
    }
    
    /**
     *Gibt den Port des Socketserver z&Uuml;ruck
     *@author mohamed
     *@return Port als int Wert
     */
    public int getPort(){
        return port;
    }

    
    
    
}
