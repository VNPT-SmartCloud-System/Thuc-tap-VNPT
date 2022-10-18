# Managing software
Package management là một phương thức nhằm cài đặt và bảo trì các phần mềm được cài đặt trong hệ thống. Mỗi một bản phân phối Linux lại có một hệ thống phân phối package riêng được gọi là packaging system.
- Các thành phần cơ bản trong packaging system đó là:

  - Package files: đơn vị cơ bản nhất của một package và được quản lý bởi maintainer, là một dạng file nén chứa tất cả thông tin cần thiết để cài đặt chương trình.
  - Repositories: Một nơi tập trung chứa các package files, một distribution có thể có một vài repositories khác nhau phục vụ nhiều mục đích khác nhau, hoặc phục vụ cho từng quá trình phát trình phần mềm (repository cho quá trình test,...).
  - Dependencies: Một package thì rất it khi mang tính độc lập mà nó thường được xây dựng dựa trên các package khác, cũng giống như khi các bạn lập trình, khi cài đặt sử dụng một thư viện thì thư viện đó đều xây dựng dựa trên một thư viện khác, các thư viện khác đó gọi là dependencies.
- Có hai loại packaging system phổ biến nhất là Debian và RedHat:
  
|Packaging system|Distributions|
|---|----|
|Debian-style (.deb)|Debian, Ubuntu, Linux Mint, Raspbian|
|Red Hat–style (.rpm)|Fedora, CentOS, Red Hat Enterprise Linux, OpenSUSE|

### Repository
- Repository là một tập hợp nhiều mục được lưu trữ cùng nhau với số lượng  rất lớn, nó chứa các phần mềm và gói(package) mà bạn có thể cài dặt trên hệ thống của mình
- Chúng giống như định dạng file nén mà trong đó chứa tất cả nhưng file chạy và cấu hình của phần mềm, thông tin về phần mềm, nhà sản xuất, những yêu cầu về hệ thống
- Linux cung cấp phần mềm cho người dùng ở định dạng với các bản phân phối khác nhau. Ví dụ phân phối dựa trên Debian có các gói DEB, các gói RPM trên Fedora, CentOS
- Vì repository là tập hợp các gói nên người dùng có thể tìm và tải xuống gói mình cần trong kho này, các bản phân phối Linux khác nhau có bộ repository riêng, để thêm bất kỳ repository nào khác sử dụng lệnh add-apt-repository

### Các lệnh quản lý package cơ bản
#### Using yum 
- Tìm gói (Khi bạn sử dụng tìm kiếm YUM nóe sẽ liên lạc với các kho lưu trữ trực tuyến )
```sh
yum search packagename
```
Khi bạn cần tìm gói tin có chứa một tệp cụ thể bạn có thể sử dụng 
```sh
yum whatprovides*/name_file.
```
- Tìm thông tin của gói
```sh
    yum info + packagename
```
- Cài đặt gói
```sh
yum install packagename
```
- Gỡ cài đặt gói
```sh
yum remove packagename
```
- Danh sách gói
  - Hiển thị tất cả các gói phần mềm có sẵn 
```sh
yum list
```
  - Hiển thị tất cả các package đã được cài đặt
```sh
yum list installed
```


- Cập nhật gói 
   - Trong kho lưu trữ luôn chứa phiên bản hiện tại, khi sử dụng lệnh yum update, các phiên bản của các gói được cài đặt được so sánh với phiên bản của các gói này trong kho lưu trữ.
```sh
yum update packagename
```
   - Kiểm tra package đang có bản update nào hay không
```sh
yum check update
```
   - Nếu muốn cập nhật toàn bộ package trên hệ thống thì chạy lệnh sau.
```sh
yum update
```
- Hiển thị tất cả Group Packages
   - Số lượng các package sẽ được đứa vào một nhóm cụ thể ví dụ như nhóm installed, available Group
```sh
yum grouplist
```
   - Cài đặt tất cả những package nằm trong nhóm Available 
```sh
yum groupinstall 'Available Group'
```
   - Update các package nằm trong nhóm đó thì chạy lệnh.
```sh
yum groupupdate 'Available Group'
```
   - Xóa tất cả package trong group thì chạy lệnh.
```sh
yum groupremove 'Available Group'
```
- Liệt kê repo 
   - Xem tất cả những kho repo nào có sẵn trong hệ thống thì chạy lệnh sau.
```sh
yum repolist
```
   - Liệt kê tất cả các kho yum được kích hoạt và vô hiệu hoá
