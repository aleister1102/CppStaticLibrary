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

Project `LibraryClient` là để test thư viện.

## Install
Lưu ý: Thư viện này được cần được compile thành file Static Library (`lib`) bằng **Visual 
Studio**.

Nếu cần compile lại thư viện:
1. Tạo mới một project, chọn loại project là **library**, kiểu app là **Window Desktop App**.
2. Thêm các file `.cpp` cùng `.h` trong thư mục **StaticLibrary** vào solution, chọn tất cả các file header trong VS rồi cấu hình "file type" là `copy file`. Cấu hình này giúp cho các file header được copy vào thư mục output của chương trình.
3. Build project, thư mục output là thư mục **Debug**.

## Usage
- Nếu muốn sử dụng ở một project khác:
	1. Mở phần **Properties** của project lên, chọn mục **VC++ Directories** 
	2. Thêm vào **Library Directories** và **Include Directories** là đường dẫn thư mục Debug ở trên
	3. Chọn mục **Linker**, chọn input, thêm vào file `StaticLibrary.lib`.
	4. Import thư viện cần sử dụng trong file `.cpp/.h` với cú pháp `#include <Header.h>`, với Header là tên file Header.
- Nếu muốn test nhanh thư viện:
	1. Mở solution `cpp_libraries` lên và build project `LibraryClient`.
	2. Test các tính năng của thư viện trong file `Source.cpp`.

Có thể tham khảo thêm về cách build thư viện và sử dụng tại [đây](https://docs.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-static-library-cpp?view=msvc-170).

