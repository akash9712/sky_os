.code16
# Receiving the data in dx
# using $0x1234 as example throughout comments

print_hex:
	pusha            # save register values before starting a function

	mov $0, %cx

hex_loop:
	cmp $4, %cx      # 16 byte values represented using 4 hex digits
	je end

	mov %dx, %ax     # using ax as the working register
	and $0x000f, %ax # 0x1234 -> 0x0004
	add $0x30, %al   # since '0' is 0x30, hex 4 is converted to ascii '4'
	cmp $0x39, %al   # If > 9, add extra to represent 'A' to 'F'
	jle step2
	add $7, %al      # Suppose we need 'A', which means al 0s 0d58. ASCII 'A' is 65.
			 # So we need to add 7.
	
step2:
	lea HEX_OUT, %bx
	add $5, %bx
	sub %cx, %bx
	mov %al, (%bx)
	ror $4, %dx

	add $1, %cx
	jmp hex_loop

end:
	lea HEX_OUT, %bx
	call print

	popa
	ret
HEX_OUT:
	.string "0x0000" # reserver memory for our new string

