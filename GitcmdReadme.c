　　
/***git 基本建仓，提交命令***/
1> git init //把这个目录变成Git可以管理的仓库
2> git add README.md //文件添加到仓库
3> git add . //不但可以跟单一文件，还可以跟通配符，更可以跟目录。一个点就把当前目录下所有未追踪的文件全部add了 
4> git commit -m "first commit" //把文件提交到仓库
5> git remote add origin git@github.com:wangjiax9/practice.git //关联远程仓库,后面是去拷贝仓的地址，ssh
6> git push -u origin master //把本地库的所有内容推送到远程库上

/***git 提高命令***/
1> git log //查看日志
2> git format-patch -s "branchname" //生成patch
   或者
   git format-patch HEAD^  		//<==最近的1次commit的patch
   git format-patch HEAD^^ 		//<==最近的2次commit的patch
   git format-patch HEAD^  		//<==最近的3次commit的patch
   git format-patch HEAD^  		//<==最近的4次commit的patch
   git format-patch HEAD^^^^^ 	//<==不支持！！！！error！！
3> git reset --hard "branchname"//回退版本
4> patch -p1 < 0001-#######.patch //打补丁
 