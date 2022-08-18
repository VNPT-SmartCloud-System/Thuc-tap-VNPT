# Địa chỉ IP 
Do địa chỉ MAC không có cấu trúc nên không thể sử dụng để định tuyến  phải tạo ra một spanning tree. Việc kết nối các mạng vật lý: cấu trúc vật lý khác nhau và cách đánh địa chỉ khác nhau cực kỳ phức tạp
* Cần phải có một phân lớp chung độc lập với các mạng vật lý, kết nối mạng lớp Internetworking tạo thành mạng Internet
## Địa chỉ IP dùng để làm gì?
* Interface trên host và router đều có thể gửi và nhận IP datagram, nên mỗi giao diện phải có một IP address IP Address có tính duy nhất!
* Địa chỉ IP có 2 version: IPv4 (32 bit) và IPv6(128 bit)
- Cấu trúc: Gồm 2 phần
    * Network address: địa chỉ mạng
    * Host address: địa chỉ máy trạm
* Cấp phát địa chỉ IP: Tĩnh và Động
## IP Address Classifying
* Multicast Address
  * Địa chỉ định danh (logic) cho một nhóm các host trên mạng máy tính có khả năng xử lý datagrams hoặc frames cho một số dịch vụ mạng được chỉ định
* Broadcast Address
  * Địa chỉ có các bit phần HostID bằng 1
  * Sử dụng khi muốn phát quảng bá đến toàn bộ host trong cùng mạng
* Default Mask/Subnet mask
  * Địa chỉ dùng để che phần host ID của địa chỉ IP  để xác định network ID
* Private: Có 3 dải mạng dành cho private, sẽ không được định tuyến trên internet, có thể dùng đi dùng lại được
![Private](https://3.bp.blogspot.com/-tqXXjldaJSs/V1ECAxQxmmI/AAAAAAAAAfI/qHUIvZG30mMGLcsNAB16dn7OeMk-sGYpACLcB/s1600/Capture.PNG)
Public: Ngoài 3 dải mạng trên sẽ đi được trên internet
Chuyển đổi địa chỉ Private-> Public bằng NAT(Network Access Translation)
## Các lớp địa chỉ IP
* Địa chỉ IP là một dải nhị phân dài 32 bit và chia thành 4 bộ 8 bit gọi là các Octet, gồm phần network address dùng để xác định mạng mà thiết bị kết nối vào và phần host-address để xác định thiết bị của mạng đó.   
* Địa chỉ IP được chia làm 5 lớp, ký hiệu là A, B, C, D và E.
![](https://techhub.hpe.com/eginfolib/networking/docs/switches/5130ei/5200-3942_l3-ip-svcs_cg/content/images/image8.png) 

* Các dải địa chỉ của các lớp
Số máy trạm tối đa trong một mạng:k=2^n – 2
Trong đó: n – số bit của Host ID.
* 2 địa chỉ còn lại:
  * Địa chỉ toàn 0 – địa chỉ mạng
  * Địa chỉ toàn 1 – địa chỉ quảng bá trong phạm vi một mạng

### Cách chia địa chỉ IP
* Lớp A: (0-127)
Trong địa chỉ lớp A, byte đầu tiên được dùng để định nghĩa địa chỉ mạng. Tuy nhiên bit đầu tiên phải luôn luôn bằng ‘0’. 7 bit còn lại chỉ định các mạng khác nhau.     
    * Lớp A: Địa chỉ từ 1.0.0.0 -> 127.0.0.0
    * 126 mạng được sử dụng 
    * 2^24 - 2 là các host được sử dụng

* Lớp B   (128-191)
    * Địa chỉ mạng: 128.0.0.0 -> 191.255.0.0
    * 2^14 mạng cho lớp B
    * 2^16-2 host cho lớp B

* Lớp C (192-233)
    * Địa chỉ mạng: 192.0.0.0 -> 233.255.255.0
    *  2^21 mạng cho lớp C
    *  2^8-2 host cho lớp C

* Lớp D
    * Địa chỉ: 224.0.0.0 đến 240.0.0.0

* Lớp E
    * Địa chỉ mạng: 241.0.0.0 đến 255.0.0.0
### Nhận xét:
Đánh địa chỉ có phân lớp có một số nhược điểm
– Cứng nhắc, lớp C quá nhỏ, lớp B quá lớn không tận dụng hiệu quả miền địa chỉ
– Các router trong mạng nội bộ cần phải có địa chỉ mạng (network ID.) riêng biệt cho từng giao diện
=> CIDR để giải quyết
# CIDR
Địa chỉ IP: a.b.c.d/x, trong đó a.b.c.d là địa chỉ mạng, x (mặt nạ mạng) là số lượng bit trong phần ứng với địa chỉ mạng
* Phân chia mạng con (Subneting)
– Mở rộng địa chỉ mạng sang các bit của địa chỉ host
- VD:
  * IP class C: 203.160.9.0 và subnet mask: 255.255.255.0 (địa chỉ mạng 24 bits)
– Chia thành 4 mạng con lấy thêm 2 bít cho địa chỉ mạng (26 bits)
* Địa chỉ mạng 1: 203.160.9.0
* Địa chỉ mạng 2: 203.160.9.64
* Địa chỉ mạng 3: 203.160.9.128
* Địa chỉ mạng 4: 203.160.9.192
