#include <graphics.h>
#include <fstream>
 // Các hàm mở đầu chương trình:
#include "MO_DAU_CHUONG_TRINH.h"

// hàm vẽ đàn:
#include "VE_DAN_ORGAN.h"

// hàm chơi đàn
#include "CHAY_PHIM_DAN.h"

int main()
{
    // test hàm:
    initwindow(1500,2000, "Ung dung dan");
    //Hàm lời chào và bắt đầu chương trình mô phỏng nhạc cụ:
    ham_loi_chao_va_loading_chuong_trinh();

    // ham background

    ham_background();
    //bang ten
    ham_ve_bang_ten();

    //ten
    ham_dat_ten_va_lop();
    //Drum
    ham_ve_trong();

    //ORGAN
    ham_ve_dan_organ();

    //loa
    ham_loa();

    //bang nut
    ham_cac_nut_bam_dan();

    // hàm thông báo trên màn hình
    ham_thong_bao_tren_man_hinh_dan();

    // đánh các phím đàn:
    ham_kiem_soat_danh_cac_phim_tren_dan();

    // kết thúc:
    getch();
    closegraph();
    system("PAUSE");
    return 0;
}
