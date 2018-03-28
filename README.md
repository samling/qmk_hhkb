## To Compile
1. Copy or link `Firmware/sam` folder to `qmk_firmware/keyboards/hhkb/keymaps/sam`
2. From `qmk_firmware` root folder, run `make hhkb:sam`

## To Flash
1. Plug Hasu-modded HHKB in and press reset button under back cover
2. `sudo dfu-programmer atmega32u4 erase --force`
3. `sudo dfu-programmer atmega32u4 flash hhkb_sam.hex`
4. `sudo dfu-programmer atmega32u4 reset`

## To Debug
1. Run `./hid_listen.mac` from the `Tools` folder
2. Enter any of the following debug commands with `Magic` + key; `Magic` is `LShift` + `RShift`:
```
c:      enter console mode
d:      toggle debug enable
x:      toggle matrix debug
k:      toggle keyboard debug
m:      toggle mouse debug
v:      print device version & info
t:      print timer count
s:      print status
e:        print eeprom config
n:        toggle NKRO
0/F10:  switch to Layer0
1/F1:   switch to Layer1
2/F2:   switch to Layer2
3/F3:   switch to Layer3
4/F4:   switch to Layer4
PScr:   power down/remote wake-up
Caps:   Lock Keyboard(Child Proof)
Pause:   jump to bootloader
```
