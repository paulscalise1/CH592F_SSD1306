# SSD1306 Driver Example for CH5xx Devices

This repo is based off of the [LibDriver SSD1306](https://github.com/libdriver/ssd1306).
LibDriver SSD1306 offers robust basic and advanced APIs to interface with the OLED.

Currently, this repo only contains the code for I2C interfacing.
This repo has been tested on the CH592F so far. PRs can be accepted.

## Usage
Clone the repo:

```bash
git clone https://github.com/paulscalise1/CH592F_SSD1306.git
```

Install [MounRiver Studio](https://mounriver.com/) if not already.
Open MounRiver Studio -> File -> Open MounRiver Project -> Select CH592F_SSD1306.wvproj.
Then, Project -> Properties -> Select your target device.
Once finished, build the project.

You can change the type of tests that run -- Advanced or Basic -- depending on the global #define in Main.c.

To upload, use [WCHISP_Tool](https://www.wch.cn/downloads/WCHISPTool_Setup_exe.html).
Inside the application, select the .hex file generated during build, plug in the target in DFU mode, and select prgram.

It is likely that this code will also work with little or no modification on other CH devices.

## Contributing
The only file that need code additions is ```driver_ssd1306_interface.c```. Currently it is lacking the SPI init and driver code for the CH5xx series.
