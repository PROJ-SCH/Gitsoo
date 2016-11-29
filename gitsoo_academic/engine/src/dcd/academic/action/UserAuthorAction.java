package dcd.academic.action;

import java.util.ArrayList;

import com.opensymphony.xwork2.ActionSupport;

import dcd.academic.DAO.DAOfactory;
import dcd.academic.DAO.UserDAO;
import dcd.academic.DAO.impl.UserDaoImpl;
import dcd.academic.model.ResearcherModel;

/**
 * 
 * @author pelick
 * 在user.jsp用户主页展示用户收藏的学者列表
 *
 */
public class UserAuthorAction extends ActionSupport {
	private String user;
	
	public ArrayList<ResearcherModel> list = new ArrayList<ResearcherModel>();
	
	@Override
	public String execute() throws Exception {
		UserDAO dao = DAOfactory.getUserDAO();
		list = dao.getUserAuthor(user);
		return SUCCESS;
	}

	public String getUser() {
		return user;
	}

	public void setUser(String user) {
		this.user = user;
	}

	public ArrayList<ResearcherModel> getList() {
		return list;
	}

	public void setList(ArrayList<ResearcherModel> list) {
		this.list = list;
	}

	
}
