Noi dung: Tìm hiểu về shell( các loại shell, cách thức làm việc), terminal
Tìm hiểu về giao thức SSH


![](https://www.elprocus.com/wp-content/uploads/2014/10/Architecture-of-Linux.png)
### Kernel là gì?
- Kernel là một chương trình máy tính là cốt lõi của hệ điều hành máy tính, với toàn quyền kiểm soát mọi thứ trong hệ thống. Nó quản lý các tài nguyên sau của hệ thống Linux:
   - File management
   - Process management
   - I/O management
  - Memory management
   - Device management ect.
Người ta thường nhầm rằng Linus Torvalds đã phát triển hệ điều hành Linux, nhưng thực ra ông chỉ chịu trách nhiệm phát triển nhân Linux.
Toàn bộ hệ thống Linux = Kernel + GNU system utilities and libraries + other management scripts + installation scripts.
## 1.Shell
Shell là một chương trình người dùng đặc biệt mà nó cung cấp giao diện cho người sử dụng với các dịch vụ hệ thống. Shell cho phép người dùng có thể dùng câu lệnh từ người dùng và chuyển sang dạng mã máy(nhi phân) để kernel có thể thông dịch được(Một trong những điểm khác biệt là trình thông dịch thực hiện từng câu một). Shell được bắt đầu khi người dùng đăng nhập hoặc bắt đầu terminal.
Đây là một giao diện cho kernel che giấu sự phức tạp của các chức năng của kernel từ người dùng. Nó nhận các lệnh từ người dùng và thực thi các chức năng của kernel.
![](https://media.geeksforgeeks.org/wp-content/uploads/18834419_1198504446945937_35839918_n-300x291.png)
Co 2 loại shell :
- Command Line Shell: Shell có thể được truy cập bởi người dùng bằng cách sử dụng command line interface. Làm việc với command line shell sẽ có một chút khó khăn cho người mới bắt đầu bởi vì thật khó để nhớ hết các lệnh. Nhưng khi chúng ta đã quen thì nó rất mạnh mẽ, nó cho phép người dùng lưu trữ các lệnh trong một file và thực thi chúng cùng nhau. Với tính năng này, bất kỳ nhiệm vụ lặp đi lặp lại nào có thể xử lý tự động. Các tệp này thường được gọi là batch file trong Windows và Shell Script trong Linux / macOS.
- Graphical shell:cung cấp phương tiện để thao tác với các chương trình dựa trên graphical user interface (GUI).Người dùng không cần nhập lệnh cho mọi hành động.
  
Một số shell có sẵn trong các hệ thống Linux
### 1.1.Bourne Shell (sh):

Là Shell được viết bởi Steve Bourne , là 1 UNIX shell đầu tiên. Shell này thích hợp sử dụng cho lập trình shell vì lợi thế về tính nhỏ gọn và tốc độ. Một nhược điểm của Bourne shell là nó thiếu các tính năng tương tác, ví dụ như tính năng gọi lại các lệnh đã sử dụng trước đó (lịch sử lệnh). Bourne Shell cũng không có các tính năng tích hợp số học và xử lý biểu thức logic. Trong sh không có kiểu dữ liệu mảng.

Bourne Shell là shell mặc định của Solaris OS, là shell tiêu chuẩn cho các script quản trị hệ thống Solaris.
- Các lệnh trong Bourne shell:
   - Lệnh gọi tên đường dẫn đầy đủ là / bin / sh và / sbin / sh.
   - Lời nhắc mặc định cho non-root user là $.
    - Lời nhắc mặc định cho root user là #
  
### 1.2. C Shell (csh)
- Là một phần cải tiến UNIX được viết bởi Bill Joy - Đại học California Berkeley.
- Có các tính năng kết hợp để sử dụng tương tác, chẳng hạn như bí danh và lịch sử lệnh
- Hỗ trợ các tính năng lập trình tiện lợi, chẳng hạn như số học tích hợp và cú pháp biểu thức C-like.
- Các lệnh trong C-shell:
   - Lệnh tên đường dẫn đầy đủ là / bin / csh
   - Dấu nhắc mặc định cho non-root user là tên máy chủ %.
   - Dấu nhắc mặc định cho root user là tên máy chủ #.
### 1.3. Korn Shell(ksh)
- Được viết bởi David Korn tại AT & T Bell Labs
- Có các tính năng tương tác tương đương với các tính năng trong C shell
- Chạy các script được viết cho Bourne shell.
- Các lợi ích của ksh bao gồm:
  - Cú pháp vòng lặp tốt hơn, các phương thức thao tác chuỗi.
  - Các cách lặp lại lệnh tự nhiên
  - Mảng liên kết
- Các lệnh trong Korn shell:
  - Lệnh tên đường dẫn đầy đủ là / bin / ksh.
  - Dấu nhắc mặc định cho non-root user là $
  - Dấu nhắc mặc định cho root user là #.
### 1.4. BASH (Bourne Again SHell)
Shell mặc định cho người dùng trong Linux là GNU Bash: 
- được phát triển bởi Dự án GNU. 
- Shell Linux mặc định trên hầu hết các phân phối Linux. Tương thích ngược với vỏ SH UNIX ban đầu.
-  Bash phần lớn tương thích với SH và kết hợp các tính năng hữu ích từ Korn Shell KSH và C Shell CSH. 
-  Bash là vỏ mặc định cho Linux. Tuy nhiên, nó chạy trên mọi phiên bản của Unix và một vài hệ điều hành khác như MS-DOS, OS/2 và Windows. 
-   Ngoài ra, hầu hết các tập lệnh SH có thể được chạy bằng bash mà không cần sửa đổi.
-   Bash cũng cung cấp một số cải tiến cho người dùng:
   - Hoàn thành lệnh
   - Lịch sử lệnh
   - Bash kiểm tra mail định kì.
-  Các lệnh trong GNU Bourne-Again Shell:
  - Lệnh tên đường dẫn đầy đủ là / bin / bash.
  - Dấu nhắc mặc định cho non-root user là bash-x.xx$. (Trong đó x.xx cho biết số phiên bản shell là gì. Ví dụ: bash-3.50 $)
   - Dấu nhắc mặc định cho root user bash-x.xx #. (Trong đó x.xx cho biết số phiên bản shell là gì. Ví dụ: bash-3.50 $ #). 
### 1.5. FISH (Friendly interactive shell)
- Là một tools thay thế cho command line bash mặc định của windows, linux, macOS, nó giúp cho việc thực thi các lệnh bash trở lên đơn giản hơn, có tính tương tác hơn và thân thiện hơn. Và được phát triển dưới dạng opensource nên chắc chắn về phần maintenance và phát triển sẽ là liên tục.
- Fish cũng có một số cải tiến hơn các shell khác:
  - Các lệnh có cú pháp không hợp lệ sẽ được hiển thị màu đỏ
  - Cú pháp đúng sẽ hiển thị bằng màu xanh lam
  - Gợi ý câu lệnh: Chức năng đầu tiên phải kể đến ở đây là fish hỗ trợ chúng ta gợi ý câu lệnh, chức năng này gợi ý này được lấy từ lịch sử những lệnh mà bạn đã gõ, giống như trình web.
### 1.6.  Z Shell
- Zsh có những điểm tương đồng với bash và ksh, kết hợp nhiều tính năng được tìm thấy trong tcsh
- Các tính năng của Zsh:
  - Cd tự động: Chỉ cần nhập tên của thư mục
  - Mở rộng đường dẫn đệ quy: Ví dụ: “/ u / lo / b” mở rộng thành “/ usr / local / bin”
  - Sửa lỗi chính tả và hoàn thành gần đúng: Nếu bạn mắc một lỗi nhỏ khi nhập tên thư mục, ZSH sẽ sửa nó cho bạn
  - Hỗ trợ plugin và chủ đề: ZSH bao gồm nhiều khung plugin khác nhau
  - Hỗ trợ plugin và chủ đề có lẽ là tính năng thú vị nhất của ZSH 

-Teminal la à giao diện cung cấp bởi hệ thống để viết các lệnh và tương tác với các lệnh
-Shell là chương trình lấy câu lệnh làm đầu vào và cung cấp cho ta đầu ra. Khi terminal được khởi tạo thì shell mặc định cũng được khởi Tạo
-Một số Linux Shell có sẵn. Để tìm ra tất cả các shell có sẵn trên hệ thống của bạn, hãy mở terminal và nhập:
cat /etc/shells

![](https://raw.githubusercontent.com/HaHong2551/Thuc-tap/main/linux1.png)

## 2. Giao thuc SSH
- Secure Shell (SSH) là một giao thức mạng dùng để thiết lập kết nối mạng một cách bảo mật. Port mặc định đuợc sử dụng bởi SSH là 22. SSH tạo ra một kênh kết nối được mã hóa an toàn từ một mạng không an toàn nhu Telnet( Giao thức này trao đổi dữ liệu, mật khẩu dưới dạng plaintext, khiến chúng rất dễ bị phân tích và đánh cắp).Điểm đặc biệt của SSH là giao thức này sử dụng các thuật toán mã hóa bất đối xứng, đối xứng và hashing để đảm bảo tính bảo mật và toàn vẹn của dữ liệu được trao đổi từ client tới server và ngược lại.
- SSH có nhiều cách để xác thực một người dùng, nhưng hai cách thông dụng nhất vẫn là xác thực dựa trên mật khẩu và xác thực public-key.
   - Xác thực dựa trên mật khẩu đơn giản là bạn chỉ việc sử dụng mật khẩu của user bạn tạo để truy cập, server sẽ lưu chúng, và đối chiếu với mật khẩu của bạn khi đăng nhập. Cách này thì không đủ an toàn do bạn có khả năng bị đánh cắp mật khẩu.
   - Cách này sử dụng một cặp khóa – public-key và private-key – được tạo ra dựa trên thuật toán mã hóa public-key. 
### 2.1. Cau lenh
- Sử dụng SSH để login với password
Trên máy local của bạn:
> ssh your-username@host

host ở đây có thể là địa chỉ ip hoặc domain name của máy mà bạn truy cập tới. Sau đó nhập mật khẩu tương ứng với user của bạn ở host đó.

- Tạo cặp khóa
Câu lệnh để tạo ra một cặp khóa xác thực SSH.
Câu lệnh đơn giản nhất, trên máy local:

ssh-keygen
  