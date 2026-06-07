
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
	int nn;
	int n=0;
	times();
        sputc(13);
        sputc(10);
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
.globl _keyit
.globl _copys
.globl _times
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
_times:
    mov ah,*4
    int $1a
    mov dl,ch
    shr dl,*4
    and dl,*0xf
    add dl,*0x30
    mov ah,*02
    int *0x21
    mov ah,*4
    int $1a
    and ch,*0xf
    add ch,*0x30
    mov dl,ch
    mov ah,*02
    int *0x21


    mov ah,*4
    int $1a
    shr cl,*4
    and cl,*0xf
    add cl,*0x30
    mov dl,cl
    mov ah,*02
    int *0x21
    mov ah,*4
    int $1a
    and cl,*0xf
    add cl,*0x30
    mov dl,cl
    mov ah,*02
    int *0x21
 
    mov dl,*0x2f
    mov ah,*02
    int *0x21

    mov ah,*4
    int $1a
    shr dh,*4
    and dh,*0xf
    add dh,*0x30
    mov dl,dh
    mov ah,*02
    int *0x21
    mov ah,*4
    int $1a
    and dh,*0xf
    add dh,*0x30
    mov dl,dh
    mov ah,*02
    int *0x21


    mov dl,*0x2f
    mov ah,*02
    int *0x21

    mov ah,*4
    int $1a
    shr dl,*4
    and dl,*0xf
    add dl,*0x30
    mov ah,*02
    int *0x21
    mov ah,*4
    int $1a
    and dl,*0xf
    add dl,*0x30
    mov ah,*02
    int *0x21


    ret
_keyit:
    mov ax,*1
    int $16
    jnz _keyit0
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

