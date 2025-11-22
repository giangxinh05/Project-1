#include <iostream>
#include <vector>


struct Enemy {
    void matmau() { std::cout << "mất máu\n"; }
};

struct Bullet {
    bool chamvao(Enemy e) { return true; // gsu luon trung dan 
        }
};

int main() {
    
    std::vector<Bullet> bullets(5); // Tạo thử 5 viên đạn
    std::vector<Enemy> enemies(3);  // Tạo thử 3 con quái

    
    
    // Với mỗi viên đạn...
    for (int i = 0; i < bullets.size(); )  
    { 
        
        bool danno = false; // Cờ đánh dấu xem đạn đã nổ chưa

        // ...đi kiểm tra với từng con quái vật
        for (int j = 0; j < enemies.size(); j++) {
            
            if (bullets[i].chamvao(enemies[j])) {
                enemies[j].matmau();
                
                // Xóa viên đạn
                bullets.erase(bullets.begin() + i); 
                
                // đạn đã nổ và thoát vòng lặp quái vật ngay
                danno = true; 
                break; // Đạn nổ rồi thì break
            }
        }

        // Nếu đạn chưa nổ thì mới tăng i để kiểm tra viên tiếp theo
        // Nếu đạn nổ rồi (đã bị xóa), thì vị trí i hiện tại chính là viên đạn mới dồn lên soso
        // nên ta giữ nguyên i để kiểm tra nó ở vòng sau.
        if (!danno) {
            i++;
        }
    }

    return 0;
}