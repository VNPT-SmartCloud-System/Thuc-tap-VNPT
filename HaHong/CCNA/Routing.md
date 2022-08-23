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

# Các giao thức định tuyến 
- Các giao thức định tuyến cũng có thể được phân loại thành Giao thức cổng bên trong (IGP) hoặc Giao thức cổng bên ngoài (EGP). IGP là các giao thức định tuyến trao đổi thông tin định tuyến với các bộ định tuyến khác trong một hệ thống tự trị duy nhất (AS). Một AS được định nghĩa là một mạng hoặc một tập hợp các mạng dưới sự kiểm soát của một doanh nghiệp. 
- Hoặc cũng có thể được phân loại vectơ khoảng cách (distance vector) và giao thức định tuyến trạng thái liên kết (link-state)
   - Vecto routing protocol: các router trao đổi các thông tin về địa chỉ của các router khác mà chúng có thể gửi data tới được với các router kết nối trực tiếp với nó.
   - Link-state routing protocol: các router trao đổi với nhau về thông tin của topo mạng. Thông tin topo mạng này sẽ được dùng để tính toán đường dẫn tốt nhất qua AS từ điểm nguồn đến điểm đích.
## Mỗi thứ sau đây được phân loại là IGP:
### Giao thức định tuyến thông tin RIP(Routing information protocol)
- Giao thức định tuyến bên trong mạng tự trị
- SỬ dụng thuật toán tìm đường distance-vector, mỗi rouer sẽ thường xuyên cập nhật bảng định tuyến của nó sang hàng xóm theo định kì 30s/lần, thông tin này lại tiếp tục được hàng xóm lan truyền tiếp đến các láng giềng khác và cứ thế lan truyền ra mọi router toàn mạng ; khi có bảng định tuyến nó sẽ cập nhật đường đi tốt hơn dựa vào thuật toán Bellman-Ford 
- Chọn đường đi theo metric cố định : số nút mạng đi qua( hop count), giới hạn metric tối đa là 15, giá trị 16 được gọi là infiniy metric
- RIP sử dụng UDP để chuyển các gói tin
- Có thể bị loop trên mạng khi gặp sự cố down mạng

