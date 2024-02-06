---
date created: 2024-01-18
importance: 
status: todo
---
# Tmux筆記

Status: Completed
Created time: November 11, 2023 12:14 PM
Last edited time: November 23, 2023 10:10 PM

[linux命令tumx](https://www.victorchu.info/posts/85f7767b/)

```bash
#!/bin/sh
tmux new-session -d -s mysession

echo 'hscchscc' | sudo systemctl restart mongod
echo 'hscchscc' | sudo netstat -tlnp | grep mongod

tmux send-keys "echo '2' | ~/lnmc/LNMC/daemon/build/bin/lnmcd" C-m

tmux split-window -h
tmux send-keys "echo '1' | ~/LNM_Test/procedure\ test/build/bin/set_procedure_test_tests; $SHELL" C-m

tmux select-pane -L

tmux split-window -v
tmux send-keys "cd ~/lnmc/NMA_cfs/fsw/build/exe/dsp-1; ~/lnmc/NMA_cfs/fsw/build/exe/dsp-1/core-dsp-1" C-m

tmux select-pane -R

sleep 2
tmux split-window -v
tmux send-keys "python3 ~/lnmc/LNMC/tools/cFS-GroundSystem/Subsystems/cmdGui/test.py" C-m

sleep 2

tmux split-window -h
tmux send-keys "~/lnmc/LNMC/hook/build/bin/lnmc.hook -f ~/lnmc/LNMC/hook/build/bin/input_nmagent_set.json; $SHELL" C-m

tmux attach -t mysession
```

# 常用指令

```bash
#新建一个指定名称的窗口
$ tmux new-window -n <window-name>
# 切换到指定名称的窗口
$ tmux select-window -t <window-name>
## 命名
$ tmux kill-session -t <name>

# 划分上下两个窗格
$ tmux split-window -v
# 划分左右两个窗格
$ tmux split-window -h

# 光标切换到上方窗格
$ tmux select-pane -U
# 光标切换到下方窗格
$ tmux select-pane -D
# 光标切换到左边窗格
$ tmux select-pane -L
# 光标切换到右边窗格
$ tmux select-pane -R

Ctrl+b & # kill 窗口
Ctrl+b x #关闭当前窗格。
```

# tmux重要設定

```bash
# reload tmux的config
在tmux窗口中，先按下Ctrl+b指令前缀，然后按下冒号 : ，进入到命令模式后输入source-file ~/.tmux.conf，回车后生效。
```

## 設定

- 可以用滑鼠切換panel
- 可以用滑鼠調整panel的大小
- 美化status bar

```bash
# ~/.tmux.conf
set-option -g mouse on # 等同于以上4个指令的效果

set-option -g status-justify left
set-option -g status-left '#[bg=colour72] #[bg=colour237] #[bg=colour236] #[bg=colour235]#[fg=colour185] #S #[bg=colour236] '
set-option -g status-left-length 16
set-option -g status-bg colour237
set-option -g status-right '#[bg=colour236] #[bg=colour235]#[fg=colour185] %a %R #[bg=colour236]#[fg=colour3] #[bg=colour237] #[bg=colour72] #[]'
set-option -g status-interval 60

set-option -g pane-active-border-style fg=colour246
set-option -g pane-border-style fg=colour238

set-window-option -g window-status-format '#[bg=colour238]#[fg=colour107] #I #[bg=colour239]#[fg=colour110] #[bg=colour240]#W#[bg=colour239]#[fg=colour195]#F#[bg=colour238] '
set-window-option -g window-status-current-format '#[bg=colour236]#[fg=colour215] #I #[bg=colour235]#[fg=colour167] #[bg=colour234]#W#[bg=colour235]#[fg=colour195]#F#[bg=colour236] '

```

[linux命令tumx](https://www.victorchu.info/posts/85f7767b/)



```bash
#!/bin/sh
tmux new-session -d -s mysession

echo 'hscchscc' | sudo systemctl restart mongod
echo 'hscchscc' | sudo netstat -tlnp | grep mongod

tmux send-keys "echo '2' | ~/lnmc/LNMC/daemon/build/bin/lnmcd" C-m

tmux split-window -h
tmux send-keys "echo '1' | ~/LNM_Test/procedure\ test/build/bin/set_procedure_test_tests; $SHELL" C-m

tmux select-pane -L

tmux split-window -v
tmux send-keys "cd ~/lnmc/NMA_cfs/fsw/build/exe/dsp-1; ~/lnmc/NMA_cfs/fsw/build/exe/dsp-1/core-dsp-1" C-m

tmux select-pane -R

sleep 2
tmux split-window -v
tmux send-keys "python3 ~/lnmc/LNMC/tools/cFS-GroundSystem/Subsystems/cmdGui/test.py" C-m

sleep 2

tmux split-window -h
tmux send-keys "~/lnmc/LNMC/hook/build/bin/lnmc.hook -f ~/lnmc/LNMC/hook/build/bin/input_nmagent_set.json; $SHELL" C-m

tmux attach -t mysession
```

# 常用指令

```bash
#新建一个指定名称的窗口
$ tmux new-window -n <window-name>
# 切换到指定名称的窗口
$ tmux select-window -t <window-name>
## 命名
$ tmux kill-session -t <name>

# 划分上下两个窗格
$ tmux split-window -v
# 划分左右两个窗格
$ tmux split-window -h

# 光标切换到上方窗格
$ tmux select-pane -U
# 光标切换到下方窗格
$ tmux select-pane -D
# 光标切换到左边窗格
$ tmux select-pane -L
# 光标切换到右边窗格
$ tmux select-pane -R

Ctrl+b & # kill 窗口
Ctrl+b x #关闭当前窗格。
```

# tmux重要設定

```bash
# reload tmux的config
在tmux窗口中，先按下Ctrl+b指令前缀，然后按下冒号 : ，进入到命令模式后输入source-file ~/.tmux.conf，回车后生效。
```

## 設定

- 可以用滑鼠切換panel
- 可以用滑鼠調整panel的大小
- 美化status bar

```bash
# ~/.tmux.conf
set-option -g mouse on # 等同于以上4个指令的效果

set-option -g status-justify left
set-option -g status-left '#[bg=colour72] #[bg=colour237] #[bg=colour236] #[bg=colour235]#[fg=colour185] #S #[bg=colour236] '
set-option -g status-left-length 16
set-option -g status-bg colour237
set-option -g status-right '#[bg=colour236] #[bg=colour235]#[fg=colour185] %a %R #[bg=colour236]#[fg=colour3] #[bg=colour237] #[bg=colour72] #[]'
set-option -g status-interval 60

set-option -g pane-active-border-style fg=colour246
set-option -g pane-border-style fg=colour238

set-window-option -g window-status-format '#[bg=colour238]#[fg=colour107] #I #[bg=colour239]#[fg=colour110] #[bg=colour240]#W#[bg=colour239]#[fg=colour195]#F#[bg=colour238] '
set-window-option -g window-status-current-format '#[bg=colour236]#[fg=colour215] #I #[bg=colour235]#[fg=colour167] #[bg=colour234]#W#[bg=colour235]#[fg=colour195]#F#[bg=colour236] '
```"
url: "# Tmux筆記

Status: Completed
Created time: November 11, 2023 12:14 PM
Last edited time: November 23, 2023 10:10 PM

[linux命令tumx](https://www.victorchu.info/posts/85f7767b/)

```bash
#!/bin/sh
tmux new-session -d -s mysession

echo 'hscchscc' | sudo systemctl restart mongod
echo 'hscchscc' | sudo netstat -tlnp | grep mongod

tmux send-keys "echo '2' | ~/lnmc/LNMC/daemon/build/bin/lnmcd" C-m

tmux split-window -h
tmux send-keys "echo '1' | ~/LNM_Test/procedure\ test/build/bin/set_procedure_test_tests; $SHELL" C-m

tmux select-pane -L

tmux split-window -v
tmux send-keys "cd ~/lnmc/NMA_cfs/fsw/build/exe/dsp-1; ~/lnmc/NMA_cfs/fsw/build/exe/dsp-1/core-dsp-1" C-m

tmux select-pane -R

sleep 2
tmux split-window -v
tmux send-keys "python3 ~/lnmc/LNMC/tools/cFS-GroundSystem/Subsystems/cmdGui/test.py" C-m

sleep 2

tmux split-window -h
tmux send-keys "~/lnmc/LNMC/hook/build/bin/lnmc.hook -f ~/lnmc/LNMC/hook/build/bin/input_nmagent_set.json; $SHELL" C-m

tmux attach -t mysession
```

# 常用指令

```bash
#新建一个指定名称的窗口
$ tmux new-window -n <window-name>
# 切换到指定名称的窗口
$ tmux select-window -t <window-name>
## 命名
$ tmux kill-session -t <name>

# 划分上下两个窗格
$ tmux split-window -v
# 划分左右两个窗格
$ tmux split-window -h

# 光标切换到上方窗格
$ tmux select-pane -U
# 光标切换到下方窗格
$ tmux select-pane -D
# 光标切换到左边窗格
$ tmux select-pane -L
# 光标切换到右边窗格
$ tmux select-pane -R

Ctrl+b & # kill 窗口
Ctrl+b x #关闭当前窗格。
```

# tmux重要設定

```bash
# reload tmux的config
在tmux窗口中，先按下Ctrl+b指令前缀，然后按下冒号 : ，进入到命令模式后输入source-file ~/.tmux.conf，回车后生效。
```

## 設定

- 可以用滑鼠切換panel
- 可以用滑鼠調整panel的大小
- 美化status bar

```bash
# ~/.tmux.conf
set-option -g mouse on # 等同于以上4个指令的效果

set-option -g status-justify left
set-option -g status-left '#[bg=colour72] #[bg=colour237] #[bg=colour236] #[bg=colour235]#[fg=colour185] #S #[bg=colour236] '
set-option -g status-left-length 16
set-option -g status-bg colour237
set-option -g status-right '#[bg=colour236] #[bg=colour235]#[fg=colour185] %a %R #[bg=colour236]#[fg=colour3] #[bg=colour237] #[bg=colour72] #[]'
set-option -g status-interval 60

set-option -g pane-active-border-style fg=colour246
set-option -g pane-border-style fg=colour238

set-window-option -g window-status-format '#[bg=colour238]#[fg=colour107] #I #[bg=colour239]#[fg=colour110] #[bg=colour240]#W#[bg=colour239]#[fg=colour195]#F#[bg=colour238] '
set-window-option -g window-status-current-format '#[bg=colour236]#[fg=colour215] #I #[bg=colour235]#[fg=colour167] #[bg=colour234]#W#[bg=colour235]#[fg=colour195]#F#[bg=colour236] '
```"
```
