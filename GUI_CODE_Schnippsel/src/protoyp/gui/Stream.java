/*
 * Stream.java
 *
 * Created on 15. Juni 2006, 19:35
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package protoyp.gui;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

/**
 * Diese Klasse ist f&uuml;r die &Uuml;bertragung der Informationen aus der GUI zust&auml;ndig
 * @author mohamed
 */
public class Stream {
    
    private PrintStream outStream;
    private BufferedReader inputStream;
    private String daten;
    
    
    /** 
     * Konstruktor der Klasse Stream.
     * Erstellt eine neue Instanz der Klasse Stream und
     * initialisiert dabei den Lese- und Ausgabestrom
     * @param s Ein Socketdeskriptor vom Typ {@link Socket}  
     */
    public Stream(Socket s){
        initStreams(s);
    }
    
    /**
     * Diese Methode wird im Konstruktor von {@link Stream} aufgerufen.
     * Dabei werden s&auml;mtliche privaten Attribute von der Klasse {@link Stream} 
     * initialisiert
     * @param s Ein Socketdeskriptor vom Typ {@link Socket}
     */
    public void initStreams(Socket s){
        try {
            this.outStream = new PrintStream(s.getOutputStream());
            this.inputStream = new BufferedReader(new InputStreamReader( s.getInputStream()));
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
    
    /**
     * Diese Methode liest aus einem Stream und gibt sie als String zur&uuml;ck
     * @return gibt den Streaminhalt als {@link String} zur&uuml;ck
     */
    public String getOutStreams(){
        try {
            daten = inputStream.readLine();
            
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        
        return daten;
    }
    
    /**
     * Diese Methode gibt die gesendeten Daten zr&uuml;ck
     * @return gesendete Daten als {@link PrintStream}
     */
    public PrintStream getPrinStream(){
        return outStream;
    }
    
  
    /**
     * Die Methode sendStream() sendet einen u&umlbergebenen String zu einen gešffneten Stream
     * @param s Ein {@link String} der gesendet wird
     * @author mohamed
     */
    public void sendStream(String s){
        outStream.println(s);
        outStream.flush();
    }
    
    
    
}
