section .data
    arr dd 1,2,3,4,5
    decimal db "%d",0
    size equ ($-arr) / 4
section .rodata
section .text
    extern print_arr:
    extern printf:
    global main:

print_arr: 
    enter 0,0
    mov ebx, 0 
loop_: 
    cmp ebx, dword[rbp-8]
    jae end

    mov rax, 0
    mov rdi, decimal
    movsx rsi, dword[arr + rbx * 4]
    call printf

    inc rbx
    jmp loop_

    leave
    ret

main: 
    push rbp
    mov rbp, rsp
    sub rsp, 16

    mov dword[rbp-8], size
    
end: 
    mov rsp, rbp
    pop rbp
    ret

