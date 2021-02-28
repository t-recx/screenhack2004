#include <allegro.h>
#define I(x, y)if(x){y}
#define E(z)else{z}
#define C(y,z)case y: z break;
#define W(x,y){a, x, y, 60, 60, 255, 0, 0, 0, 0, 0},
int s=0,j[2];int a(int msg,DIALOG *d,int c){switch(msg){C(MSG_DRAW,rect(screen,d
->x,d->y,d->x+d->w,d->y+d->h,d->fg);I(d->d1,I(d->d2,rectfill(screen,d->x+2,d->y+
2,d->x+d->w-2,d->y+d->h-2,d->fg);)E(line(screen,d->x,d->y,d->x+d->w,d->y+d->h,d
->fg);line(screen,d->x,d->y+d->h,d->x+d->w,d->y,d->fg);)))C(MSG_LPRESS,I(!d->d1,
d->d2=s;d->d1=1;I(s,s=0;)E(s=1;);return D_REDRAW;))}return D_O_K;}int z(int msg,
DIALOG *d, int c){int x,y,p,l;DIALOG *b=d->dp;switch(msg){C(MSG_IDLE,for(p=0;p<3
;p++){for(x=0;x<3;x++){l=0;for(y=0;y<3;y++){I(b[1+y*3+x].d1&&b[1+y*3+x].d2==p,l
++;)}I(l==3,j[p]++;return D_CLOSE;)}for(y=0;y<3;y++){l=0;for(x=0;x<3;x++){I(b[1+
y*3+x].d1&&b[1+y*3+x].d2==p,l++;)}I(l==3,j[p]++;return D_CLOSE;)}y=0;l=0;for(x=0
;x<3;x++){I(b[1+y*3+x].d1&&b[1+y*3+x].d2==p,l++;)y++;}I(l==3,j[p]++;return 
D_CLOSE;)y=0;l=0;for(x=2;x>-1;x--){I(b[1+y*3+x].d1&&b[1+y*3+x].d2==p,l++;)y++;}I
(l==3,j[p]++;return D_CLOSE;)l=0;for(x=0;x<3;x++){for(y=0;y<3;y++){I(b[1+y*3+x].
d1,l++;)I(l==9,return D_CLOSE;)}}})}return D_O_K;}int game(){DIALOG w[]={{
d_clear_proc,0,0,0,0,16,16},W(0,0)W(0,60)W(0,120)W(60,0)W(60,60)W(60,120)W(120,0
)W(120,60)W(120,120){d_ctext_proc,250,20,0,0,40},{d_ctext_proc,250,30,0,0,1},{
d_ctext_proc,250,0,0,0,255,0,0,0,0,0,"TicTacToe"},{z,0,0,0,0,0,0,0,0,0,0,w},{0}}
;char v[2][20];sprintf(v[0],"%d",j[0]);sprintf(v[1],"%d",j[1]);w[10].dp=v[0];w
[11].dp=v[1];I(do_dialog(w,-1)==-1,return 0;)return game();}void main(){
allegro_init();install_keyboard();install_mouse();install_timer();set_gfx_mode(
GFX_AUTODETECT_WINDOWED,320,200,0,0);game();}END_OF_MAIN();
