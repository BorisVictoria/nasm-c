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
                
                mov rcx, rdx ; length
                xor rax, rax ; index
        l1: 
                cmp rcx, 0
                je done

                movss xmm0, [rdi+rax]
                add rax, 4
                movss xmm1, [rdi+rax]
                add rax, 4
                movss xmm2, [rdi+rax]
                add rax, 4

                subss xmm1, xmm0
                mulss xmm1, [meters]
                divss xmm1, [seconds]
                divss xmm1, xmm2

                cvtss2si rdx, xmm1
                mov [rsi], rdx
                add rsi, 4
                dec rcx 
                jmp l1

        done:
                ret        
                
                
                
        
