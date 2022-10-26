### Bài 1. Chương trình đầu tiên và chú thích 
- In ra màn hình
     - Khi dùng print in chuỗi print("abc")=>abc
     - khi dùng print tính toán print(a+b)=>c(với c=a+b)
     - Kết hợp chuỗi và tính toán bằng `,` print("a+b=",a+b)=>a+b=c
- Chú thích
   - Comment trên 1 dòng #
   - Comment trên nhiều dòng """""";'''''';

### Bài 2. Kiểu dữ liệu, biến, ép kiểu
#### Kiểu dữ liệu

- Trong Python cũng như các ngôn ngữ lập trình khác, một biến luôn có kiểu dữ liệu. Một số kiểu dữ liệu cơ bản trong Python:

   - int: đây là kiểu dữ liệu được dùng để lưu trữ các số nguyên (1, 2, 3, 4, ...).
   - float: đây là kiểu dữ liệu dùng để lưu trữ các biến kiểu số thực (1.43, 5.34, 3.333, ...).
   - bool: đây là kiểu dữ liệu dùng để lưu trữ các giá trị luận lý (True hoặc False)
   - str: đây là kiểu dữ liệu dùng để lưu trữ các xâu ký tự ("Viet Nam", "Codelearn", ...)
*Để kiểm tra kiểu dữ liệu của biến sử dụng type()
VD: print(type(name))*
- `str`
  - Toán tử nối chuỗi `+` print("hello " + name) với name là 1 chuỗi
  - Toán tử lặp chuỗi `*` print("hello "*3)
Bạn chỉ có thể nối chuỗi với chuỗi chứ không thể nối chuỗi với một số 
- Cần thực hiện ép kiểu để đưa về dạng chuỗi VD: str(19)

### Bài 3. Nhập xuất dữ liệu cơ bản từ bàn phím
Để nhập dữ liệu cho biến từ bàn phím sử dụng hàm input()
VD: 
```sh
name =input()
print("hello "+name)
```
Chú ý: Khi bạn nhập dữ liệu từ bàn phím thì kiểu dữ liệu bến đó luôn là `str`
Có thể ép kiểu đầu vào `int(input())`
- Hoán đổi sử dụng 1 biến trung gian c để hoán đổi cho a và b
```sh
c = a
a = b
b = c
```

### Bài 4. Toán tử cơ bản

#### Toán tử số học 

|Toán tử|Mục đích|Ví dụ|
|---|---|---|
|"//"|Chia lấy phần nguyên|7 // 3 = 2|
|%|Chia lấy phần dư|10%4=2|
|**|Toán tử mũ(a**b=a^b)|2**3=8|

#### Toán tử so sánh

|Toán tử|Mục đích|VD|
|---|---|---|
|==|bằng|3==3 (True)|
|!=|khác|3!=3(False)|
|>=|lơn hơn hoặc bằng||
|<=|nhỏ hơn hoặc bằng||

#### Toán tử gán

|Loại toán tử|Mục đích|Cách dùng|
|---|---|---|
|+=|Tăng vế trái một phần bằng vế phải sau đó gán kết quả cho vế trái|x+=5|
|-=|..|x-=5(x=x-5)|
|&=|Thực hiện phép toán của toán tử AND cho 2 vế sau đó gán cho vế trái|x &= 5

(x = x & 5)|
||=|Thực hiện phép toán của toán tử OR cho 2 vế sau đó gán cho vế trái|x |= 5

(x = x | 5)|
|^=|Thực hiện phép toán của toán tử XOR 2 vế sau đó gán cho vế trái|x ^= 5

(x = x ^ 5)|
|>>=|Thực hiện phép toán dịch phải của vế phải sau đó gán cho vế trái|x >>= 5

(x = x >> 5)|
|<<=|Thực hiện phép toán dịch trái của vế phải sau đó gán cho vế trái|x <<= 5

(x = x << 5)|

- Sử dụng `in` và `not in` 
VD:
```sh
print("Code" in "Codelearn")
print("Py" not in "Python")
```
kết quả:

True

False
### Toán tử định danh 
```sh
a = 5
b = 7
print(a is b)
print(a is not b)
```

### Toán tử logic

```sh
x = True
y = False
print(x and y)
print(x or y)
print(not x)
```
### Bài 5. Câu lệnh lựa chọn
#### `If-else`
Mệnh đề if-else được dùng để kiểm tra một điều kiện có đúng hay không, nếu đúng thì khối lệnh bên trong if sẽ được thực thi, ngược lại nếu điều kiện là sai thì khối lệnh bên trong else sẽ được thực thi
```sh
if condition:
    # Nếu condition đúng thì khối lệnh này sẽ được thực thi
else:
    # Nếu condition sai thì khối lệnh này sẽ được thực thi
```
VD:
```sh
a,b= 5, 10
if a!=b:
     print('a is not equal b' )
else:
    if a>b:
        print('a is greater than b')
    else:
        print('b is greater than a')
```
VD:
```sh
a = int(input())
b = int(input())
if a == b:
    print("a = b")
elif a > b:
    print("a > b")
else:
    print("a < b")
```

#### `Vòng lặp`
##### Vòng lặp `while` lặp lại một hành động cho tới khi điều kiện lặp không còn thỏa mãn nữa
```sh
while condition:
    # Khối lệnh này sẽ được thực thi nếu condition còn đúng
```
VD:
```sh
i = 1
while i <= 5:
    print(i)
    i += 1
```
VD:
```sh
n = int(input())
i = 1
answer = 0
while i <= n:
    answer += i
    i += 1
print(answer)
```
#### Vòng lặp `for` dùng để lặp một tập hợp cho trước, vòng lặp `for` thường được sử dụng với hàm `range()` 
```sh
name = "Codelearn"
for c in name:
    print(c)
```
```sh
for i in range(1, 5):
    print(i)
```
*in i từ 1, 2, 3, 4*
VD
```sh
n = int(input())
answer = 0
for i in range(1, n + 1):
    answer += i
print(answer)
```




