package dcd.academic.action;

import java.util.Calendar;
import java.util.Date;

import com.opensymphony.xwork2.ActionSupport;

import dcd.academic.DAO.DAOfactory;
import dcd.academic.DAO.SaveDAO;
import dcd.academic.util.StdOutUtil;

/**
 * 
 * @author pelick
 * 用户收藏论文，加上时间戳后交给DAO处理
 *
 */
public class SavePaperAction extends ActionSupport {
	
	private String user;
	private String title;
	private String tag;
	
	public int type;
	
	@Override
	public String execute() throws Exception {
		SaveDAO dao = DAOfactory.getSaveDAO();
		if (!dao.existPaper(user, title)) {
			Calendar cal = Calendar.getInstance();
			Date date = cal.getTime();
			dao.savePaper(user, title, tag, date.toLocaleString());
			type = 1;
		} else {
			type = 0;
		}
		return SUCCESS;
	}
	
	

	public String getTag() {
		return tag;
	}


	public void setTag(String tag) {
		this.tag = tag;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}



	public int getType() {
		return type;
	}

	public void setType(int type) {
		this.type = type;
	}

	public String getUser() {
		return user;
	}

	public void setUser(String user) {
		this.user = user;
	}
}
