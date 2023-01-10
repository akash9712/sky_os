### Real mode assembler commands
```
as <file_name> -o <output_file> # Assemble source code
ld <output_file> -o <final_binary> --oformat=binary -Ttext=0x7c00 # Generating flat form binary, with all adresses being relative to 0x7c00 (e.g. offset to memory locations of 0x7c00 being added). Alternatively, we can skip the Ttext flag and modify the segment registers in the source.

qemu-system-i386 <final_binary> # Run the code on QEMU
```
