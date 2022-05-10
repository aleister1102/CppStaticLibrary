# C++ Static Library
Thư viện chứa các công cụ hỗ trợ cho ngôn ngữ C++, được xây dựng trong lúc học môn OOP tại HCMUS. Sẽ được cập nhật thêm trong quá trình học và làm việc với ngôn ngữ C++.

## Table of contents
Thư viện gồm:
1. DTOs
	- Date
	- Fraction
	- DynamicArray
2. Helper
	- FileHelper
	- NumberHelper
	- StringHelper
3. Misc
	- Converter
	- RandomGenerator

## Install
**Lưu ý**: thư viện chỉ có thể sử dụng với Visual Studio.

Nếu cần compile lại thư viện:
1. Cài đặt Visual Studio.
2. Tạo mới một project, chọn loại project là **library**, kiểu app là **Window Desktop App**.
3. Thêm các file `.cpp` cùng `.h` trong thư mục **StaticLibrary** vào solution, chọn tất cả các file header trong project rồi cấu hình "file type" là `copy file`. Cấu hình này giúp cho các file header được copy vào thư mục output của chương trình.
4. Build project, thư mục output là thư mục **x64/Debug**.

## Usage

- Nếu muốn dùng ngay: tải về file `StaticLibrary.zip` ở phần **Release** về và cho tất cả các file header cần dùng kèm file `StaticLibrary.lib` vào thư mục project. Import thư viện cần sử dụng trong file `.cpp/.h` với cú pháp `#include "Header.h"`, với Header là tên file header.
- Nếu muốn sử dụng ở một project khác và liên kết với thư mục thư viện:
	1. Mở phần **Properties** của project lên, chọn mục **VC++ Directories**.
	2. Thêm vào **Library Directories** và **Include Directories** là đường dẫn thư mục Debug ở trên.
	3. Chọn mục **Linker**, chọn input, thêm vào file `StaticLibrary.lib`.
	4. Import thư viện cần sử dụng trong file `.cpp/.h` với cú pháp `#include <Header.h>`, với Header là tên file header.

Có thể tham khảo thêm về cách build thư viện và sử dụng tại [đây](https://docs.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-static-library-cpp?view=msvc-170).

