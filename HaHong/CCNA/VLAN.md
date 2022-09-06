<<<<<<< HEAD
### Với mạng LAN thông thường, các máy tính trong cùng một địa điểm có thể được kết nối với nhau thành một mạng LAN, chỉ sử dụng một thiết bị tập trung như hub hoặc switch. Có nhiều mạng LAN khác nhau cần rất nhiều bộ hub, switch. Tuy nhiên thực tế số lượng máy tính trong một LAN thường không nhiều. Mạng được kết nối cùng một switch thường có một broadcast domain
# VLAN ( Virtual LAN) 
- là 1 cách để chia switch thành nhiều mạng LAN khác. Việc tạo lập nhiều mạng VLAN trong cùng một mạng LAN sẽ chia switch thành những broadcast domains nhỏ hơn nó sẽ tương với mạng con (subnet)(* Thông thường thì router sẽ đóng vai trò tạo broadcast domain.*) thuận lợi cho việc quản lý một mạng cục bộ rộng và tránh tốn tài nguyên số lượng hub, switch và lãng phí số lượng port Ethernet.
![](VLAN.jpg)
## Có ba loại VLAN, bao gồm:

* VLAN dựa trên cổng (port based VLAN): Mỗi cổng (Ethernet hoặc Fast Ethernet) được gắn với một VLAN xác định. Do đó mỗi máy tính/thiết bị host kết nối với một cổng của switch đều thuộc một VLAN nào đó. Đây là cách cấu hình VLAN đơn giản và phổ biến nhất.
* VLAN dựa trên địa chỉ vật lý MAC (MAC address based VLAN): Mỗi địa chỉ MAC được gán tới một VLAN nhất định. Cách cấu hình này rất phức tạp và khó khăn trong việc quản lý.
* VLAN dựa trên giao thức (protocol based VLAN): tương tự với VLAN dựa trên địa chỉ MAC nhưng sử dụng địa chỉ IP thay cho địa chỉ MAC. Cách cấu hình này không được thông dụng.
## Dãy giá trị VLAN-ID chạy từ 0-4095:
Chạy từ 0 tới 4095:  riêng VLAN 0 và 4095 là không dùng
   * 1 – 1001 : dải VLAN thường được sử dụng.
   * 1002 – 1005 : dùng để giao tiếp với mạng kiểu cũ Tokenring( truyền theo một chiều nhất định)
   * 1006 – 4094: dải VLAN mở rộng, sử dụng khi switch hoạt động ở mode Transparent.

        ![Transparent Mode](https://www.anphat.vn/images/anphat/HD_Cau_hinh_tinh_nang/DrayTek/Q_Cac_bai_viet_cu_hon/Transparent_mode/Transparent_mode1.gif)
   * Các VLAN mặc định sau không được sửa xóa: VLAN 1 là default, 1002 tới 1005. Ban đầu tất cả các cổng của Switch cisco mặc định là VLAN 1
   


## Các chế độ VLAN
- Trunking mode (chế độ trung kế): là một kết nối vật lý và logic để hỗ trợ các VLAN trên các Switch liên kết với nhau.
 ![](https://vnpro.vn/wp-content/uploads/2015/08/trunk.jpg)
 
 ~ Dùng mỗi kết nối cho một VLAN or kết nối đường trunk ~
 
   - Cổng trung kế cho phép frame của nhiều VLAN có thể truyền trên đó. Một cổng trung kế không được gán cho một VLAN riêng biệt.
   - Cổng trung kế thường được dùng để kết nối giữa các Switch hoặc giữa Switch và Router. Chính vì vậy cổng trung kế thường là cổng có băng thông lớn.
  - Các VLAN được ghép kênh qua cổng trung kế. Để ghép kênh lưu lượng của các VLAN, một giao thức đặc biệt sẽ được sử dụng để đóng gói frame để thiết bị có thể xác định được nó thuộc VLAN nào. Chuẩn frame được sử dụng đó là 802.1Q hoặc ISL.
  - Nhờ cổng trung kế mà một VLAN có thể được mở rộng ra toàn mạng.
  - Chỉ cần một đường vật lý cho cả hai VLAN giữa hai Switch.
- Access mode (chế độ truy nhập):Giao diện này thuộc về một và chỉ một VLAN. Thông thường một cổng của switch gắn tới một thiết bị của người dùng đầu cuối hoặc một server.
   *  Trong chế độ cổng truy nhập, cổng chỉ thuộc một VLAN. Tất cả các máy tính cắm vào cổng mày đều thuộc VLAN đó.

   - Frame được gửi trên cổng truy nhập sẽ tuân theo chuẩn định dạng khung ethernet (802.3).

   - Cổng truy nhập thường dùng khi cổng được kết nối đến máy trạm.
## Lí do sử dụng VLAN
* Bảo mật - khi chúng ta sử dụng VLAN, chúng ta có thể sử dụng một thiết bị vật lý cho những người dùng có quyền truy cập khác nhau, lưu lượng trong một nhóm nhạy cảm có thể sử dụng cùng một switch với một nhóm có lưu lượng chung mà không vi phạm chính sách bảo mật.
* Giảm chi phí - bằng cách sử dụng VLAN, sẽ giảm chi phí cần thiết nếu mỗi bộ phận trong tổ chức cần một bộ chuyển mạch vật lý. 
* Cải thiện hiệu suất - như chúng tôi đã đề cập trước đó, hoạt động mặc định của công tắc nằm trong một miền quảng bá. Điều này có nghĩa là nếu một khung được định hướng đến một nút không có trong bảng địa chỉ mac, thì bộ chuyển mạch phải truyền nó đến tất cả các cổng. Điều này có thể làm giảm hiệu suất của mạng. 

## So sánh mạng VLAN và mạng LAN
- Mạng LAN
![](https://s8182.pcdn.co/wp-content/uploads/2014/07/070214_1809_VLANsPartI2.jpg)
Khi muốn chuyển dữ liệu từ PC1 sang PC6 như thì frame sẽ được phát tới tất cả người dùng được kết nối với switch A và switch B. 
- Mạng VLAN
![](https://s8182.pcdn.co/wp-content/uploads/2014/07/070214_1809_VLANsPartI3.jpg)
Kết nối giữa hai thiết bị chuyển mạch là một liên kết trung kế nghĩa là lưu lượng từ nhiều VLAN có thể đi qua nó. Trong trường hợp trên, lưu lượng truy cập trên bất kỳ VLAN nào chỉ bị giới hạn trong VLAN đó. Có nghĩa là PC 1 và PC 2 không thể giao tiếp và PC 2 và PC 6 không thể giao tiếp vì chúng nằm trên các VLAN khác nhau, tuy nhiên, PC 2 và PC 5 có thể giao tiếp vì chúng ở trên cùng một VLAN.
# Ứng dụng
- Sử dụng VLAN để tạo các mạng LAN khác nhau của nhiều máy tính cùng văn phòng:
- Sử dụng VLAN để tạo mạng dữ liệu ảo (Virtual Data Network - VAN)
=======
### Với mạng LAN thông thường, các máy tính trong cùng một địa điểm có thể được kết nối với nhau thành một mạng LAN, chỉ sử dụng một thiết bị tập trung như hub hoặc switch. Có nhiều mạng LAN khác nhau cần rất nhiều bộ hub, switch. Tuy nhiên thực tế số lượng máy tính trong một LAN thường không nhiều. Mạng được kết nối cùng một switch thường có một broadcast domain
# VLAN ( Virtual LAN) 
- là 1 cách để chia switch thành nhiều mạng LAN khác. Việc tạo lập nhiều mạng VLAN trong cùng một mạng LAN sẽ chia switch thành những broadcast domains nhỏ hơn nó sẽ tương với mạng con (subnet)(* Thông thường thì router sẽ đóng vai trò tạo broadcast domain.*) thuận lợi cho việc quản lý một mạng cục bộ rộng và tránh tốn tài nguyên số lượng hub, switch và lãng phí số lượng port Ethernet.
![](VLAN.jpg)
## Có ba loại VLAN, bao gồm:

* VLAN dựa trên cổng (port based VLAN): Mỗi cổng (Ethernet hoặc Fast Ethernet) được gắn với một VLAN xác định. Do đó mỗi máy tính/thiết bị host kết nối với một cổng của switch đều thuộc một VLAN nào đó. Đây là cách cấu hình VLAN đơn giản và phổ biến nhất.
* VLAN dựa trên địa chỉ vật lý MAC (MAC address based VLAN): Mỗi địa chỉ MAC được gán tới một VLAN nhất định. Cách cấu hình này rất phức tạp và khó khăn trong việc quản lý.
* VLAN dựa trên giao thức (protocol based VLAN): tương tự với VLAN dựa trên địa chỉ MAC nhưng sử dụng địa chỉ IP thay cho địa chỉ MAC. Cách cấu hình này không được thông dụng.
## Dãy giá trị VLAN-ID chạy từ 0-4095:
Chạy từ 0 tới 4095:  riêng VLAN 0 và 4095 là không dùng
   * 1 – 1001 : dải VLAN thường được sử dụng.
   * 1002 – 1005 : dùng để giao tiếp với mạng kiểu cũ Tokenring( truyền theo một chiều nhất định)
   * 1006 – 4094: dải VLAN mở rộng, sử dụng khi switch hoạt động ở mode Transparent.

        ![Transparent Mode](https://www.anphat.vn/images/anphat/HD_Cau_hinh_tinh_nang/DrayTek/Q_Cac_bai_viet_cu_hon/Transparent_mode/Transparent_mode1.gif)
   * Các VLAN mặc định sau không được sửa xóa: VLAN 1 là default, 1002 tới 1005. Ban đầu tất cả các cổng của Switch cisco mặc định là VLAN 1
   


## Các chế độ VLAN
- Trunking mode (chế độ trung kế): là một kết nối vật lý và logic để hỗ trợ các VLAN trên các Switch liên kết với nhau.
 ![](https://vnpro.vn/wp-content/uploads/2015/08/trunk.jpg)
 
 ~ Dùng mỗi kết nối cho một VLAN or kết nối đường trunk ~
 
   - Cổng trung kế cho phép frame của nhiều VLAN có thể truyền trên đó. Một cổng trung kế không được gán cho một VLAN riêng biệt.
   - Cổng trung kế thường được dùng để kết nối giữa các Switch hoặc giữa Switch và Router. Chính vì vậy cổng trung kế thường là cổng có băng thông lớn.
  - Các VLAN được ghép kênh qua cổng trung kế. Để ghép kênh lưu lượng của các VLAN, một giao thức đặc biệt sẽ được sử dụng để đóng gói frame để thiết bị có thể xác định được nó thuộc VLAN nào. Chuẩn frame được sử dụng đó là 802.1Q hoặc ISL.
  - Nhờ cổng trung kế mà một VLAN có thể được mở rộng ra toàn mạng.
  - Chỉ cần một đường vật lý cho cả hai VLAN giữa hai Switch.
- Access mode (chế độ truy nhập):Giao diện này thuộc về một và chỉ một VLAN. Thông thường một cổng của switch gắn tới một thiết bị của người dùng đầu cuối hoặc một server.
   *  Trong chế độ cổng truy nhập, cổng chỉ thuộc một VLAN. Tất cả các máy tính cắm vào cổng mày đều thuộc VLAN đó.

   - Frame được gửi trên cổng truy nhập sẽ tuân theo chuẩn định dạng khung ethernet (802.3).

   - Cổng truy nhập thường dùng khi cổng được kết nối đến máy trạm.
## Lí do sử dụng VLAN
* Bảo mật - khi chúng ta sử dụng VLAN, chúng ta có thể sử dụng một thiết bị vật lý cho những người dùng có quyền truy cập khác nhau, lưu lượng trong một nhóm nhạy cảm có thể sử dụng cùng một switch với một nhóm có lưu lượng chung mà không vi phạm chính sách bảo mật.
* Giảm chi phí - bằng cách sử dụng VLAN, sẽ giảm chi phí cần thiết nếu mỗi bộ phận trong tổ chức cần một bộ chuyển mạch vật lý. 
* Cải thiện hiệu suất - như chúng tôi đã đề cập trước đó, hoạt động mặc định của công tắc nằm trong một miền quảng bá. Điều này có nghĩa là nếu một khung được định hướng đến một nút không có trong bảng địa chỉ mac, thì bộ chuyển mạch phải truyền nó đến tất cả các cổng. Điều này có thể làm giảm hiệu suất của mạng. 

## So sánh mạng VLAN và mạng LAN
- Mạng LAN
![](https://s8182.pcdn.co/wp-content/uploads/2014/07/070214_1809_VLANsPartI2.jpg)
Khi muốn chuyển dữ liệu từ PC1 sang PC6 như thì frame sẽ được phát tới tất cả người dùng được kết nối với switch A và switch B. 
- Mạng VLAN
![](https://s8182.pcdn.co/wp-content/uploads/2014/07/070214_1809_VLANsPartI3.jpg)
Kết nối giữa hai thiết bị chuyển mạch là một liên kết trung kế nghĩa là lưu lượng từ nhiều VLAN có thể đi qua nó. Trong trường hợp trên, lưu lượng truy cập trên bất kỳ VLAN nào chỉ bị giới hạn trong VLAN đó. Có nghĩa là PC 1 và PC 2 không thể giao tiếp và PC 2 và PC 6 không thể giao tiếp vì chúng nằm trên các VLAN khác nhau, tuy nhiên, PC 2 và PC 5 có thể giao tiếp vì chúng ở trên cùng một VLAN.
# Ứng dụng
- Sử dụng VLAN để tạo các mạng LAN khác nhau của nhiều máy tính cùng văn phòng:
- Sử dụng VLAN để tạo mạng dữ liệu ảo (Virtual Data Network - VAN)
>>>>>>> e78ff55194d3607bda30252a41a118886c45a1fa
- Hữu ích cho những nhóm người dùng cần tính bảo mật cao, hoặc không thích mạng bị chậm do số lượng broadcast lớn