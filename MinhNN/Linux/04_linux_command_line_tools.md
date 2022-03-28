# Linux Command Line Tools

## Overview

1. Các loại shell trong Linux
2. Các command-line cơ bản
3. Cách sử dụng wildcard khi chạy lệnh
4. Cách sử dụng piping and redirection trong linux

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

- tail Syntax:

`tail + [options] + [filename]`

### 2.8 grep command

grep dùng để lọc dữ liệu theo hàng

- grep Syntax:

`grep + [words you want to find] + [destination file]`

| Options    | Description                                                 |
| ---------- | ----------------------------------------------------------- |
| -n, number | Hiển thị số thự tự dòng bên một bên trái                    |
| -i,        | Lọc dữ liệu mà không cần quan tâm đến kí tự hoa hay thường. |

## 3. Cách sử dụng Wildcard khi chạy lệnh

### 3.1 Symbol '?'

Symbol '?' thường được áp dùng trong việc tìm file mà trong đó người sử dụng quên 1 số kí tự ở tên của file.

Ví dụ: Muốn tìm 1 file có tên: word3.doc ở trong thư mục word, chúng ta đang đứng ở thư mục word

Chúng ta có thể làm như sau :

- ls wo???.doc
- ?o?d.???

cũng đều cho ra một kết quả

### 3.2 Symbol '\*'

Để chọn tất cả những thứ có trong file.

Ví dụ: trong thư mục images có các file: image1.png, image2.png, image3.png, image4.png, image5.png, image6.png, image10.png, image11.png, image12.png và 1 số thư mục khác có định dạng .doc.

chúng ta có thể in hết tất cả các thư mục có định dạng đuôi là .png bằng cách
`ls *.png`
mà không cần quan tâm nó có bao nhiêu kí tự ở phía trước định dạng đuôi.

## 4. Cách sử dụng piping and redirection trong Linux

### Luồng dữ liệu

![data-stream-image](images/data-stream-image.png)

- **stdin** (standard input) đây là luồng sẽ đưa dữ liệu vào chương trình để xử lý.
- **stdout** (standard output) luồng này dùng để xuất dữ liệu ra màn hình hiển thị sau khi quá trình thực thi hoàn tất mà không gặp lỗi.
- **stderr** (standard error) luồng này có chức năng tương tự **stdout**, tuy nhiên nó chỉ dùng để in các thông báo lỗi và đồng thời khi đó tín hiệu lỗi cũng được gửi tới hệ điều hành

- Khi làm việc trên Linux command line. Chắc hẳn chúng ta đã từng sử dụng pipe và redirection. Chẳng hạn như để tìm và in dòng chứa từ "Hello World" từ file log.txt ra file result.txt: `cat log.txt | grep "Xin chào" > README.txt`. Tuy nhiên bạn không biết rằng là mình đã vừa sử dụng pipe ( | ) và redirection ( > ) trong linux

### 4.1 Piping

- Pipe có tác dụng chuyển dòng chảy dữ liệu (data stream) từ output của chương trình này thành input của chương trình ở sau nó `A | B - Output(STDOUT) của chương trình A sẽ thành input (STDIN) của chương trình B`

- Ví dụ: Liệt kê file, thư mục chứa từ "php"
  - `$ ls ~ | grep php`

### 4.2 Redirection

- Redirection: dùng để điều hướng data stream giữa 1 chương trình và 1 file (**khác với pipe là 2 chương trình**).
- Các ký hiệu của redirection bao gồm:

  - `>` Xuất STDOUT vào file (overwrite)
  - `>>` Xuất STDOUT vào file (append)
  - `<` Đọc STDIN từ file (is used for input (stdin) redirection)
  - `2>` Xuất STDERR vào file

- Redirection the standard output of command to file
  - Kí tự '>' đại diện cho chuyển hướng đầu ra (STDOUT). Nếu câu lệnh được thực hiện thành công, nó sẽ gửi output của file vào destination.

> Command > File = Command 1> File (1 là abbrevation của STDOUT)

- Redirection the standard error of command to file

`Command 2> filebash` (2 là abbreviation của stderr)

#### Các dạng chuyển hướng

##### Chuyển hướng tới file

- Dữ liệu đầu ra sẽ được lưu vào file thay vì in ra màn hình hiển thị.
- Để chuyển hướng 1 câu lệnh tới file, Linux cung cấp cho người sử dụng 2 cú pháp: `>` (ghi nội dung file từ điểm bắt đầu, nếu file đã có nội dung thì ghi đè) và `>>` (cách này sẽ thêm nội dung vào cuối file mà không ghi đè)
-

##### Chuyển hướng từ file

- Cách này giống với việc đọc dữ liệu từ file và sử dụng dữ liệu đó làm đầu vào cho chương trình
- Ký hiệu: `<`

##### Chuyển hướng tới stderr

- Thông thường, khi gặp lỗi, thông tin sẽ hiển thị luôn lên màn hình cùng với các dữ liệu đầu ra
- Linux cung cấp ký hiệu `2>` để đưa nội dung thông báo lỗi ra file thay vì màn hình hiển thị

##### Tài liệu tham khảo về phần piping và redirection:

[1]: [https://ryanstutorials.net/linuxtutorial/piping.php](https://ryanstutorials.net/linuxtutorial/piping.php)

[2]: [http://www.linfo.org/pipes.html](http://www.linfo.org/pipes.html)
