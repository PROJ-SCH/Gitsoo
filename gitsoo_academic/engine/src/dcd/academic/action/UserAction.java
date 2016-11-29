package dcd.academic.action;

import com.opensymphony.xwork2.ActionSupport;

import dcd.academic.DAO.DAOfactory;
import dcd.academic.DAO.UserDAO;
import dcd.academic.model.User;

/**
 * 
 * @author pelick
 * 通过用户名得到用户信息的action，和user.jsp相关
 */
public class UserAction extends ActionSupport {
	private String username;
	
	public User user;
	
	@Override
	public String execute() throws Exception {
		UserDAO dao = DAOfactory.getUserDAO();
		user = dao.getUser(username);
		return SUCCESS;
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public User getUser() {
		return user;
	}

	public void setUser(User user) {
		this.user = user;
	}
	
}
