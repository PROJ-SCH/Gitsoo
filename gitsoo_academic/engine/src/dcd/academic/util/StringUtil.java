package dcd.academic.util;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.HashSet;
import java.util.List;

import org.wltea.analyzer.core.IKSegmenter;
import org.wltea.analyzer.core.Lexeme;


public class StringUtil {
	public static boolean isBlank(String str) {
		int strLen;
		if (str == null || (strLen = str.length()) == 0) {
			return true;
		}
		for (int i = 0; i < strLen; i ++) {
			if ((Character.isWhitespace(str.charAt(i)) == false)) {
				return false;
			}
		}
		return true;
	}
	
	public static ArrayList<String> getTokens(String text) throws IOException {
		ArrayList<String> tokens = new ArrayList<String>();
		InputStream is = new ByteArrayInputStream(text.getBytes("UTF-8"));
		BufferedReader input = new BufferedReader(new InputStreamReader(is));

		// true为智能划词, false为最细粒度划词
		IKSegmenter segmenter = new IKSegmenter(input, true);
		Lexeme token = null;
		do {
			token = segmenter.next();
			if (token != null) 
				if (!isBlank(token.getLexemeText()) && token.getLexemeText().length() > 3)
					tokens.add(token.getLexemeText());
		} while (token != null);
		return tokens;
	}
	
	public static String filterSymbols(String target) {
		target = target.replaceAll("\\[", "");
		target = target.replaceAll("\\]", "");
		target = target.replaceAll("\"", "");
		target = target.replaceAll("\\,", " ");
		target = target.replaceAll("  ", ",");
		target = target.replaceAll(",,,", ",");
		target = target.replaceAll(",,", ",");
		if (target.endsWith(",")) {
			target = target.substring(0, target.length()-1);
		}
		return target;
	}

	public static String filterComma(String target) {
		target = target.replaceAll(",", "");
		return target;
	}
	
	public static String filterAmp(String target) {
		target = target.replaceAll("&amp;", "");
		return target;
	}

	public static String transformQuery(String field, String target) {
		if (target.contains("(")) {
			target = target.substring(0, target.indexOf("(")-1);
		}
		String[] qs = target.split(" ");
		String qq = "";
		for (int i = 0; i < qs.length; i ++) {
			if (!qs[i].equals("")) {
				if (qq.equals("")) {
					qq = field+":" +qs[i];
				} else {
					qq = qq + " " +(field+":" +qs[i]);
				}
			}
		}
		
		return qq;
	}
	
	public static String transformIK(String field, String target) throws IOException {		
		InputStream is = new ByteArrayInputStream(target.getBytes("UTF-8"));
		BufferedReader input = new BufferedReader(new InputStreamReader(is));

		// true为智能划词, false为最细粒度划词
		IKSegmenter segmenter = new IKSegmenter(input, true);
		Lexeme token = null;
		String qq = "";
		do {
			token = segmenter.next();
			if (token != null) {
				if (!qq.equals("")) {
					qq = qq + " " + field + ":" + token.getLexemeText();
				} else {
					qq = field + ":" + token.getLexemeText();
				}	
			}
		} while (token != null);
		return qq;
	}
	
	
	public static ArrayList<String> ArrayToArrayList(String[] objs) {
		ArrayList<String> list = new ArrayList<String>();
		for (int i = 0; i < objs.length; i ++) {
			list.add(objs[i]);
		}
		return list;
	}
	
	public static String[] removeDupl(List<String> list) {
		HashSet<String> set = new HashSet<String>();
		for (String s : list ) {
			if (!set.contains("s")) {
				set.add(s);
			}
		}
		return set.toArray(new String[set.size()]);
	}
	
	public static HashSet<String> removeDuplToSet(List<String> list) {
		HashSet<String> set = new HashSet<String>();
		for (String s : list ) {
			if (!set.contains("s")) {
				set.add(s);
			}
		}
		return set;
	}
	
	public static void main(String[] args) throws IOException {
		transformQuery("name", "Deng Cai (蔡登)");
		
	}
}
