　　
/***git 基本建仓，提交命令***/
1> git init //把这个目录变成Git可以管理的仓库
2> git add README.md //文件添加到仓库
3> git add . //不但可以跟单一文件，还可以跟通配符，更可以跟目录。一个点就把当前目录下所有未追踪的文件全部add了 
4> git commit -m "first commit" //把文件提交到仓库
5> git remote add origin git@github.com:wangjiax9/practice.git //关联远程仓库,后面是去拷贝仓的地址，ssh
6> git push -u origin master //把本地库的所有内容推送到远程库上

/***git 打包命令***/
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

/***git 经过验证的打包命令***/
1> (这一步是别人做)git format-patch -s "branchname" //生成patch,"branchname" 为git log 倒数第二个commit id
2> git apply --reject "0001-test.patch" //应用patch 包，可能有错，warning不用管;如果没有错，测试应该是更改了；有错，需要手动更改
3> git add .   "或者其他add" 
4> git commit -m "commit"

/***git 使用***/
1> git clean -dxf  //命令用来从你的工作目录中删除所有没有tracked过的文件
	-df 删除 文件 和 目录
	-xf删除当前目录下所有没有track过的文件. 不管他是否是.gitignore文件里面指定的文件夹和文件.

 