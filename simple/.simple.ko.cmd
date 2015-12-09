cmd_/home/admin/simple.ko := ld -r -m elf_x86_64 -T /usr/src/kernels/3.10.0-229.el7.x86_64/scripts/module-common.lds --build-id  -o /home/admin/simple.ko /home/admin/simple.o /home/admin/simple.mod.o
