<%@ page language="java" contentType="text/html; charset=utf-8"
	pageEncoding="utf-8"%>
<%@ taglib prefix="s" uri="/struts-tags"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
  <title>Researcher</title>
  <script src="js/jquery-1.7.2.js"></script>
  <script src="bootstrap/js/bootstrap.min.js"></script>
  <script src="bootstrap/js/bootstrap-tooltip.js"></script>
  <script src="http://d3js.org/d3.v3.min.js"></script>
  <script src="js/index.js"></script>
  <script src="js/cloud.js"></script>
  <script src="js/spin.js"></script>
  <link href="bootstrap/css/bootstrap.min.css" rel="stylesheet" />
  <link href="css/index.css" rel="stylesheet" />
</head>
<body>
  <!-- smallhead -->
  <div class="navbar navbar-inverse">
    <div class="navbar-inner">
      <a class="brand" href="#">Gitsoo Academic</a>
      <div class="nav-collapse collapse">
        <ul class="nav">
          <li>
            <a href="home.jsp">Home</a>
          </li>
          <li class="active">
            <a href="index.jsp">Search</a>
          </li>
          <li>
            <a href="discover.jsp">Discover</a>
          </li>
          <li>
            <a href="about.jsp">About</a>
          </li>
          <li class="dropdown">
            <a href="#" class="dropdown-toggle" data-toggle="dropdown">
               Menu<b class="caret"></b>
            </a>
            <ul class="dropdown-menu">
              <li><a href="#">haha</a></li>
              <li><a href="#">hehe</a></li>
              <li><a href="#">heihei</a></li>
              <li class="divider"></li>
              <li class="nav-header">Menu 2nd</li>
              <li><a href="#">enen</a></li>
              <li><a href="#">hoho</a></li>
            </ul>
          </li>
        </ul>
      </div>
    </div>
  </div>

  <!-- 正文 -->
  <div class="container-fluid">
	<div class="row-fluid">
	  <!-- 左侧 -->
	  <div class="span9">
	    <div class="media well" >
          <a class="pull-left" href="#">
            <img class="media-object" src="<s:property value="info.picurl" />" id="author_pic">
          </a>
          <div class="media-body">
            <h3 class="media-heading"><s:property value="info.name" /><i class="icon-user"></i></h3>
            <dl class="dl-horizontal">
  				<dt><span class="label label-info">Homepage</span></dt>
  				<dd><s:property value="info.homepage" /></dd>
  				<dt><span class="label label-warning">Workplace</span></dt>
  				<dd><s:property value="info.workplace" /></dd>
  				<dt><span class="label label-important">Field</span></dt>
  				<dd><s:property value="info.field" /></dd>
			</dl>
          </div>
        </div>
		
		<a href="#" class="btn btn-large btn-inverse disabled" id="back_to_top">Top</a>
		
		<!-- wordcloud -->
		<div class="page-header">
          <h2>Keywords<small> from his/her papers</small></h2>
        </div>
        <div class="wordcloud"></div>
        <button class="btn btn-primary" type="button" id="cloudword_btn">Generate Cloud</button>
        <div id="load_three"></div>
        
		
		<!-- publications -->
        <div class="page-header">
          <h2>Publications<small><s:property value="total" /></small></h2>
        </div>
        <button class="btn btn-primary" type="button" id="rankpaper_btn">PageRank Them</button>
        <div id="load_rank"></div>
        <div id="unrank_papers">
		<s:if test="paperlist.size()>0">
		  <s:iterator id="prs" value="paperlist">
		  <blockquote>
			<p>
			  ${prs.title}
			  <s:if test="%{#prs.view_url.length()>5}">
			    <a href="${prs.view_url}" class="text-error"><i class="icon-share-alt"></i></a>
			  </s:if>
			</p>
			<p class="muted"><small>${prs.author}
			<s:if test="%{#prs.conference.length()>5}">
			  <i>@${prs.conference}</i>		 
		    </s:if>
			</small></p>
	      </blockquote>
		  </s:iterator>
		</s:if>
		</div>
		<div id="ranked_papers"></div>
      </div>
	 
	  <!-- 右侧 -->
	  <div class="alert alert-info span3">
	    <h3>Recommend</h3>
	    <div id="related_author"></div>
	    <button class="btn" type="button" id="related_btn">Click</button>
	  </div>
    </div>
  </div>
  <input id="rname" type=hidden value="<s:property value="info.name" />" ></input>
  <input id="rfield" type=hidden value="<s:property value="info.field" />" ></input>
  <input id="rplace" type=hidden value="<s:property value="info.workplace" />" ></input>
</body>
</html>