package mytest03;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Notepad {

	private Date moment = new Date();
	
	private String describe;
	
	private String content;

	public String getDescribe() {
		return describe;
	}

	public void setDescribe(String describe) {
		this.describe = describe;
	}

	public String getContent() {
		return content;
	}

	public void setContent(String content) {
		this.content = content;
	}
	
	public void getMoment() {
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		System.out.println(sdf.format(moment));
	}
}
