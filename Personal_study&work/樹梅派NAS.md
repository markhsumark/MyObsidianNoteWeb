---
date created: 2024-01-16
---
# 樹莓派NAS


[給蘋果迷的五個樹莓派應用](http://3c.technews.tw/2015/02/11/5-hot-raspberry-pi-projects-for-mac-geeks/)

# 網路連接

## **ZeroTier**

```bash
curl -s https://install.zerotier.com | sudo bash
```

[ZeroTier Central](https://my.zerotier.com)

~~id那些要上zerotier網站登入後獲取~~

[用Zerotier內網穿透(虛擬內網)連線樹梅派Node-Red - HackMD](https://hackmd.io/@LHB-0222/zerotier)

```bash
sudo zerotier-cli join <<zerotier-id>>
sudo systemctl daemon-reload
sudo systemctl disable zerotier-one
sudo systemctl enable zerotier-one
```

### 設備列表

| 設備名 | 說明 | 區網ip | zerotier ip |
| --- | --- | --- | --- |
| marknas | raspberry pi zero | 192.168.68.未設定 | X |
| markRP4 | raspberry pi 4B 4GB | 192.168.68.104 | 192.168.195.71 |

# 網站伺服器架設

[解决Linux关闭终端(关闭SSH等)后运行的程序自动停止_检测到finalshell正在运行,点击确定关闭进程-CSDN博客](https://blog.csdn.net/gatieme/article/details/52777721)


[（五）树莓派安装可道云](https://blog.bombox.org/2021-09-08/raspberrypi-kodexplorer/)

[树莓派所有版本一键安装nextcloud | 开源爱好者](https://ee-fans.com/树莓派所有版本一键安装nextcloud/?source=post_page-----be5a36102f05--------------------------------)

[Raspberry Pi 安装 code-server( vs-code)](https://lingshunlab.com/book/raspberry-pi/raspberry-pi-install-code-server-vs-code)

[NextCloud 安裝設定紀錄 [Jonathan's Wiki 筆記]](https://www.ichiayi.com/tech/nextcloud)

## **開機設定**

[Raspberry pi 開機自動執行 Shell script](https://hms5232.medium.com/raspberry-pi-%E9%96%8B%E6%A9%9F%E8%87%AA%E5%8B%95%E5%9F%B7%E8%A1%8C-shell-script-e5b60781bfa0)

**必要指令**

```bash
sudo systemctl daemon-reload
sudo systemctl disable zerotier-one
sudo systemctl enable zerotier-one
sudo mount -t auto /dev/sda3 /media/HDD_MBP_backup
sudo mount -t auto /dev/sda2 /home/markRP4/HDD_2T
```

## 網速

[树莓派4B openwrt wifi 提升速度_dvfvfv的博客-CSDN博客](https://blog.csdn.net/u011013648/article/details/115007308)

## Nextcloud

帳號：admin

密碼：openmediavault

- MySQL root用户密码：qwerty（可自行修改MYSQL_ROOT_PASSWORD=qwerty）
- nextcloud数据库用户：ncuser（可通过修改脚本源码修改）
- nextcloud数据库密码：raindrop(可自行修改NCUSER_PASSWORD=raindrop)
- nextcloud数据库名：nextcloud（可通过修改脚本源码修改）

# 硬碟

## **[掛載外接硬碟](https://mailtojacklai.medium.com/%E7%8E%A9%E9%9B%BB%E8%85%A6-%E7%B6%B2%E8%B7%AF%E5%88%86%E4%BA%AB%E8%A3%9D%E5%9C%A8raspberry-pi%E4%B8%8A%E9%9D%A2%E7%9A%84%E5%A4%96%E6%8E%A5%E7%A1%AC%E7%A2%9F-4ed70cbfe738)**

```bash
sudo mount -t auto /dev/sda3 /media/HDD_MBP_backup
sudo mount -t auto /dev/sda2 /home/markRP4/HDD_2T
```

## **RAID**

[Linux 的 Parted 指令教學：建立、變更與修復磁碟分割區 - G. T. Wang](https://blog.gtwang.org/linux/parted-command-to-create-resize-rescue-linux-disk-partitions/)

[](https://ithelp.ithome.com.tw/m/articles/10006536)

[使用 mdadm 管理 RAID 阵列](https://zhuanlan.zhihu.com/p/63990027)

# 各種傳輸協議/protocol

## **smba**

[https://blog.gtwang.org/iot/raspberry-pi/raspberry-pi-samba-setup-tutorial/](https://blog.gtwang.org/iot/raspberry-pi/raspberry-pi-samba-setup-tutorial/)

### 新增smba使用者

```bash
sudo adduser pi
sudo usermod -a -G sambashare pi
sudo pdbedit -a -u pi
sudo nano /etc/samba/smb.conf
sudo service smbd restart
```

### marknas

**使用者：**marknas

**密碼：**21315675

**使用者：**aivial

**密碼：**030891

**使用者：**hsuhome

**密碼：**035207263

### markRP4

**使用者：**markRP4

**密碼：21315675**

## **AFP**

> apple裝置的檔案共享協議
> 

[怎么设置Mac和树莓派(Raspberry Pi)之间的文件共享  AFP设置教程](https://shilei165.github.io/2021/01/06/怎么设置mac和树莓派raspberry-pi之间的文件共享-afp设置教程/)

```bash
sudo nano /etc/netatalk/afp.conf
sudo systemctl restart netatalk
```

## **SSHFS**

> 使用ssh協議進行檔案共享
> 

[How To Use SSHFS on macOS — Peter Girnus](https://www.petergirnus.com/blog/how-to-use-sshfs-on-macos)

```bash
# 開始掛載樹莓派nas
sshfs markhsu@192.168.195.214:/home/marknas/HDD/mark /Users/markhsu/marknas_mountpoint
# 卸載樹莓派nas
diskutil umount force /Users/markhsu/marknas_mountpoint
```

# 裝置備份

## **遠端時光機**

[利用树莓派打造时间机器 - 少数派](https://sspai.com/post/69197)

```bash
# 先掛載指定硬碟到指定路徑下
sudo mount -t auto /dev/sda3 /media/HDD_MBP_backup
# 設置權限
nohup sudo chown -R markRP4: /media/HDD_MBP_backup > /dev/null 2>&1 &
nohup sudo chmod 755 -R /media/HDD_MBP_backup > /dev/null 2>&1 &
# ps aux | less #用來查看背景執行的process
```

## **手機備份**

[Mac修改iPhone備份到外接硬碟教學，避免備份空間不足 - 瘋先生](https://mrmad.com.tw/mac-modify-iphone-backup-location)

ln -s /Volumes/markRP4/HDD_2T/iphone_backup /Users/markhsu/Library/Application\ Support/MobileSync/Backup

# 其他

媒體

m3u8**影片下載**

ffmpeg -i [](https://b-hls-05.doppiocdn.org/hls/63188730/63188730_240p.m3u8)[https://cdn77-vid.xvideos-cdn.com/2apzfcfi5rJStmkJzhSNFA==,1695585761/videos/hls/7b/46/0c/7b460c64ae2e89058935a34f8dc23b5b/hls.m3u8](https://cdn77-vid.xvideos-cdn.com/2apzfcfi5rJStmkJzhSNFA==,1695585761/videos/hls/7b/46/0c/7b460c64ae2e89058935a34f8dc23b5b/hls.m3u8) [](https://b-hls-05.doppiocdn.org/hls/63188730/63188730_240p.m3u8)-c copy ****PassionateCouplemakesRealEroticLove****.mp4

ffmpeg -i www -c copy .mp4

**影片剪輯**

ffmpeg -ss 00:00:00 -i input.mp4 -to 00:02:00 -c copy -movflags +faststart output.mp4

[在Ubuntu上安装Aria2完整手把手教程/Ubuntu server上安装BT下载软件Aria2](https://zhuanlan.zhihu.com/p/658156257)

花費

RPi 4：2300