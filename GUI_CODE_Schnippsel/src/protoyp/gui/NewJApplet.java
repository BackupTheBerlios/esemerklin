/*
 * NewJApplet.java
 *
 * Created on 15. Juni 2006, 16:27
 */

package protoyp.gui;
import java.io.BufferedReader;
import java.io.IOException;


/**
 *
 * @author  mohamed
 */
public class NewJApplet extends javax.swing.JApplet {
    

    
    /** Initializes the applet NewJApplet */
    public void init() {
       

        try {
            java.awt.EventQueue.invokeAndWait(new Runnable(){
                    public void run(){
                        initComponents();
                    }
                }
            );
            
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
    
    public void start(){}
    
    public void stop(){
        
       /* try{
           socket.close();
            }
        catch(IOException e){
            // TODO Auto-generated catch block
            e.printStackTrace();
            }    */
    }
    
    /** This method is called from within the init() method to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    // <editor-fold defaultstate="collapsed" desc=" Generated Code ">//GEN-BEGIN:initComponents
    private void initComponents() {

        org.jdesktop.layout.GroupLayout layout = new org.jdesktop.layout.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 272, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 189, Short.MAX_VALUE)
        );
    }// </editor-fold>//GEN-END:initComponents
    
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
    
}
