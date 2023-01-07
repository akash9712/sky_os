.code16
print:
	pusha

start:
	movb (%bx), %al   # bx has been loaded with the base address of the string
	cmp $0, %al
	je done

	mov $0x0e, %ah    # al already contains the char to be printed
	int $0x10
	
	add $1, %bx       # move to the next character
	jmp start
	
done:
	popa
	ret

print_nl:
	pusha

	mov $0x0e, %ah
	mov $0x0a, %al      # newline char
	int $0x10
	mov $0x0d, %al      # carriage return
	int $0x10

	popa
	ret

