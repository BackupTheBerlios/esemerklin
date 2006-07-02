/*
 * Lock.java
 *
 * Created on 25. Juni 2006, 16:14
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package gui;

/**
 * Die Klasse Lock ist für die Lokverwaltung zust&auml;ndig
 * @author arrass
 */
public class Lock {
    
    protected String LockID;
    protected String Sonderfunktion = "Hallo";
    protected char befehl;
    
    /** Creates a new instance of Lock */
    public Lock() {
    }
    
    /**
     * Gibt die 
     */
    public String getLockID(){
        return LockID;
    }
    
    public void setLockID(String LockID){
         this.LockID = LockID;   
    }
    
    
    public void getSpeed(){}
    
    public void setSpeed(){}
    
    public void getFunction(){}
    
    public void setFunction(){}
    
    public char getBefehl(){
        return befehl;
    }
    
    public void setBefehl(char befehl){
        this.befehl = befehl;
    }
    

}
