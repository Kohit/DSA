import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class JComBoxFrame extends JFrame{
	private JComboBox imagesBox;
	private JLabel label;
	private static final String[] names = { "bug1.png", "bug2.png" };
	private Icon[] icons = { new ImageIcon( getClass().getResource( names[0] ) ), new ImageIcon( getClass().getResource( names[1] ) ) };
	
	public JComBoxFrame(){
		super( "Testing JComboBox" );
		setLayout( new FlowLayout() );
		
		imagesBox = new JComboBox( names );
		imagesBox.setMaximumRowCount( 2 );
		
		imagesBox.addItemListener( new ItemListener(){            // anonymous inner class
			public void itemStateChanged( ItemEvent event ){
				if ( event.getStateChange() == ItemEvent.SELECTED )
					label.setIcon( icons[imagesBox.getSelectedIndex()] );
			}
		});
		
		add( imagesBox );
		label = new JLabel( icons[0] );
		add( label );
	}
}
