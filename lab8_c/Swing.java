import java.awt.Button;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class Swing extends JFrame implements ActionListener{
	
	JLabel label, labelMean, labelStandardDev;
	JTextField textFieldSamples, textFieldMean, textFieldStandardDev ;
	JButton buttonGo;
	
	private int noofsamples;
	

	public Swing(){
	    //set the frame title
	    super("Week8");
        this.setVisible(true);	

	    createGUI();
	}
	
	void createGUI(){
		label = new JLabel("Enter the number of samples to generate:");
		label.setBounds(100,20,240,30);
		add(label);		
		
		textFieldSamples = new JTextField();
		textFieldSamples.setBounds(190,70,60,25);
		add(textFieldSamples);
		
		buttonGo = new JButton("Go!");
		buttonGo.setBounds(175,120,90,30);
		add(buttonGo);	
		
		buttonGo.addActionListener(this);
		
		labelMean = new JLabel("Mean = ");
		labelMean.setBounds(100,170,120,30);
		
		labelStandardDev = new JLabel("Standard deviation = ");
		labelStandardDev.setBounds(100,210,120,30);

		
		add(labelMean);
		add(labelStandardDev);
		
		textFieldMean = new JTextField();
		textFieldMean.setBounds(250,170,60,25);
		
		textFieldStandardDev = new JTextField();
		textFieldStandardDev.setBounds(250,210,60,25);
		
		add(textFieldMean);
		add(textFieldStandardDev);
		
	}
		
	
	int[] arr = new int[noofsamples];
	@Override
   	public void actionPerformed(ActionEvent ae) {
		
		if(ae.getSource() == buttonGo){
			
			try{
				noofsamples = Integer.parseInt(textFieldSamples.getText());
			}catch(NumberFormatException e){
				e.printStackTrace();
			}
			//arr[] = new int[noofsamples];
			
			Random rn = new Random();
			for(int i=0; i<arr.length; i++){
				arr[i] = rn.nextInt();
				System.out.println(arr[i]);
				
			}
		}
   
    };  

	public static void main(String[] args) {
		 EventQueue.invokeLater(new Runnable(){
	            @Override
	            public void run(){
	               Swing frame = new Swing();
	               frame.setLayout(null);
	               frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	               frame.setSize(500,300);
	               frame.getContentPane().setBackground(Color.WHITE);
	               frame.setLocationRelativeTo(null);
	               frame.setBackground(Color.YELLOW);
		int rev = frame.calculateMean(arr);
		int ver = frame.calculateSTDDev(arr);
	            }
	         });

	}
	public native double calculateMean(int [] numbers );
	
	public native double calculateSTDDev( int [] numbers );
	
	

}
