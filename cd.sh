labels="mysys"
mkdir -p CD_root/isolinux
mkdir -p CD_root/images
mkdir -p CD_root/kernel
cp isolinux.bin CD_root/isolinux/isolinux.bin
cp isolinux.cfg CD_root/isolinux/isolinux.cfg
cp *.bss CD_root/isolinux/
cp *.sys CD_root/isolinux/
cp *.c32 CD_root/isolinux/
cp *.com CD_root/isolinux/
cp *.elf CD_root/isolinux/
cp *.jpg CD_root/isolinux/
cp *.menu CD_root/isolinux/
cp *.txt CD_root/isolinux/
bcc -c -Md libdos.c -o libdos.a
bcc -x -i -L -Md cat.c -o cat.com
bcc -x -i -L -Md ls.c -o ls.com
bcc -x -i -L -Md more.c -o more.com
bcc -x -i -L -Md cmd.c -o cmd.com
bcc -x -i -L -Md pointer.c -o pointer.com
bcc -x -i -L -Md clock.c -o clock.com
bcc -x -i -L -Md clear.c -o clear.com
bcc -x -i -L -Md color.c -o color.com
bcc -x -i -L -Md date.c -o date.com
bcc -x -i -L -Md echo.c -o echo.com
bcc -x -i -L -Md label.c -o label.com

cp *.c32 CD_root/isolinux/
cp *.com CD_root/isolinux/
ls CD_root/isolinux > CD_root/isolinux/ls.txt
tree CD_root/ > CD_root/isolinux/tree.txt
printf "$labels\n" > CD_root/isolinux/label.txt
genisoimage -o myos.iso -V "$labels" -input-charset utf-8 -b isolinux/isolinux.bin -no-emul-boot -boot-load-size 4  -boot-info-table ./CD_root 

