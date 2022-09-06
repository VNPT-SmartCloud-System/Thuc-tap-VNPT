Do địa chỉ IP private không được trung chuyển trên mạng Internet, vậy nên sử dụng NAT( Network Address Translation) để cho phép nhiều thiết có thể truy cập Internet thông qua một địa chỉ public, để biên dịch địa chỉ IP private sang địa chỉ IP public.
# NAT( Network Address Translition)
Nat (Network Address Translation) là một kỹ thuật cho phép chuyển đổi từ một địa chỉ IP này thành một địa chỉ IP khác. Thông thường, NAT được dùng phổ biến trong mạng sử dụng địa chỉ cục bộ, cần truy cập đến mạng công cộng (Internet). Vị trí thực hiện NAT là router biên kết nối giữa hai mạng.
- Địa chỉ private( định nghĩa trong RFC 1918)

10.0.0.0 - 10.255.255.255

172.16.0.0 - 172.31.255.255

192.168.0.0 - 192.168.255.255

- Địa chỉ public:
Là các địa chỉ còn lại. Các địa chỉ public là các địa chỉ được cung cấp bởi các tổ chức có thẩm quyền.
 ## Nhiệm vụ của NAT
-	NAT (Network Address Translation) giống như một Router, chuyển tiếp các gói tin giữa những lớp mạng  nội bộ sang mạng toàn cầu. 
-	NAT dịch hay thay đổi một hoặc nhiều địa chỉ bên trong một gói tin khi gói tin đó đi qua một Router. Thông thường NAT thường thay đổi địa chỉ thường là địa chỉ riêng (IP Private) của một kết nối mạng thành địa chỉ công cộng (IP Public).
-	NAT cũng có thể coi như một Firewall (tường lửa) cơ bản hỗ trợ bảo mật IP của thiết bị. Giả sử máy tính bị gián đoạn khi kết nối với internet, IP public khi đó lập tức chuyển đổi thành IP thay thế mạng cục bộ.
## Cơ chế hoat động 
 
Gói tin gửi từ PC3 trước khi đi qua Router sẽ được gắn địa chỉ nguồn và địa chỉ đích như hình.

