# Linux Command Line Tools

## Overview

1. Các loại shell trong Linux
2. Các command-line cơ bản
3. Cách sử dụng wildcard khi chạy lệnh
4. Biết piping and redirection trong linux

---

## 1. Các loại Shell trong Linux

> - Để biết về Shell, trước hết chúng ta phải biết về **Kernel**

Kernel là một chương trình máy tính, nó quản lý tài nguyên của hệ thống Linux bao gồm:

- File management
- Process management
- I/O management
- Memory management
- Device management etc.

Hệ thống Linux sẽ bao gồm: Kernel + GNU system utilities and libraries + other management scripts + installation scripts.

### Shell là gì?

Shell là một command line interpreter, nó sẽ dịch command line input của người dùng để chuyển thành ngôn ngữ máy để cho Kernel có thể hiểu được, từ đó giúp cho người dùng có thể giao tiếp với máy tính thông qua Shell.

**Shell** được chia ra làm 2 loại:

- Command Line Shell:

  - **Terminal** ở trên Macbook, hay **Command Prompt** ở trên Windows được coi là 1 **Command Line Interface**. Nó là một cách để tương tác với máy tính bằng câu lệnh.

  - Loại này thường khó dùng với một số người mới, bởi vì một số lượng lớn câu lệnh cần được nhớ và sử dụng. Tuy nhiên khi đã quên thì nó lại rất mạnh, bởi nó có thể kết hợp nhiều thao tác chỉ trong 1 vài câu lệnh. Các tệp lưu trữ các dòng lệnh này thường được gọi là **batch file** trong Windows, và **Shell Script** trong Linux/Mac OS

- Graphic Shell:

  - Graphic Shell sẽ cung cấp 1 Graphic User Interface (GUI) giúp cho người đọc có thể tương tác với hệ thống thông qua giao diện.
  - Windows OS hay Ubuntu OS được coi là ví dụ điển hình cung cấp GUI cho người dùng để tương tác với hệ thống. Ngừoi dùng không cần nhập lệnh cho mọi hành động.

**Một số loại Shell trong Linux:**

- C Shell (1978)

  - Được tạo ra bởi Bill Joy, với mục tiêu là thân thuộc với ngôn ngữ lập trình C. Nó hữu dụng bởi vì C là một ngôn ngữ gần giống với mã máy, vì thế nó sẽ cải thiện tốc độ cũng như dễ dàng tương tác với hệ thống hơn.

- Korn Shell (1983)

  - Được tạo ra bởi David Korn. Nó bao gồm các đặc điểm từ C Shell và Bourne Shell như là job control, command aliasing và command history.

- BASH (Bourne-Again Shell) (1989)

  - Được sử dụng rộng rãi trong các hệ thống Linux. Nó được viết bởi Brian Fox cho dự án GNU như là một phần mềm để thay thế cho Bourne Shell.

> Mỗi Shell thực hiện cùng một công việc **nhưng** cú pháp khác nhau và các hàm xây dựng cũng khác nhau.

## 2. Các command-line cơ bản

### 2.1 pwd command

pwd là prints the current working directory path. Tức là in ra thư mục hiện tại đang làm việc.

- pwd Syntax

> `pwd [-options]`

- pwd Option

| Options        | Description                                                     |
| -------------- | --------------------------------------------------------------- |
| -L, --logical  | Không hiện các liên kết đặc trưng                               |
| -P, --physical | Hiển thị thư mục vật lý, không có bất kỳ liên kết đặc trưng nào |

Để cần hiểu thêm về options -L, -P, chúng ta cần phải hiểu **Symbolic Links** và **Hard Links**

- Symbolic Links:

  - Tạo được link cả trên file và directory.
  - Không giới hạn việc đặt link ở đâu trên ổ đĩa.
  - Symlink đơn giản chỉ là con trỏ tới file thư mục.
  - Khi xoá Symlink thì toàn bộ link lẫn contents đều bị xoá.
  - Có thể phân biệt dễ dàng nhờ kí tự **l** khi dùng ls ở long format.

- Hard Links

  - Chỉ tạo được trên file, không tạo được trên directory.
  - Không thể tạo được hard link trên một file nằm khác partition với partition đặt link đó.
  - Không thể phân biệt hard link với file khi dùng **ls**
  - Khi xoá hard link thì link bị xoá, còn content vẫn được giữ nguyên, dẫn đến không gian nhớ không được xác định.

### 2.2 cd command

cd là change directory, tức là di chuyển đến folder bạn cần đến.

- cd Syntax

  `cd + [tên thư mục muốn đến]`

### 2.3 cat command

cat là đọc tất cả nội dung của file và in ra màn hình. Tuy nhiên chúng ta cần kéo thanh cuộn để xem nội dung của file nếu file dài.

- cat syntax

`cat + [options] + [tên thư mục muốn đọc]`

| Options      | Description                                                                            |
| ------------ | -------------------------------------------------------------------------------------- |
| -n, --number | Hiển thị Line numbers của file.                                                        |
| -e           | Hiển thị kí tự '$' ở cuối mỗi dòng và ở giữa 2 đoạn văn nếu đoạn văn không có kí tự gì |

- đọc nhiều file cùng 1 lúc: `cat test; cat test1; cat test2;`

### 2.4 more command

more là đọc một phần của nội dung file, nếu muốn xem thêm, nhấn space thế đọc thêm, tuy nhiên chúng ta chỉ có thể xem tiếp mà không quay về được. Để quay về, chúng ta lại phải gõ lại command + tên file.

- more Syntax

`more + [options] + [tên thư mục]`

| Options | Description                                                                           |
| ------- | ------------------------------------------------------------------------------------- |
| -       | Nó dùng để hiện hướng dẫn ở bên dưới file. (Press space to continue, Press q to quit) |
| -f      | Tuỳ chọn này sẽ không gọp dòng dài lại và hiển thị ra                                 |
| -p      | Xoá màn hình và hiển thị tiếp                                                         |

### 2.5 less command

less cũng dùng để đọc file, tuy nhiên có nhiều tuỷ chỉnh hơn ở trên file, như là dùng phím mũi tên để đọc từ đầu đến cuối. Pagedown, Pageup, để di chuyển về cuối file hoặc đầu trang. 'g' để quay về đầu file, và 'Shift g' để cuộn tới cuối file.

- less Syntax

`less + [options] + [filename]`

Ngoài ra chúng ta cũng có thể tìm từ ở trong file bằng cách dùng `/ + từ muốn tìm`, ấn **n** để đi tới các kết quả tiếp theo và **shift n** để quay về kết quả trước đó.

Và cuối cùng là nhấn **q** để thoát khỏi file.

### 2.6 head command

head cũng là lệnh đọc file, tuy nhiên sẽ đọc từ đầu file, và sẽ in ra 10 dòng đầu tiên của file.

- head syntax

`head + [options] + [filename]`

| Options               | Description                         |
| --------------------- | ----------------------------------- |
| -c, --byte, + number  | Hiển thị số kỹ tự tối đa đã đặt ra. |
| -n, --lines, + number | Giới hạn số dòng in ra              |
| -v, --verbose         | In ra tên file ở standard output    |

### 2.7 tail command

tail là một dạng đọc file từ cuối lên đầu, nó thường được sử dụng để check log (vì log thường được viết vào cuối file)
