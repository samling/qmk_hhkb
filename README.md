## To Compile
1. Copy or link `sam` folder to `qmk_firmware/keyboards/hhkb/keymaps/sam`
2. From `qmk_firmware` root folder, run `make hhkb:sam`

## To flash
1. Plug Hasu-modded HHKB in and press reset button under back cover
2. `sudo dfu-programmer atmega32u4 erase --force`
3. `sudo dfu-programmer atmega32u4 flash hhkb_sam.hex`
4. `sudo dfu-programmer atmega32u4 reset`
