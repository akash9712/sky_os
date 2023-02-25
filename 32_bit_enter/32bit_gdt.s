# Note: The limit section in the GDT is 20 bits. Since the limit tells the maximum addressable
# unit in either 1Byte units or 4 KiB units (if the Granularity bit is set), the maximum
# limit becomes 4K * 0xfffff, i.e 4GB.
gdt_start:
	# 8 empty bytes for the first, null entry of the GDT
	# Simple error proofing mechanism in case you forget to set the segment register
	# Since the segment register is used as the index in the GDT, not setting it,
	# i.e. the segment being 0x0 will point to this null entry, whereby the
	# CPU will raise an interrupt.
	.long 0x0
	.long 0x0

gdt_code:
	# GDT for the code segment (refer to the structure of a row in GDT in os-dev.pdf)
	.word 0xffff                  # Limit (Bits 0-15)
	.word 0x0                     # Segment base (bits 0-15)
	.byte 0x0                     # Segment base (bits 0-15)
	.byte 0b10011010	      # 1st flags, type flags
	.byte 0b11001111              # 2nd flags, limit (bits 16-19)
	.byte 0x0                     # Base (bits 24-31)

gdt_data:
	.word 0xffff
	.word 0x0
	.byte 0x0
	.byte 0b10010010
	.byte 0b11001111
	.byte 0x0

gdt_end:

gdt_descriptor:
	.word gdt_end - gdt_start - 1 # size in 16 bits
	.long gdt_start               # 32 bit address

.equ CODE_SEG, gdt_code - gdt_start
.equ DATA_SEG, gdt_data - gdt_start

