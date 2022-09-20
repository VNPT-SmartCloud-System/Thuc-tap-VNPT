
- Tìm hiểu về cấu trúc thư mục trong Linux
- Cách sử dụng các lệnh tương tác với thư mục: pwd, cd, mkdir, rmdir,..
## 1. The Linux File Hierarchy Structure hay Filesystem Hierarchy Standard (FHS)
- Một hệ thống Linux được trình bày như một phân cấp với thư mục gốc (/) làm điểm bắt đầu.
- Là danh sách các folder được xắp xếp bên trong hệ điều hành Linux, qua đó dữ liệu sẽ được lưu trữ đúng nơi vị trí của nó.
Một số thư mục :

|  | Ý nghĩa |
|----|---------|
| /| Là thư mục gốc, là nơi cây hệ thống bắt đầu |
| /bin| Chứa các chương trình cài dặt vào Linux |
|/boot|Chứa tất cả các tệp và thư mục cần thiết để khởi động nhân Linux.|
|/dev|Chứa các tệp thiết bị được sử dụng để truy cập các thiết bị vật lý.|
|/etc|Chứa các tệp cấu hình được sử dụng bởi các chương trình và dịch vụ trên máy chủ của bạn.|
|/home| Chứa các tập tin của người dùng trong hệ thống, mỗi user sẽ có một thư mục bên trong này|
|/media,/mnt| Chứa các thư mục được sử dụng để lắp các thiết bị trong cây|
|/opt|Được sử dụng cho các gói tùy chọn có thể được cài đặt trên máy chủ của bạn, chứa các ứng dụng thêm của các hãng khác nhau|
|/proc|Được sử dụng bởi hệ thống tệp Proc. Đây là cấu trúc hệ thống tệp cho phép truy cập vào thông tin kernel|
|/root|chứa tập tin của root|
|/run|Chứa thông tin quy trình và người dùng cụ thể đã được tạo kể từ lần khởi động cuối cùng.|
|/srv|Chứa các dữ liệu liên quan các dịch vụ máy chủ như FTP và HTTP|
|/sys|Được sử dụng như một giao diện cho các thiết bị phần cứng khác được quản lý bởi nhân Linux|
|/tmp|Chứa các file tạm thời có thể bị xóa mà không có bất kỳ cảnh báo khi khởi động lại|
|/usr|Chứa các tập tin thực thi, thư viện, tài liệu và mã nguồn cho các chương trình.|
|/var|Chứa các file có thể thay đổi kích thước linh động như  log files,mail boxes, and spool files|
Mounting ?
- Trong quá trình gắn, một thiết bị được kết nối với một thư mục cụ thể, sao cho sau khi gắn kết, thư mục này cho phép truy cập vào noi dung thiết bị.
- Hệ thống phân cấp này có thể được phân phối trên các thiết bị khác nhau và thậm chí các hệ thống máy tính được gắn vào thư mục gốc.
- Các thiết bị gắn kết cho phép tổ chức hệ thống tệp Linux một cách linh hoạt. 
- Có một số nhược điểm để lưu trữ tất cả các tệp chỉ trong một hệ thống tệp, điều này cho một số lý do chính đáng để làm việc với nhiều mounts: 
  - Hoạt động cao trong một khu vực có thể lấp đầy toàn bộ hệ thống tệp, điều này sẽ tác động tiêu cực đến các dịch vụ chạy trên máy chủ. 
  - Nếu tất cả các tệp nằm trên cùng một thiết bị, rất khó để đảm bảo truy cập và phân biệt giữa các khu vực khác nhau của hệ thống tệp với các nhu cầu bảo mật khác nhau. Bằng cách gắn một hệ thống tệp riêng biệt, các tùy chọn gắn kết có thể được thêm vào để đáp ứng các nhu cầu bảo mật cụ thể. 
  - Nếu hệ thống tệp một thiết bị được lấp đầy hoàn toàn, có thể khó có thể cung cấp thêm không gian lưu trữ. 

