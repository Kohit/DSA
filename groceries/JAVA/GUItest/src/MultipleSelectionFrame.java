import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class MultipleSelectionFrame extends JFrame{
	private JList color, copy;
	private JButton copyButton;
	private static final String[] colorNames = { "Black", "Blue", "Cyan", "Dark Gray",
		"Gray", "Green", "Light Gray", "Magenta", "Orange", "Pink", "Red", "White", "Yellow"};
	public MultipleSelectionFrame(){
		super( "MultipleSelection Lists" );
		setLayout( new FlowLayout() );
		
		color = new JList( colorNames );
		color.setVisibleRowCount( 5 );
		color.setSelectionMode( ListSelectionModel.MULTIPLE_INTERVAL_SELECTION );
		add( new JScrollPane( color ) );
		
		copyButton = new JButton( "Copy >>>" );
		copyButton.addActionListener( new ActionListener(){
			public void actionPerformed( ActionEvent event ){
				copy.setListData( color.getSelectedValues() );
			}
		});
		add( copyButton );
		copy = new JList();
		copy.setVisibleRowCount( 5 );
		copy.setFixedCellWidth( 100 );
		copy.setFixedCellHeight( 15 );
		copy.setSelectionMode( ListSelectionModel.SINGLE_INTERVAL_SELECTION );
		add( new JScrollPane( copy ) );
	}
}
