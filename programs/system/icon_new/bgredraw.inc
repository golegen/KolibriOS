BGRedrawThread:

        mcall   40,010000b

BGRTRedrawIcons:
     @@:
        cmp     [bIcoBuff],1   ;��� �����஢�� ����ᮢ�� ������
        jne     @f
        mcall   5,1
        jmp     @b
     @@:

        mov     [bIcoBuff],1

        mcall   48,5
        mov     dx,ax
        shr     eax,16
        sub     dx,ax
        mov     [ScreenX],dx
        mov     ax,bx
        shr     ebx,16
        sub     ax,bx
        mov     [ScreenY],ax

        mov     ecx,[MaxNumIcon]
        test    ecx,ecx
        jz      .NoDraw
        xor     ebx,ebx
    @@: push    ecx
        cmp     [IconNoDraw],ebx
        je      .nd
        stdcall DrawIcon,ebx,0
      .nd:
        inc     ebx
        pop     ecx
        loop    @b
   .NoDraw:

        mov     [bIcoBuff],0


BGRTmessages:
        mcall   10
        sub     eax,5
        jz      BGRTRedrawIcons

        jmp     BGRTmessages





