# arduino_update
[Arduino入门参考](https://blog.csdn.net/qq_29506411/article/details/134164156)
## 注意
1. 这个例程是针对串口的`DTR`管脚没有和`MCU`的`reset`管脚连接的情况使用的。如果串口的`DTR`已经连接到`MCU`的`reset`管脚了，那么就不需要这么麻烦，通过`Tools-->Burn Bootloader`后，直接写`application`就好，不需要实现跳转部分的代码，因为串口的`DTR`管脚会使`MCU`复位，然后进入`bootloader`等待更新。
## How to use?
1. open upload log output.
![config upload output](./resource/config_upload_output.png)
2. burn bootloader(must use the downloader).
![burn bootloader](./resource/burn_bootloader.png)
According to your kit, select the relative configuration, then click `Burn Bootloader`.
3. upload app(by UART): click `Sketch-->Upload`.
![upload](./resource/upload.png)\
Then, you will see the upload command in the output window of `Arduino IDE`:
![upload command](./resource/upload_cmd.png)
4. modify the [script](./upload_cmd.py) for uploading:
> - modify the UART Port. (line7 & line13)
> - modify the upload cmd according the output of last step. (line13) (you can change `-v` to `-vvvvv` see more details)
5. run the [script](./upload_cmd.py):
```shell
python upload_cmd.py
```
