.code16

switch_to_pm:
	cli	
	lgdtl gdt_descriptor
	
	# Set the first bit of the CPU control register, cr0, which enables protected mode.
	mov %cr0, %eax
	or $0x1, %eax
	mov %eax, %cr0

	# jump to a differet code segment to flush the pipeline when changing modes.
	ljmp $CODE_SEG, $init_pm

.code32

init_pm:
	# All old segment registers are now meaningless after changing modes, so we point
	# all of them to the data segment we defined in the GDT.
	mov $DATA_SEG, %ax
	mov %ax, %ds	
	mov %ax, %ss
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs

	# Define the stack
	mov $0x90000, %ebp
	mov %ebp, %esp

	call BEGIN_PM
