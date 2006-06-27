/*
 * Lock.java
 *
 * Created on 25. Juni 2006, 16:14
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package protoyp.gui;

/**
 *
 * @author arrass
 */
public class Lock {
    
    private String LockID;
    private String Sonderfunktion = "";
    private char befehl;
    private char Typ = 108;
    
    /** Creates a new instance of Lock */
    public Lock() {
    }
    
    public String getLockID(){
        return LockID;
    }
    
    public void setLockID(String LockID){
         this.LockID = LockID;   
    }
    
    public void setSonderFunktion(String Funktion){
        Sonderfunktion = Funktion;
    }
    
    public String getSonderFunktion(){
        return Sonderfunktion;
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
    
    public char getTyp(){
        return Typ;
    }
}
