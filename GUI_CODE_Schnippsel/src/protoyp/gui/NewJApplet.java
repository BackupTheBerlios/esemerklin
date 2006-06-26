/*
 * NewJApplet.java
 *
 * Created on 15. Juni 2006, 16:27
 */

package protoyp.gui;
import java.io.IOException;
import javax.swing.*;


/**
 *
 * @author  mohamed
 */
public class NewJApplet extends javax.swing.JApplet {
    

    SocketConnect socketCon;
    Stream stream;
    Lock lock;
    
    /** Initializes the applet NewJApplet */
    public void init() {
        
   
    socketCon = new SocketConnect("134.147.59.3"); 
    stream = new Stream(socketCon.getSocket());
    lock = new Lock();
    
  

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
    
    public void start(){
   
    }
    
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
        SteuerFenster = new javax.swing.JTabbedPane();
        lok1 = new javax.swing.JPanel();
        Lock1 = new javax.swing.JTextField();
        Weiche1 = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        GesendetLok = new javax.swing.JTextField();
        GesendetWeiche = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        Sonderfunktion1 = new javax.swing.JRadioButton();
        Sonderfunktion2 = new javax.swing.JRadioButton();
        jButton4 = new javax.swing.JButton();
        jSlider1 = new javax.swing.JSlider();
        lok2 = new javax.swing.JPanel();
        lok3 = new javax.swing.JPanel();
        lok4 = new javax.swing.JPanel();
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
                .addContainerGap(31, Short.MAX_VALUE))
        );

        jInternalFrame2.setVisible(true);
        SteuerFenster.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                TabAuswahl(evt);
            }
        });

        Lock1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Lock1ActionPerformed(evt);
            }
        });

        Weiche1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Weiche1ActionPerformed(evt);
            }
        });

        jLabel3.setText("Lock");

        jLabel4.setText("Weiche");

        GesendetLok.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                GesendetLokActionPerformed(evt);
            }
        });

        jLabel5.setText("Gesendet");

        jLabel8.setText("Gesendet");

        Sonderfunktion1.setText("SonderFunktion1");
        Sonderfunktion1.setBorder(javax.swing.BorderFactory.createEmptyBorder(0, 0, 0, 0));
        Sonderfunktion1.setMargin(new java.awt.Insets(0, 0, 0, 0));
        Sonderfunktion1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Sonderfunktion1ActionPerformed(evt);
            }
        });

        Sonderfunktion2.setText("Sonderfunktion2");
        Sonderfunktion2.setBorder(javax.swing.BorderFactory.createEmptyBorder(0, 0, 0, 0));
        Sonderfunktion2.setMargin(new java.awt.Insets(0, 0, 0, 0));

        jButton4.setText("jButton4");

        org.jdesktop.layout.GroupLayout lok1Layout = new org.jdesktop.layout.GroupLayout(lok1);
        lok1.setLayout(lok1Layout);
        lok1Layout.setHorizontalGroup(
            lok1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(lok1Layout.createSequentialGroup()
                .add(lok1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                    .add(lok1Layout.createSequentialGroup()
                        .addContainerGap()
                        .add(lok1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                            .add(lok1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.TRAILING, false)
                                .add(org.jdesktop.layout.GroupLayout.LEADING, Weiche1)
                                .add(org.jdesktop.layout.GroupLayout.LEADING, Lock1, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 172, Short.MAX_VALUE))
                            .add(jLabel3)
                            .add(jLabel4)))
                    .add(lok1Layout.createSequentialGroup()
                        .add(93, 93, 93)
                        .add(lok1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                            .add(jSlider1, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                            .add(Sonderfunktion1))))
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(lok1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                    .add(lok1Layout.createSequentialGroup()
                        .add(jLabel8)
                        .addContainerGap())
                    .add(lok1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                        .add(lok1Layout.createSequentialGroup()
                            .add(lok1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                                .add(jLabel5)
                                .add(lok1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING, false)
                                    .add(GesendetWeiche)
                                    .add(GesendetLok, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 186, Short.MAX_VALUE)))
                            .addContainerGap(131, Short.MAX_VALUE))
                        .add(org.jdesktop.layout.GroupLayout.TRAILING, lok1Layout.createSequentialGroup()
                            .add(Sonderfunktion2)
                            .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED, 47, Short.MAX_VALUE)
                            .add(jButton4)
                            .add(62, 62, 62)))))
        );
        lok1Layout.setVerticalGroup(
            lok1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(lok1Layout.createSequentialGroup()
                .add(23, 23, 23)
                .add(lok1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.BASELINE)
                    .add(jLabel3)
                    .add(jLabel5))
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(lok1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.BASELINE)
                    .add(Lock1, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                    .add(GesendetLok, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE))
                .add(39, 39, 39)
                .add(lok1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.BASELINE)
                    .add(jLabel4)
                    .add(jLabel8))
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(lok1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.BASELINE)
                    .add(Weiche1, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                    .add(GesendetWeiche, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED, 12, Short.MAX_VALUE)
                .add(jSlider1, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(lok1Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.BASELINE)
                    .add(Sonderfunktion1)
                    .add(Sonderfunktion2)
                    .add(jButton4))
                .addContainerGap())
        );
        SteuerFenster.addTab("tab1", lok1);

        org.jdesktop.layout.GroupLayout lok2Layout = new org.jdesktop.layout.GroupLayout(lok2);
        lok2.setLayout(lok2Layout);
        lok2Layout.setHorizontalGroup(
            lok2Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 606, Short.MAX_VALUE)
        );
        lok2Layout.setVerticalGroup(
            lok2Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 236, Short.MAX_VALUE)
        );
        SteuerFenster.addTab("tab2", lok2);

        org.jdesktop.layout.GroupLayout lok3Layout = new org.jdesktop.layout.GroupLayout(lok3);
        lok3.setLayout(lok3Layout);
        lok3Layout.setHorizontalGroup(
            lok3Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 606, Short.MAX_VALUE)
        );
        lok3Layout.setVerticalGroup(
            lok3Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 236, Short.MAX_VALUE)
        );
        SteuerFenster.addTab("tab3", lok3);

        org.jdesktop.layout.GroupLayout lok4Layout = new org.jdesktop.layout.GroupLayout(lok4);
        lok4.setLayout(lok4Layout);
        lok4Layout.setHorizontalGroup(
            lok4Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 606, Short.MAX_VALUE)
        );
        lok4Layout.setVerticalGroup(
            lok4Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(0, 236, Short.MAX_VALUE)
        );
        SteuerFenster.addTab("tab4", lok4);

        org.jdesktop.layout.GroupLayout jInternalFrame2Layout = new org.jdesktop.layout.GroupLayout(jInternalFrame2.getContentPane());
        jInternalFrame2.getContentPane().setLayout(jInternalFrame2Layout);
        jInternalFrame2Layout.setHorizontalGroup(
            jInternalFrame2Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(SteuerFenster, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 627, Short.MAX_VALUE)
        );
        jInternalFrame2Layout.setVerticalGroup(
            jInternalFrame2Layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(SteuerFenster, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 282, Short.MAX_VALUE)
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
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                    .add(jInternalFrame3)
                    .add(jInternalFrame2, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(layout.createSequentialGroup()
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.TRAILING, false)
                    .add(jInternalFrame3)
                    .add(jInternalFrame1))
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING, false)
                    .add(Nachrichtenbox)
                    .add(jInternalFrame2)))
        );
    }// </editor-fold>//GEN-END:initComponents

    private void Sonderfunktion1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Sonderfunktion1ActionPerformed
