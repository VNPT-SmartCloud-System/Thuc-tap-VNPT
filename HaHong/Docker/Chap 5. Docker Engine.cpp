Chap 5. Docker Engine
Dockerfile là tập các lệnh chỉ dẫn đóng image(source code, các phụ thuộc)
Khi chạy lệnh `docker run it alpine` trong docker muốn dừng lại sử dụng `Ctrl+D` để dừng tiến trình chủ đạo. LÀM SAO ĐỂ thoát ra tạm thời mà container vẫn run hay không?
Chế độ sống của container là attach và detach mode:
Nhấn tổ hợp phím `Ctrl+P+Q` để detach container(container vẫn chạy trên máy nhưng không còn hiển thị trên terminal)


# Images
Docker image là một gói rằng nó chứa tất cả yêu cầu cho một ứng dụng để chạy. Một images chứa code, các phụ thuộc và hệ điều hành. Docker imgae được pull từ image resistry(Docker Hub) đến local Docker host để có thể bắt đầu chạy một hoặc nhiều container
Images được làm từ nhiều lớp, được trình bày như một đối tượng độc lập. Nó giống như một hệ điều hành được cắt giảm và chứa tất cả các file và những phụ thuộc yêu cầu để chạy một ứng dụng. Bởi vì container được dự định sẽ nhanh và nhẹ nên image có xu hướng nhỏ
### Docker images- deep dive
Images là một container dừng. 
Bạn có thể dừng một container và tạo một ảnh mới từ nó. Images là build-time, container là runtime

![](image1/run_build.png)

Để bắt đầu một hoặc nhiều container từ 1 image
```sh
docker container run
```
```sh
docker service creat
```
Bạn không thể xóa image mãi cho đến khi dừng hoặc hủy bỏ container cuối cùng sử dụng cái image đó.
Mục đích của một container là chạy một ứng dụng hoặc dịch vụ độc lập. Nó chỉ cần code, các phụ thuộc của app/service để chạy,
Image cũng không chứ một kernel, tất cả các container chạy trên một docker host sẽ chua sẻ truy cập từ kernel máy chủ
*Chú ý: Hyper-V container chạy một container bên trong máy ảo nhẹ VM, Container tận dụng kernel của hệ điều hành đang chạy bên trong VM*

