import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ButtonFrame extends JFrame{
	private JButton plainJButton;
	private JButton fancyJButton;
	
	public ButtonFrame(){
		super( "Testing Buttons" );
		setLayout( new FlowLayout() );
		
		plainJButton = new JButton( "Plain Button" );
		add( plainJButton );
		
		Icon bug1 = new ImageIcon( getClass().getResource( "bug1.png" ) );
		Icon bug2 = new ImageIcon( getClass().getResource( "bug2.png" ) );
		fancyJButton = new JButton( "Fancy Button", bug1 );
		fancyJButton.setRolloverIcon( bug2  );
		add( fancyJButton );
		
		ButtonHandler handler = new ButtonHandler();
		plainJButton.addActionListener( handler );
		fancyJButton.addActionListener( handler );
	}
	private class ButtonHandler implements ActionListener{
		public void actionPerformed( ActionEvent event ){
			JOptionPane.showMessageDialog( ButtonFrame.this , String.format( "You pressed: %s", event.getActionCommand() ));
		}
	}
}