![](https://raw.githubusercontent.com/HaHong2551/Thuc-tap/main/Screenshot_1.png)
![](https://raw.githubusercontent.com/HaHong2551/Thuc-tap/main/Screenshot_2.png)

 
Sau khi gói tin đi đến Router thì địa chỉ IP private sẽ được thay thế bằng địa chỉ IP public thông qua Bảng NAT đã được cấu hình sẵn. Sau khi gói tin trở về đến NAT sẽ dựa vào bảng NAT và thay đổ địa chỉ IP đích thành địa chỉ ban đầu.
 
-	Trường hợp nhiều PC có thể chia sẻ cùng 1 IP public trên mạng thì cần định danh port( một session sẽ ứng với 1 socket). Gói tin chuyển đi sẽ có them các địa chỉ port nguồn và port đích 
![](https://raw.githubusercontent.com/HaHong2551/Thuc-tap/main/Screenshot_3.png)
![](https://raw.githubusercontent.com/HaHong2551/Thuc-tap/main/Screenshot_4.png)
-	Sử dụng bảng NAT để chuyển địa chỉ nguồn đi ra mạng Internet.


#### Ưu điểm của NAT:
-	Tiết kiệm địa chỉ IPv4: Lượng người dùng truy cập internet ngày càng tăng cao. Điều này dẫn đến nguy cơ thiếu hụt địa chỉ IPv4. Kỹ thuật NAT sẽ giúp giảm thiểu được số lượng địa chỉ IP cần sử dụng.
-	Giúp che giấu IP bên trong mạng LAN.
-	NAT có thể chia sẻ kết nối internet cho nhiều máy tính, thiết bị di động khác nhau trong mạng LAN chỉ với một địa chỉ IP public duy nhất.
-	NAT giúp nhà quản trị mạng lọc được các gói tin đến và xét duyệt quyền truy cập của IP public đến 1 port bất kỳ.
Nhược điểm của NAT là gì?
#### Nhược điểm :
-	Khi dùng kỹ thuật NAT, CPU sẽ phải kiểm tra và tốn thời gian để thay đổi địa chỉ IP. Điều này làm tăng độ trễ trong quá trình switching. Làm ảnh hưởng đến tốc độ đường truyền của mạng internet.
-	NAT có khả năng che giấu địa chỉ IP trong mạng LAN nên kỹ thuật viên sẽ gặp khó khăn khi cần kiểm tra nguồn gốc IP hoặc truy tìm dấu vết của gói tin.

#### NAT hiện nay có 3 loại phổ biến sau:
-	Static NAT.
-	Dynamic NAT.
-	NAT Overload.
Mỗi một kỹ thuật NAT khác nhau sẽ có đặc điểm khác nhau, cụ thể như sau:
### Static NAT
 
Static NAT (hay NAT tĩnh) áp dụng cho những trường hợp chuyển đổi IP cục bộ sang IP công cộng một cách cố định, có nghĩa là những địa chỉ IP được chuyển sẽ không thay đổi. Đối với loại NAT này thì cần phải cài đặt thủ công và mỗi một địa chỉ IP cục bộ khi được chuyển đổi sẽ tương ứng duy nhất với một IP công cộng.
- Loại NAT này thường được dùng cho những thiết bị cần truy cập ứng dụng, Internet bằng IP tĩnh như Web, Server, Mail,…
Địa chỉ IP của thiết bị trong Static NAT là 192.168.32.10 luôn được Router chuyển đổi thành địa chỉ IP 213.18.123.110.
Hướng dẫn cấu hình Static NAT
-	Tạo mối quan hệ giữa IP nội bộ và IP đại diện mạng bên ngoài dành cho việc chuyển đổi.
>Router (config) # ip nat inside source static [local ip] [global ip]
-	Cấu hình cổng kết nối vào mạng cục bộ:
>Router (config-if) # ip nat inside
-	Cấu hình cổng kết nối đến mạng bên ngoài: 
>Router (config-if) # ip nat outside

Ví dụ:
![](https://www.totolink.vn/public/uploads/img_article/3loainatnetworkaddresstranslationbancanbietstaticnat.png)
>Router (config) # ip nat inside source static 192.168.1.100 202.1.1.10

>Router (config) # interface fa0/0

>Router (config-if) # ip nat inside

>Router (config) # interface s0/0/0

>Router (config-if) # ip nat outside
### Dynamic NAT
 
Dynamic NAT (hay NAT động) thường được dùng cho trường hợp chuyển đổi địa chỉ IP cục bộ sang địa chỉ IP bên ngoài một cách tự động. Thông thường loại NAT này sẽ được cấu hình trước một dải các địa chỉ IP đại diện cho mạng bên ngoài. Khi các địa chỉ IP cục bộ cần được chuyển đổi thì sẽ được chuyển thành một trong các IP nằm trong dải IP được cấu hình trước đó.
#### Hướng dẫn cấu hình Dynamic NAT
•	Cấu hình dải IP đại diện cho mạng bên ngoài.
>Router (config) # ip nat pool [name start ip] [name end ip] netmask [netmask]/prefix-lenght [prefix-lenght]

•	Cài đặt ACL để phân quyền cho những IP nội bộ nào được phép chuyển đổi thành 1 trong các IP thuộc dải IP đại diện bên ngoài.
>Router (config) # access-list [access-list-number-permit] source [source-wildcard]

•	Tạo mối quan hệ giữa các IP đã được cài đặt trong ACL với dải IP đại diện cho mạng ngoài.
>Router (config) # ip nat inside source list <acl-number> pool <name>

•	Cấu hình cổng kết nối vào mạng cục bộ.
>Router (config-if) # ip nat inside

•	Cấu hình cổng kết nối đến mạng bên ngoài.
>Router (config-if) # ip nat outside

Ví dụ 
![](https://www.totolink.vn/public/uploads/img_article/3loainatnetworkaddresstranslationbancanbietdynamicnat.png)
>Router (config) # ip nat pool abc 202.1.1.177 202.1.1.185 netmask 255.255.255.0

>Router (config) # access-list 1 permit 192.168.1.0 0.0.0.255

>Router (config) # ip nat inside source list 1 pool abc

>Router (config) # interface fa0/0

>Router (config-if) # ip nat inside
Router (config) # interface s0/0/0
Router (config-if) # ip nat outside
### NAT Overload
 
- NAT Overload (hay còn có tên là PAT) được áp dụng cho những trường hợp chuyển đổi nhiều địa chỉ IP nội bộ thành 1 địa chỉ IP đại diện cho mạng bên ngoài. Để tránh bị nhầm lẫn việc chuyển gói tin, NAT Overload sẽ dùng các địa chỉ số cổng cho mỗi một chuyển đổi để phân biệt.
- Các chỉ số cổng sẽ được mã hóa 16 bit. Có nghĩa là tối đa có thể có 65536 IP nội bộ có thể cùng chuyển đổi thành một IP đại diện trong NAT Overload.
#### Hướng dẫn cấu hình NAT Overload
•	Cài đặt ACL cho những địa chỉ IP nội bộ nào cần chuyển đổi.
>Router (config) # access-list <ACL-number> permit <source> <wildcard>

•	Cấu hình các IP nội bộ trong ACL đến cổng nối ra ngoài.
>Router (config) # ip nat inside source list <ACL-number> interface <interface> overload

•	Cấu hình cổng kết nối vào mạng cục bộ.
>Router (config-if) # ip nat inside

•	Cấu hình cổng kết nối đến mạng bên ngoài.
>Router (config-if) # ip nat outside

#### Các lệnh kiểm tra cấu hình của NAT
- Hiển thị bảng NAT đang hoạt động

>R#show ip nat translation
- Hiển thị trạng thái hoạt động của NAT

>R#show ip nat statistics
- Xóa bảng NAT

>R#clear ip nat translation
- Kiểm tra hoạt động của NAT, hiển thị các thông tin chuyển đổi NAT bởi router.

>R#debug ip nat

Tổng kết:
-  Giao thức NAT dùng để chuyển đổi địa chỉ IP private sang IP public. Static NAT được sử dụng để ánh xạ địa chỉ theo kiểu “one-to-one” và được chỉ định bởi người quản trị. Dynamic NAT là kiểu chuyển dịch địa chỉ dạng “one-to-one” một cách tự động. NAT Overload là kiểu chuyển dịch địa chỉ dạng “many-to-one” một cách tự động, sử dụng các chỉ số cổng (port) để phân biệt cho từng chuyển dịch.
##### Chú ý: Ở phần cấu hình PAT có nhắc đến cài đặt ACL(Access Control List)
ACL (Access control list) hay còn gọi là access lists, là một danh sách tuần tự các câu lệnh được áp dụng trên một Interface nào đó, và trên bộ đệm vào hoặc ra, điều khiểu Router từ chối hoặc chuyển tiếp các gói tin dựa vào thông tin trong IP header hoặc TCP/UDP header. Có 2 chức năng chính là phân loại lưu lượng và lọc dữ liệu.
- Ứng dụng trong công nghệ NAT lọc ra các IP, địa chỉ mạng nào được cho phép truy cập ra mạng Internet