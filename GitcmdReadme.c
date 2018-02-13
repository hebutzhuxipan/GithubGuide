　　
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

/***git 撤销操作***/
1> 工作区-暂存区-本地仓库-远程仓库
   未修改（origin）- 已修改（modified）- 已暂存（staged）- 已提交（committed）- 已推送（pushed）
2> 已修改，未暂存：
   查看diff: git diff
   撤销修改：git checkout .  或 git reset --hard
3> 已暂存，未提交：git add .
   查看diff: git diff --cached
   撤销修改：git reset , git checkout . 或 git reset --hard
4> 已提交，未推送：git add .
   查看diff: git diff master origin/master 这里master 就是本地仓库，origin/master就是远程仓库
   撤销修改：git reset --hard origin/master
5> 已推送
   撤销修改：git reset --hard HEAD^
   			 git push -f
6> 终极武器 
   git reflog

/***git diff ***/
1> git diff > 1.diff (源)
2> git apply 1.diff  （目的）
//上面两者的前提是要有共同的 base commit
//

1>使用git bisect快速定位版本的错误

//基本操作
1> 创建分支： $ git branch mybranch
2> 切换分支： $ git checkout mybranch
3> 创建并切换分支： $ git checkout -b mybranch
4> 重命名本地分支：git branch -m oldname newname

/////////////////////////////////////////////////////////////////////////
/***git 建立****/
1> git clone git@github.com:hebutzhuxipan/GithubGuide.git

问题1：
fatal: Could not read from remote
 repository.Please make sure you
 have the correct access rights and the repository exists.
解决1：出现这个问题是因为没有在github账号添加SSH key。
$ ssh-keygen -t rsa -C "hebutzhuxipan"  //应该是可以复制本机的 id_rsa.pub 下的

执行：
$ ssh -T git@github.com
问题2：ssh: connect to host github.com port 22: Connection timed out
解决2：在.ssh文件夹下，新建一个config文件，记住把扩展名去掉。
文件内容：
Host github.com
User hebut_zhuxipan@126.com
Hostname ssh.github.com
PreferredAuthentications publickey
IdentityFile ~/.ssh/id_rsa
Port 443
=======
_____________________________________________________________

git push origin 本地分支名称：sandbox/xpzhu/本地分支名称（远程分支）

_____________________________________________________________

/*拷贝代码 ，断电续传功能*/

git clone 断线了，就会自动把下载的都删除掉；与其不同下面，即使断了也可以继续
 
git init + git fetch + git checkout -b 
断了就再 git fetch

__________________________________________

/***********git rebase***********/

网址：http://blog.csdn.net/wh_19910525/article/details/7554489


 