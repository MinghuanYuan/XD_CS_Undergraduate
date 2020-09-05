package application;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class PlayerMethon extends Application {
	Stage stage = new Stage();

	@Override
	public void start(Stage primaryStage)  {
		try {
			Text t1 = new Text(130.0,50.0,"������Ϸ");
			t1.setFont(Font.font("Verdana",FontWeight.BOLD,30));
			t1.setFill(Color.BLACK);
			
			Text t2 = new Text(10.0,100.0,"��Ϸ�淨\r\n" + 
					"���������Ҫ�ƶ��Ŀ飬����ϰ벿���������ƣ�����°벿���������ƣ����������ƶ��Դ����ơ�ͨ���ƶ������飬�����ܲٴӳ�ʼλ���Ƶ��������·��в����ӳ������ߣ��ƶ������в������Խ�顣\r\n" + 
					"\n\n");
			t2.setWrappingWidth(380.0);
			t2.setFont(Font.font("Verdana",20));
			t2.setFill(Color.BLACK);
			
			Text t3 = new Text(10.0,260.0,"��Ϸ��ʷ\r\n" + 
					"���ݵ���Ϸȡ���������������£��ܲ��ڳ�ڴ�ս�б���������Ȩ�ġ�����ơ������������ۡ���ܣ��������ӵ����ݵ���������������ķ���������Ϊ�˱���ܲٶ����Ķ��飬����ʵ�ã����ڰ����ܲ��ӳ��˻��ݵ�����Ϸ�������ա����������߻��ݣ�����ع���·�ꡣֻΪ���������أ��ſ���������������һ������ڡ�\r\n" );
			t3.setFont(Font.font("Verdana",20));
			t3.setWrappingWidth(380.0);
			t3.setFill(Color.BLACK);
			
			Pane pane = new Pane();
			pane.setPrefSize(400, 500);
			pane.getChildren().addAll(t1,t2,t3);
			
			primaryStage.setTitle("About");
			primaryStage.setResizable(false);
	        primaryStage.setScene(new Scene(pane, 400, 500));
	        primaryStage.show();
			
		}catch(Exception e) {
			e.printStackTrace();
		}
		// TODO Auto-generated method stub
	}
	
	public void  showWindow() throws Exception {
		start(stage);
	}

}
