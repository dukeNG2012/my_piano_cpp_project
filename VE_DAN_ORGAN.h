#ifndef VE_DAN_ORGAN_H_INCLUDED
#define VE_DAN_ORGAN_H_INCLUDED
void ham_background()
{
    readimagefile("file_anh/back1.jpg",0,0,1500,1100);
}
void ham_ve_trong()
{
    setcolor(15);
    setlinestyle(SOLID_LINE,0x1010,7);
    //chan trong ben trai
    setfillstyle(SOLID_FILL,15);
    bar(693,200,697,400);
    line(695,250,595,500);
    line(695,250,795,500);
    //chan trong ben phai
    bar(993,200,997,400);
    line(995,250,895,500);
    line(995,250,1095,500);
    //set lai line
    setcolor(0);
    setlinestyle(SOLID_LINE,0x1010,1);
    //than trong ben trai
    setfillstyle(SOLID_FILL,8);
    fillellipse(695,200,135,68);
    bar(560,100,830,200);
    //than trong ben phai
    setfillstyle(SOLID_FILL,8);
    fillellipse(995,200,135,68);
    bar(860,100,1130,200);
    //vien trong trai & phai
    setfillstyle(SOLID_FILL,8);
    fillellipse(695,100,135,68);
    fillellipse(995,100,135,68);
    //mat trong trai & phai
    setfillstyle(SOLID_FILL,15);
    fillellipse(695,100,130,60);
    setfillstyle(SOLID_FILL,7);
    fillellipse(995,100,130,60);
    //vong tron o giua
    setfillstyle(SOLID_FILL,7);
    fillellipse(695,100,65,20);
    setfillstyle(SOLID_FILL,15);
    fillellipse(995,100,65,20);
}
void ham_ve_dan_organ()
{

    //set mau organ
    setfillstyle(SOLID_FILL,12);
    bar(10,300,1130,700);

    //set vien bao quanh
    setcolor(8);
    setlinestyle(0,0x1010,4);
    rectangle(10,300,1130,700);



    setfillstyle(SOLID_FILL,15);
    //NỐT ĐÔ
    bar(80,500,180,700);
    //NỐT RÊ
    bar(180,500,280,700);
    //NỐT MI
    bar(280,500,380,700);
    //NỐT PHA
    bar(380,500,480,700);
    //NỐT SON
    bar(480,500,580,700);
    //NỐT LA
    bar(580,500,680,700);
    //NỐT SI
    bar(680,500,780,700);
    //NỐT ĐÔ CAO
    bar(780,500,880,700);
    //NỐT RÊ CAO
    bar(880,500,980,700);
    //NỐT MI CAO
    bar(980,500,1080,700);

    //PHÍM ĐEN:
    setfillstyle(SOLID_FILL,BLACK);
    // NỐT ĐÔ THĂNG
    bar(160,500,200,600);

    // NỐT RÊ THĂNG
    bar(260,500,300,600);


    // NỐT PHA THĂNG
    bar(460,500,500,600);


    // NỐT SON THĂNG
    bar(560,500,600,600);


    // NỐT LA THĂNG
    bar(660,500,700,600);


    // NỐT ĐÔ THĂNG
    bar(860,500,900,600);


    // NỐT RÊ THĂNG
    bar(960,500,1000,600);





    //set not nhac
    settextstyle(1,0,2);
    setcolor(14);
    outtextxy(110,620,"Do");
    outtextxy(110,660,"Q");
    setcolor(13);
    outtextxy(210,620,"Re");
    outtextxy(205,660,"W");
    setcolor(12);
    outtextxy(310,620,"Mi");
    outtextxy(315,660,"E");
    setcolor(11);
    outtextxy(400,620,"Pha");
    outtextxy(415,660,"R");
    setcolor(10);
    outtextxy(500,620,"Son");
    outtextxy(515,660,"T");
    setcolor(9);
    outtextxy(610,620,"La");
    outtextxy(610,660,"Y");
    setcolor(8);
    outtextxy(715,620,"Si");
    outtextxy(710,660,"U");
    setcolor(7);
    outtextxy(810,620,"Do");
    outtextxy(820,660,"I");
    setcolor(6);
    outtextxy(910,620,"Re");
    outtextxy(910,660,"O");
    setcolor(5);
    outtextxy(1010,620,"Mi");
    outtextxy(1015,660,"P");

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


    //set vien cua phim trang
    setcolor(0);
    setlinestyle(SOLID_LINE,0x1010,1);
    line(180,500,180,700);
    line(280,500,280,700);
    line(380,500,380,700);
    line(480,500,480,700);
    line(580,500,580,700);
    line(680,500,680,700);
    line(780,500,780,700);
    line(880,500,880,700);
    line(980,500,980,700);

}
void ham_cac_nut_bam_dan()
{
    setfillstyle(SOLID_FILL,7);
    bar(300,320,840,495);
    bar(30,460,1110,495);

    //nut bat dan
    setfillstyle(SOLID_FILL,0);
    circle(60,478,7);
    floodfill(60,478,0);

    //nut chuyen bai
    bar(310,330,830,485);

    //nut play
    setfillstyle(SOLID_FILL,15);
    setcolor(15);
    setlinestyle(SOLID_LINE,0x1010,2);
    line(520,450,520,480);
    line(520,450,550,465);
    line(520,480,550,465);
    floodfill(530,460,15);

    //nut pause
    bar(600,450,610,480);
    bar(620,450,630,480);

    //nut skip
    line(680,450,680,480);
    line(680,450,710,465);
    line(680,480,710,465);
    floodfill(685,455,15);

    line(700,450,700,480);
    line(700,450,730,465);
    line(700,480,730,465);
    floodfill(705,455,15);

    bar(722,450,732,480);

    //nut skip back
    line(470,450,470,480);
    line(440,465,470,450);
    line(440,465,470,480);
    floodfill(465,455,15);

    line(450,450,450,480);
    line(420,465,450,450);
    line(420,465,450,480);
    floodfill(445,455,15);

    bar(429,450,419,480);
}
void ham_loa()
{
    //loa trai
    setfillstyle(SOLID_FILL,8);
    bar(30,320,280,450);
    setfillstyle(SOLID_FILL,0);
    circle(95,385,60);
    floodfill(90,385,0);
    circle(215,385,60);
    floodfill(215,385,0);

    //loa phai
    setfillstyle(SOLID_FILL,8);
    bar(860,320,1110,450);
    setfillstyle(SOLID_FILL,0);
    circle(925,385,60);
    floodfill(925,385,0);
    circle(1045,385,60);
    floodfill(1045,385,0);
}
void ham_thong_bao_tren_man_hinh_dan()
{
    settextstyle(5,0,3);

    outtextxy(370,340, "An phim 'a' de bat che do danh dan");
    outtextxy(390,370, "An phim shift + s de bat nhac");
    outtextxy(360,400, "An phim shift + a de chuyen lai bai hat");
    outtextxy(340,430, "An phim shift + f de chuyen bai tiep theo");
}

#endif // VE_DAN_ORGAN_H_INCLUDED
