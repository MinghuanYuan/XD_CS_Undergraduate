package Road;

import java.awt.Color;  
import java.awt.Font;  
import java.awt.event.FocusEvent;  
import java.awt.event.FocusListener;  
import javax.swing.JButton;  
  
public class Person extends JButton implements FocusListener {  
    int number;  
    Color c = new Color(255, 245, 170);  
    Font font = new Font("ËÎÌו", Font.BOLD, 12);  
    Person(int number, String s) {  
        super(s);  
        setBackground(c);  
        setFont(font);  
        this.number = number;  
        c = getBackground();  
        addFocusListener(this);  
    }  
  
    @Override  
    public void focusGained(FocusEvent arg0) {  
        // TODO Auto-generated method stub  
        setBackground(Color.red);  
    }  
  
    @Override  
    public void focusLost(FocusEvent arg0) {  
        // TODO Auto-generated method stub  
        setBackground(c);  
    }  
}  