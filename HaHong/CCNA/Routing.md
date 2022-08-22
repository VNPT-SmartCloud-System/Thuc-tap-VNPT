### Đặt vấn đề 
- Trong mạng gia đình hoặc mạng doanh nghiệp, các thiết bị có cùng dải địa chỉ mạng được kết nôi với nhau bằng thiết bị trung gian như Switch, Hub. Chúng cung cấp kết nối giữa các máy trạm trên mạng cục bộ. Các máy trạm cục bộ có thể kết nối với nhau và chia sẻ thông tin mà không cần thêm bất kỳ thiết bị nào. Nếu một máy chủ đang gửi một gói đến một thiết bị được cấu hình với cùng một dải mạng IP với nó, thì gói đó chỉ được chuyển tiếp ra khỏi giao diện máy chủ, thông qua thiết bị trung gian và trực tiếp đến thiết bị đích.
- Tuy nhiên, chúng ta muốn thiết bị của mình có thể kết nối ngoài phân đoạn mạng cục bộ, các thiết bị nằm ngoài phân đoạn mạng cục bộ được gọi là máy chủ từ xa. Khi một thiết bị nguồn gửi một gói tin đến một thiết bị đích từ xa, khi đó cần sự trợ giúp của các bộ định tuyến và định tuyến. 
## Định tuyến là quá trình xác định con đường tốt nhất để đến đích. Bộ định tuyến được kết nối với phân đoạn mạng cục bộ được gọi là defaul gateway.
#### Defaul gateway
- Nó có địa chỉ IP cục bộ trong cùng dải địa chỉ với các máy khác trên mạng cục bộ.
- Nó có thể chấp nhận dữ liệu vào mạng cục bộ và chuyển tiếp dữ liệu ra khỏi mạng cục bộ.
- Nó định tuyến lưu lượng đến các mạng khác.

=> Cần có cổng mặc định để gửi lưu lượng ra bên ngoài mạng cục bộ. Router dựa vào địa chỉ IP đích (destination IP) trong các gói tin và sử dụng bảng định tuyến (routing table) để xác định đường đi cho chúng.
### Bảng định tuyến
- Danh sách các đường đi có thể từ nguồn đến đích
- Địa chỉ đích/mặt nạ mạng, Router kế tiếp (interface, metris)
- Cho phép với một địa chỉ mạng đích thì phải gửi gói tin ra giao diện mạng nào của router
- Bảng định tuyến được tạo ra do các router trao đổi bản tin định tuyến thông qua các giao thức định tuyến(routing protocols)
- Nguyên lý định tuyến của router: “longest prefix match”
## Định tuyến
![](https://anninhmang.net/wp-content/uploads/2014/09/static5.jpg)
- Mặc định ban đầu, ta chưa cấu hình định tuyến cho R0 và R1 thì hai mạng LAN của R0 và R1 chưa thể đi đến nhau được( PC trong mạng LAN 1 sẽ không ing được đến một PC trong mạng LAN2). Do các router R1 và R2 chưa có thông tin về các mạng LAN của nhau trong bảng định tuyến do đó không thể chuyển gói tin đi đến các mạng LAN này. 
- Sử dụng lệnh # show ip route để xem bảng định tuyến. Các rouet hoàn toàn không có thông tin về các subnet ở xa. Để 2 mạng 192.168.1.0/24 và 172.16.1.0/24 có thể đi được với nhau, các router phải điền được thông tin về 2 mạng này vào trong bảng định tuyến của mình. Có 2 cách:
   - Định tuyến tĩnh: người quản trị tự điền tay các thông tin
   - Định tuyến động: hai router tự trao đổi thông tin định tuyến với nhau và tự điền các thông tin còn thiếu vào bảng định tuyến của mình 
## Định tuyến tĩnh 
Cú pháp định tuyến tĩnh:
Router(config)#ip route destination_subnet subnetmask {IP_next_hop|output_interface}
- Trong đó: 
   - destination_subnet : mạng đích đến
   - subnetmask : mặt nạ mạng đích
   - IP_next_hop : đại chỉ IP của trạm kết tiếp trên đường đi
   - output_interface : cổng ra trên router
- Ở ví dụ trên R0 muốn đi đến mạng 172.1.1.0, ta phải đi ra khỏi cổng Fa0/0, ta sẽ thực hiện cấu hình như sau:
  - R0(config)# ip route 172.1.1.0 255.255.255.0 Fa0/0
  - R1(config)# ip route 192.168.1.0 255.255.255.0 Fa0/0
- Sau khi cấu hình xong các route cho các mạng 172.1.1.0 và 192.168.1.0 bảng định tuyến của các router R0 và R1 đã xuất hiện các thông tin mới 
- Cách khác sử dụng địa chỉ IP next-hop
   - R0(config)# ip route 172.1.1.0 255.255.255.0 10.0.0.2
   - R1(config)# ip route 192.168.1.0 255.255.255.0 10.0.0.1
( ở cấu hình 1 AD=0, cấu hình 2 AD=1) với cổng ra là cổng multi-access thì ta nên sử dụng kiểu khai báo IP next-hope.
- Ví dụ 2:
![](https://3.bp.blogspot.com/-KWgHv7p3yyQ/U0TZ1_PzWYI/AAAAAAAAAVg/mGG-ivp_e_s/s1600/lab1.3.PNG)
Câu lệnh static route trên R1 là
 
- R1(config)# ip route 172.17.0.0 255.255.0.0 f0/1
- R1(config)# ip route 196.168.23.0 255.255.255.0 f0/1
- R1(config)# ip route 10.0.0.0 255.0.0.0 f0/1
tương tự với R2 và R3
Cần phải điền đầy đủ thông tin định tuyến trên tất cả accs router vì chỉ cần 1 router nào đó trên đường đi của gói tin bị thiếu gói tin sẽ bị drop giữa đường
Sử dụng AD để so sánh dộ ưu tiên giữa các route, khi tồn tại nhiều đường đi đến đích, AD nhỏ sẽ là đường chính thức, AD lớn hơn sẽ là đường dự phòng.

VD:
- R1(config)# ip route 172.17.0.0 255.255.0.0 f0/1 5
- R1(config)# ip route 172.17.0.0 255.255.0.0 f0/2 10 
đường qua cổng f0/2 sẽ là đường phụ


[Nguồn tham khảo](https://vnnet.edu.vn/951-2/)