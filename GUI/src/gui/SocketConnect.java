/*
 * socketConnect.java
 *
 * Created on 15. Juni 2006, 16:36
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package gui;

import java.awt.TextField;
import java.net.*;
import java.io.*;
import javax.swing.JOptionPane;


/**
 * Diese Klasse ist f&uuml;r die Socketverbindung und das ein- und auslesen 
 * aus dem Socketstream zust&auml;ndig
 * @author mohamed
 */
public class SocketConnect {
    
    
    private static String inet;  
    private static int port = 7;
    private Socket socket;
    
    private PrintStream outStream;
    private BufferedReader inputStream = null;
    

    
        
    /**
     * Konstruktor der Klasse SocketConnection.
     * Erstellt eine neuen Instanz der Klasse
     * SocketConnection.
     * @param inet Die IP Adresse des SocketServers
     */
    public SocketConnect(String inet){
       this.inet = inet;
        
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
    
    /**
     * Die Methode connect() baut eine Verbindung mit dem Socketserver auf
     */
    public void connect(){
        
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
     * Die Methode disconnect() schließt eine vorhandene Verbindung zu einem Socketserver
     */
    public void disconnect(){
    try {
           socket.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
    
    /**
     * Die Methode sendStream() sendet einen String Parameter über eine vorhandenen Socketverbindung
     * @param daten Ein String der die zu sendenden Informationen enthält
     */
    public void sendStream(String daten){
        
        
        try {
            outStream = new PrintStream(socket.getOutputStream());
            outStream.println(daten);
            outStream.flush();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
    
    
    /**
     * Die Methode readStream() ließt aus einen offenen Stream die Informationen raus und
     * gibt diese als String zurück
     * @return Die Informationen aus dem Socketstream als String 
     */
    public String readStream(){
        
        
    try {
            inputStream = new BufferedReader(new InputStreamReader( socket.getInputStream()));
            return(inputStream.readLine());
        } catch (IOException ex) {
            JOptionPane.showMessageDialog(null,"Keine rückantwort vom SocketServer");
            ex.printStackTrace();
            return "Keine Daten empfangen";
        }
        
    }
    
            
           

    
    
    
}
