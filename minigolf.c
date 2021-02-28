#include <allegro.h>
volatile int sc=0;int gl=0,dx,dy,dd,rl,points=0,lives=2;fixed x,y,ang;void 
sc_add(){sc++;}int re(int m,int a){return rand()%(a+1-m)+m;}void iv(){rl=0;x=
itofix(re(10,310));y=itofix(re(10,230));dx=re(20,300);dy=re(20,180);dd=re(5,15);
ang=itofix(re(0,255));}void main(){BITMAP *d;allegro_init();install_keyboard();
install_timer();set_gfx_mode(GFX_AUTODETECT,320,240,0,0);install_int_ex(sc_add,
BPS_TO_TIMER(60));d=create_bitmap(320,240);ang=itofix(0);srand(time(0));start:
text_mode(-1);while(!key[KEY_ENTER]){if(key[KEY_ESC]){fade_out(10);allegro_exit(
);exit(0);}clear_to_color(d,191);textprintf_centre(d,font,162,122,16,"MiniGolf")
;textprintf_centre(d,font,160,120,255,"MiniGolf");textprintf_right(d,font,320,
230,255,"Hiscore: %d",get_config_int("hs","s",20));draw_sprite(screen,d,0,0);}iv
();gl=0;while(1){while(sc>0){if(key[KEY_ESC]){goto start;}if(!rl){if(key[
KEY_LEFT]){if(key[KEY_RSHIFT]){ang-=ftofix(0.25);}else{ang-=itofix(1.5);}}if(key
[KEY_RIGHT]){if(key[KEY_RSHIFT]){ang+=ftofix(0.25);}else{ang+=itofix(1.5);}}if(
key[KEY_SPACE]){rl=1;}}else{x+=fmul(itofix(2),fcos(ang));y+=fmul(itofix(2),fsin(
ang));if(fixtoi(x)>=dx-dd/2&&fixtoi(x)<=dx+dd/2&&fixtoi(y)>=dy-dd/2&&fixtoi(y)<=
dy+dd/2){iv();points+=10;gl++;}if(fixtoi(x)<-5||fixtoi(y)<-5||fixtoi(x)>325||
fixtoi(y)>245){iv();lives--;if(lives==-1){if(points>get_config_int("hs","s",0)){
set_config_int("hs","s",points);}lives=2;points=0;goto start;}}}if(gl==10){lives
++;gl=0;}sc--;}clear_to_color(d,191);circlefill(d,dx,dy,dd,16);if(!rl){line(d,
fixtoi(x),fixtoi(y),fixtoi(x+30*fcos(ang)),fixtoi(y+30*fsin(ang)),104);}
circlefill(d,fixtoi(x),fixtoi(y),4,255);textprintf(d,font,0,230,255,
"Lives: %d Points: %d",lives,points);draw_sprite(screen,d,0,0);}}END_OF_MAIN();
