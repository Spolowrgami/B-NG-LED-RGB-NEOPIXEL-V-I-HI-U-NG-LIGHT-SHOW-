# Bảng LED RGB (NeoPixel) với hiệu ứng Light Show  
Sử dụng vi điều khiển **STM32F407VET6** để điều khiển dải LED **WS2812B**, kết hợp xử lý âm thanh qua **MAX9814** và thuật toán **FFT** để tạo hiệu ứng ánh sáng theo nhạc. Giao diện điều khiển hiển thị trên màn hình cảm ứng **LCD ILI9341**.

## 🎯 Tính năng chính
- Thu âm thanh từ micro MAX9814 và phân tích tần số bằng FFT (CMSIS-DSP).
- Hiển thị nhiều hiệu ứng LED đẹp mắt:
  - Light Bar  
  - Sparkle  
  - Flash  
  - EchoSplit  
- LED phản hồi theo âm thanh theo thời gian thực.
- Giao diện cảm ứng trên LCD cho phép chọn hiệu ứng dễ dàng.

## 🔧 Phần cứng sử dụng
- STM32F407VET6 Black Board  
- Dải LED WS2812B (NeoPixel)  
- Microphone MAX9814  
- LCD ILI9341 (kèm cảm ứng)  
- Dây jumper & ST-Link

## 🧩 Cấu trúc phần mềm
- **ADC + DMA**: đọc tín hiệu âm thanh  
- **Timer + DMA PWM**: điều khiển WS2812  
- **FFT (arm_rfft_fast_f32)**: phân tích âm thanh theo dải Bass – Mid – Treble  
- **FSMC**: giao tiếp tốc độ cao với LCD  
- **Touch driver + Calibration**: xử lý cảm ứng chính xác  

## 🚀 Cách chạy project
1. Mở project bằng **STM32CubeIDE**.  
2. Cấu hình phần cứng theo sơ đồ kết nối (WS2812 – LCD – MAX9814).  
3. Build và nạp chương trình bằng ST-Link.  
4. Chọn hiệu ứng trên LCD và thử với nguồn âm thanh.

## 📸 Demo
<img width="1074" height="807" alt="image" src="https://github.com/user-attachments/assets/a3b0ee69-6f85-4b92-b417-d5c16631c8a2" />


## 👥 Thành viên
- Dương Thanh Hiếu  
- Trần Triệu Dân

