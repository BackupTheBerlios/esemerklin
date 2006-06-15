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
 *
 * @author mohamed
 */
public class Stream {
    
    private PrintStream outStream;
    private BufferedReader inputStream;
    private String stream; 
    
    
    /** Creates a new instance of Stream */
    public Stream(Socket s){
        initStreams(s);
    }
    
    
    public void initStreams(Socket s){
        try {
            this.outStream = new PrintStream(s.getOutputStream());
            this.inputStream = new BufferedReader(new InputStreamReader( s.getInputStream()));
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
    
    public String getOutStreams(){
        try {
            stream = inputStream.readLine();
            
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        
        return stream;
    }
    
    
    
}
