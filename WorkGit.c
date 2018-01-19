$ git pull
$ git add --all
$ git status
$ git commit --verbose
提交commit时，必须给出完整扼要的提交信息，参考LOG书写规范。
//TODO
————review 有问题，第二次提交，$ git commit –amend

与主干同步，避免提交冲突
$ git fetch origin dev
$ git rebase origin/dev

推送当前分支到远程仓库进行代码review。
$ git review -r origin dev_normalization --reviewers xnliu lizongkuan zmtian SunBo xhli clsun chwang blli

________________________________________

//压缩commit
$ git rebase -i commit_id (最早的一次提交前一个，即服务器版本提交)
$ pick/squash
$ 没有错的话，会弹出commit 提交信息，注释掉无用的，提交有效的
$ 不想合并的话，可以执行 git rebase --abort
_____________________________________

//Windows 本地 git review 环境配置
1. 安装含有 pip 命令的 python (现在用得是Python3.5.4)
   安装时，自定义安装，选择配置到环境变量。
2. 安装成功后保证，含有pip命令
3. 然后“一定”管理员权限执行下面的指令
	# pip install git-review
	安装时，会有下载进度条，同时安装成功，会有成功安装提示。
4. 这时，打开git bash .
	$ git help -a
	会出现 显示有review ，证明可以使用。
5. 当正常修改后，不需要执行push 操作，直接执行
	$ git review //会自动推送到我们的服务器
	即使审核未通过，再次修改后，也会git review
6. commit 注释不能有中文，会报错（3.png）
__________________________________________

git 提交异常 
方案一
// GIT 提交错误 fatal: LF would be replaced by CRLF
// 由于Unix 和 Windows 下对换行符的解释不同，提示为

// fatal: LF would be replaced by CRLF

// 因为win下文件回车换行是以CRLF结尾，而用VIM编辑器新建的文件是以LF结尾，导致出现了此问题。

// 解决方法：

// 找到win项目的.git目录,修改config文件，在[core]配置项添加下面一句话，就ok了。

// autocrlf = false

方案二
还可以在 linux vim 新建文件，把代码编辑进去。

