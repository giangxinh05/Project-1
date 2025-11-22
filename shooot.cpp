// Lười tải cái thư viện đồ họa quá, nhưng dùng tạm cái này làm trò bắn chết ông già noen
// về nguyên tắc chung như sau:
// gốc tọa độ (0,0) nằm ở góc trái bên trên cùng, trục ngang x, trục dọc y
//x tăng từ trái sang phải giống toah độ bth, y ngược lại
// đạn bay lên thì y phải giảm (y--)
// đi trái a, đi phải d, bắn g, thoát esc





#include <iostream> // dùng lệnh in ra màn hình
#include <windows.h> // dùng tạm cnay in màu, chỉ trỏ chuột
#include <conio.h> // bắt lệnh bắn 
#include <vector> // dùng chứa đạn
using namespace std; // cho đỡ gõ nhiều


struct shot {
    int x;
    int y;
};

void GoToXY(int x, int y) {
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { (short)x, (short)y };
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
    // dịch chuyển con trỏ đến tọa độ x,y
}

void ShowCur(bool CursorVisibility) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
    SetConsoleCursorInfo(handle, &cursor);
    // ẩn con trỏ đi
}

int main() {
    ShowCur(0);

    int x = 40; // cái tọa độ cho điểm bay A là cột 40 dòng 25
    int y = 25; 
    
    // Tạo một túi chứa các viên đạn (giống đống snowflake )
    vector<shot> dan; 

    while (true) {
        // vòng lặp chạy mãi đến lúc bấm esc
        
        for (int i = 0; i < dan.size(); i++) {
            // Xóa dan ở vị trí cũ
            GoToXY(dan[i].x, dan[i].y); cout << " "; // cái này xóa đạn y như xóa mấy cái vệt sáng đuôi ở bài trước

            // Cho dan bay lên (giảm y)
            dan[i].y--;

            // Nếu đạn bay thoát khỏi màn hình (y < 0) thì xóa khỏi danh sách
            if (dan[i].y < 0) {
                dan.erase(dan.begin() + i);
                i--; // Lùi i lại 1 để không bỏ sót viên đạn kế tiếp
            }
            else {
                // Nếu chưa thoát màn hình thì vẽ ở vị trí mới
                GoToXY(dan[i].x, dan[i].y); cout << ".";
            }
        }

        // điểm bay A
        GoToXY(x, y); cout << "   "; // Xóa A cũ

        if (_kbhit()) {
            char key = _getch();
            if (key == 'a' && x > 0) x--;  // Giới hạn biên trái
            if (key == 'd' && x < 75) x++; // Giới hạn biên phải
            
            // Bấm g để bắn chet bonno
            if (key == 'g') {
                // Tạo viên đạn mới ngay tại đầu máy bay (x + 1 để căn giữa)
                dan.push_back({ x + 1, y - 1 });

            }

            if (key == 27) break; // ESC để thoát
        }

        GoToXY(x, y); cout << "^A^"; // điểm bay A mới

        Sleep(30); // tốc độ của k.hinh
    }

    return 0;
}