// TODO add your handling code here:
        lock.setSonderFunktion(" 0x41");
    }//GEN-LAST:event_Sonderfunktion1ActionPerformed

    private void TabAuswahl(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_TabAuswahl
// TODO add your handling code here:
        lock.setLockID("0x14");
    }//GEN-LAST:event_TabAuswahl

    private void Weiche1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Weiche1ActionPerformed
// TODO add your handling code here:
        String senden = "w " + Weiche1.getText();
        stream.sendStream(senden);
        GesendetWeiche.setText(stream.getOutStreams());
    }//GEN-LAST:event_Weiche1ActionPerformed

    private void GesendetLokActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_GesendetLokActionPerformed
// TODO add your handling code here:
        
    }//GEN-LAST:event_GesendetLokActionPerformed

    private void Lock1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Lock1ActionPerformed
// TODO add your handling code here:
        String senden = "l " + lock.getLockID() + lock.getSonderFunktion() + " " + Lock1.getText();
        stream.sendStream(senden);
        GesendetLok.setText(stream.getOutStreams());
    }//GEN-LAST:event_Lock1ActionPerformed

    

    
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
    private javax.swing.JTextField GesendetLok;
    private javax.swing.JTextField GesendetWeiche;
    private javax.swing.JTextField Lock1;
    private javax.swing.JInternalFrame Nachrichtenbox;
    private javax.swing.JRadioButton Sonderfunktion1;
    private javax.swing.JRadioButton Sonderfunktion2;
    private javax.swing.JTabbedPane SteuerFenster;
    private javax.swing.JTextField Weiche1;
    private javax.swing.JFormattedTextField benutzer;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton4;
    private javax.swing.JFrame jFrame1;
    private javax.swing.JInternalFrame jInternalFrame1;
    private javax.swing.JInternalFrame jInternalFrame2;
    private javax.swing.JInternalFrame jInternalFrame3;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane4;
    private javax.swing.JSlider jSlider1;
    private javax.swing.JTextPane jTextPane1;
    private javax.swing.JTextPane jTextPane2;
    private javax.swing.JPanel lok1;
    private javax.swing.JPanel lok2;
    private javax.swing.JPanel lok3;
    private javax.swing.JPanel lok4;
    private javax.swing.JPasswordField password;
    // End of variables declaration//GEN-END:variables
    
}
