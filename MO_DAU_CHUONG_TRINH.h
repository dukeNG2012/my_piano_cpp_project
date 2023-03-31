#ifndef MO_DAU_CHUONG_TRINH_H_INCLUDED
#define MO_DAU_CHUONG_TRINH_H_INCLUDED
void ham_loi_chao_va_loading_chuong_trinh()
{

    //phan loading
for(int  a=0;a<1250;a=a+30)
    {
        readimagefile("file_anh/chaomungbandenvoichuongtrinh.jpg",a-1000,220,a,350); //1500,300
        setfillstyle(SOLID_FILL,BLACK);
        bar(a-2100,220,a-1000,350);

        readimagefile("file_anh/mophongnhaccu.jpg",200,380,1300,700);
        bar(190,300+(a/2),1310,710);

        delay(1);
    }


	settextstyle(6,0,4);
	setcolor(YELLOW);
	outtextxy(350,750, "- AN MOT PHIM BAT KY DE BAT DAU -");

    getch();
	cleardevice();



	//backloading
    readimagefile("file_anh/backloading.jpg",0,0,1500,1100);

    // hình chữ nhật của loading
    setfillstyle(SOLID_FILL,WHITE);
    bar(290,340,1110,410);

    //ham chay thanh loading
    int i=50;
    for(int j =0 ; j < 800; j=j+5)
	{
	    //setlinestyle(SOLID_LINE,0x1010,7);
        setcolor(i++);
		line(300+j,350,300+j,400);
        line(301+j,350,301+j,400);
        line(302+j,350,302+j,400);
        line(303+j,350,303+j,400);
        line(304+j,350,304+j,400);
        delay(2);
	}
	 cleardevice();
}

void ham_ve_bang_ten()
{

    setfillstyle(SOLID_FILL,15);
    bar(110,0,120,40);
    bar(390,0,400,40);

    setfillstyle(SOLID_FILL,0);
    bar(10,20,500,270);
    setlinestyle(0,0x1010,10);

    //cai vien mau xanh xanh to to
    setcolor(3);
    rectangle(10,20,500,270);
}
void ham_dat_ten_va_lop()
{

    settextstyle(10,0,4);
    outtextxy(90,40,"-Nguyen Minh Duc");
    outtextxy(90,80,"21021292");
    outtextxy(90,120,"-Nguyen Duc Long");
    outtextxy(90,160,"21021336");
    setcolor(11);
    settextstyle(10,0,6);
    outtextxy(45,200,"  INT1008-20");
}

#endif // MO_DAU_CHUONG_TRINH_H_INCLUDED
