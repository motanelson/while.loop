
//bcc  -Md hello.c -o HELLO.COM

#define varn 0xc080

int lowercmp(a,b);
void getss(s,i);
char getcc();
void sputs(cc);
void scopy(s1,s2);
void scat(s1,s2);
void slower(s1);
int main()

{
        char *r=" ";
        char *rr="\n";
        char *rrr;
	int nn=1;
	char n;
	
	char *argv0=0x82;
        int x=0;
        int y=0;
        int xx=0;
        int aa=0x70;
        aa=0x70;
        xx=y*160+(x*2)+1;
        pointer(xx,aa);

	sputs("keys a<>d x.|-w  space\r\n");
        while (nn){
	    
	    n=(char)keyit();
	    
            aa=0x07;
            xx=y*160+(x*2)+1;
            pointer(xx,aa);
            
            if (n==' ')nn=0;
            if (n=='a')x--;
            if (n=='d')x++;
            if (n=='w')y--;
            if (n=='x')y++;
            if (x<0)x=0;
            if (y<0)y=0;
            if (x>78)x=78;
            if (y>20)y=20;
            
            aa=0x70;
            xx=y*160+(x*2)+1;
            pointer(xx,aa);
            //sleep(1);
        }
        
        
	systems("cmd.com");
	return 0;
}
int lowercmp(a,b)
char *a;
char *b;
{
    int n=0;
    for(n=0;n<78;n++){
        if(b[n]==0){
            return 1;    
        
        }else{
            a[n]=a[n] | 0x20;
            b[n]=b[n] | 0x20;
            if(a[n]!=b[n])return 0;
        }
    }
    return 1;
}
void getss(s,i)
char *s;
int i;
{   
    int nn=0;
    int n=0;
    
    for (n=0;n<i;n++){
        s[n]=getcc();
        
        
        if(s[n]==13){
            s[n]=0;
            
            
            
            n=i+1;
            
        }
    }
    
    s[i]=0;
    
}
char getcc(){
    char keys=getchar();
    sputc(keys);
    return keys;
}
void sputs(cc)
char *cc;
{
		int i=0;
while(cc[i]!=0){
		sputc(cc[i]);
		i++;
}
}
void scopy(s1,s2)
char *s1;
char *s2;
{
	char cc=0;
	int counter=0;
	do{
		s1[counter]=s2[counter];
		cc=s2[counter];
		counter++;
	}while(cc!=0);
	
}
void scat(s1,s2)
char *s1;
char *s2;
{
	char *s3;
	char cc=0;
	int counter=0;
	do{
		cc=s1[counter];
		counter++;
	}while(cc!=0);
	s3=s1+counter-1;
	scopy(s3,s2);
}

void slower(s1)
char *s1;
{
	char *s3;
	char cc=0;
	int counter=0;
	do{
		cc=s1[counter];
		if (cc>='A' && cc<='Z')s1[counter]=cc+32;
		counter++;
	}while(cc!=0);
}

#asm
.globl _cls3
.globl _sputc
.globl _getchar
.globl _sleep 
.globl _keyit
.globl _copys
.globl _pointer
.globl _systems
_cls3:
    mov si,sp
    add si,*0x2
    mov dx,[si]
    mov ax,*0xb800
    push ds
    mov ds,ax
    
    mov ax,dx
    mov cx,*0x8a0
    mov si,*0x1
    
cls31:
    
    mov [si],al    
    inc si
    inc si
    dec cx
    cmp cx,*0x0
    jnz cls31
    pop ds
    ret
_pointer:
    mov si,sp
    add si,*0x2
    mov bx,[si]
    mov si,sp
    add si,*0x4
    mov dx,[si]
    mov ax,*0xb800
    push ds
    mov ds,ax
    mov al,dl
    mov [bx],al
    pop ds
    ret
_sputc:
    mov si,sp
    add si,*0x2
    mov dx,[si]
    mov ah,*02
    int *0x21
    ret
_getchar:
    mov ax,*0
    int $16
    ret
_sleep:
    mov si,sp
    add si,*0x2
    mov ax,[si]
    push ax
    mov ah,*2
    int $1a
    pop ax
    mov dl,dh
    mov dh,*0
    add ax,dx 
    cmp ax,*59
    jb _sleep1
    sub ax,*60
    jmp _sleep1
_sleep1:
    push ax
    mov ah,*2
    int $1a
    pop ax
    mov dl,dh
    mov dh,*0x0
    cmp dx,ax
    ja _sleep1
_sleep2:
    push ax
    mov ah,*0x2
    int $1a
    pop ax
    mov dl,dh
    mov dh,*0
    cmp dx,ax
    jb _sleep2
    ret
_keyit:
    mov ah,*0
    int $16
    ret
_keyit0:
    mov ax,0
    ret
_copys:
    mov si,0x80
    mov cx,0
    mov cl,[si]
    add si,cx
    mov ax,0
    mov [si],al
    mov si,0x81
    ret
_systems:
    mov bx,sp
    add bx,*0x2
    mov dx,[bx]
    mov bx,dx
    
    mov ax,*0x3
    int $22
    ret
systems2:
    mov ax,1
    ret
#endasm