### Pulling images
Nơi lưu trữ image tại local thường đặt tại /var/lib/docker/image đối với Linux
### 
sử dụng docker run --name=test-mysql mysql để đặt tên 
Với một số ứng dụng cần phải đặt password cho môi trường
VD:
```sh
docker run --name=test-mysql --env="MYSQL_ROOT_PASSWORD=abc124" mysql
Lấy thông tin của một container đang chạy
```sh
docker inspect test-mysql
```
--
Port Mapping 
Câu lệnh để 
```sh
docker run -p <target_port>:<container_port> name_container|ID_container
```
Muốn xem logs của container sử dụng
```sh
docker logs -f <container_id>
```
-f: giữ cho màn hình inlog theo thời gian

Filtering image 
Option: --filter
Command:
- List: 
VD
```sh
docker image ls -filter dangling=true
```
```sh
docker search alpine --filter "is-official=true"
```
chú ý tắt container:
+ SIGTERM signal: Cho thời gian tắt các ...
+ SIGKILL signal: Dừng tiến trình ngay lập tức
### Self-healing containers: Cơ chế để đảm bảm container đang chạy không bị dừng vì một lí do nào đó
- restart policies per-container:
+ Always: luôn running (VD stop container nhưng khi restart container đó sẽ up)
+ Unless-stopped: luôn bật cho tới khi thấy lệnh stop
+ On-failed: 
Vd:
```sh
docker container run --name tannt -it --restart always alpine sh
```

Chú ý lệnh sau để tìm ứng dụng chạy port 80
```sh
netstat -anptlu |grep 80
```
Ví dụ muốn tắt ứng dụng đang chạy port 80 chẳng hạn là apache
```sh
/etc/init.d/apache stop
```
Remove container: 
```sh
docker container rm $(docker ps -aq) -f
```
*$(docker ps -aq) xóa hết các container cả đang chạy*
docker commit: là một lệnh để tạo ra 1 image mới từ một container


Contaimering app
Build-ship-run apps
- Bắt đầu với code ứng dụng của bạn
- Tạo một Dockerfile: file chỉ dẫn cách thức đóng gói 
- Xây dựng ảnh từ Dockerfile
- Run một container
Dockerfile:
FROM alpine #image base(triển khai ứng dụng trên một image)
LABEL maintainer='nigelopulton@hotmail.com' khi gặp sự cố thì liên hệ với ai 
RUN apk add --update nodejs nodejs-non (giống lệnh cài đặt gói): command inside image, new layer
COPY lệnh copy một thư mục: add file into image, new layer
WORKDIR giống lệnh cd trong linux
RUN 
EXPOSE listen ở port nào
ENIRYPOINT chỉ dẫn để thực thi ứng dụng này như thế nào
LABEL, ENV, ONBUILD, HEALTHCHECK, CMD,....



MULTI-STAGE
### Ship apps
Command:
- docker login
- docker image tag web:latest nigelpoulton/web:lastest
- docker image push nigelpoulton/web:lastest
### Best practies
Build cache:
Squash the image: nhóm các layer trong image thành 1 layer base người đọc sẽ không biết trước đấy layer gồm những gì
Use no-install-recommends:
### Docker compose: triển khai cùng lúc nhiều container cho app
VD: có 4 image => Tạo ra một file chỉ dẫn 
Câu lệnh `docker-compose` không có sẵn trong docker local cần phải pull 
Deploying apps with compose
Compose files: chỉ dẫn start service như thế nào
Command:
```sh
cat docker-compose.yml
```
```sh
docker-compose up -d 
```
docker-compose down (stop and delete app)
docker-compose ps
docker-compose top 
docker-compose stop
docker-compose rm
docker-compose restart
   

## Containerizing an app
### Containerizing an app- TLDR
Quá trình lấy một ứng dụng và định cấu hình có thể chạy như một container được gọi là containerizing
Conatiner là tầt cả làm cho các ứng dụng build, ship and run
Quá trình của container hóa một app là:
1. Bắt đầu với code, dependencies app của bạn 
2. Tạo một Dockerfile để miêu tả ứng dụng của bạn, phụ thuộc của nó và cách để chạy nó
3. Cung cấp Dockerfile vào bằng lệnh `docker image build`
4. Đẩy image mới nên registry(Không bắt buộc)
5. Chạy container từ image đó.
![](image1/app.png)
### Containerizing an app - The deep dive
- Containerize một ứng dụng duy nhất: Quá trình của một app đơn giản theo các bước sau:
    - Clone repo để lấy code ứng dụng
    - Kiểm tra Dockerfile
    - Containerize ứng dụng
    - Chạy ứng dụng
    - Test ứng dụng
    - Nhìn ứng dụng gần hơn 
    - Di chuyển sản phẩm với Multi-stage Builds
    - Một vài thực hành tốt
- Di chuyển sản phẩm với xây dựng nhiều giai đoạn 
- Một vài thực hành tốt nhất 
#### Getting the application code
The application on GitHub: https://github.com/nigelpoulton/psweb.git
Clone từ Github: 
```sh
$ git clone https://github.com/nigelpoulton/psweb.git
Cloning into 'psweb'...
remote: Counting objects: 15, done.
remote: Compressing objects: 100% (11/11), done.
remote: Total 15 (delta 2), reused 15 (delta 2), pack-reused 0
Unpacking objects: 100% (15/15), done.
Checking connectivity... done.
$ cd psweb
$ ls -l
total 28
-rw-r--r-- 1 root root 341 Sep 29 16:26 app.js
-rw-r--r-- 1 root root 216 Sep 29 16:26 circle.yml
-rw-r--r-- 1 root root 338 Sep 29 16:26 Dockerfile
-rw-r--r-- 1 root root 421 Sep 29 16:26 package.json
-rw-r--r-- 1 root root 370 Sep 29 16:26 README.md
drwxr-xr-x 2 root root 4096 Sep 29 16:26 test
drwxr-xr-x 2 root root 4096 Sep 29 16:26 views
```
#### Kiểm tra Dockerfile
Dockerfile là điểm bắt đầu để tạp image – nó mô tả ứng dụng và nói với docker cách để xây dựng nó thành 1 image. Nó bao gồm các lệnh liên tiếp nhau được thực hiện tự động trên 1 image gốc để tạo ra một image mới. Dockerfile bắt đầu bằng chữ D và được đặt tên bắt buộc là Dockerfile. Ngoài tên này, các tên khác đều không hợp lệ
VD:
```sh
$ cat Dockerfile
FROM alpine
LABEL maintainer="nigelpoulton@hotmail.com"
RUN apk add --update nodejs nodejs-npm
COPY . /src
WORKDIR /src
RUN npm install
EXPOSE 8080
ENTRYPOINT ["node", "./app.js"]
```
Tệp Dockerfile mô tả chính xác ứng dụng và các phụ thuộc của nó dưới định dạng dễ đọc 

Cú pháp chung của một Dockerfile có dạng:
```sh
INSTRUCTION arguments
```
VD:
```sh
$ cat Dockerfile
FROM alpine
LABEL maintainer="nigelpoulton@hotmail.com"
RUN apk add --update nodejs nodejs-npm
COPY . /src
WORKDIR /src
RUN npm install
EXPOSE 8080
ENTRYPOINT ["node", "./app.js"]
```
- `From`: Chỉ định rằng image nào sẽ được dùng làm image cơ sở để quá trình build image thực thiện các câu lệnh tiếp theo. Các image base này sẽ được tải về từ Public Repository hoặc Private Repository riêng của mỗi người tùy theo setup.
Chỉ thị FROM là bắt buộc và phải được để lên phía trên cùng của Dockerfile.
![](image1/from.png)
- `Label`: dùng để thêm các thông tin meta vào Docker Image khi chúng được build. Chúng tồn tại dưới dạng các cặp key - value, được lưu trữ dưới dạng chuỗi. Có thể chỉ định nhiều label cho một Docker Image, và tất nhiên mỗi cặp key - value phải là duy nhất. Nếu cùng một key mà được khai báo nhiều giá trị (value) thì giá trị được khai báo gần đây nhất sẽ ghi đè lên giá trị trước đó.
```sh
LABEL <key>=<value> <key>=<value> <key>=<value> ... <key>=<value> 
```
VD:
```sh
LABEL com.example.some-label="lorem"
LABEL version="2.0" description="Lorem ipsum dolor sit amet, consectetur adipiscing elit."
```
- `Maintainer` dùng để khai báo thông tin tác giả người viết ra file Dockerfile.
VD:
```sh
MAINTAINER NamDH <namduong3699@gmail.com>
```
-`Run` dùng để chạy một lệnh nào đó trong quá trình build image và thường là các câu lệnh Linux. Tùy vào image gốc được khai báo trong phần FROM thì sẽ có các câu lệnh tương ứng. Ví dụ, để chạy câu lệnh update đối với Ubuntu sẽ là RUN apt-get update -y còn đối với CentOS thì sẽ là Run yum update -y.
VD:
```sh
RUN /bin/bash -c 'source $HOME/.bashrc; echo $HOME'
-------- hoặc --------
RUN ["/bin/bash", "-c", "echo hello"]
```
Ở cách thức shell form bạn có thể thực hiện nhiều câu lệnh cùng một lúc với dấu \ như:
```sh
FROM ubuntu
RUN apt-get update; \
    apt-get install curl -y
