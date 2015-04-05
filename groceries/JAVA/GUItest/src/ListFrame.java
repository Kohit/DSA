import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;
public class ListFrame extends JFrame{
	private JList color;
	private static final String[] colorNames = { "Black", "Blue", "Cyan", "Dark Gray",
		"Gray", "Green", "Light Gray", "Magenta", "Orange", "Pink", "Red", "White", "Yellow"};
	private static final Color[] colors = { Color.BLACK, Color.BLUE, Color.CYAN, Color.DARK_GRAY,
		Color.GRAY, Color.GREEN, Color.LIGHT_GRAY, Color.MAGENTA, Color.ORANGE, Color.PINK, Color.RED, Color.WHITE, Color.YELLOW
	};
	public ListFrame(){
		super( "List Test" );
		setLayout( new FlowLayout() );
		
		color = new JList( colorNames );
		color.setVisibleRowCount( 5 );
		color.setSelectionMode( ListSelectionModel.SINGLE_SELECTION );
		add ( new JScrollPane( color ) );
		
		color.addListSelectionListener( new ListSelectionListener(){
			public void valueChanged( ListSelectionEvent event ){
				getContentPane().setBackground( colors[ color.getSelectedIndex() ] );
			}
		});
	}
}