VD: ![](https://itforvn.com/wp-content/uploads/2018/03/H2.-B%E1%BA%A3ng-%C4%91%E1%BB%8Bnh-tuy%E1%BA%BFn-c%E1%BB%A7a-c%C3%A1c-Router.jpg)
- Giả sử R1 sẽ gửi cho R2 thông tin bằng định tuyến của mình, khi đó R2 sẽ cập nhật thông tin dải địa chỉ mạng mà nó chưa có trong bảng định tuyến khi đó metric sẽ tăng lên 1. 
- Sau đó R2 sẽ gửi cho R3 thông tin bảng định tuyến mà R2 đã cập nhật, sau đó R3 sẽ cập nhật thông tin những dải địa chỉ mà nó chưa có trong bảng định tuyến và cập nhật metric.
=> Các subnet của R1 đã được học trên toàn mạng
- Tuy nhiên như trên hình dải mạng 172.16.1.0/24 bị down thì R1 sẽ loại bỏ mạng này ra khỏi bảng định tuyến sau 30s thì R2 lại gửi bảng định tuyến có chứa dải mạng đã bị down cho R1, R1 sẽ cập nhật lại dải mạng và metric, R2 thấy metric R1 tăng nó cũng sẽ cập nhật lại metric và cứ thế metric tăng. Khi một gói tin được gửi đến dải mạng đã bị down nó sẽ bị đẩy qua lại giữa các con router tạo thành vòng lặp.
#### Các bộ quy tắc chống loop của RIP
- Luật Split Horizon
   - Khi router nhận được cập nhật định tuyến của một mạng từ phía cổng nào thì nó sẽ không gửi ngược lại cập nhật cho mạng ấy về phía cổng mà nó nhận được nữa.
- Cơ chế Route Poisoning
  - Khi một subnet đấu nối trực tiếp down. Router sẻ gửi đi một update packet có metric = 16 cho subnet này cho các neighbor của nó. Neighbor khi nhận được bản tin này thì bíêt rằng subnet này không còn nữa. Và nó sẻ tiếp tục gửi gói tin infinity metric cho neighbor tiếp theo theo cơ chế truyền tin đồn để cho các neighbor trong topology bíêt được rằng subnet này không còn nữa. Cơ chế gửi gói update packet này được gửi ngay lập tức sau khi một subnet down không cần gửi theo định kì 30s/lần.
- Cơ chế Poison-reverse
 - Cơ chế này thực hiện một khi neighbor nhận được bản tin update có metric = 16 thì nó sẻ ngay lập tức trả về một gói tin respond cho subnet đó với metric = 16
- Trigger Update
 - Là hoạt động phát ra bản tin Route-poisoning và poison-reserve được thực hiện ngay lập tức sau khi có một subnet down được gọi là Trigger Update. Và Trigger Update chỉ được gửi khi mạng có sự thay đổi như subnet down. Và các gói tin update thường xuyên vẫn được gửi theo định kỳ bình thường.
#### Các loại timer trong RIP
- Holddown-timer 
  - Thời gian downtime cho mỗi route có định kì là 180s bắt đầu sau khi subnet đó mất đi. Router sẻ tiến hành quảng bá với láng giềng là route này không đến được nữa. Trong thời gian Holdtime này thì Router sẻ không nhận bất kì thông tin định tuyến nào từ subnet này trừ khi được neighbor cập nhật subnet này cho nó đầu tiên. Không chỉnh sửa bảng định tuyến cho đến khi hết thời gian timer này.
- Update timer
   -Khoảng thời gian định kì mà Router chạy RIP gửi bản tin cập nhật định tuyến đến neighbor của nó trong topology. Timer mặc định là 30s.
- Invalid timer
  - Khi Router nhận được bản tin cập nhật update về một subnet nào đó, sau khoảng thời gian invalid timer mà vẫn không nhận được bản cập nhật kế tiếp (theo định kì 30s/lần). Router sẽ xem route này invalid nhưng chưa vội xóa route này ra khỏi bản định tuyến mà sẻ tiến hành đưa route này vào Holddown timer. Giá trị mặc định của invalid timer là 180s
- Flush timer
  - Khi Router nhận được bản tin cập nhật update về một subnet nào đó. Sau khoảng thời gian flush timer mà vẫn không nhận được bản cập nhật kế tiếp về subnet này nó sẻ xóa hoàn toàn route này ra khỏi routing table. Giá trị mặc định của flush timer là 240s

### Mở đường dẫn ngắn nhất đầu tiên (OSPF) (theo liên kết trạng thái đòi hỏi các nút mạng phải có đầy đủ thông tin về các topo mạng)(open shortest path first)
- Đặc điểm: 
  - Là một giao thức link-state điển hình, mỗi router khi chạy giao thức sẽ gửi các trạng thái đường link của nó cho tất cả các router trong vùng. Sau một thời gian trao đôit, các router sẽ đồng nhất được bảng cơ sở dữ liệu trạng thái đường link với nhau.
  - Chạy thuật toán Dijkstra tính toán ra cây đường đi ngắn nhất và dựa vào cây này để xây dựng nên bảng định tuyến
  - Metric của OSPF còn gọi là cost, được tính theo bandwidth trên cổng chạy OSPF
  - OSPF chạy trực tiếp trên nền IP
#### Các bước hoạt động:
##### Bước 1: Chọn Router ID: Để giao thức OSPF có thể hoạt động được thì người dùng phải tạo ra một định danh gọi là Router ID.
  - Cách 1: Router tự tạo định danh: Router xem xét các interface để tự động lấy Router có IP cao nhất làm Router ID.
  - Cách 2: Người dùng tự cấu hình định danh: Router sẽ không cần định danh Router ID bằng cách chọn IP có sẵn trên interface mà chỉ cần tự tạo ra nó.
 Cấu hình:
   - Router(config)#router ospf 1
   - Router(config-router)#router-id A.B.C.D
   - Câu lệnh khởi động lại OSPF:
   - Router#clear ip ospf process
##### Bước 2: Thiết lập mối quan hệ láng giềng: Hai router được xem là láng giềng nếu chúng đáp ứng được các điều kiện sau:
- Cùng Area - ID: 
 - Một hệ thống mạng lớn sẽ được chia thành nhiều khu vực để giảm thiểu tối đa những ảnh hưởng khi xuất hiện sự cố, mỗi vùng là một Area-ID. 
 - Vùng trung tâm sẽ có Area-Id bằng 0 còn những vùng khác muốn truyền được dữ liệu phải có đường truyền trực tiếp về cùng trung tâm. 
 - Khi thực hiện cấu hinhfphaan vùng cho router, ta thực hiện gán link trên router vào một vùng. 
 - Những router thuộc 2 phân vùng phải ghi nhớ trạng thái đường link của 2 vùng=> được gọi là router biên giới giữa 2 vùng.
 - Khi 2 router có chung link thì sẽ tự thống nhất với nhau về Are-id của link này.
 ![](https://vnpro.vn/upload/images/Th%C6%B0%20vi%E1%BB%87n/c10-5.PNG)
- Cùng Subnet: Hai IP phải có cùng Subnet thì mới có thể ping và thực hiện trao đổi thông tin lẫn nhau.
- Cùng thông số: Mặc định dead time hoặc hello trên hai cổng là 10s/40s.(hello timer là khoảng thời gian định kỳ gửi gói tin hello đến router hàng xóm, nếu sau thời gian dead timer không nhận được gói tin hello nó sẽ coi hàng xóm này không tồn tại nữa)
- Cùng xác thực trên hai cổng: Đây là điều kiện dành cho mạng lớn bởi khi đặt xác thực thì các router khác sẽ không lấy được thông tin.( thiết lập password treenn hai router hai đầu đường link phải có password giống nhau để có thể thiết lập neighbor)
##### Bước 3: Trao đổi LSDB: Với vai trò như tấm bản đồ, LSDB chính là căn cứ để Router tính toán định tuyến. Mỗi Router sẽ tiến hành giao tiếp và trao đổi với nhau theo từng đơn vị thông tin LSA( Link State Advertisement)
##### Bước 4: Tính toán trong giao thức OSPF bảng định tuyến.
- Tính toán metric đối với OSPF:
   - Ta sẽ sử dụng giá trị danh định định tuyến 
   - Metric= cost = 10^8/Bandwidth
  - R(config-if)#bandwidth BW
  - Ta phải chỉnh giá trị định danh này trùng với giá trị thật
 - Metric của nguồn đến đích sẽ bằng tổng cost trên mỗi link liên kết, nếu 2 cổng router có cost khác nhau sẽ thực hiện tính tổng cost, ta thực hiện lần lượt ngược từ đích lần về và cộng dồn theo quy tắc vào cộng, ra không cộng.
- Cấu hình OSPF:
  - R(config)#router ospf process-id
  - R(config-router)#network subnet wildcard-mask are-id

### Hệ thống trung gian đến hệ thống trung gian (IS-IS) ### Giao thức định tuyến cổng nội bộ nâng cao (EIGRP)
- EIGRP(Enhanced Interior Gateway Routing Protocol) là một giao giao thức định tuyến do Cisco phát triển, chỉ chạy trên các sản phẩm của Cisco. Đây là điểm khác biệt của EIGRP so với các giao thức đã được đề cập ở trên. Các giao thức RIP và OSPF là các giao thức chuẩn, có thể chạy trên các router của nhiều hãng khác nhau.
-EIGRP là một giao thức dạng Distance- vector được cải thiện,nó không sử dụng thuật toán Bell man-Ford mà sử dụng thuật toán riêng DUAL, và kế thừa một số cấu trúc của OSPF như: xây dựng quan hệ láng giềng, bảng topology và bảng định tuyến
- EIGRP sử dụng một số công thức tính metric rất phức tạp dựa trên 
## Các giao thức EGP bao gồm:
### Giao thức cổng biên (BGP)
### Giao thức cổng ngoài (EGP)
### Giao thức định tuyến liên miền ISO (IDRP)



[Định tuyến](https://vnnet.edu.vn/951-2/)

[RIP](https://itforvn.com/bai-12-giao-thuc-dinh-tuyen-rip.html/)
[OSPF](https://itforvn.com/bai-12-giao-thuc-dinh-tuyen-rip.html/)
[EIGRP](https://vnnet.edu.vn/giao-thuc-dinh-tuyen-eigrp-enhanced-interior-gateway-routing-protocol/)