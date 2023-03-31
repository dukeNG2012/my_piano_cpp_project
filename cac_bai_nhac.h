#ifndef CAC_BAI_NHAC_H_INCLUDED
#define CAC_BAI_NHAC_H_INCLUDED
#include <fstream>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

void chay_nhac()
{
    char ch[255];
    char nguon[255] = ".wav";
    int x,y;
    int bien_dem_bai_hat = 0;
    fstream danh_sach1("danh_sach_nhac.txt", ios::in);
    if(!danh_sach1)
    {
        cout<< "\tDANH SACH NHAC CUA BAN KHONG TON TAI!"<<endl;
        exit(1);
    }
    fstream danh_sach2("danh_sach_nhac.txt", ios::in);
    fstream danh_sach3("danh_sach_nhac.txt", ios::in);
    fstream danh_sach4("danh_sach_nhac.txt", ios::in);
    fstream danh_sach5("danh_sach_nhac.txt", ios::in);
    fstream danh_sach6("danh_sach_nhac.txt", ios::in);
    fstream danh_sach7("danh_sach_nhac.txt", ios::in);
    fstream danh_sach8("danh_sach_nhac.txt", ios::in);
    fstream danh_sach9("danh_sach_nhac.txt", ios::in);
    fstream danh_sach10("danh_sach_nhac.txt", ios::in);

        delay(0.000002);
        if(ismouseclick(WM_LBUTTONUP))
                {
                        getmouseclick(WM_LBUTTONUP, x, y);
                            // nút bật bài hát:
                        if(x >= 520 && x <= 550 && y >= 450 && y <= 480)
                            {
                                bien_dem_bai_hat = 6;
                                settextstyle(5,0,3);
                                outtextxy(320,340, "                                       ");
                                outtextxy(320,370, "           Dang bat bai hat:           ");
                                outtextxy(320,400, "            ");
                                outtextxy(480,400, "   endless_love             ");
                                outtextxy(670,400, "         ");
                                PlaySound(TEXT("endless_love.wav"), GetModuleHandle(NULL),SND_FILENAME | SND_ASYNC | SND_LOOP);
                            }
                            // nút chuyển bài tiếp theo:
                        if(x >= 680 && x <= 710 && y >= 450 && y <= 480)
                            {
                                bien_dem_bai_hat++;
                                if(bien_dem_bai_hat == 1)
                                {
                                    danh_sach1>>ch;
                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }
                                if(bien_dem_bai_hat == 2)
                                {
                                    danh_sach1>>ch;
                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }
                                if(bien_dem_bai_hat == 3)
                                {
                                    danh_sach1>>ch;

                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }
                                if(bien_dem_bai_hat == 4)
                                {
                                    danh_sach1>>ch;

                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }
                                if(bien_dem_bai_hat == 5)
                                {
                                    danh_sach1>>ch;

                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }

                                if(bien_dem_bai_hat == 6)
                                {
                                    danh_sach1>>ch;

                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }
                                if(bien_dem_bai_hat == 7)
                                {
                                    danh_sach1>>ch;

                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }
                                if(bien_dem_bai_hat == 8)
                                {
                                    danh_sach1>>ch;

                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT("nang_am_xa_dan.wav"), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }
                                if(bien_dem_bai_hat == 9)
                                    {
                                        danh_sach1>>ch;

                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    }
                                if(bien_dem_bai_hat == 10)
                                {
                                        danh_sach1>>ch;

                                        settextstyle(5,0,3);
                                        outtextxy(320,340, "                                      ");
                                        outtextxy(320,370, "           Dang bat bai hat:          ");
                                        outtextxy(320,400, "             ");
                                        outtextxy(480,400,ch);
                                        outtextxy(660,400, "           ");
                                        strcat(ch, nguon);
                                        PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }
                                cout<<bien_dem_bai_hat<<endl;
                            }
                            // nút chuyển lại bài hát:
                        if(x >= 440 && x <= 470 && y >= 450 && y <= 480)
                            {
                                bien_dem_bai_hat--;
                                if(bien_dem_bai_hat == 1)
                                {
                                    danh_sach1>>ch;

                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }
                                if(bien_dem_bai_hat == 2)
                                {
                                    danh_sach2>>ch;
                                    danh_sach2>>ch;

                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }
                                if(bien_dem_bai_hat == 3)
                                {
                                    danh_sach3>>ch;
                                    danh_sach3>>ch;
                                    danh_sach3>>ch;

                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }
                                if(bien_dem_bai_hat == 4)
                                {
                                    danh_sach4>>ch;
                                    danh_sach4>>ch;
                                    danh_sach4>>ch;
                                    danh_sach4>>ch;
                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }
                                if(bien_dem_bai_hat == 5)
                                {
                                    danh_sach5>>ch;
                                    danh_sach5>>ch;
                                    danh_sach5>>ch;
                                    danh_sach5>>ch;
                                    danh_sach5>>ch;
                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }

                                if(bien_dem_bai_hat == 6)
                                {
                                    danh_sach6>>ch;
                                    danh_sach6>>ch;
                                    danh_sach6>>ch;
                                    danh_sach6>>ch;
                                    danh_sach6>>ch;
                                    danh_sach6>>ch;

                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }
                                if(bien_dem_bai_hat == 7)
                                {
                                    danh_sach7>>ch;
                                    danh_sach7>>ch;
                                    danh_sach7>>ch;
                                    danh_sach7>>ch;
                                    danh_sach7>>ch;
                                    danh_sach7>>ch;
                                    danh_sach7>>ch;

                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }
                                if(bien_dem_bai_hat == 8)
                                {
                                    danh_sach8>>ch;
                                    danh_sach8>>ch;
                                    danh_sach8>>ch;
                                    danh_sach8>>ch;
                                    danh_sach8>>ch;
                                    danh_sach8>>ch;
                                    danh_sach8>>ch;
                                    danh_sach8>>ch;

                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT("nang_am_xa_dan.wav"), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }
                                if(bien_dem_bai_hat == 9)
                                    {
                                        danh_sach9>>ch;
                                    danh_sach9>>ch;
                                    danh_sach9>>ch;
                                    danh_sach9>>ch;
                                    danh_sach9>>ch;
                                    danh_sach9>>ch;
                                    danh_sach9>>ch;
                                    danh_sach9>>ch;
                                    danh_sach9>>ch;

                                    settextstyle(5,0,3);
                                    outtextxy(320,340, "                                      ");
                                    outtextxy(320,370, "           Dang bat bai hat:          ");
                                    outtextxy(320,400, "             ");
                                    outtextxy(480,400,ch);
                                    outtextxy(660,400, "           ");
                                    strcat(ch, nguon);
                                    PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                    }
                                if(bien_dem_bai_hat == 10)
                                {
                                        danh_sach10>>ch;
                                        danh_sach10>>ch;
                                        danh_sach10>>ch;
                                        danh_sach10>>ch;
                                        danh_sach10>>ch;
                                        danh_sach10>>ch;
                                        danh_sach10>>ch;
                                        danh_sach10>>ch;
                                        danh_sach10>>ch;
                                        danh_sach10>>ch;

                                        settextstyle(5,0,3);
                                        outtextxy(320,340, "                                      ");
                                        outtextxy(320,370, "           Dang bat bai hat:          ");
                                        outtextxy(320,400, "             ");
                                        outtextxy(480,400,ch);
                                        outtextxy(660,400, "           ");
                                        strcat(ch, nguon);
                                        PlaySound(TEXT(ch), GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);

                                }
                                cout<<bien_dem_bai_hat<<endl;
                            }
                // nút dừng bài hát:
                        if(x >= 600 && x <= 630 && y >= 450 && y <= 480)
                            {
                                settextstyle(5,0,3);
                                outtextxy(320,340, "                                       ");
                                outtextxy(320,370, "           Ban da an nut pause         ");
                                outtextxy(320,400, "           Da dung bat bai hat         ");
                                PlaySound(TEXT("turn_off_music.wav"), GetModuleHandle(NULL),
                                SND_FILENAME | SND_ASYNC | SND_ASYNC);
                            }
                }

}



#endif // CAC_BAI_NHAC_H_INCLUDED
