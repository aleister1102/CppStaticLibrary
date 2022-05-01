# C++ Static Library
Thư viện chứa các công cụ hỗ trợ cho ngôn ngữ C++, được xây dựng trong lúc học môn OOP tại HCMUS.

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
Lưu ý: Thư viện này được cần được compile thành file Static Library (`lib`) và dùng chung với Visual 
Studio. 
- Chọn loại project là library với kiểu app là Window Desktop App và build. Thư mục của thư viện đã compile là thư mục Debug.
- Có thể chọn "copy file" trong phần file type của các file header để chúng được copy vào thư mục Debug.

## Usage
- Khai báo library path và include path là thư mục của thư viện ở phần properties của project. 
- Chọn input cho linker là file `StaticLibrary.lib`.
- Import thư viện với cú pháp `#include <Header.h>`, với Header là tên file Header cần import.

Có thể tham khảo thêm về cách build thư viện và sử dụng tại [đây](https://docs.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-static-library-cpp?view=msvc-170).

