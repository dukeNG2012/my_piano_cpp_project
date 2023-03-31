#ifndef CHAY_PHIM_DAN_H_INCLUDED
#define CHAY_PHIM_DAN_H_INCLUDED
#include <cstring>
#include <fstream>
#include <iostream>

// define các nút để bấm các phím đàn
#define KEY_2 50
#define KEY_3 51
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define KEY_9 57
#define KEY_0 48
#define key_F 70
#define key_a 97
#define key_q 113
#define key_w 119
#define key_e 101
#define key_r 114
#define key_t 116
#define key_y 121
#define key_u 117
#define key_i 105
#define key_o 111
#define key_p 112
#define key_A 65
#define key_S 83
#define key_D 68

using namespace std;
void ham_kiem_soat_danh_cac_phim_tren_dan()
{

    // ý tưởng: khách hàng ghi tên bài nhạc vào notepad. Có thể thay thế bài mình thích vào tệp danh sách bài hát.
    // thế nhưng vẫn chỉ có thể 12 bài hát.


    char ch[255]; // biến để lưu tên bài hát từ notepad

    char nguon[255] = ".wav"; // sử dụng strcat để chạy nhạc



    int bien_dem_bai_hat = 0; // sử dụng biến đếm bài hát cho câu lệnh điều kiện

    fstream danh_sach1("danh_sach_nhac.txt", ios::in); // nếu khách hàng không có tệp danh_sach_nhac, lập tức thoát chương trình.
    if(!danh_sach1)
    {
        cout<< "\tDANH SACH NHAC CUA BAN KHONG TON TAI!"<<endl;
        exit(1);
    }


    // bắt đầu chơi nhạc và chuyển nhạc:


    while(1) // sử dụng vòng while vì ở trong vòng lặp vô hạn thì sẽ ấn được phím thoải mái. Nếu không có nó ấn 1 phím lập tức kết thúc chương trình.
    {

        // tại sao lại dùng switch mà không phải if else???
        // vì sau khi thử nghiệm, switch sử dụng bắt phím vẫn tốt hơn if-else (nhạy hơn).
                switch( getch() ) // getch(): lệnh bắt phím: để nhận các phím tương ứng trên bàn phím
                    {


                    // chế độ ấn xong là chơi được đàn:


                    case key_a:
                        /* tại sao lại cần chế độ này? Để khi bấm bài hát thì các tiếng beep sẽ trùng với tần số
                        của "âm thanh chơi đàn cho mượt". Nói cách khác, có chế độ này chơi đàn sẽ mượt hơn.*/

                            PlaySound(TEXT("am_thanh_choi_dan_cho_muot.wav"), GetModuleHandle(NULL),SND_FILENAME | SND_ASYNC | SND_LOOP);
                                break;

                    case key_S:    // nút bật bài hát:

                        bien_dem_bai_hat = 6; /* tại sao lại cần biến đếm bài hát? Khi biến đếm bài hát = 6 có nghĩa là
                        đang bật bài hát ở dòng số 6 trong tệp danh sách txt. Tuy nhiên ở nút play ta chỉ mặc định khi ấn vào
                        là chỉ ra 1 bài hát mà thôi. */


                            if(bien_dem_bai_hat == 6)
                            {

                                fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;

                                    // gọi đến bài hát thứ 6 ở trong tệp danh_sach_nhac.txt

                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,390,ch);


                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"2/3");



                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    // chế độ nhấp nháy để người dùng biết mình vừa bật bài nào

                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,350,1500,450);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,350,1500,450);


                                    danh_sach1.close();
                                /* Cố định nút play chỉ chơi 1 bài hát duy nhất. Sau đó sẽ chuyển sang các bài tiếp theo lần lượt
                                từ nút A và F. */
                            }
                            break;


                        // nút chuyển bài tiếp theo:


                     case key_F:
                        bien_dem_bai_hat++; /*tại sao lại cần tăng biến đếm bài hát?



                             Có 3 lý do để dùng biến đếm bài hát:

                             - Lý do 1: để đặt vào câu điều kiện (để có thể chuyển bài hát trong danh sách nhạc.)
                             - Lý do 2: Để người dùng nhìn màn hình console biết đang chạy bài hát ở dòng số mấy (một trong những
                             lý do để có thể thêm và bớt bài hát vào trong tệp txt.)
                             - Lý do 3: Để mỗi khi ấn nút F, danh_sach1 sẽ tự chuyển sang bài tiếp theo và đến khi bài cuối cùng,
                              dù có ấn nữa thì cũng ko ra bài gì. */

                            // ĐIỀU KIỆN ĐỂ KHÔNG BẤM BÀI HÁT NỮA:
                            if(bien_dem_bai_hat < 1)
                                {
                                    settextstyle(5,0,3);
                                    outtextxy(370,340, "                                 ");
                                    outtextxy(390,370, "                                 ");
                                    outtextxy(360,400, "                                 ");
                                    outtextxy(340,400, "   Da qua gioi han bai hat cho phep     ");
                                }

                            if(bien_dem_bai_hat == 1)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;

                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,290,ch);

                                    //nut next
                                    readimagefile("file_anh/nextbutton.jpg",1400,700,1450,750);

                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"1/3");


                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);


                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,250,1500,350);

                                    // chuyển lại màu bình thường khi bấm xong:
                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,250,1500,350);

                                    // che đi dòng chữ (quá giới hạn bài hát cho phép):
                                        settextstyle(5,0,3);
                                        outtextxy(370,340, "                                 ");
                                        outtextxy(390,370, "                                 ");
                                        outtextxy(360,400, "                                 ");
                                        outtextxy(340,400, "                                     ");

                                    danh_sach1.close();

                                }
                            if(bien_dem_bai_hat == 2)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;


                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,390,ch);

                                    //nut next
                                    readimagefile("file_anh/nextbutton.jpg",1400,700,1450,750);

                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"1/3");


                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);


                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,350,1500,450);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,350,1500,450);



                                    danh_sach1.close();
                                }
                            if(bien_dem_bai_hat == 3)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;

                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,490,ch);

                                    //nut next
                                    readimagefile("file_anh/nextbutton.jpg",1400,700,1450,750);

                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"1/3");


                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,450,1500,550);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,450,1500,550);


                                    danh_sach1.close();
                                }
                            if(bien_dem_bai_hat == 4)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;

                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,590,ch);

                                    //nut next
                                    readimagefile("file_anh/nextbutton.jpg",1400,700,1450,750);

                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"1/3");


                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,550,1500,650);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,550,1500,650);


                                    danh_sach1.close();
                                }
                            if(bien_dem_bai_hat == 5)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;

                                    // chèn ảnh lên 1 lần nữa khi chuyển sang trang thứ 2:
                                    //readimagefile("bancutback1.jpg",720,0,1,800);

                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,290,ch);

                                    //nut next
                                    readimagefile("file_anh/nextbutton.jpg",1400,700,1450,750);

                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"2/3");


                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,250,1500,350);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,250,1500,350);

                                    // che đi dòng chữ (endless_love) khi khách hàng ấn phím s:
                                        settextstyle(5,0,3);
                                        outtextxy(370,340, "                                 ");
                                        outtextxy(390,370, "                                 ");
                                        outtextxy(360,400, "                                 ");
                                        outtextxy(340,400, "                                     ");


                                    danh_sach1.close();
                                }

                            if(bien_dem_bai_hat == 6)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;



                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,390,ch);


                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"2/3");



                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,350,1500,450);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,350,1500,450);


                                    danh_sach1.close();
                                }
                            if(bien_dem_bai_hat == 7)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;



                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,490,ch);

                                    //nut next
                                    readimagefile("file_anh/nextbutton.jpg",1400,700,1450,750);

                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"2/3");



                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,450,1500,550);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,450,1500,550);

                                    // che đi dòng chữ (endless_love) khi khách hàng ấn phím s:
                                        settextstyle(5,0,3);
                                        outtextxy(370,340, "                                 ");
                                        outtextxy(390,370, "                                 ");
                                        outtextxy(360,400, "                                 ");
                                        outtextxy(340,400, "                                     ");


                                    danh_sach1.close();
                                }
                            if(bien_dem_bai_hat == 8)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;



                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,590,ch);

                                    //nut next
                                    readimagefile("file_anh/nextbutton.jpg",1400,700,1450,750);

                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"2/3");



                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,550,1500,650);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,550,1500,650);


                                    danh_sach1.close();
                                }
                            if(bien_dem_bai_hat == 9)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;

                                    // chèn ảnh lên 1 lần nữa khi chuyển sang trang thứ 2:
                                    //readimagefile("back1.jpg", 0,0,1500,1100);

                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,290,ch);

                                    //nut next
                                    readimagefile("file_anh/nextbutton.jpg",1400,700,1450,750);

                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"3/3");




                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,250,1500,350);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,250,1500,350);


                                    danh_sach1.close();
                                }
                            if(bien_dem_bai_hat == 10)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;



                                        // hiện tên bài hát:
                                        setcolor(LIGHTCYAN);
                                        settextstyle(9,0,2);
                                        outtextxy(1220,390,ch);

                                        //nut next
                                        readimagefile("file_anh/nextbutton.jpg",1400,700,1450,750);

                                        setcolor(LIGHTCYAN);
                                        settextstyle(0,0,5);
                                        outtextxy(1250,710,"3/3");


                                        strcat(ch, nguon);
                                        PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                        // hiện màu vàng cái bảng có bài hát:
                                        setcolor(YELLOW);
                                        setlinestyle(SOLID_LINE,0x1010,2);
                                        rectangle(1210,350,1500,450);

                                        delay(500);
                                        setcolor(CYAN);
                                        setlinestyle(SOLID_LINE,0x1010,2);
                                        rectangle(1210,350,1500,450);

                                        danh_sach1.close();
                                }
                                if(bien_dem_bai_hat == 11)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;


                                        // hiện tên bài hát:
                                        setcolor(LIGHTCYAN);
                                        settextstyle(9,0,2);
                                        outtextxy(1220,490,ch);

                                        //nut next
                                        readimagefile("file_anh/nextbutton.jpg",1400,700,1450,750);

                                        setcolor(LIGHTCYAN);
                                        settextstyle(0,0,5);
                                        outtextxy(1250,710,"3/3");


                                        strcat(ch, nguon);
                                        PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                        // hiện màu vàng cái bảng có bài hát:
                                        setcolor(YELLOW);
                                        setlinestyle(SOLID_LINE,0x1010,2);
                                        rectangle(1210,450,1500,550);

                                        delay(500);
                                        setcolor(CYAN);
                                        setlinestyle(SOLID_LINE,0x1010,2);
                                        rectangle(1210,450,1500,550);

                                        danh_sach1.close();
                                }
                                if(bien_dem_bai_hat == 12)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;



                                        // hiện tên bài hát:
                                        setcolor(LIGHTCYAN);
                                        settextstyle(9,0,2);
                                        outtextxy(1220,590,ch);

                                        //nut next
                                        readimagefile("file_anh/nextbutton.jpg",1400,700,1450,750);

                                        setcolor(LIGHTCYAN);
                                        settextstyle(0,0,5);
                                        outtextxy(1250,710,"3/3");


                                        strcat(ch, nguon);
                                        PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                        // hiện màu vàng cái bảng có bài hát:
                                        setcolor(YELLOW);
                                        setlinestyle(SOLID_LINE,0x1010,2);
                                        rectangle(1210,550,1500,650);

                                        delay(500);
                                        setcolor(CYAN);
                                        setlinestyle(SOLID_LINE,0x1010,2);
                                        rectangle(1210,550,1500,650);

                                        // che đi dòng chữ (quá giới hạn bài hát cho phép):
                                        settextstyle(5,0,3);
                                        outtextxy(370,340, "                                 ");
                                        outtextxy(390,370, "                                 ");
                                        outtextxy(360,400, "                                 ");
                                        outtextxy(340,400, "                                    ");

                                        danh_sach1.close();
                                }

                                // câu lệnh kết thúc:
                                if(bien_dem_bai_hat > 12)
                                {
                                        settextstyle(5,0,3);
                                        outtextxy(370,340, "                                 ");
                                        outtextxy(390,370, "                                 ");
                                        outtextxy(360,400, "                                 ");
                                        outtextxy(340,400, "   Da qua gioi han bai hat cho phep     ");
                                }
                                cout<<"dang chay bai hat so: "<<bien_dem_bai_hat<<endl;
                                break;

                        // nút chuyển lại bài hát:
                        case key_A:

                            bien_dem_bai_hat--;
                            // ĐIỀU KIỆN ĐỂ KHÔNG BẤM BÀI HÁT NỮA:
                            if(bien_dem_bai_hat < 1)
                                {
                                    settextstyle(5,0,3);
                                        outtextxy(370,340, "                                 ");
                                        outtextxy(390,370, "                                 ");
                                        outtextxy(360,400, "                                 ");
                                        outtextxy(340,400, "   Da qua gioi han bai hat cho phep     ");
                                }

                            if(bien_dem_bai_hat == 1)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;

                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,290,ch);

                                    //nut next
                                    readimagefile("nextbutton.jpg",1400,700,1450,750);

                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"1/3");


                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);


                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,250,1500,350);

                                    // chuyển lại màu bình thường khi bấm xong:
                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,250,1500,350);

                                    // che đi dòng chữ (quá giới hạn bài hát cho phép):
                                        settextstyle(5,0,3);
                                        outtextxy(370,340, "                                 ");
                                        outtextxy(390,370, "                                 ");
                                        outtextxy(360,400, "                                 ");
                                        outtextxy(340,400, "                                    ");

                                    danh_sach1.close();

                                }
                            if(bien_dem_bai_hat == 2)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;


                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,390,ch);

                                    //nut next
                                    readimagefile("nextbutton.jpg",1400,700,1450,750);

                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"1/3");


                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);


                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,350,1500,450);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,350,1500,450);



                                    danh_sach1.close();
                                }
                            if(bien_dem_bai_hat == 3)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;

                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,490,ch);

                                    //nut next
                                    readimagefile("nextbutton.jpg",1400,700,1450,750);

                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"1/3");


                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,450,1500,550);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,450,1500,550);


                                    danh_sach1.close();
                                }
                            if(bien_dem_bai_hat == 4)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;

                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,590,ch);

                                    //nut next
                                    readimagefile("nextbutton.jpg",1400,700,1450,750);

                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"1/3");


                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,550,1500,650);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,550,1500,650);


                                    danh_sach1.close();
                                }
                            if(bien_dem_bai_hat == 5)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;

                                    // chèn ảnh lên 1 lần nữa khi chuyển sang trang thứ 2:
                                    //readimagefile("bancutback1.jpg",720,0,1,800);

                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,290,ch);

                                    //nut next
                                    readimagefile("nextbutton.jpg",1400,700,1450,750);

                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"2/3");


                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,250,1500,350);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,250,1500,350);

                                    // che đi dòng chữ (endless_love) khi khách hàng ấn phím s:
                                        settextstyle(5,0,3);
                                        outtextxy(370,340, "                                 ");
                                        outtextxy(390,370, "                                 ");
                                        outtextxy(360,400, "                                 ");
                                        outtextxy(340,400, "                                     ");


                                    danh_sach1.close();
                                }

                            if(bien_dem_bai_hat == 6)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;



                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,390,ch);


                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"2/3");



                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,350,1500,450);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,350,1500,450);


                                    danh_sach1.close();
                                }
                            if(bien_dem_bai_hat == 7)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;



                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,490,ch);

                                    //nut next
                                    readimagefile("nextbutton.jpg",1400,700,1450,750);

                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"2/3");



                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,450,1500,550);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,450,1500,550);

                                    // che đi dòng chữ (endless_love) khi khách hàng ấn phím s:
                                        settextstyle(5,0,3);
                                        outtextxy(370,340, "                                 ");
                                        outtextxy(390,370, "                                 ");
                                        outtextxy(360,400, "                                 ");
                                        outtextxy(340,400, "                                     ");


                                    danh_sach1.close();
                                }
                            if(bien_dem_bai_hat == 8)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;



                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,590,ch);

                                    //nut next
                                    readimagefile("nextbutton.jpg",1400,700,1450,750);

                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"2/3");



                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,550,1500,650);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,550,1500,650);


                                    danh_sach1.close();
                                }
                            if(bien_dem_bai_hat == 9)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;
                                    danh_sach1>>ch;

                                    // chèn ảnh lên 1 lần nữa khi chuyển sang trang thứ 2:
                                    //readimagefile("back1.jpg", 0,0,1500,1100);

                                    // hiện tên bài hát:
                                    setcolor(LIGHTCYAN);
                                    settextstyle(9,0,2);
                                    outtextxy(1220,290,ch);

                                    //nut next
                                    readimagefile("nextbutton.jpg",1400,700,1450,750);

                                    setcolor(LIGHTCYAN);
                                    settextstyle(0,0,5);
                                    outtextxy(1250,710,"3/3");




                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    // hiện màu vàng cái bảng có bài hát:
                                    setcolor(YELLOW);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,250,1500,350);

                                    delay(500);
                                    setcolor(CYAN);
                                    setlinestyle(SOLID_LINE,0x1010,2);
                                    rectangle(1210,250,1500,350);


                                    danh_sach1.close();
                                }
                            if(bien_dem_bai_hat == 10)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;



                                        // hiện tên bài hát:
                                        setcolor(LIGHTCYAN);
                                        settextstyle(9,0,2);
                                        outtextxy(1220,390,ch);

                                        //nut next
                                        readimagefile("nextbutton.jpg",1400,700,1450,750);

                                        setcolor(LIGHTCYAN);
                                        settextstyle(0,0,5);
                                        outtextxy(1250,710,"3/3");


                                        strcat(ch, nguon);
                                        PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                        // hiện màu vàng cái bảng có bài hát:
                                        setcolor(YELLOW);
                                        setlinestyle(SOLID_LINE,0x1010,2);
                                        rectangle(1210,350,1500,450);

                                        delay(500);
                                        setcolor(CYAN);
                                        setlinestyle(SOLID_LINE,0x1010,2);
                                        rectangle(1210,350,1500,450);

                                        danh_sach1.close();
                                }
                                if(bien_dem_bai_hat == 11)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;


                                        // hiện tên bài hát:
                                        setcolor(LIGHTCYAN);
                                        settextstyle(9,0,2);
                                        outtextxy(1220,490,ch);

                                        //nut next
                                        readimagefile("nextbutton.jpg",1400,700,1450,750);

                                        setcolor(LIGHTCYAN);
                                        settextstyle(0,0,5);
                                        outtextxy(1250,710,"3/3");


                                        strcat(ch, nguon);
                                        PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                        // hiện màu vàng cái bảng có bài hát:
                                        setcolor(YELLOW);
                                        setlinestyle(SOLID_LINE,0x1010,2);
                                        rectangle(1210,450,1500,550);

                                        delay(500);
                                        setcolor(CYAN);
                                        setlinestyle(SOLID_LINE,0x1010,2);
                                        rectangle(1210,450,1500,550);

                                        danh_sach1.close();
                                }
                                if(bien_dem_bai_hat == 12)
                                {
                                    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;
                                        danh_sach1>>ch;



                                        // hiện tên bài hát:
                                        setcolor(LIGHTCYAN);
                                        settextstyle(9,0,2);
                                        outtextxy(1220,590,ch);

                                        //nut next
                                        readimagefile("nextbutton.jpg",1400,700,1450,750);

                                        setcolor(LIGHTCYAN);
                                        settextstyle(0,0,5);
                                        outtextxy(1250,710,"3/3");


                                        strcat(ch, nguon);
                                        PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                        // hiện màu vàng cái bảng có bài hát:
                                        setcolor(YELLOW);
                                        setlinestyle(SOLID_LINE,0x1010,2);
                                        rectangle(1210,550,1500,650);

                                        delay(500);
                                        setcolor(CYAN);
                                        setlinestyle(SOLID_LINE,0x1010,2);
                                        rectangle(1210,550,1500,650);

                                        // che đi dòng chữ (quá giới hạn bài hát cho phép):
                                        settextstyle(5,0,3);
                                        outtextxy(370,340, "                                 ");
                                        outtextxy(390,370, "                                 ");
                                        outtextxy(360,400, "                                 ");
                                        outtextxy(340,400, "                                    ");

                                        danh_sach1.close();
                                }

                                // câu lệnh kết thúc:
                                if(bien_dem_bai_hat > 12)
                                {
                                        settextstyle(5,0,3);
                                        outtextxy(370,340, "                                 ");
                                        outtextxy(390,370, "                                 ");
                                        outtextxy(360,400, "                                 ");
                                        outtextxy(340,400, "   Da qua gioi han bai hat cho phep     ");
                                }
                                cout<<"dang chay bai hat so: "<<bien_dem_bai_hat<<endl;
                                break;

                                // nút dừng bài hát:
                            case key_D: //(x >= 600 && x <= 630 && y >= 450 && y <= 480)

                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                       ");
                                    outtextxy(320,370, "           Ban da an nut pause         ");
                                    outtextxy(320,400, "           Da dung bat bai hat         ");
                                    PlaySound(TEXT("turn_off_music.wav"), GetModuleHandle(NULL),SND_FILENAME | SND_ASYNC | SND_ASYNC);


                    // phần đánh các nốt trên đàn:
                   case key_q: // '113' key_q

                        // ĐÔ
                        Beep(264,290);

                        // gọi lại vẽ các phím 1 lần nữa để hiện màu vàng:
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(80,500,180,700);


                        settextstyle(1,0,2);
                        setcolor(14);

                        outtextxy(110,620,"Do");
                        outtextxy(110,660,"Q");
                        /* phải gọi cả phím đen vì khi sử dụng thì màu vàng theo tọa độ
                        sẽ chèn lên phím đen luôn.*/



                        setfillstyle(SOLID_FILL,BLACK);
                        bar(160,500,200,600);

                        // dù ấn vào xong nhưng vẫn phải giữ cái nút đen:
                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");

                        delay(100);
                        // sau delay thì gọi để trở lại phím ban đầu.
                        // PHÍM TRẮNG BAN ĐẦU
                        setfillstyle(SOLID_FILL, WHITE);
                        bar(80,500,180,700);
                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(110,620,"Do");
                        outtextxy(110,660,"Q");

                        // NỐT ĐÔ THĂNG BAN ĐẦU
                        setfillstyle(SOLID_FILL,BLACK);
                        bar(160,500,200,600);

                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");

                        break;

                    case key_w: // key_w '119'

                        Beep(297,290);

                         // gọi lại vẽ các phím 1 lần nữa
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(180,500,280,700);


                        settextstyle(1,0,2);
                        setcolor(14);

                        outtextxy(210,620,"Re");
                        outtextxy(205,660,"W");
                        /* phải gọi cả phím đen vì khi sử dụng thì màu vàng theo tọa độ
                        sẽ chèn lên phím đen luôn.*/


                        setfillstyle(SOLID_FILL,BLACK);
                        bar(260,500,300,600);

                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");

                        delay(100);
                        // sau delay thì gọi để trở lại phím ban đầu.
                        // PHÍM TRẮNG BAN ĐẦU


                        setfillstyle(SOLID_FILL, WHITE);
                        bar(180,500,280,700);
                        settextstyle(1,0,2);
                        setcolor(13);
                        outtextxy(210,620,"Re");
                        outtextxy(205,660,"W");

                        // NỐT ĐÔ THĂNG BAN ĐẦU
                        setfillstyle(SOLID_FILL,BLACK);

                        // line ban đầu:
                        setcolor(0);
                        setlinestyle(SOLID_LINE,0x1010,1);
                        line(180,500,180,700);

                        // NỐT ĐÔ THĂNG
                        bar(160,500,200,600);

                        // NỐT RÊ THĂNG
                        bar(260,500,300,600);

                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");

                        break;

                    case key_e: // key_e '101'

                        // mi
                        Beep(330,290);

                        // gọi lại vẽ các phím 1 lần nữa
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(280,500,380,700);
                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(310,620,"Mi");
                        outtextxy(315,660,"E");

                        // NỐT RE THĂNG
                        setfillstyle(SOLID_FILL,BLACK);
                        bar(260,500,300,600);

                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");

                        delay(100); // sử dụng delay(500)



                        setfillstyle(SOLID_FILL, WHITE);
                        bar(280,500,380,700);

                        // NỐT RE THĂNG
                        setfillstyle(SOLID_FILL,BLACK);
                        bar(260,500,300,600);

                        settextstyle(1,0,2);
                        setcolor(12);
                        outtextxy(310,620,"Mi");
                        outtextxy(315,660,"E");
                        //set lai line
                        setcolor(BLACK);
                        line(380,500,380,700);
                        line(280,500,280,700);

                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");



                        break;
                    case key_r:

                        // pha
                        Beep(352,290);

                        // gọi lại vẽ các phím 1 lần nữa
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(380,500,480,700);
                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(400,620,"Pha");
                        outtextxy(415,660,"R");

                        // NỐT Pha THĂNG
                        setfillstyle(SOLID_FILL,BLACK);
                        bar(460,500,500,600);
                        delay(100); // sử dụng delay(500)
                        setfillstyle(SOLID_FILL, WHITE);
                        bar(380,500,480,700);
                        setfillstyle(SOLID_FILL,BLACK);
                        // NỐT Pha THĂNG
                        bar(460,500,500,600);
                        settextstyle(1,0,2);
                        setcolor(11);
                        outtextxy(400,620,"Pha");
                        outtextxy(415,660,"R");
                        //set lai line
                        setcolor(BLACK);
                        line(380,500,380,700);
                        line(480,500,480,700);

                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");

                        break;
                    case key_t:

                        // son
                        Beep(390,290);

                        // gọi lại vẽ các phím 1 lần nữa
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(480,500,580,700);
                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(500,620,"Son");
                        outtextxy(515,660,"T");

                        // NỐT Son THĂNG
                        setfillstyle(SOLID_FILL,BLACK);
                        bar(560,500,600,600);
                        // NỐT PHA THĂNG
                        bar(460,500,500,600);

                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");

                        delay(100); // sử dụng delay(500)


                        setfillstyle(SOLID_FILL, WHITE);
                        bar(480,500,580,700);


                        // NỐT PHA THĂNG
                        setfillstyle(SOLID_FILL,BLACK);
                        bar(460,500,500,600);

                        // NỐT Son THĂNG
                        bar(560,500,600,600);
                        settextstyle(1,0,2);
                        setcolor(10);
                        outtextxy(500,620,"Son");
                        outtextxy(515,660,"T");


                        //set lai line
                        setcolor(BLACK);
                        line(580,500,580,700);
                        line(480,500,480,700);

                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");



                        break;
                    case key_y:

                        // la
                        Beep(440,290);

                        // gọi lại vẽ các phím 1 lần nữa
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(580,500,680,700);
                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(610,620,"La");
                        outtextxy(610,660,"Y");


                        setfillstyle(SOLID_FILL,BLACK);

                        // NỐT La THĂNG
                        bar(660,500,700,600);

                        // NỐT Son THĂNG
                        bar(560,500,600,600);

                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");



                        delay(100); // sử dụng delay(500)
                        setfillstyle(SOLID_FILL, WHITE);
                        bar(580,500,680,700);
                        setfillstyle(SOLID_FILL,BLACK);

                        // NỐT Son THĂNG
                        bar(560,500,600,600);


                        // NỐT La THĂNG
                        bar(660,500,700,600);

                        settextstyle(1,0,2);
                        setcolor(9);
                        outtextxy(610,620,"La");
                        outtextxy(610,660,"Y");


                        //set lai line
                        setcolor(BLACK);
                        line(580,500,580,700);
                        line(680,500,680,700);

                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");

                        break;
                    case key_u:

                        // Si
                        Beep(495,290);

                        // gọi lại vẽ các phím 1 lần nữa
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(680,500,780,700);
                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(715,620,"Si");
                        outtextxy(710,660,"U");


                        setfillstyle(SOLID_FILL,BLACK);

                        // NỐT La THĂNG
                        bar(660,500,700,600);

                        delay(100); // sử dụng delay(500)
                        setfillstyle(SOLID_FILL, WHITE);
                        bar(680,500,780,700);

                        // NỐT La THĂNG
                        setfillstyle(SOLID_FILL, BLACK);
                        bar(660,500,700,600);

                        settextstyle(1,0,2);
                        setcolor(8);
                        outtextxy(715,620,"Si");
                        outtextxy(710,660,"U");

                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");


                        //set lai line
                        setcolor(BLACK);
                        line(780,500,780,700);
                        line(680,500,680,700);

                        break;
                    case key_i:

                        // do cao
                        Beep(528,290);

                        // gọi lại vẽ các phím 1 lần nữa
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(780,500,880,700);
                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(810,620,"Do");
                        outtextxy(820,660,"I");


                        // NỐT Do cao THĂNG
                        setfillstyle(SOLID_FILL,BLACK);
                        bar(860,500,900,600);

                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");


                        delay(100); // sử dụng delay(500)


                        setfillstyle(SOLID_FILL, WHITE);
                        bar(780,500,880,700);
                        setfillstyle(SOLID_FILL,BLACK);
                        // NỐT Do cao THĂNG
                        bar(860,500,900,600);
                        settextstyle(1,0,2);
                        setcolor(7);
                        outtextxy(810,620,"Do");
                        outtextxy(820,660,"I");

                        //set lai line
                        setcolor(BLACK);
                        line(780,500,780,700);
                        line(880,500,880,700);

                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");

                        break;
                    case key_o:

                        // re cao
                        Beep(594,290);

                        // gọi lại vẽ các phím 1 lần nữa
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(880,500,980,700);
                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(910,620,"Re");
                        outtextxy(910,660,"O");


                        // NỐT RE THĂNG
                        setfillstyle(SOLID_FILL,BLACK);
                        bar(960,500,1000,600);

                        //not Do Thang
                        bar(860,500,900,600);

                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");

                        delay(100); // sử dụng delay(500)


                        setfillstyle(SOLID_FILL, WHITE);
                        bar(880,500,980,700);
                        setfillstyle(SOLID_FILL,BLACK);

                        //not Do Thang
                        bar(860,500,900,600);

                        // NỐT RE THĂNG
                        bar(960,500,1000,600);

                        //set lai phim trang
                        settextstyle(1,0,2);
                        setcolor(6);
                        outtextxy(910,620,"Re");
                        outtextxy(910,660,"O");

                        //set lai line
                        setcolor(BLACK);
                        line(980,500,980,700);
                        line(880,500,880,700);

                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");

                        break;
                    case key_p:

                        // mi cao
                        Beep(660,290);

                        // gọi lại vẽ các phím 1 lần nữa
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(980,500,1080,700);
                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(1010,620,"Mi");
                        outtextxy(1015,660,"P");

                        setfillstyle(SOLID_FILL,BLACK);

                        // NỐT RE THĂNG
                        bar(960,500,1000,600);

                        delay(100); // sử dụng delay(500)
                        setfillstyle(SOLID_FILL, WHITE);
                        bar(980,500,1080,700);

                        // NỐT RE THĂNG
                        setfillstyle(SOLID_FILL,BLACK);
                        bar(960,500,1000,600);

                        settextstyle(1,0,2);
                        setcolor(5);
                        outtextxy(1010,620,"Mi");
                        outtextxy(1015,660,"P");


                        //set lai line
                        setcolor(BLACK);
                        line(980,500,980,700);

                        // ĐIỀN CÁC SỐ Ở NỐT ĐEN:
                        // nốt đô thăng
                        setcolor(14);
                        outtextxy(170,560,"2");
                        // nốt rê thăng
                        outtextxy(270,560,"3");
                        // nốt pha thăng
                        outtextxy(470,560,"5");
                        // nốt son thăng
                        outtextxy(570,560,"6");
                        // nốt la thăng
                        outtextxy(670,560,"7");
                        // nốt đô thăng
                        outtextxy(870,560,"9");
                        // nốt rê thăng
                        outtextxy(970,560,"0");



                        break;
                    case KEY_2:

                        // do thang
                        Beep(281,300);

                        // gọi lại vẽ các phím 1 lần nữa
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(160,500,200,600);

                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(170,560,"2");


                        delay(100); // sử dụng delay(100)

                        setfillstyle(SOLID_FILL, BLACK);
                        bar(160,500,200,600);

                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(170,560,"2");



                        break;
                    case KEY_3:

                        // re thang
                        Beep(313,300);

                        // gọi lại vẽ các phím 1 lần nữa
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(260,500,300,600);

                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(270,560,"3");

                        delay(100);
                        setfillstyle(SOLID_FILL,BLACK);
                        bar(260,500,300,600);

                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(270,560,"3");


                        break;
                    case KEY_5:

                        // pha thang
                        Beep(374,300);

                        // gọi lại vẽ các phím 1 lần nữa
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(460,500,500,600);

                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(470,560,"5");

                        delay(100);
                        setfillstyle(SOLID_FILL,BLACK);
                        bar(460,500,500,600);


                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(470,560,"5");



                        break;
                    case KEY_6:

                        // son thang
                        Beep(415,300);

                        // gọi lại vẽ các phím 1 lần nữa
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(560,500,600,600);

                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(570,560,"6");

                        delay(100);
                        setfillstyle(SOLID_FILL,BLACK);
                        bar(560,500,600,600);


                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(570,560,"6");



                        break;
                    case KEY_7:

                        // la thang
                        Beep(468,300);

                        // gọi lại vẽ các phím 1 lần nữa
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(660,500,700,600);

                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(670,560,"7");

                        delay(100);
                        setfillstyle(SOLID_FILL,BLACK);
                        bar(660,500,700,600);

                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(670,560,"7");



                        break;
                    case KEY_9:

                        // do cao thang
                        Beep(565,300);

                        // gọi lại vẽ các phím 1 lần nữa
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(860,500,900,600);
                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(870,560,"9");

                        delay(100);
                        setfillstyle(SOLID_FILL,BLACK);
                        bar(860,500,900,600);

                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(870,560,"9");



                        break;
                    case KEY_0:

                        // re cao thang
                        Beep(625,300);

                        // gọi lại vẽ các phím 1 lần nữa
                        setfillstyle(SOLID_FILL,YELLOW);
                        bar(960,500,1000,600);
                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(970,560,"0");

                        delay(100);
                        setfillstyle(SOLID_FILL,BLACK);
                        bar(960,500,1000,600);

                        settextstyle(1,0,2);
                        setcolor(14);
                        outtextxy(970,560,"0");
                    default:
                        //cout<< '\007';
                        break;
                } // dau switch

        }// dau while



}
#endif // CHAY_PHIM_DAN_H_INCLUDED
