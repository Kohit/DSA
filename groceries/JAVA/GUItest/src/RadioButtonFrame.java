import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class RadioButtonFrame extends JFrame{
	private JTextField textField;
	private Font plain;
	private Font bold;
	private Font italic;
	private Font boldItalic;
	private JRadioButton plainJRadioButton, boldJRadioButton, italicJRadioButton, boldItalicJRadioButton;
	private ButtonGroup radioGroup;
	public RadioButtonFrame(){
		super( "RadioButton Test" );
		setLayout( new FlowLayout() );
		
		textField = new JTextField( "Watch the font style change", 25 );
		add( textField );
		
		plainJRadioButton = new JRadioButton( "Plain", true );
		boldJRadioButton = new JRadioButton( "Bold", false );
		italicJRadioButton = new JRadioButton( "Italic", false );
		boldItalicJRadioButton = new JRadioButton( "Bold + Italic", false );
		add( plainJRadioButton ); add( boldJRadioButton ); add( italicJRadioButton ); add( boldItalicJRadioButton );
		
		radioGroup = new ButtonGroup();
		radioGroup.add( plainJRadioButton );
		radioGroup.add( boldJRadioButton );
		radioGroup.add( italicJRadioButton );
		radioGroup.add( boldItalicJRadioButton );
		
		plain = new Font( "Serif", Font.PLAIN, 14 );
		bold = new Font( "Serif", Font.BOLD, 14 );
		italic = new Font( "Serif", Font.ITALIC, 14 );
		boldItalic = new Font( "Serif", Font.BOLD + Font.ITALIC, 14 );
		textField.setFont( plain );
		
		plainJRadioButton.addItemListener( new RadioButtonHandler( plain ) );
		boldJRadioButton.addItemListener( new RadioButtonHandler( bold ) );
		italicJRadioButton.addItemListener( new RadioButtonHandler( italic ) );
		boldItalicJRadioButton.addItemListener( new RadioButtonHandler( boldItalic ) );
	}
	private class RadioButtonHandler implements ItemListener{
		private Font font;
		public RadioButtonHandler( Font f ){
			font = f;
		}
		public void itemStateChanged( ItemEvent event ){
			textField.setFont( font );
		}
	}
}
