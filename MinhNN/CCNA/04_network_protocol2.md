# Title

## Overview

1. DHCP (Dynamic Host Configuration Protocol)
2. Cách cấu hình router thành DHCP Server
3. Cơ chế phân giải địa chỉ ARP (Address Resolution Protocol)
4. ICMP (Internet Control Messages Protocol)

### 1 DHCP (Dynamic Host Configuration Protocol)

- Cho phép DHCP sever cấp 1 dải địa chỉ IP, cấp IP tự động cho các host trong hệ thống mạng mà không cần phải cấu hình IP tĩnh trên từng PC.

#### 1.1 Cách hoạt động của DHCP

- Khi muốn kết nối internet, thiết bị sẽ gửi yêu cầu `DHCP Discover` đến máy chủ. Máy chủ DHCP sẽ tìm địa chỉ IP khả dụng để gán cho thiết bị cùng với gói `DHCP Offer`. Sau khi nhận được địa chỉ, thiết bị sẽ phản hồi với máy chủ thông qua một gói tin `DHCP REQUEST`. Khi đó máy chủ sẽ gửi tin báo nhận (`ack`) xác nhận thiết bị đã có ip và thời gian sử dụng ip đến khi có địa chỉ mới.

- Sơ đồ hoạt động được mô tả như sau:

  ![](images/04_network-example1.png)

- Các thông điệp của DHCP:
  - `DHCP Discover`: Là gói tin được tạo khi thiết bị yêu cầu truy cập mạng gửi broadcast trên physical subnet để đến server DHCP
  - `DHCP Offer`: Sau khi nhân được DHCP Discover thì DHCP Server sẽ gửi gói tin chứa thông tin địa chỉ IP và cấu hình TCP/IP bổ sung cho máy tính Client
  - `DHCP Request`: Là gói thông tin do DHCP client gửi lại cho máy chủ DHCP sau khi tiếp nhận DHCP Offer nhằm xác nhận đã chấp nhận địa chỉ IP được cấp phát
  - `DHCP Acknowledgement`: Khi xác nhận DHCP Request của máy Client thì DHCP gửi lại gói DHCP acknowledge và kèm theo đính hướng tham số để Client có thể tham gia mạng TCP/IP
  - `DHCP Nak`: Đối với các địa chỉ IP không còn giá trị sử dụng hoặc được sử dụng bởi 1 máy khác thì DHCP server thực hiện gửi gói DHCP Nak để thông báo cho Client thuê bao lại IP
  - `DHCP Decline`: Được gửi đến các DHCP server khi Client thực hiện quyết định tham số thông tin không còn giá trị và tiến hành thuê bao lại.
  - `DHCP Release`: Do DHCP Client gửi đến server để thông báo giải phóng địa chỉ IP cùng lúc đó Client sẽ tiến hành xóa thuê bao đang tồn tại

#### 1.2 Ưu điểm của DHCP

- Cung cấp tự động IP, cho phép các thiết bị kết nối internet nhanh chóng.
- Quản lý IP khoa học, tránh bị trùng IP.
- Các thiết bị di chuyển tự do giữa các mạng, và được tự động cập nhật ip mới
- Có thể thay đổi và cấu hình thông số IP
- Quản lý địa chỉ IP, các tham số TCP/IP trên cùng một màn hình, dễ dàng quản lý

#### 1.3 Nhược điểm của DHCP

- Với các thiết bị cố định, cần truy cập liên tục như máy in, file server, vì nếu dùng DHCP, máy tính sẽ thường xuyên cập nhật cài đặt để có thể sử dụng máy in, file server
- Thường sử dụng ở các hộ gia đình, các mô hình nhỏ.

