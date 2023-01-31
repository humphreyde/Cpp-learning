# cpp-learning




## git使用

### 第一种提交方式(本地无仓库)

- 获取github仓库保存到本地：

```
git clone https://github.com/humphreyde/cpp-learning.git
```

修改后

- 进入本地仓库，输入`git status`查看仓库状态

- 然后`git add [文件名]`添加到暂存区
  - `git add .`添加全部文件
  - `git add [文件架]/`

- 然后`git commit -m ""`提交到仓库
  - ""中一般是说明内容：“commit xxx file” "第一次提交"

- 同步到远程仓库：`git push origin master`

### 第二种提交方式(本地有仓库)：

初始化本地仓库：`git init`

关联远程仓库：`git remote add origin https://github.com/humphreyde/cpp-learning.git`

拉取远程仓库进行同步：`git pull origin master`

本地仓库修改后

添加和执行：`git add helloworld` 和 `git commit -m "commit helloworld file"`提交到本地仓库

提交到远程仓库：` git push origin master` 将本地修改（添加）后的内容提交到远程仓库