```
![](image1/run.png)
- `Add` Chỉ thị ADD sẽ thực hiện sao chép các tập, thư mục từ máy đang build hoặc remote file URLs từ src và thêm chúng vào filesystem của image dest.
Cú pháp:
```sh
ADD [--chown=<user>:<group>] <src>... <dest>
ADD [--chown=<user>:<group>] ["<src>",... "<dest>"]
```
src có thể khai báo nhiều file, thư mục, ...
dest phải là đường dẫn tuyệt đối hoặc có quan hệ chỉ thị đối với WORKDIR.
```sh
ADD hom* /mydir/
ADD hom?.txt /mydir/
ADD test.txt relativeDir/
```
- `Copy` Chỉ thị COPY cũng giống với ADD là copy file, thư mục từ <src> và thêm chúng vào <dest> của container. Khác với ADD, nó không hỗ trợ thêm các file remote file URLs từ các nguồn trên mạng
![](image1/copy.png)
- `Workdir` đặt thư mục làm việc bên trong hệ thống tập tin image cho phần còn lại của các hướng dẫn trong tệp. hướng dẫn không tạo một layer image mới.
- `Env` ùng để khai báo các biến môi trường. Các biến này được khai báo dưới dạng key - value bằng các chuỗi
VD:
```sh
ENV DOMAIN="viblo.asia"
ENV PORT=80
ENV USERNAME="namdh" PASSWORD="secret"
```
- `CMD` định nghĩa các câu lệnh sẽ được chạy sau khi container được khởi động từ image đã build. Có thể khai báo được nhiều nhưng chỉ có duy nhất CMD cuối cùng được chạy.
Cú pháp:
```sh
CMD ["executable","param1","param2"]
CMD ["param1","param2"] 
CMD command param1 param2
```
Vd:
```sh
FROM ubuntu
CMD echo test
```
- `User` Có tác dụng set username hoặc UID để sử dụng khi chạy image và khi chạy các lệnh có trong RUN, CMD, ENTRYPOINT sau nó.
Cú pháp
```sh
USER <user>[:<group>]
hoặc
USER <UID>[:<GID>]
```
VD:
```sh
FROM alpine:3.4
RUN useradd -ms /bin/bash namdh
USER namdh
```
-`Entrypoint` đặt ứng dụng chính mà image(container) sẽ chạy. Không tạo thêm image layer
#### Containerize the app/build the image
```sh
git clone https://github.com/nigelpoulton/psweb.git
cd psweb
docker image build -t web:latest .
```
Cái câu lệnh này giúp bạn tạo một image mới có tên là web:latest, 
#### Pushing images
Để lưu trữ trên một image registry, Docker Hub là một public image registry phổ biến
Để push image lên, bạn cần login với Docker ID
![](image1/hahong.png)
Trước khi push image cần phải đặt tag 
Sử dụng câu lệnh 
```sh
docker image push hahong182551/web:latest
```
Kết quả:
![](image1/182551.png)
### Run the app
Ứng dung containerized là một web server lắng nghe trên TCP cổng 8080, 
```sh
docker container run -d --name c1 -p 80:8080 web:latest
```
Bạn sẽ có thể trot một trình duyệt web tại DNS hoặc địa chỉ IP của Docker host chạy container.

Kết quả:
![](image1/KQ.png)


