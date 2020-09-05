package mytest04;

import java.io.*;
import java.util.*;

import javax.swing.event.ListDataListener;

public class Count {

	private File filein;
	
	private File fileout;
	
	private BufferedReader in;
	
	private BufferedWriter out;
	
	private Map<Character, Integer> alphabetmap = new TreeMap<>();
	
	private Map<String, Integer> wordmap = new TreeMap<>();
	
	private String readaline;
	
	private int readaword;
	
	private Integer freq;
	
	public boolean theFileToRead(String pathname) throws IOException{
		this.filein = new File(pathname);
		if(filein.exists()) {
			return true;
		}
		else {
			return false;
		}
	}
	
	public void theFileToWrite(String pathname) throws IOException {
		this.fileout = new File(pathname);
		if(!fileout.exists()) {
			fileout.createNewFile();
		}
	}
	
	public void openInStream() throws IOException {
		this.in = new BufferedReader(new FileReader(this.filein));
	}
	
	public void closeInStream() throws IOException{
		this.in.close();
	}
	
	public void openOutStream() throws IOException {
		this.out = new BufferedWriter(new FileWriter(this.fileout));
	}
	
	public void closeOutStream() throws IOException{
		this.out.close();
	}
	
	private boolean isLetter(char c) {
		if(c >= 'A' && c <= 'Z' || c >= 'a' && c <='z')
			return true;
		else
			return false;
	}
	
	private String manageToWord(String str) {
		char[] tempstr = str.toCharArray();
		StringBuilder returnstr = new StringBuilder();
		int mark = -1;
		for(char a : tempstr) {
			if(this.isLetter(a) && mark == -1) {
				returnstr.append(a);
				mark = 0;
			}
			else if(this.isLetter(a) && mark == 0) {
				returnstr.append(a);
			}
			else if(!this.isLetter(a) && mark == 0) {
				returnstr.append(a);
				mark = 1;
			}
			else if(this.isLetter(a) && mark == 1) {
				returnstr.append(a);
			}
		}
		char[] examstr = returnstr.toString().toCharArray();
		if(!isLetter(examstr[examstr.length - 1])) {
			examstr[examstr.length - 1] = 0;
		}
		return String.valueOf(examstr).trim();
	}
	
	public void alphabetread() throws IOException{
		this.in.mark((int)filein.length()+1);
		this.freq = 0;
		while((readaword = this.in.read()) != -1) {
			char temp = (char)readaword;
			if(this.isLetter(temp)) {
				freq = alphabetmap.get(temp);
				if(freq == null) {
					freq = 1;
				}
				else {
					freq = freq + 1;
				}
				alphabetmap.put(temp, freq);
			}
		}
		this.in.reset();
	}
	
	public void wordread() throws IOException{
		this.in.mark((int)filein.length()+1);
		this.freq = 0;
		while((readaline = this.in.readLine()) != null) {
			String[] word = readaline.split(" ");
			for(String a : word) {
				String b = this.manageToWord(a);
				if(b != "") {
					freq = wordmap.get(b);
					if(freq == null) {
						freq = 1;
					}
					else {
						freq = freq + 1;
					}
					wordmap.put(b, freq);
				}
			}
		}
		this.in.reset();
	}
	
	public void printAlphabetToConsole() {
		Iterator<Map.Entry<Character, Integer>> it = alphabetmap.entrySet().iterator();
		while(it.hasNext()) {
			Map.Entry<Character, Integer> me = it.next();
			System.out.println(me.getKey()+"的个数为："+me.getValue());
		}
	}
	
	public void printWordToConsole() {
		Iterator<Map.Entry<String, Integer>> it = wordmap.entrySet().iterator();
		while(it.hasNext()) {
			Map.Entry<String, Integer> me = it.next();
			System.out.println(me.getKey()+"的个数为："+me.getValue());
		}
	}
	
	public void printAlphabetToFile() throws IOException {
		Iterator<Map.Entry<Character, Integer>> it = alphabetmap.entrySet().iterator();
		while(it.hasNext()) {
			Map.Entry<Character, Integer> me = it.next();
			this.out.write(me.getKey()+"的个数为："+me.getValue()+"\r\n");
		}
		this.out.flush();
	}
	
	public void printWordToFile() throws IOException {
		Iterator<Map.Entry<String, Integer>> it = wordmap.entrySet().iterator();
		while(it.hasNext()) {
			Map.Entry<String, Integer> me = it.next();
			this.out.write(me.getKey()+"的个数为："+me.getValue()+"\r\n");
		}
		this.out.flush();
	}
	
}
