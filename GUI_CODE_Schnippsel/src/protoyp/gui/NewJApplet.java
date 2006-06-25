/*
 * NewJApplet.java
 *
 * Created on 15. Juni 2006, 16:27
 */

package protoyp.gui;
import java.io.BufferedReader;
import java.io.IOException;
import java.net.URL;
import java.net.URLEncoder;
import java.io.*;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import javax.swing.*;


/**
 *
 * @author  mohamed
 */
public class NewJApplet extends javax.swing.JApplet {
    

    SocketConnect socketCon;
    Stream stream;
    
    /** Initializes the applet NewJApplet */
    public void init() {
        
    socketCon = new SocketConnect("192.168.0.1"); 
    stream = new Stream(socketCon.getSocket());
    

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
    
 public void destroy(){
     
     stream.getPrinStream().close();
     try {
           socketCon.getSocket().close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }   
 }   
 


    /** This method is called from within the init() method to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    // <editor-fold defaultstate="collapsed" desc=" Generated Code ">//GEN-BEGIN:initComponents
    private void initComponents() {
        jFrame1 = new javax.swing.JFrame();
        jPanel3 = new javax.swing.JPanel();
        jInternalFrame1 = new javax.swing.JInternalFrame();
        benutzer = new javax.swing.JFormattedTextField();
        password = new javax.swing.JPasswordField();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jButton1 = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        Nachrichtenbox = new javax.swing.JInternalFrame();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jScrollPane4 = new javax.swing.JScrollPane();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTextPane1 = new javax.swing.JTextPane();
        jScrollPane2 = new javax.swing.JScrollPane();
        jTextPane2 = new javax.swing.JTextPane();
        jInternalFrame2 = new javax.swing.JInternalFrame();
        jTabbedPane1 = new javax.swing.JTabbedPane();
        jPanel2 = new javax.swing.JPanel();
        jCheckBox4 = new javax.swing.JCheckBox();
        jCheckBox5 = new javax.swing.JCheckBox();
        jPanel1 = new javax.swing.JPanel();
        jPanel4 = new javax.swing.JPanel();
        jPanel5 = new javax.swing.JPanel();
        jInternalFrame3 = new javax.swing.JInternalFrame();

        org.jdesktop.layout.GroupLayout jFrame1Layout = new org.jdesktop.layout.GroupLayout(jFrame1.getContentPane());
        jFrame1.getContentPane().setLayout(jFrame1Layout);
        jFrame1Layout.setHorizontalGroup(
            jFrame1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 400, Short.MAX_VALUE)
        );
        jFrame1Layout.setVerticalGroup(
            jFrame1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 300, Short.MAX_VALUE)
        );
        org.jdesktop.layout.GroupLayout jPanel3Layout = new org.jdesktop.layout.GroupLayout(jPanel3);
        jPanel3.setLayout(jPanel3Layout);
        jPanel3Layout.setHorizontalGroup(
            jPanel3Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 100, Short.MAX_VALUE)
        );
        jPanel3Layout.setVerticalGroup(
            jPanel3Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 100, Short.MAX_VALUE)
        );

        jInternalFrame1.setVisible(true);
        benutzer.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                benutzerActionPerformed(evt);
            }
        });
        benutzer.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                benutzerKeyPressed(evt);
            }
        });

        password.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                passwordActionPerformed(evt);
            }
        });

        jButton2.setText("Konfiguration");

        jButton3.setText("Abmelden");

        jButton1.setText("login");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jLabel1.setText("Benutzer");

        jLabel2.setText("Passwort");

        org.jdesktop.layout.GroupLayout jInternalFrame1Layout = new org.jdesktop.layout.GroupLayout(jInternalFrame1.getContentPane());
        jInternalFrame1.getContentPane().setLayout(jInternalFrame1Layout);
        jInternalFrame1Layout.setHorizontalGroup(
            jInternalFrame1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(org.jdesktop.layout.GroupLayout.TRAILING, jInternalFrame1Layout.createSequentialGroup()
                .addContainerGap()
                .add(jInternalFrame1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.TRAILING)
                    .add(password, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 143, Short.MAX_VALUE)
                    .add(org.jdesktop.layout.GroupLayout.LEADING, jLabel2)
                    .add(org.jdesktop.layout.GroupLayout.LEADING, jButton1, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 143, Short.MAX_VALUE)
                    .add(jButton3, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 143, Short.MAX_VALUE)
                    .add(org.jdesktop.layout.GroupLayout.LEADING, benutzer, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 143, Short.MAX_VALUE)
                    .add(org.jdesktop.layout.GroupLayout.LEADING, jLabel1)
                    .add(org.jdesktop.layout.GroupLayout.LEADING, jButton2, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 143, Short.MAX_VALUE))
                .addContainerGap())
        );
        jInternalFrame1Layout.setVerticalGroup(
            jInternalFrame1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(jInternalFrame1Layout.createSequentialGroup()
                .addContainerGap()
                .add(jButton2)
                .add(78, 78, 78)
                .add(jLabel1)
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(benutzer, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(jLabel2)
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(password, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                .add(16, 16, 16)
                .add(jButton1)
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(jButton3)
                .addContainerGap(org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        Nachrichtenbox.setVisible(true);
        jLabel6.setText("aktuelle User:");

        jLabel7.setText("Servermeldung:");

        jScrollPane1.setViewportView(jTextPane1);

        jScrollPane4.setViewportView(jScrollPane1);

        jScrollPane2.setViewportView(jTextPane2);

        org.jdesktop.layout.GroupLayout NachrichtenboxLayout = new org.jdesktop.layout.GroupLayout(Nachrichtenbox.getContentPane());
        Nachrichtenbox.getContentPane().setLayout(NachrichtenboxLayout);
        NachrichtenboxLayout.setHorizontalGroup(
            NachrichtenboxLayout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(NachrichtenboxLayout.createSequentialGroup()
                .add(37, 37, 37)
                .add(NachrichtenboxLayout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                    .add(NachrichtenboxLayout.createSequentialGroup()
                        .add(jScrollPane4, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, 121, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                        .addContainerGap())
                    .add(NachrichtenboxLayout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                        .add(NachrichtenboxLayout.createSequentialGroup()
                            .add(jLabel6, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 126, Short.MAX_VALUE)
                            .addContainerGap())
                        .add(jLabel7, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 146, Short.MAX_VALUE)
                        .add(NachrichtenboxLayout.createSequentialGroup()
                            .add(jScrollPane2, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, 118, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                            .addContainerGap()))))
        );
        NachrichtenboxLayout.setVerticalGroup(
            NachrichtenboxLayout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(NachrichtenboxLayout.createSequentialGroup()
                .addContainerGap()
                .add(jLabel6)
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(jScrollPane2, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, 67, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                .add(24, 24, 24)
                .add(jLabel7)
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(jScrollPane4, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, 98, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(28, Short.MAX_VALUE))
        );

        jInternalFrame2.setVisible(true);
        jCheckBox4.setText("jCheckBox4");
        jCheckBox4.setBorder(javax.swing.BorderFactory.createEmptyBorder(0, 0, 0, 0));
        jCheckBox4.setMargin(new java.awt.Insets(0, 0, 0, 0));

        jCheckBox5.setText("jCheckBox5");
        jCheckBox5.setBorder(javax.swing.BorderFactory.createEmptyBorder(0, 0, 0, 0));
        jCheckBox5.setMargin(new java.awt.Insets(0, 0, 0, 0));

        org.jdesktop.layout.GroupLayout jPanel2Layout = new org.jdesktop.layout.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .add(jPanel2Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                    .add(jCheckBox4)
                    .add(jCheckBox5))
                .addContainerGap(493, Short.MAX_VALUE))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(jPanel2Layout.createSequentialGroup()
                .add(31, 31, 31)
                .add(jCheckBox4)
                .add(24, 24, 24)
                .add(jCheckBox5)
                .addContainerGap(142, Short.MAX_VALUE))
        );
        jTabbedPane1.addTab("tab1", jPanel2);

        org.jdesktop.layout.GroupLayout jPanel1Layout = new org.jdesktop.layout.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 606, Short.MAX_VALUE)
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 233, Short.MAX_VALUE)
        );
        jTabbedPane1.addTab("tab2", jPanel1);

        org.jdesktop.layout.GroupLayout jPanel4Layout = new org.jdesktop.layout.GroupLayout(jPanel4);
        jPanel4.setLayout(jPanel4Layout);
        jPanel4Layout.setHorizontalGroup(
            jPanel4Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 606, Short.MAX_VALUE)
        );
        jPanel4Layout.setVerticalGroup(
            jPanel4Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 233, Short.MAX_VALUE)
        );
        jTabbedPane1.addTab("tab3", jPanel4);

        org.jdesktop.layout.GroupLayout jPanel5Layout = new org.jdesktop.layout.GroupLayout(jPanel5);
        jPanel5.setLayout(jPanel5Layout);
        jPanel5Layout.setHorizontalGroup(
            jPanel5Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 606, Short.MAX_VALUE)
        );
        jPanel5Layout.setVerticalGroup(
            jPanel5Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 233, Short.MAX_VALUE)
        );
        jTabbedPane1.addTab("tab4", jPanel5);

        org.jdesktop.layout.GroupLayout jInternalFrame2Layout = new org.jdesktop.layout.GroupLayout(jInternalFrame2.getContentPane());
        jInternalFrame2.getContentPane().setLayout(jInternalFrame2Layout);
        jInternalFrame2Layout.setHorizontalGroup(
            jInternalFrame2Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(jTabbedPane1, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 627, Short.MAX_VALUE)
        );
        jInternalFrame2Layout.setVerticalGroup(
            jInternalFrame2Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(jTabbedPane1, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 279, Short.MAX_VALUE)
        );

        jInternalFrame3.setVisible(true);
        org.jdesktop.layout.GroupLayout jInternalFrame3Layout = new org.jdesktop.layout.GroupLayout(jInternalFrame3.getContentPane());
        jInternalFrame3.getContentPane().setLayout(jInternalFrame3Layout);
        jInternalFrame3Layout.setHorizontalGroup(
            jInternalFrame3Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 627, Short.MAX_VALUE)
        );
        jInternalFrame3Layout.setVerticalGroup(
            jInternalFrame3Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 311, Short.MAX_VALUE)
        );

        org.jdesktop.layout.GroupLayout layout = new org.jdesktop.layout.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(layout.createSequentialGroup()
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                    .add(Nachrichtenbox)
                    .add(org.jdesktop.layout.GroupLayout.TRAILING, jInternalFrame1))
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING, false)
                    .add(jInternalFrame2)
                    .add(jInternalFrame3)))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(layout.createSequentialGroup()
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.TRAILING, false)
                    .add(jInternalFrame1)
                    .add(jInternalFrame3))
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING, false)
                    .add(Nachrichtenbox)
                    .add(jInternalFrame2)))
        );
    }// </editor-fold>//GEN-END:initComponents

    private void passwordActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_passwordActionPerformed
// TODO add your handling code here:
    }//GEN-LAST:event_passwordActionPerformed

    
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
// TODO add your handling code here:
    stream.sendStream(benutzer.getText());
    password.setText(stream.getOutStreams());  
    }//GEN-LAST:event_jButton1ActionPerformed

    private void benutzerKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_benutzerKeyPressed
// TODO add your handling code here:
     
    }//GEN-LAST:event_benutzerKeyPressed

    private void benutzerActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_benutzerActionPerformed
    // TODO add your handling code here:
    stream.sendStream(benutzer.getText());
    password.setText(stream.getOutStreams());
    
    }//GEN-LAST:event_benutzerActionPerformed
    
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JInternalFrame Nachrichtenbox;
    private javax.swing.JFormattedTextField benutzer;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JCheckBox jCheckBox4;
    private javax.swing.JCheckBox jCheckBox5;
    private javax.swing.JFrame jFrame1;
    private javax.swing.JInternalFrame jInternalFrame1;
    private javax.swing.JInternalFrame jInternalFrame2;
    private javax.swing.JInternalFrame jInternalFrame3;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JPanel jPanel4;
    private javax.swing.JPanel jPanel5;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane4;
    private javax.swing.JTabbedPane jTabbedPane1;
    private javax.swing.JTextPane jTextPane1;
    private javax.swing.JTextPane jTextPane2;
    private javax.swing.JPasswordField password;
    // End of variables declaration//GEN-END:variables
    
}
