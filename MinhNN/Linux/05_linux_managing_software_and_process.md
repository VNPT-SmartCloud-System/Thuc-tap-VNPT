# Managing Software And Process In Linux

## Overview

1. Các package management phổ biến: RPM, DEB.
2. Các lệnh quản lý package: yum, rpm, dnf.
3. Các lệnh tương tác với tiến trình trong máy chủ.

## 1. Các package management phổ biến trong Linux

### 1.1 Red Hat Package Management (RPM)

- RPM được phát triển cơ bản dựa trên Linux Standard Base (LSB)
- là một open-source program dùng để tải xuống, gỡ cài đặt và quản lý software packages cho các hệ thống dựa trên Red Hat (RHEL, CentOS, và Fedora)
  > Các chức năng cơ bản của RPM

1. **Install** dùng để tải bất kỳ gói **RPM** nào
2. **Remove** dùng để xoá hoặc huỷ cái đặt bất kỳ gói **RPM** nào
3. **Upgrade** dùng để cập nhật các gói **RPM** hiện có
4. **Verify** dùng để xác minh bất kỳ gói **RPM** hiện có nào
5. **Query** Dùng để truy vấn bất kỳ gói **RPM** hiện có nào đó.

Với quyền `root` ta có thể sử dụng `rpm` với các lệnh phù hợp để quản lý các gói phần mềm RPM

**RPM** sẽ lưu trữ thông tin tất cả các gói đã cài đặt trong `/var/lib/rpm`.

**RPM** sẽ xử lý các tệp .rpm chứa thông tin về các gói như: nó là gì, đến từ đâu.

### 1.2 Debian package (DEB)

Debian package bao gồm **metadata** và **files**. Metadata bao gồm package name, mô tả, và list of dependencies.

Debian packages có thể dùng

- Thao tác và quản lý các gói, các phần của gói
- Quản lý ghi đè cục bộ các tệp trong một gói

- Hỗ trợ các nhà phát triển trong việc xây dựng các kho lưu trữ trọn gói

- Hỗ trợ người dùng trong việc cài đặt các gói nằm trên một trang FTP từ xa.

## 2. Các lệnh quản lý package cơ bản

### 2.1 Yum Command Line

1. Cài đặt gói bằng **yum install**

```sh
yum install packagename
```

2. Gỡ cài đặt gói bằng **yum remove**

```sh
yum remove packagename
```

3. Cập nhật gói bằng **yum update**

```sh
yum update + packagename
```

> ngoài ra có thể sử dụng `yum update` để cập nhật cả hệ thống. 4. Liệt kê các package bằng **yum list**

```sh
yum list + packagename
```

5. Tìm kiếm gói bằng **yum search**

```sh
    yum search + name
```

6. Lấy thông tin của package **yum info**

```sh
    yum info + packagename
```

7. Liệt kê tất cả các package có sẵn bằng **yum list**

```sh
yum list
```

8. Liệt kê tất cả các package đã tài đặt bằng **yum list installed**

```sh
yum list installed
```

> 2 lệnh **yum list** thường kếp hợp với lệnh **less** để có thể đọc dữ liệu dễ dàng hơn `yum list || less`

9. Kiểm tra tệp tin thuộc về gói nào bằng **yum provides**

10. Kiểm tra cập nhật có sẵn bằng **yum**

```sh
yum check-update
```

11. Liệt kê các nhóm phần mềm có sẵn sử dụng **yum grouplist**

```sh
yum grouplist
```

12. Cài đặt gói nhóm bằng **yum groupinstall**

```sh
yum groupinstall + packagename
```

13. Xoá gói nhóm bằng **yum groupremove**

```sh
yumm groupremove + packagename
```

14. Cập nhật gói nhóm bằng **yum groupupdate**

```sh
yum groupupdate + package name
```

15. Liệt kê danh sách kho yum được kích hoạt bằng **yum repolist**

```sh
yum repolist
```

16. Liệt kê tất cả các kho yum được kích hoạt và vô hiệu hoá

```sh
yum repolist all
```

17. Clean bộ nhớ cache bằng **yum clean all**

```sh
yum clean all
```

18. Xem lịch sử của yum

```sh

yum history list

```

### 2.2 RPM Command Line

> Cấu trúc của 1 file rpm sẽ như sau:

`<name>-<version>-<release>.<architecture>.rpm`

Ví dụ: Telnet-0.17-65.el7_8.x86_64.rpm

1. Cài đặt gói RPM

Ví dụ cài đặt gói rpm wget:

```sh
rpm -ivh wget-1.19.5-7.el8_0.1.x86_64.rpm
```

Trong đó:

    -i: cài đặt 1 gói

    -v: hiển thị đầy đủ

    -h: hiển thị hash khi gói được giải nén

2. Truy vấn tất cả các gói RPM

```sh
rpm -qa + package name
```

