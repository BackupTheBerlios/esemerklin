/*
 * benutzer.java
 *
 * Created on 25. Juni 2006, 23:49
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package gui;

/**
 * Die Klasse Benutzer ist f�r die Benutzerverwaltung zust&auml;ndig
 * @author arrass
 */

public class Benutzer{
    
    protected int benutzerStatus = 0;
    protected String Benutzer;
    protected String Password;
    
    
    /** Creates a new instance of benutzer */
    public Benutzer(){
    }
    
    /**
     * Die Methode setBenutzer() speichert den Benutzer
     * @param Benutzer Der Benutzername als String Wert
     */
    public void setBenutzer(String Benutzer){
    this.Benutzer = Benutzer;
    }
    
    /**
     * Die Methode setPassword() speichert das Passwort des Benutzers
     * @param Password Das Password der Benutzers
     */
    public void setPassword(String Password){
    this.Password = Password;
    }
    
    
    /**
     * Gibt den aktuellen Benutzer zur�ck
     * @return der aktuelle Benutzername als String
     */
    public String getBenutzer(){
    return Benutzer;
    }
    
    /**
     * Gibt das Password als Benutzer zur�ck
     * @return Das aktuelle Benutzerpasswort als String
     */
    public String getPassword(){
    return Password;
    }
    
    /**
     * Setzt den Benutzerstatus ein
     * @param benutzerStatus Der Status des Benutzer 
     */
    public void setBenutzerStatus(int benutzerStatus){
        this.benutzerStatus = benutzerStatus;
    }
   
    /**
     * Gibt den aktuellen Benutzerstatus zur�ck
     * @return Benutzerstatus als int Wert
     */
    public int getBenutzerStatus(){
        return benutzerStatus;
    }
}
