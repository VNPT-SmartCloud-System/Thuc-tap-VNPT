# TÌM HIỂU VỀ LINUX  PHÂN BIỆT CÁC LOẠI DISTRO DISTRO VA GIAY PHEP MA NGUON MO
# Mục lục

[1. Lịch sử phát triển của Linux.](#1)

[2. Ưu nhược điểm của hệ điều hành linux](#2)

- [2.1. Ưu điểm](#2.1)

- [2.2. Nhược điểm](#2.2)

[3. Bản phân phối Linux](#3)
- [3.1. Giới thiệu](#3.1)
- [3.2.  Loại hình và xu hướng phát triền](#3.2)
- [3.3. Các nhánh distro phổ biến ](#3.3)
  - [3.3.1. Debian ](#3.3.1)
  - [3.3.2. RED HAD ](#3.3.2)

[4. Giấy phép mã nguồn mở](#4)
 - [4.1. Giới thiệu chung về giấy phép mã nguồn mở](#4.1)
 - [4.2. Phân loại](#4.2)
 - [4.3. MỘt số giấy phép mã nguồn mở phổ biến hiện nay](#4.3)
    - [4.3.1. Giấy phép GNU](#4.3.1)
    - [4.3.2. Giấy phép BSD](#4.3.2)
    - [ 4.3.3 Giấy phép MIT](#4.3.3)
    - [4.3.4 Giấy phép Apache](#4.3.4)



[5. Tài liệu tham khảo](#5)

---


# Hệ điều hành Linux
Linux là một hệ  điều hành  mã nguồn mở và miễn  phí.  Bất  cứ ai  cũng  có  thể sao  chép, tuyên  truyền,  phân  tán,  viết  lại  và  phát  triển  hệ  điều  hành  này. Cộng  với  khả năng  liên  kết mạng rộng khắp và toàn cầu như hiện nay, bất cứ ai cũng có thể tiếp cận, nghiên cứu, tìm hiểu hệ điều hành Linux
<a name="1"></a>

## 1. Lịch sử phát triển của Linux.
- Linux là một HĐH dạng UNIX (Unix-like Operating System) chạy trên máy PC với bộ điều khiển trung tâm (CPU) Intel 80386 trở lên, hay các bộ vi xử lý trung tâm tương thích AMD, Cyrix. 
- Linux được viết lại toàn bộ từ con số không, tức là không sử dụng một dòng lệnh nào của Unix để tránh vấn đề bản quyền của Unix. Tuy nhiên hoạt động của Linux hoàn toàn dựa trên nguyên tắc của hệ điều hành Unix. 
- Năm 1991 Linus Torvalds, sinh viên của đại học tổng hợp Helsinki, Phần lan, bắt đầu xem xét Minix, một phiên bản của Unix làm ra với mục đích nghiên cứu cách tạo ra một hệ điều hành Unix chạy trên máy PC với bộ vi xử lý Intel 80386.
- Ngày 25/8/1991, Linus cho ra version 0.01 và thông báo trên comp.os.minix của Internet về dự định của mình về Linux.
- Tháng 01/1992, Linus cho ra version 0.12 với shell và C compiler. Linus không cần Minix nữa để recompile HDH của mình. Linus đặt tên HDH của mình là Linux
- Ngày 14/3/1994, sau 3 năm miệt mài, Torvalds cho ra mắt phiên bản hoàn thiện đầu tiên, Linux 1.0 với 176.250 dòng lệnh. Sau 1 năm, phiên bản 1.2 ra mắt với 310.950 dòng lệnh.
- Ngày 3/11/1994, Red Hat Linux phiên bản 1.0 được giới thiệu. Đây là một trong những hệ điều hành được thương mại hóa đầu tiên dựa trên Linux.
- Năm 1996, Linus Torvalds ghé thăm công viên hải dương học. Ông đã quyết định sử dụng hình ảnh chú chim cánh cụt để làm biểu tượng chính thức của Linux.
- Năm 1998, Linux bắt đầu được các tập đoàn công nghệ quan tâm và đầu tư để phát triển. Nổi bật là IBM đã đầu tư hàng tỉ USD để phát triển các dịch vụ và phần mềm trên nền tảng Linux. Ngoài IBM, còn có Compaq và Oracle cũng bắt đầu đầu tư và phát triển hê điều hành Linux.
- Năm 2005, Linus Torvalds được xuất hiện trên trang bìa của tạp chí về kinh tế BusinessWeek, với câu chuyện về sự thành công của hệ điều hành Linux.
- Năm 2007, các hãng sản xuất máy tính như HP, ASUS, Dell, Lenovo,… bắt đầu bán ra các sản phẩm laptop được cài đặt sẵn Linux.
- Tính đến hiện tại, Linux đã có rất nhiều phiên bản khác nhau, được xây dựng và phát triển riêng biệt bởi các công ty phần mềm và các cá nhân. Nổi bật trong số đó chính là hệ điều hành di động Android của Google, hiện là một trong những hệ điều hành thông dụng nhất hiện nay.
- Hiện nay, Linux được sử dụng rộng rãi trên toàn thế giới, trên các máy tính cá nhân, các máy chủ, đến các thiết bị di động, máy nghe nhạc, máy tính bảng, các máy ATM và thậm chí trên cả các siêu máy tính.
<a name="2"></a>

## 2. Ưu nhược điểm của hệ điều hành linux
<a name="2.1"></a>

### 2.1. Ưu điểm
- Kinh tế: không tốn chi phí bản quyền
- Tính bảo mật cao :
  - Trước hết, trong Linux có một cơ cấu phân quyền hết sức rõ ràng. Chỉ có "root"(người dùng tối cao) mới có quyền cài đặt và thay đổi hệ thống. Ngoài ra Linux cũng có cơ chế để một người dùng bình thường có thể tạm thời chuyển sang quyền "root" để thực hiện một số thao tác
  - Ngoài ra chính tính chất "mở" cũng tạo nên sự an toàn của Linux. Nếu như một lỗ hổng nào đó trên Linux được phát hiện thì nó sẽ được cả cộng đồng mã nguồn mở cùng sửa và thường thì chỉ sau 24h sẽ có thể cho ra bản sửa lỗi
- Linh hoạt, uyển chuyển
Linux là một Hệ điều hành mã nguồn mở nên chúng ta có thể tùy ý sửa chữa theo như mình thích (tất nhiên là trong khả năng kiến thức của mỗi người). Chúng ta có thể chỉnh sửa Linux và các ứng dụng trên đó sao cho phù hợp với mình nhất. Mặt khác do Linux được một cộng đồng rất lớn những người làm phần mềm cùng phát triển trên các môi trường, hoàn cảnh khác nhau nên tìm một phiên bản phù hợp với
yêu cầu của mỗi người sẽ không phải là một vấn đề quá khó khăn.
<a name="2.2"></a>

### 2.2. Nhược điểm
- Đòi hỏi người dùng phải thành thạo:Trước kia việc sử dụng và cấu hình Linux được xem là một công việc chỉ dành cho những kĩ thuật viên CNTT. Hầu như mọi công việc đều thực hiện trên các dòng lệnh và phải cấu hình nhờ sửa trực tiếp các file. Nên chưa thể đến được với người dùng cuối.
<a name="3"></a>

## 3. Bản phân phối Linux
<a name="3.1"></a>

### 3.1. Giới thiệu
- Một bản phân phối Linux (thường được gọi tắt là distro) là một hệ điều hành được tạo dựng từ tập hợp nhiều phần mềm dựa trên hạt nhân Linux và thường có một hệ thống quản lý gói tin
- Một bản phân phối Linux điển hình bao gồm một Linux kernel, các công cụ và thư viện GNU, các phần mềm thêm vào, tài liệu, một window system (phần lớn sử dụng X Window System), và window manager, và một môi trường desktop
- Hầu như tất cả các bản phân phối Linux là tương tự Unix; ngoại lệ đáng chú ý nhất là Android, không bao gồm một giao diện dòng lệnh và các chương trình làm cho các bản phân phối Linux điển hình
- Hiện tại, có khoảng 600 bản distro tồn tại, với gần 500 trong số đó phát triển tích cực, liên tục được sửa đổi và cải thiện. Bởi sự sẵn có của số lượng lớn phần mềm, distro khá là đa dạng về hình thức 
<a name="3.2"></a>

### 3.2. Loại hình và xu hướng phát triền
- Thương mại hoặc phi thương mại
- Thiết kế cho người dùng doanh nghiệp, người dùng chuyên nghiệp hay cho người dùng gia đình.
- Hỗ trợ nhiều nền tảng phần cứng, hoặc nền tảng riêng, thậm chí đến mức chứng nhận bởi các nhà cung cấp nền tảng.
- Thiết kế cho máy chủ, máy tính cá nhân, hoặc cho thiết bi nhúng.
- Mục đích chung hoặc có chuyên môn cao về phía các chức năng máy cụ thể (ví dụ: tường lửa, router mạng, và điện toán cụm).
- Nhắm đến nhóm người dùng cụ thể, ví dụ thông qua việc quốc tế và bản địa hóa ngôn ngữ, hoặc thông qua bao gồm nhiều sản phẩm âm nhạc hoặc các gói tính toán khoa học.
- Xây dựng chủ yếu cho an ninh, khả năng sử dụng, tính di động, hoặc toàn diện.
#### Các nhóm phát triển 
- Nhóm 1: Dành cho người am hiểu Linux

  - Gồm có: Arch, Gentoo và Slackware
  - Nhóm này phần lớn các phương thức xây dựng, cũng như cách cấu hình hệ thống đều được thực hiện qua các dòng lệnh.

- Nhóm 2: Dành cho người am hiểu về hệ thống, nhưng chưa thực sự hiểu về Linux

    - Gồm có: Debian, Fedora
    - Nhóm này được cung cấp cho họ nhiều công cụ để tương tác với hệ thống hơn, phù hợp với người bắt đầu sử dụng Linux.
    - Tuy nhiên, nhóm này lại có quy trình phát triển và kiểm tra chất lượng phần mềm khắt khe hơn các nhóm còn lại.

- Nhóm 3: Dành cho thị trường máy chủ, doanh nghiệp, cơ quan
    - Gồm: CentOS, RHEL, SUSE EL
    - Nhóm này có độ ổn định cao, thời gian ra phiên bản mới lâu, khoảng 3-5 năm tùy distro.

- Nhóm 4: Dành cho người bắt đầu sử dụng Linux, hoặc người dùng cuối.
    - Gồm: Ubuntu, Open SUSE, Linux Mint
    - Đặc tính của chúng là phát triển trong thời gian ngắn, ứng dụng các công nghệ mới liên tục, nhóm này có GUI thân thiện với người dùng.
<a name="3.3"></a>

### 3.3. Các nhánh distro phổ biến
- Linux Distribution là các bản phân phối của linux - là một hệ điều hành, chúng đều dựa trên 3 nhánh chính để phát triển, đó là Debian, Red Hat, Slackware.
![](https://hostingviet.vn/data/tinymce/tin%20tuc%202019/distro-linux-la-gi-2.jpg)

<a name="3.3.1"></a>

#### 3.3.1. Debian
Là một bản phân phối phi thương mại và là một trong những bản phân phối ra đời sớm nhất, duy trì bởi một cộng đồng phát triển tình nguyện với một cam kết mạnh mẽ cho nguyên tắc phần mềm miễn phí và quản lý dự án dân chủ.

- Có 3 dạng khác nhau:
  - Phiên bản ổn định mà người dùng được khuyến khích sử dụng.
  - Phiên bản không ổn định.
  - Phiên bản thử nghiệm cho những ai mong muốn có được phần mềm mới nhất.
- Hiện tại có rất nhiều hệ điều hành Linux được xây dựng dựa trên Debian GNU/Linux, trong đó có Ubuntu, Linux Mint, Knoppix, MEPIS, DreamLinux, Damn Small Linux và các hệ điều hành khác.

Đặc điểm : Debian nổi tiếng với hệ thống quản lý gói của nó, mà cụ thể APT (công cụ quản lý gói cao cấp, Advanced Packaging Tool), chính sách nghiêm ngặt đối với chất lượng các gói và bản phát hành, cũng như tiến trình phát triển và kiểm tra mở. Cách thức làm việc này đã giúp cho việc nâng cấp giữa các bản phát hành và việc cài đặt hay gỡ bỏ các gói phần mềm được dễ dàng hơn

*Có khá nhiều distro phát triển dựa trên distro Debian như: Raspbian, Knoppix, Astra Linux, Kali Linux, ... và phổ biến nhất là nhánh Ubuntu*
##### Ubuntu
![](https://hostingviet.vn/data/tinymce/Tin%20tuc%202020/ubuntu-la-gi-1.jpg)
- Do công ty Canonical phân phối chỉ mới xuất hiện vào quý 3/2004 và không lâu sau đó HĐH này đã trở nên phổ biến, uy tín về chất lượng và dễ dàng sử dụng.

- Dựa trên hệ thống quản lý gói mạnh mẽ APT của Debian, nhắm đến đối tượng người dùng đầu cuối, nhỏ gọn chỉ với 1 đĩa cài đặt. Người dùng Ubuntu có thể cảm nhận được sự tự do, tùy biến cao trong sử dụng, quản lý hệ thống.

- Theo thống kê của trang Distrowatch, cho đến hiện nay Ubuntu là distro phổ biến nhất với khoảng hơn 2.000 lượt người truy cập/ngày.

- Cứ 6 tháng, Ubuntu sẽ ra bản phát hành mới, còn với các phiên bản Long Term Support (LTS) thì việc cập nhật trình bảo mật sẽ từ 3 đến 5 năm.

- Cách đặt tên của Ubuntu theo định dạng YY.MM trong đó YY là năm phát hành và MM là tháng phát hành.

- Ubuntu sử dụng giao diện đồ họa thân thiện GNOME, hướng đến sự đơn giản hóa trong quá trình sử dụng. Ngoài ra, Ubuntu còn có bộ ứng dụng văn phòng OpenOffice, trình duyệt Firefox, trình gửi tin nhắn tức thời Pidgin, trình biên tập đồ họa GIMP…

- Ngoài Ubuntu, các nhà phát triển còn sản sinh ra các distro mang hơi hướng tương tự Ubuntu như Kubuntu, Xubuntu và Lunbuntu, Linux Mint. Các distro này chủ yếu khác biệt với Ubuntu ở giao diện màn hình.

<a name="3.3.2"></a>

#### 3.3.2 RED HAT

##### Fedora
Là một bản phân phối cộng đồng được "đỡ đầu" bởi một công ty của Mỹ - Red Hat. Nó được tạo ra nhằm kiểm thử các công nghệ cho một bản phân phối thương mại khác của Red Hat - nơi mà các phần mềm nguồn mở mới được tạo lập, phát triển và kiểm thử trong môi trường cộng đồng trước khi được đưa vào Red Hat Enterprise Linux.

Chu kì ra phiên bản mới của Fedora là 6 tháng. Phiên bản mới với các tính năng bảo mật mà các chuyên gia đánh giá khá tốt.

Có thể nâng cấp lên phiên bản mới mà không cần cài đặt lại.

Dùng yum để quản lý các gói phần mềm định dạng .rpm

Fedora có thể dùng cho máy tính để bàn và máy trạm, thậm chí máy chủ; dành cho những người mới tiếp cận PMTDNM hay những người đã có nhiều kinh nghiệm.

2 distro phổ biến nhất được phát triển dựa trên Fedora là Red Hat Enterprise Linux - với đối tượng hướng tới là các doanh nghiệp và công ty lớn (tất nhiên là có tính phí) ; và CentOS - free và hướng tới đối tượng là người sử dụng cá nhân.

<a name="4"></a>

## 4. Giấy phép mã nguồn mở
<a name="4.1"></a>

### 4.1. Giới thiệu chung về giấy phép mã nguồn mở

- Giấy phép mã nguồn mở: là các giấy phép bản quyền dành cho các phần mềm máy tính trong đó đặt ra các quy định buộc người sử dụng phần mềm đó phải tuân theo. Giấy phép mã nguồn mở được sử dụng cho các phần mềm nguồn mở.
Giấy phép mã nguồn mở có giá trị về mặt pháp lý được quy định rõ ràng.

Giấy phép mã nguồn mở do một số công ty, tổ chức lập ra để quy định về trách nhiệm của người sử dụng đối với một phần mềm/mã nguồn mở. Hiện tại, tổ chức Open Source Initiative (OSI) là người đưa ra định nghĩa về mã nguồn mở - OSD - Open Source Definition được cộng đồng công nhận rộng rãi. Các giấy phép mã nguồn mở đa phần được xây dựng dựa trên OSD.

Mục đích sử dụng: Các giấy phép mã nguồn mở được sử dụng để đảm bảo rằng các phần mềm, mã nguồn có sử dụng giấy phép này luôn là mã nguồn mở, phù hợp với OSD.

- 3 điểm chủ yếu trong một giấy phép mã nguồn mở là:
  - Tự do phân phối lại: không cấm bất kì ai cho hoặc bán chương trình.
  - Mã nguồn: cho phép sự phân phối dưới dạng mã nguồn, và nếu mã nguồn không đi kèm chương trình, nó phải truy cập được một cách dễ dàng và miễn phí trên thực tế.
  - Phiên bản dẫn xuất: cho phép các thay đổi và các phiên bản dẫn xuất, và phải cho phép rằng những phiên bản này được phân phối dưới cùng các điều khoản giấy phép.

<a name="4.2"></a>

### 4.2. Phân loại
Được chia thành 2 loại chính:

- Những giấy phép không quy định bất kì sự hạn chế nào trong việc sự dụng mã nguồn - còn có thể gọi là các giấy phép không bảo hộ vì chúng không bảo vệ mã nguồn mở khỏi việc bị sử dụng trong các phần mềm không phải là mã nguồn mở.

    - Người giữ bản quyền mã nguồn sẽ giữ lại bản quyền của họ đối với mã nguồn, và cấp cho người được cấp bản quyền (có thể hiểu là người sử dụng sản phẩm, mã nguồn) tất cả các quyền thuộc về bản quyền của mã nguồn đó.Còn được gọi là non-copyleft.

   - Các giấy phép thuộc loại này: Apache Software License v.1.1, BSD License, Intel Open Source License for CDSA/CSSM Implementation, MIT License, Sun Industry Standards Source License, W3C Software Notice and License…

- Những giấy phép quy định các hạn chế trong việc sử dụng mã nguồn - còn có thể gọi là các giấy phép bảo hộ vì chúng đảm bảo rằng các mã nguồn mở khi được sử dụng trong bất cứ tình huống nào sẽ vẫn được công khai/miễn phí.

  - Người giữ bản quyền mã nguồn giữ lại bản quyền của họ đối với mã nguồn, và cấp cho người được cấp bản quyền tất cả các quyền thuộc về bản quyền của mã nguồn đó, nhưng có ít nhất một điều kiện, thông thường là việc phân phối lại phần mềm/mã nguồn đó, dù đã được sửa đổi hay chưa, đều phải sử dụng cùng loại giấy phép ban đầu. Còn được gọi là copyleft.

  - Các giấy phép thuộc loại này: Apple Public Source License v.1.2, Common Public License v.1.0; GNU General Public License v.2.0, IBM Public License v.1.0, Mozilla Public License v.1.0 and v.1.1, Nokia Open Source License v.1.0a, Open Software License v.1.1, Python License; Python Software Foundation License v.2.1.1, Sun Public License v.1.0…

<a name="4.3"></a>

### 4.3. MỘt số giấy phép mã nguồn mở phổ biến hiện nay

Tuy đa dạng về số lượng nhưng nhìn chung mỗi loại giấy phép mã nguồn mở đều gồm 3 nội dung chính: quyền lợi; trách nhiệm khi sử dụng, phân phối lại hay chỉnh sửa chương trình; xử lí nếu vi phạm giấy phép.

<a name="4.3.1"></a>

#### 4.3.1. Giấy phép GNU
a) Nhà phát hành:

GNU (GNU General Public License – Giấy phép công cộng GNU, còn được gọi là GNU GPL hay đơn giản là GPL) là giấy phép phần mềm tự do phổ biến nhất, ban đầu được thiết kê bới Richard Stallman, dành cho dự án GNU. Phiên bản 2 của giấy phép này được phát hành năm 1991, và phiên bản 3, phiên bản hiện tại, được phát hành năm 2007.

b) Nội dung chính:

Quyền lợi:

- Quyền được sao chép và phân phối chương trình, quyền được yêu cầu trả phí cho việc phân phối đó.
- Quyền được thay đổi chương trình để sử dụng cho mục đích cá nhân.
- Quyền được phân phối bản đã được thay đổi đó.

Nghĩa vụ:

- Khi sao chép và phân phối chương trình, phải đính kèm các thông báo về bản quyền gốc và không nhận bảo hành (trừ trường hợp có văn bản thêm về quy định bảo hành.)

- Khi phân phối bản đã được thay đổi bởi bản thân, phải chú thích rõ đó là bản đã được thay đổi, các thành phần được thay đổi, và áp dụng giấy phép GNU cho bản đã được thay đổi đó.

-  Khi phát hành chương trình phải công khai mã nguồn của chương trình của nó, đồng thời phải công bố mã nguồn của chương trình trong tối thiểu 3 năm mà không được đòi một khoản phí nào từ những người yêu cầu mã nguồn trừ chi phí vận chuyển hay tương đương.

Xử lí vi phạm:

Người vi phạm giấy phép bị tước quyền sử dụng giấy phép GNU, tuy nhiên nếu B thừa hưởng giấy phép từ A, mà A vi phạm mà B không vi phạm thì B vẫn được giữ giấy phép GNU.

Ta có thể thấy giấy phép GNU có những điểm đáng chú ý sau:

- Có đặc tính virus, bởi sức lây lan và kế thừa của nó. Một người nhận sản phẩm từ người mang giấy phép GNU thì ngay lập tức người đó cũng mang giấy phép GNU. Hệ quả là GNU là giấy phép phổ biến nhất, bởi mã nguồn luôn ở dạng công cộng cho phép ai cũng có thể tham gia ở bất kì thời điểm nào.

- Tác giả gốc giữ bản quyền, và cho người dùng các quyền hợp pháp trong việc: sao chép, chỉnh sửa, phân phối sản phẩm. Mặc dù giấy phép GNU yêu cầu mã nguồn và chương trình phải được cung cấp miễn phí, song nó cho phép người phân phối có thể kinh doanh với sản phẩm nhờ đưa ra các chính sách về bảo hành, tính chi phí phân phối sản phẩm, đào tạo sử dụng …

Một số người lo ngại về vấn đề mã nguồn bị public tạo điều kiện cho hacker tìm ra lỗ hổng, song thực tế lại chứng minh ngược lại, càng cố che giấu mã nguồn thì lại càng bị tấn công nhiều hơn.

=> GNU là giấy phép phổ biến nhất, bởi mã nguồn luôn ở dạng công cộng cho phép ai cũng có thể tham gia ở bất kì thời điểm nào.

Mặc dù giấy phép GNU yêu cầu mã nguồn và chương trình phải được cung cấp miễn phí, song nó cho phép người phân phối có thể kinh doanh với sản phẩm nhờ đưa ra các chính sách về bảo hành, tính chi phí phân phối sản phẩm, đào tạo sử dụng …

c) Các phần mềm sử dụng giấy phép GNU GPL nổi bật:
-  RedHat Enterprise Linux
- Ubuntu
- GIMP
- Drupal, WordPress, Joomla…
<a name="4.3.2"></a>

#### 4.3.2. Giấy phép BSD:

a) Nhà phát hành:

Giấy phép BSD (Berkeley Software Distribution License) là một giấy phép phần mềm tự do với các điều kiện rất đơn giản được sử dụng rộng rãi cho phần mềm máy tính. Ban đầu giấy phép BSD được thiết kế bởi Đại học California tại Berkeley năm 1980 cho dự án BSD (Berkeley Source Distribution).

b) Nội dung chính:

Quyền lợi:

Giấy phép BSD cho phép sử dụng và phân phối lại mã nguồn và sản phẩm, có hoặc không có sửa đổi, miễn là tuân thủ các yêu cầu sau:

Nghĩa vụ:

- Phải giữ nguyên thông báo bản quyền của sản phẩm. Yêu cầu này nhằm đảm bảo một người dùng bất kì không thể tuyên bố anh ta đã viết ra một phần mềm nếu thực sự anh ta không viết ra nó.

- Phải kèm theo 2 thông báo: Danh sách các điều kiện và từ chối trách nhiệm.

- Không được sử dụng tên dự án hay tên nhà phân phối vào mục đích quảng bá bản thân nếu không được cho phép.

Như vậy, có thể thấy đặc điểm lớn nhất của BSD là nó cho phép các nhà phát triển phần mềm có thể thương mại hóa một cách thực sự các sản phẩm phần mềm có sử dụng mã nguồn mở dùng giấy phép BSD, tức kiếm tiền dựa trên mã nguồn của chương trình (chủ yếu là mã nguồn do họ viết thêm và giữ lại mã nguồn đã được sửa đổi đó cho bản thân mà không công bố) thay vì chỉ có thể kiếm tiền từ các hoạt động không trực tiếp gắn với phần mềm như bảo hành, phát hành, đào tạo hướng dẫn sử dụng … Ngoài ra, giấy phép BSD còn cho phép các nhà phát triển thay thế, bổ sung thêm các điều khoản vào trong giấy phép cho phù hợp với mình, hoặc thậm chí sử dụng một giấy phép khác.

c) Một số phần mềm sử dụng giấy phép BSD:

Một số lớn các dự án xây dựng phần mềm nguồn mở, bao gồm cả những phần mềm lớn, đã được cấp giấy phép dạng BSD. Ví dụ:
– Hệ thống Window Xfree86: nền tảng của hầu hết các giao diện với người sử dụng trong các hệ thống phần mềm nguồn mở.
– FreeBSD, NetBSD và OpenBSD: các biến thể của phiên bản Unix gốc được cấp giấy phép BSD, cả ba đều được sử dụng rộng rãi trên mạng Internet, đặc biệt là FreeBSD, chương trình điều hành Yahoo Mail và dịch vụ Hotmail.

Tích hợp mã nguồn được cấp phép theo chế độ giấy phép BSD vào các ứng dụng thương mại và việc khá đơn giản. Ngay Microsoft trước đây cũng đã từng sử dụng một số mã BSD trong phần kết nối mạng của mã nguồn Window. Nhiều công ty đưa cả phần mềm máy chủ Apache vào trong gói phần mềm thương mại mà họ cung cấp cho khách hàng.
<a name="4.3.3"></a>

#### 4.3.3 Giấy phép MIT

a) Nhà phát hành:

- MIT là một giấy phép phần mềm tự do được phát hành bởi Học viện Công nghệ Massachusetts (Massachusetts Institute of Technology – MIT), được hội đồng MIT X sử dụng.

- Theo Tổ chức phần mềm tự do, giấy phép MIT nên được gọi chính xác hơn là giấy phép X11, do Học viện Massachusetts đã từng dùng nhiều loại giấy phép khác nữa, và do giấy phép này ban đầu được soạn thảo cho X Window System (dự án tạo giao diện đồ họa cho người dùng ở các máy tính kết nối mạng vào năm 1984).

b) Nội dung chính:

MIT là một giấy phép dạng “permissive”, nghĩa là nó cho phép tái sự dụng các phần mềm độc quyền nhưng với điều kiện giấy phép MIT đã được phân phối kèm phần mềm đó. Giấy phép MIT cũng tương thích GLP, nghĩa là GPL cho phép tổng hợp và tái phân phối các phần mềm sử dụng giấy phép MIT.

- Các quyền lợi của người sử dụng giấy phép vẫn tương tự như ở giấy phép GNU. Tuy nhiên MIT loại bỏ thuộc tính virus khỏi giấy phép, tức không bắt buộc các chương trình sử dụng tài nguyên có dùng giấy phép MIT cũng phải sử dụng giấy phép MIT.

- Giấy phép MIT không bắt buộc phải công khai mã nguồn.

- Người sử dụng phải kèm theo giấy phép MIT vào bản chỉnh sửa của mình, tuy nhiên không bị bắt buộc phải sử dụng giấy phép MIT cho toàn bộ bản đó.

- Giấy phép MIT cũng có thể được chỉnh sửa lại cho phù hợp với thực tế.

Ngoài ra, giấy phép MIT không cấm sử dụng tên của người giữ bản quyền vào mục đích quảng bá, và cũng không bắt buộc phải hiện danh sách tất cả những người từng tham gia thực hiện dự án trong phần About của chương trình.

c) Một số phần mềm sử dụng giấy phép MIT:

- Các gói phần mềm sử dụng giấy phép MIT bao gồm Expat, PuTTY, Ruby on Rails, Lua 5.0 và X Window System.

- Cũng có một số sản phẩm sử dụng chung giấy phép MIT với một giấy phép khác, mà nổi tiếng nhất là thư viện jQuery của JavaScript, sản phẩm này sử dụng cả giấy phép MIT và GNU.

<a name="4.3.4"></a>

#### 4.3.4 Giấy phép Apache:

Tìm hiểu về các giấy phép mã nguồn mở (Open Source License) 169px-asf-logo-svg

a) Nhà phát hành:

- Giấy phép Apache là giấy phép mã nguồn mở được soạn ra bởi Tổ chức phần mềm Apache (ASF – Apache Software Foundation).

- Tất cả mọi phần mềm do ASF phát hành đều mang giấy phép Apache. Những dự án không thuộc ASF nhưng vẫn mang giấy phép Apache, cho đến tháng 7 năm 2009 là vào khoảng 5000 dự án.

- ASF và Tổ chức phần mềm tự do (FSF) đều công nhận giấy phép Apache 2.0 là một giấy phép phần mềm tự do, tương thích với phiên bản giấy phép GNU 3.0.

b) Nội dung chính:

- Giống như các giấy phép mã nguồn mở khác, giấy phép Apache cho phép người dùng tự do sự dụng phần mềm với bất kì mục đích nào, tự do phân phối, tự do sửa đổi, tự do phân phối bản sửa đổi mình làm (đoạn 3 của giấy phép).

- Giấy phép Apache không yêu cầu bản sửa đổi của phần mềm phải được phân phối dưới cùng giấy phép với bản gốc, cũng không yêu cầu bản sửa đổi phải được phân phối dưới dạng mã nguồn mở. Giấy phép Apache chỉ yêu cầu có một thông báo nhắc nhở người nhận rằng giấy phép Apache đã được sử dụng trong sản phẩm họ nhận được.

Như vậy, trái ngược với các giấy phép Copyleft, người nhận được những bản sửa đổi của chương trình mang giấy phép Apache cũng không nhất thiết phải nhận toàn bộ những quyền trên. Nói cách khác là họ có nhận được quyền sử dụng chương trình và mã nguồn theo cách họ muốn, kể cả việc giữ lại mã nguồn cho riêng mình (đoạn 4 của giấy phép).

Có hai file cần được đặt trong thư mục gốc khi phân phối chương trình:

–          LICENSE: bản copy của chính giấy phép MIT.

–          NOTICE: văn bản chú thích tên của các thư viện đã dùng, kèm tên người phát triển.

–        Trong mỗi tệp tin đã được cấp phép, bất kì thông tin về bản quyền và bằng sáng chế trong bản phân phối lại phải được giữ nguyên như ở bản gốc, và ở mỗi tệp tin đã được chỉnh sửa phải thêm vào ghi chú là đã được chỉnh sửa khi nào.

<a name="5"></a>

## 5. Tài liệu tham khảo
[Lịch sử hệ điều hành Linux](https://vi.wikipedia.org/wiki/L%E1%BB%8Bch_s%E1%BB%AD_Linux#:~:text=L%E1%BB%8Bch%20s%E1%BB%AD%20c%E1%BB%A7a%20Linux%20b%E1%BA%AFt,su%E1%BB%91t%20l%E1%BB%8Bch%20s%E1%BB%AD%20c%E1%BB%A7a%20n%C3%B3.)

[ Bản phân phối Linux](https://vi.wikipedia.org/wiki/B%E1%BA%A3n_ph%C3%A2n_ph%E1%BB%91i_Linux)

[Giấy phép mã nguồn mở](https://openlab.forumvi.com/t36-topic)
