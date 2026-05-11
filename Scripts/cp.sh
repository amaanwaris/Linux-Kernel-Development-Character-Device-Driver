function objdumpshowsections
 {
          objdump -h cdd.ko
 }
objdumpdisassembly()
{
         objdump cdd.ko -d -j .modinfo
}

