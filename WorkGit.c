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