```sh
yum repolist all
```
- Theo mặc định, lệnh yum chỉ cài đặt từ kho được kích hoạt. Vì một số lý do bạn muốn cài đặt một gói từ kho lưu trữ bị vô hiệu hóa
```sh
yum --enablerepo=base install packagename
```
- Clean bộ nhớ cache bằng yum
```sh
yum clean all
```
- Xem lịch sử của yum
```sh
yum history list
```
#### Using rpm
- Trước đó các kho lưu trữ không tồn tại và lệnh rpm được sử dụng để cài đặt các gói sau khi chúng được tải xuống. Tuy nhiên để cài dặt các gói cụ thể thì có các gói phụ thuộc cần được cài đặt trước. Không giống yum, yum sẽ xem xét tất cả các gói phụ thuộc và cố gắng tìm kiếm chúng trong các kho lưu trữ hiện có => Sử dụng Yum để cài đặt phần mềm
*Chú ý : Trên hệ thống, có 2 cơ sở dữ liệu gói được duy trì: cở sở dữ liệu YUM và cở sở dữ liệu RPM. Khi bạn cài đặt các gói thông qua YUM, cơ sở dữ liệu YUM sẽ được cập nhật trước, sau đó thông tin được cập nhật đến cơ sở dữ liệu RPM. Nếu bạn cài đặt các gói bằng lệnh RPM, bản cập nhật chỉ được ghi vào cơ sở dữ liệu RPM và sẽ không được cập nhật lên cơ sở dữ liệu YUM=> không nên sử dụng lện RPM để cài đặt phần mềm gói.*
- Cấu trúc của một RPM package như sau:
  
name-version-release.architecture.rpm

name : tên của gói cài đặt. 

version: số phiên bản, là phiên bản của gói được phát hành. Ví dụ: 84.0.2

release: đại diện cho những thay đổi nhỏ được thực hiện bởi người bảo trì gói, không phải tác giả của chương trình. Những thay đổi này có thể là các bản vá được thêm vào chương trình gốc để sửa lỗi hoặc để làm cho chương trình tương thích hơn với các bản phân phối Linux 

architecture: thành phần cuối cùng đứng trước phần mở rộng .rpm là mã cho kiến trúc của gói. Ví dụ như với x86_64 thể hiện gói này hỗ trợ cài trên các máy Intel 64bit.

#### Quản lý gói với RPM
- Kiểm tra gói RPM
```sh
rpm --checksig cautrucgoi
```
- Cài đặt gói RPM 
```sh
rpm -ivh telnet-0.17-65.el7_8.x86_64.rpm
```
-i : Cài đặt một gói

-v : verbose hiển thị đẹp mắt hơn

-h: hiển thị dấu # khi giải nén gói
- Kiểm tra các phụ thuộc trước khi cài đặt gói RPM
```sh
rpm -qpR telnet-0.17-65.el7_8.x86_64.rpm
```
-q: Truy vấn gói

-p: Liệt kê các phần phụ mà gói này cung cấp

-R: Liệt kê các tthành phần mà gói này phụ thuộc.
- Kiểm tra gói RPM đã cài đặt( sử dụng -qa)
```sh
rpm -qa
```
- Liệt kê các gói RPM được cài đặt gần đây
```sh
rpm -qa --last
```
- Nâng cấp gói RPM
```sh
rpm -Uvh telnet-0.17-65.el7_8.x86_64.rpm
```
- Cách xoá gói RPM (dụng lệnh rpm và tuỳ chọn -e để gở bỏ.)
```sh
rpm -e telnet
```
### Quản lý bằng DNF

- DNF là bản viết lại của YUM. Trong nhiều trường hợp, khi yêu cầu thông tin về YUM, bạn đã chuyển hướng đến tài nguyên DNF
- Dnf là một trình quản lý kho lưu trữ, nhưng nó sử dụng libsolv để giải quyết sự phụ thuộc và hawkey để cung cấp các API C và Python đơn giản
- DNF có sẵn trong kho lưu trữ chính thức của RHEL 7 và CentOS. Để cài đặt DNF trên CentOS 7, chỉ cần chạy lệnh sau như nguồn gốc người sử dụng:

- Cài đặt dnf
```sh
 yum install dnf
 ```
- Tìm kiếm package
```sh
dnf search + packagename
```
- Cài đặt package
```sh
dnf install + packagename
```
- Kiểm tra thông tin package
```sh
dnf info + packagename
```
- Kiểm tra cập nhật package
```sh
dnf check-update + packagename
```
- Cập nhật package
```sh
dnf update + packagename
```
- Gỡ bỏ package
```sh
dnf remove + packagename
```
- Gỡ bỏ các dependencies đã được cài đặt với package
```sh
dnf autoremove
```