[Tài liệu tham khảo DHCP 1](https://fptcloud.com/dhcp-la-gi/)

[Tài liệu tham khảo DHCP 2](https://wiki.matbao.net/dhcp-la-gi-tim-hieu-cach-tao-ip-dong-va-giai-phap-bao-mat-dhcp/)

#### 1.4 Các thuật ngữ DHCP

- `DHCP Server`: Máy chủ quản lý việc cấu hình và cấp phát địa chỉ IP cho Client
- `DHCP Client`: Máy trạm nhận thông tin cấu hình IP từ DHCP Server
- `Scope`: Phạm vi liên tiếp của các địa chỉ IP có thể cho một mạng
- `Exclusion Scope`: Là dải địa chỉ nằm trong Scope không được cấp phát động cho Clients
- `Reservation`: Địa chỉ đặt trước dành riêng cho máy tính hoặc thiết bị chạy các dịch vụ (tùy chọn này thường được thiết lập để cấp phát địa chỉ cho các Server, Printer,…..)
- `Scope Options`: Các thông số được cấu hình thêm khi cấp phát IP động cho Clients như DNS Server(006), Router(003)
- `DHCP Relay Agent`: Là một máy tính hoặc một Router được cấu hình để lắng nghe và chuyển tiếp các gói tin giữa DHCP Client và DHCP Server từ subnet này sang subnet khác

### 2. Address Resolution Protocol (ARP)

#### 2.1 Các khái niệm cơ bản

- Giao thức phân giải địa chỉ ARP là một giao thức dùng để kết nối giao thức Internet Protocol luôn thay đổi với một địa chỉ máy chủ vật lý cố định. Máy chủ cố định này còn được gọi là địa chỉ Media Acess Control (MAC) trong mạng Local Area Network (LAN)
- Giao thức ARP này, từ địa chỉ IP có thể tìm ra địa chỉ MAC của máy

- Có 4 loại địa chỉ nằm trong một bản tin ARP đó là:

  - Sender Hardware Address: Đây là địa chỉ lớp hai của thiết bị gửi bản tin

  - Sender Protocol Address: Đây là địa chỉ lớp ba (hay còn gọi là địa chỉ logic) của thiết bị gửi bản tin

  - Target Hardware Address: Địa chỉ lớp hai (hay còn được gọi là địa chỉ phần cứng) của thiết bị đích của bản tin

  - Target Protocol Address: Địa chỉ lớp ba (hay gọi là địa chỉ logic) của thiết bị đích của bản tin

[Tài liệu tham khảo ARP 1](https://wiki.tino.org/arp-la-gi/)

[Tài liệu tham khảo ARP 2](https://vsudo.net/blog/arp-la-gi.html)
[Tài liệu tham khảo ARP 3](https://httl.com.vn/wiki/giao-thuc-arp-la-gi/)

[Cách thức hoạt động của ARP](https://www.totolink.vn/article/632-arp-la-gi-muc-dich-va-cach-thuc-hoat-dong-cua-arp.html)

#### 2.2 Cách thức hoạt động của ARP

- **Bước 1**: `Source Device Checks Cache`: Trong bước này, thiết bị sẽ thực hiện kiểm tra cache (bộ đệm) của mình. Nếu đã có địa chỉ IP đích tương ứng với MAC nào đó rồi thì lập tức hệ thống chuyển sang bước 9.
- **Bước 2**: `Source Device Generates ARP Request Message`: Hệ thống bắt đầu khởi tạo gói tin ARP Request với các trường địa chỉ như trên

- **Bước 3**: `Source Device Broadcasts ARP Request Message`: Thiết bị nguồn truyền gói tin ARP Request trên toàn mạng
- **Bước 4**: `Local Devices Process ARP Request Message`: Các thiết bị trong mạng đều sẽ nhận được gói tin ARP Request. Gói tin được xử lý bằng cách đưa thiết bị vào trường địa chỉ Target Protocol Address. Nếu trùng với địa chỉ của mình thì tiếp tục xử lý, nếu không thì hủy gói tin
- **Bước 5**: `Destination Device Generates ARP Reply Message`: Nếu thiết bị với IP trùng với IP trong trường Target Protocol Address sẽ thực hiện quá trình khởi tạo gói tin ARP Reply. Đồng thời thiết bị sẽ lấy địa chỉ datalink của mình để tiến hành đưa vào trường Sender Hardware Address
- **Bước 6**: `Destination Device Updates ARP Cache`: Thiết bị đích cập nhật bảng ánh xạ địa chỉ IP và MAC của thiết bị nguồn vào bảng ARP cache của mình để giảm bớt thời gian xử lý cho những lần sau.

  - Để kiểm tra, các bạn có thể dùng:
    ```sh
    $ arp -a
    ```

- **Bước 7**: `Destination Device Sends ARP Reply Message`: Thiết bị đích sẽ bắt đầu gửi gói tin Reply đã được khởi tạo đến thiết bị nguồn.

- **Bước 8**: `Source Device Processes ARP Reply Message`: Thiết bị nguồn nhận được gói tin reply và tiến hành xử lý bằng cách lưu trường Sender Hardware Address trong gói reply như những địa chỉ phần cứng của thiết bị đích
- **Bước 9**: `Source Device Updates ARP Cache`: Thiết bị nguồn update vào ARP cache giá trị tương ứng giữa địa chỉ network và cả địa chỉ datalink của thiết bị đích. Do đó, những lần tiếp theo sẽ không còn cần tới request.
