.section .data
msg:
    .asciz "Hello, World!\n"

.section .text
.global _start

_start:
    @ Write the message to stdout
    mov r0, #1         @ file descriptor (1 for stdout)
    ldr r1, =msg       @ address of the message
    ldr r2, =13        @ message length
    mov r7, #4         @ syscall number for sys_write
    svc 0              @ invoke syscall

    @ Exit program
    mov r7, #1         @ syscall number for sys_exit
    mov r0, #0         @ exit status (0 for success)
    svc 0              @ invoke syscall