Trong đó:

    -q: Dùng để truy vấn
    -a: Dùng để hiển thị tất cả các gói đã cài đặt

3. Truy vấn các gói RPM theo định dạng

```sh
rpm -qa --queryformat '%{name}-%{version}-%{release} %{size}\n
```

4. Hiển thị thông tin về gói RPM

```sh
rpm -qi + package name
```

### 2.3 dnf Command Line

- Dandified YUM (dnf) là một trình quản lý gói,
  phần mềm của các bản phân phối Linux, dựa trên RPM.

- Tương tự như yum, dnf được dùng để cài đặt, cập nhật, và gỡ bỏ các package trên hệ điều hành.

- _dnf_ có các tính năng **mạnh mẽ** hơn _yum_, giúp dễ dàng quản lý các nhóm và có khả năng giải quyết tự động các vấn đề liên quan đến phần mềm phù thuộc (dependencies).

1. Cài đặt dnf

```sh
$ yum install dnf
```

2. Kiểm tra version dnf đã cài đặt

```sh
dnf --version
```

3. Liệt kê tất cả package (cả package đã cài đặt và các package trên repo)

```sh
dnf list
```

4. Liệt kê tất cả package đã cài đặt

```sh
dnf list installed
```

5. Liệt kê tất cả các package có trên repo

```sh
dnf list available
```

6. Tìm kiếm package

```sh
dnf search + packagename
```

7. Cài đặt package

```sh
dnf install + packagename
```

8. Để kiểm tra thông tin package

```sh
dnf info + packagename
```

9. Kiểm tra cập nhật package

```sh
dnf check-update + packagename
```

10. Cập nhật package

```sh
dnf update + packagename
```

11. Gỡ bỏ package

```sh
dnf remove + packagename
```

12. Để gỡ bỏ các dependencies đã được cài đặt với package

```sh
dnf autoremove

```

---

### Làm việc với group

13. Liệt kê các package group

```sh
dnf grouplist
```

14. Cài đặt package group

```sh
dnf groupinstall + name of group_package
```

15. Cập nhật package group

```sh
dnf groupupdate + name of group_package
```

16. Gỡ bỏ package group

```sh
dnf groupremove + name of group_package
```

### Làm việc với repository

17. Liệt kê các repository

```sh
dnf repolist all
```

18. Thêm dnf repository

```sh
dnf config-manager --add-repo <repository_url>
```

19. Enable/Disable repository

Enable:

```sh
dnf config-manager --set-enabled <repository_id>
```

Disable:

```sh
 dnf config-manager --set-disabled <repository_id>
```

## 3. Các lệnh tương tác với tiến trình trong máy chủ

### 3.2 Process Management

- Process có nghĩa là một chương trình đang trong quá trình thực thi, nó sẽ lấy input, xử lý và chạy để đưa ra output phù hợp.

- Có 2 kiểu process là:

  - **Foreground processes**: Những kiểu processes này được biết đến là **interactive processes**. Những processes này thường được thực thi hoặc khởi chạy bởi người dùng. Những processes này lấy input từ người dùng và return lại output. Trong khi các quá trình này đang chạy, ta không thể tạo thêm một quá trình mới ở cùng 1 terminal.

  - **Background processes**: Là những kiểu processes được biết đến là **non-interactive processes**. Những processes này thường được thực thi bởi người dùng, hay là do hệ thống tự khởi động mặc dù nó vẫn chịu sự quản lý của người dùng. Những quá trình này có PID duy nhất hoặc process nếu gán cho nó. Chúng ta có thể khởi tạo những processes khác bên trong cùng 1 terminal

1 Số Command thường được dùng trong Job Management

| Command                      | Description                                                                                                                     |
| ---------------------------- | ------------------------------------------------------------------------------------------------------------------------------- |
| & (dùng ở cuối dòng command) | Bắt đầu command ngay lập tức ở background                                                                                       |
| Ctrl-Z                       | Tạm thời dừng công việc hiện tại, để được quản lý. Ví dụ có thể chuyển nó đến background                                        |
| Ctrl-D                       | Gửi End of File (EOF) đến job hiện tại để cho nó không đợi các input tiếp theo                                                  |
| Ctrl-C                       | Dùng để huỷ current interactive job                                                                                             |
| bg                           | Tiếp tụcc ông việc mà nó bị Ctrl-Z đóng băng vừa nãy ở background                                                               |
| fg                           | Mang last job tới foreground để thực thi                                                                                        |
| jobs                         | In ra các jobs đang thực thi hiện tại từ Shell. Hiển thị số lượng job, cái mã có thể dùng như là argument cho commands bg và fg |

### 3.2 Các lệnh cơ bản dùng để quản lý processes

1. Theo dõi process

```sh
➜  ~ ps
  PID TTY          TIME CMD
 4486 pts/1    00:00:00 zsh
 4845 pts/1    00:00:00 ps

```

