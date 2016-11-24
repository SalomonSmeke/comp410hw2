Hello!

Welcome to my little arch install with my re-compiled kernel!

Let me go through what I did to get here. Its a doozy.

1- Downloaded an arch image.
2- Installed arch in a vm
  a- Created a custom vm to boot the arch image
  b- set it to efi mode by editing the vmware image and setting `firmware='efi'`
  c- Booted into the arch install cd
  d- Set the time to use network time
  e- Created a partition table with:
  ```
  sda1 - Boot, .5G - EFI
  sda2 - Root, 22G - Filesystem
  sda3 - Swap, 2G - Swap

  ```
  f- Formatted the efi parition to f32
  g- Formatted the root parition to ext4
  h- Made sda3 swap, set to swapon.
  i- Selected a closer pacman mirror (illinois vs france)
  j- Installed base and base-devel to Filesystem. Mounted as:
  ```
  /mnt -> sda2
  /mnt/boot -> sda1

  ```
  k- Generated fstab
  l- Chroot into arch install
  m- Set locale to en_us and generated locales
  o- Set hwclock to my timezone
  p- Installed intel microcode
  q- installed default arch efi bootloader
  r- Edited the loader.conf to add an arch entry
  s- Created a boot entry for sda2 with its uuid to boot into arch and default kernel
  t- Set root password to root.
  u- Created 'archlinux' user with group wheel
  v- Gave it sudo access via visudo
  w- Enabled multilib
  x- Installed xorg
  y- Installed xfce, zsh, atom, etc. XFCE is aliased to 'gui'
  z- Installed vmware drivers.
3- Got a matching copy of my kernel from kernel.org
4- Configured to match the current kernel
5- Changed the version name to Arch-+
6- Edited the syscall table to add my own syscall
7- Added my function to sys.c
8- Make -j3 *this takes an eternity*
9- Make -j3 modules_install
10- Copy kernel to /boot
11- Copy mknitcpio and replace linux for my way cooler linux-Arch-+
12- mkinitcpio -P linux-Arch-+
13- Tried super hard for super long to get booting to darn work. I finally got it.
  a- change arch entry in bootloader to point to the new kernel.
  b- definitely dont try to emulate your kernel in qemu. qemu hates you.

Now! All that said and done. I have place a file here that should give you some cool info.

Please note. I have no idea if this works or not. It doenst seem to create a file, but the call definitely happens and definitely doesnt crash the kernel.

Boot with: root, password_in_email
If you want a GUI: gui

gcc -o syscallTest syscallTest.c
./syscallTest 1
dmesg | tail

Clearly i added my syscall. But something aint right. I didnt have time to figure
it out however :( this was pretty rough as it is.

All in all, I am happy that I got a syscall in the kernel. And boy did i learn.
Never use vido.

As far as I can tell. my syscall is having a hard time closing the file.
