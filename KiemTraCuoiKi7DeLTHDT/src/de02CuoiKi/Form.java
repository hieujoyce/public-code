
package de02CuoiKi;

import java.awt.Dimension;
import java.awt.Font;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;

public class Form extends javax.swing.JFrame {

    public Form() {
        initComponents();
        
        tblNhanVien.getTableHeader().setOpaque(false);
        tblNhanVien.getTableHeader().setFont(new Font("Segoe UI", Font.BOLD, 14));
        tblNhanVien.getTableHeader().setPreferredSize(new Dimension(40,40));
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jSeparator1 = new javax.swing.JSeparator();
        jLabel1 = new javax.swing.JLabel();
        btnLoad = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        tblNhanVien = new javax.swing.JTable();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel1.setText("Form Load data");

        btnLoad.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        btnLoad.setText("Load data");
        btnLoad.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnLoadActionPerformed(evt);
            }
        });

        tblNhanVien.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        tblNhanVien.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Họ Tên", "Ngày Sinh", "Địa chỉ", "Giới Tính", "Phòng Ban", "HSL", "Thâm Niên", "Lương CB"
            }
        ));
        tblNhanVien.setRowHeight(40);
        jScrollPane1.setViewportView(tblNhanVien);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(22, 22, 22)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(btnLoad, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, 197, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 931, javax.swing.GroupLayout.PREFERRED_SIZE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jSeparator1)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 51, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(26, 26, 26)
                .addComponent(btnLoad, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
            .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 601, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnLoadActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnLoadActionPerformed
        // TODO add your handling code here:
        DefaultTableModel tblModel = (DefaultTableModel)tblNhanVien.getModel();
        
        try {
            tblModel.setRowCount (0);
            FileInputStream fis = new FileInputStream("nhanvien.dat");
            InputStreamReader isd = new InputStreamReader(fis, "UTF-8");
            BufferedReader br = new BufferedReader(isd);
            String line = br.readLine();
            int index = 1;
            while(line != null) {
                String[] s = line.split("\\$");
                String valid = validateForm(s, index);
                if(!valid.equals("")) {
                    JOptionPane.showMessageDialog(this, valid);
                    return;
                }
                NhanVien nv = new NhanVien(s[0], s[1], s[2], s[3], s[4], Float.parseFloat(s[5]), Integer.parseInt(s[6]), Float.parseFloat(s[7]));              
                tblModel.addRow(new String[] {s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7]});
                tblModel.fireTableDataChanged();
                line = br.readLine(); 
                index++;
            }
        } catch (IOException e) {
            JOptionPane.showMessageDialog(this, "Lỗi File");
            return;
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, "Lỗi định dạng, hãy kiểm tra lại file");
            return;
        }
    }//GEN-LAST:event_btnLoadActionPerformed

    public String validateForm(String[] s, int index) {
        if(s.length != 8) {
            return "Dòng " + index + " không đủ số lượng trường dữ liệu.";
        }
        String regexNgaySinh = "^([0-2][0-9]||3[0-1])/(0[0-9]||1[0-2])/([0-9][0-9])?[0-9][0-9]$";
        if(!s[1].matches(regexNgaySinh)) return "Dòng " + index + " có Ngày sinh không hợp lệ (VD: 06/06/2001).";
        if(!s[3].equals("Nam") && !s[3].equals("Nữ")) return "Dòng " + index + " giới tính không hợp lệ. (Nam/Nữ)";
        try {
            float x = Float.parseFloat(s[5]);
            int y = Integer.parseInt(s[6]);
            float z = Float.parseFloat(s[7]);
        } catch (Exception e) {
            return "Dòng " + index + " có trường (HSL/ Thâm Niên/ Lương CB) không đúng định dạng)";
        }
        return "";
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Form.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Form.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Form.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Form.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Form().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnLoad;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JSeparator jSeparator1;
    private javax.swing.JTable tblNhanVien;
    // End of variables declaration//GEN-END:variables
}
