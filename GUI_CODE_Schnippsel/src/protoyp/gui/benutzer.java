/*
 * benutzer.java
 *
 * Created on 25. Juni 2006, 23:49
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package protoyp.gui;

/**
 *
 * @author arrass
 */
public class benutzer {
    
    private int benutzerStatus;
    private String Benutzer;
    private String Password;
    
    
    /** Creates a new instance of benutzer */
    public benutzer(){
    }
    
    public void setBenutzer(String Benutzer){
    this.Benutzer = Benutzer;
    }
    
    public void setPassword(String Password){
    this.Password = Password;
    }
    
    public String getBenutzer(){
    return Benutzer;
    }
    
    public String getPassword(){
    return Password;
    }
    
    public void sendData(String Benutzer, String Password){}
    
    public void getBenutzerStatus(){}
}