# 2. Các lệnh tương tác với thư mục
## 2.1. Lệnh ls - xem danh sách tập tin thư mục
ls -[tùy chọn] [đường dẫn thư mục muốn xem]
Các tùy chọn phổ biến
|Các tùy chọn | Ý nghĩa|
|----|----|
|-L|Hiển thị danh sách tập tin, thư mục (chỉ hiện thị tên).|
|-l|Hiển thị danh sách tập tin, thư mục (gồm nhiều cột: filename, size, date,….|
|-a|Liệt kê tất cả các tập tin, thư mục, bao gồm những tập tin ẩn.|
|-R|Liệt kê tất cả các tập tin, thư mục kể cả các tập tin, thư mục bên trong thư mục cha.|
### Lệnh grep
#### 2.1.1. Lọc lại tên tập tin thư mục muốn xem 
Lệnh ls -l của "/" cho kết quả nhiều thông tin, nếu muốn lọc lại tên tập tin thư mục muốn xem chỉ cần thêm grep.
VD: 
> ls -l | grep pro  (Muốn xem trong "/" có tập tin, thư mục nào có ký tự là pro)
> ls -l /etc/ | grep yum (Thư mục /etc có tập tin, thư mục nào có ký tự là yum )

#### Lệnh grep còn được dùng tìm kiếm chuỗi trong file
VD: grep "yum" /root/*.txt (Tìm kiếm chuỗi "yum" trong các file có đuôi .txt trong thư mục /root:)
## 2.2 Lệnh pwd - xem bạn đang ở thư mục nào
Cú pháp: pwd [-options]
Lệnh pwd tồn tại 2 trạng thái:
- 0 : Success
- Non-zero : Failure
pwd Option

|Option|Ý nghĩa |
|---|----|
|-L,--logical|Được sử dụng để in các liên kết tượng trưng|
|-P,-- physical|Dược sử dụng để in đường dẫn thực tế mà không có bất kỳ liên kết tượng trưng nào|
|--version|In ra version chương trình|
|--help|Hiển thị thông báo trợ giúp|
Chú ý: Các biến môi trường là các biến có chứa các giá trị cần thiết để thiết lập môi trường shell, các biến môi trường vẫn tồn tại trong các quá trình con của shell.
## 2.3 Lệnh cd - dùng để đổi sang một thư mục khác
Các lệnh cd thông dụng:
- Di chuyển về thư mục gốc: cd /
- Di chuyển đến 1 vị trí bất kì khi biết đường dẫn tuyệt đối: cd /etc/networks
- Di chuyển đến thư mục con nằm trong thư mục hiện tại: cd docs hoặc ./docs
- Di chuyển đến thư mục mẹ: cd ..
- Lệnh cd không có tham số, sẽ đưa bạn về home directory, dù bất kể bạn đang ở đâu: cd hoặc cd ~
- Lệnh cd dùng để quay về thư mục trước: cd -
## 2.4 Lệnh mkdir - dùng để tạo thư mục trên Linux
- Lệnh mkdir được sử dụng để tạo một thư mục trong thư mục hiện tại:
> #mkdir [tên thư mục cần tạo]

- Tạo một thư mục "abcdir" tại thư mục /root/
> #mkdir /root/abcdir/

- Tạo 3 thư mục "abcdir1","abcdir2", "abcdir3" tại thư mục hiện tại
> #mkdir abcdir1 abcdir2 abcdir3

- Tạo 3 thư mục "abcdir1","abcdir2", "abcdir3" tại thư mục root
> #mkdir /root/abcdir1/root/abcdir2/root/abcdir3 
hoặc #mkdir /root/{abcdir1,abcdir2,abcdir3}
- Tạo thư mục kèm theo thư mục cấp cha chủa nó khi thư mục cấp cha của nó chưa tồn tại.
> #mkdir -p -v /root/abcdir_parent/abcdir

(Khi đó nó sẽ tạo thư mục cha trước sau đó sẽ tạo thư mục con)
## 2.5. Lệnh xóa tập tin thư mục
- Xóa tập tin 
> #rm [đường dẫn]

VD: Xóa tập tin abc.txt trong /usr/passwd:
> #rm /usr/passwd/abc.txt

- Xóa tập tin mà không cần hỏi
> #rm -f [đường dẫn]

- Xóa thư mục
> #rm -rf [đường dẫn]

- Xóa thư mục rỗng
> #rmdir [đường dẫn]

## 2.6. Lệnh copy tập tin, thư mục
- Lệnh sao chép tập tin:
>cp [đường dẫn nguồn] [đường dẫn đích]

Ví dụ: Sao chép tập tin abc.txt trong thư mục /root sang /usr: 
> #cp /root/abc.txt /usr

- Lệnh sao chép thư mục:
> #cp -r [đường dẫn nguồn] [đường dẫn đích]
> 
Ví dụ: Sao chép thư mục /root/networks sang /usr/bin:

> #cp -r /root/networks /usr/bin
## 2.7 Lệnh mv - dùng di chuyển, đổi tên
- Cần đổi tên một tập tin
>#mv [đường dẫn với tên củ] [đường dẫn với tên mới]

Ví dụ: Đổi tên tập tin test1.txt trong /root thành test.txt:
>#mv /root/test1.txt /root/test.txt

- Di chuyển một tập tin đến vị trí khác, trong khi đó nó có thể đổi tên cùng lúc.
>#mv [đường dẫn nguồn] [đường dẫn đích]

Ví dụ: Di chuyển và đổi tên tập tin test1.txt trong /root sang /etc đổi tên thành test.txt:
>#mv /root/test1.txt /etc/test.txt
## 2.8. Cách  hiển thị các tệp văn bản 
|Lệnh|Chức năng|
|---|----|
|cat|Dùng để xem các tập tin không quá dài.|
|tac|Dùng để xem nội dung của một tập tin ngước bắt đầu từ dòng cuối.|
|less|Lệnh less dùng mở một tệp để đọc tương tác, cho phép di chuyển lên xuống và tìm kiếm.|
|head|Dùng để in 10 dòng đầu của tập tin theo mặc định|
|tail|Dùng để in 10 dòng cuối của tập tin theo mặc định.|
|cut|Được sử dụng để lọc các cột hoặc ký tự cụ thể từ tệp văn bản
|tess|Dùng để xem tập tin lớn hơn vì đây là chương trình phân trang.|
Chú ý với head và tail có thể sửa dòng lệnh để đọc n dòng 
VD:
>head -n 5 /etc/passwd

Nguồn
https://blogd.net/linux/lam-viec-voi-tap-tin-va-thu-muc-tren-linux/#2-l%E1%BB%87nh-cd