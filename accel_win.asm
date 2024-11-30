bits 64
default rel

global accel

section .data
        meters dd 1000.0
        seconds dd 3600.0

section .text
        accel:
                ; accel(float* cars, int* result, int length)
                ; Unix - rdi, rsi, rdx, rcx, r8, r9
                ; Windows - rcx, rdx, r8, r9 
                ; Preserve rbx, rbp, rdi, rsp, r12-r15
                
                xor rax, rax ; index
        l1: 
                cmp r8, 0 ; length
                je done

                movss xmm0, [rcx+rax]
                add rax, 4
                movss xmm1, [rcx+rax]
                add rax, 4
                movss xmm2, [rcx+rax]
                add rax, 4

                subss xmm1, xmm0
                mulss xmm1, [meters]
                divss xmm1, [seconds]
                divss xmm1, xmm2

                cvtss2si r9, xmm1
                mov [rdx], r9
                add rdx, 4
                dec r8 
                jmp l1

        done:
                ret        
                
                
                
        