- Chúng ta có thể thấy nếu để `ps` mặc định nó sẽ k show ra quá nhiều thông tin, chỉ show thông tin của terminal session hiện tại

- Output sẽ cho ra 2 processes:

- `TTY` là viết tắt của **Teletype**, để chỉ terminal đang chạy process đó.
- `Time` Để chỉ thời gian chiếm CPU của process tương ứng.

Khi thêm options `-x`, chúng ta có thể nhìn thấy tất cả các tiến trình của bất kỳ terminal nào

```sh
  PID TTY      STAT   TIME COMMAND
 2058 ?        Ss     0:00 /lib/systemd/systemd --user
 2059 ?        S      0:00 (sd-pam)
 2064 ?        SLl    0:00 /usr/bin/gnome-keyring-daemon --daemonize --login
 2066 ?        Ss     0:00 /sbin/upstart --user
 2144 ?        S      0:00 upstart-udev-bridge --daemon --user
 2154 ?        Ss     0:00 dbus-daemon --fork --session --address=unix:abstract=
 2166 ?        Ss     0:00 /usr/lib/x86_64-linux-gnu/hud/window-stack-bridge
 2193 ?        Ssl    0:11 /usr/bin/ibus-daemon --daemonize --xim --address unix
 2199 ?        Sl     0:00 /usr/lib/gvfs/gvfsd

```

- Chúng tả có thể thấy được một cột mới (STAT, để chỉ state của 1 process tương ứng

| State              | Meaning                                                                                              |
| ------------------ | ---------------------------------------------------------------------------------------------------- |
| R (Running)        | Process đang chạy, hoặc đang sẵn sàng để chạy                                                        |
| S (Sleeping)       | Process đang đợi 1 event để tiếp tục chạy                                                            |
| D                  | Process đang đợi I/O                                                                                 |
| T (Stopped)        | Process đang trong quá trình ngừng chạy                                                              |
| Z (Zombie process) | Đây là các process con đã bị chấm dứt nhưng chưa được giải phóng bởi process cha                     |
| <                  | Process có độ ưu tiên cao, có thể có nhiều thời gian CPU hơn                                         |
| N                  | Process có độ ưu tiên thấp, chỉ có thể chiếm CPU khi các process có độ ưu tiên hơn hết thời gian CPU |

Khi chạy với option `aux` sẽ hiện thể process thuộc về mọi user

```sh
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root         1  0.0  0.0 185380  6036 ?        Ss   20:28   0:02 /sbin/init spla
root         2  0.0  0.0      0     0 ?        S    20:28   0:00 [kthreadd]
root         4  0.0  0.0      0     0 ?        I<   20:28   0:00 [kworker/0:0H]
root         6  0.0  0.0      0     0 ?        I<   20:28   0:00 [mm_percpu_wq]
root         7  0.0  0.0      0     0 ?        S    20:28   0:00 [ksoftirqd/0]
root         8  0.1  0.0      0     0 ?        I    20:28   0:05 [rcu_sched]
root         9  0.0  0.0      0     0 ?        I    20:28   0:00 [rcu_bh]
root        10  0.0  0.0      0     0 ?        S    20:28   0:00 [migration/0]
root        11  0.0  0.0      0     0 ?        S    20:28   0:00 [watchdog/0]
root        12  0.0  0.0      0     0 ?        S    20:28   0:00 [cpuhp/0]
root        13  0.0  0.0      0     0 ?        S    20:28   0:00 [cpuhp/1]
root        14  0.0  0.0      0     0 ?        S    20:28   0:00 [watchdog/1]
root        15  0.0  0.0      0     0 ?        S    20:28   0:00 [migration/1]
root        16  0.0  0.0      0     0 ?        S    20:28   0:00 [ksoftirqd/1]
root        18  0.0  0.0      0     0 ?        I<   20:28   0:00 [kworker/1:0H]

```

2. Theo dõi process với `top`

`ps` sẽ hiển thị ra các tiến trình đang thực thi trong hệ thống
tại thời điểm mà chúng ta chạy nó. Trong khi đó `top` sẽ cung cấp cho ta một tiến trình theo dõi **động** hơn.

![top-process-image](images/top-process.png)

3. Kill một process

`Kill` Command để gửi tín hiệu để dừng một process thông qua PID hoặc ID

```sh
kill + [options] + [process_id]
```

Theo mặc định kill sẽ lấy tín hiệu 15 (TERM)

Các tín hiệu thường được dùng là:

- `1` (-HUP): để tải lại một tiến trình
- `9` (-KILL: để tắt một tiến trình
- `15` (-TERM: để dừng tiến trình.

Ngoài ra chúng ta có thể sử dụng `killall` để terminate process

> Tuy nhiên `killall + name of process` nên khi dùng phải chú ý!
